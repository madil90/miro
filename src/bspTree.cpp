#include "bspTree.h"
#include "light.h"
#include "scene.h"
#include "console.h"
#include <iostream>

// initialize static values
long int BSPTree::hits_with_mailboxing = 0;
int BSPTree::hits_without_mailboxing = 0;
int BSPTree::nSplits = 2;

// static options
bool BSPTree::render_tree = false;
bool BSPTree::mail_boxing = true;

// class constructor
BSPTree::BSPTree()
   : no_of_rays(0) 
{	
}

BSPTree::~BSPTree()
{
	if (root!=NULL){
		delete[] root;
	}
	
	delete[] &m_kObjects;
}

void BSPTree::AddObject (Object* pObj)
{
    // here you will need to add the object to the bsp tree.
    // This should also take care of the situation where the Object* above
    // needs to Refine itself.
	pObj->Refine(m_kObjects);
	m_kObjects.push_back(pObj);
}

BoundingBox BSPTree::getBoundingBox()
{
	BoundingBox sceneBox;
	ObjectList::iterator o;
	
	for (o=m_kObjects.begin();o!=m_kObjects.end();o++){
		BoundingBox objBox = ((*o)->getBoundingBox());
		sceneBox.expand(objBox);
	}

	return sceneBox;
}

void BSPTree::PreCalc()
{
	// do precalculation per object
	ObjectList::iterator o;

	for (o=m_kObjects.begin();o!=m_kObjects.end();o++)
	{
		(*o)->PreCalc();
	}

	// now get the total bounding box
	box = getBoundingBox();

	// build the tree
	buildBSPTree();
}

// ------------------------------------------------------------------------
// BSP Tree Render
// ------------------------------------------------------------------------
void BSPTree::RenderSplitPlane(int node_axis, Vector3 aboveMin, Vector3 belowMax)
{
	// render the plane
	glColor3f(0.0f, 0.0f, 1.0f);

	// figuring out other axis
	bool isx = node_axis == 0, isy = node_axis == 1;
	int second_axis, third_axis;
	if (isx) {
		second_axis = 1; third_axis = 2;
	}else if (isy){
		second_axis = 0; third_axis = 2;
	}else{
		second_axis = 0; third_axis = 1;
	}

	Vector3 v2(aboveMin);
	Vector3 v4(aboveMin);

	v2[third_axis] = belowMax[third_axis];
	v4[second_axis] = belowMax[second_axis];

    glBegin(GL_LINE_LOOP);
        glVertex3f(aboveMin.x, aboveMin.y, aboveMin.z);
        glVertex3f(v4.x, v4.y , v4.z );
        glVertex3f(belowMax.x, belowMax.y , belowMax.z );
        glVertex3f(v2.x, v2.y , v2.z );
    glEnd();
}


// render a single node
void BSPTree::RenderNode(BSP_node* node,BoundingBox box,float &boxTimes,int depth)
{
	BSP_node* left = node->left;
	BSP_node* right = node->right;


	if (node->is_leaf){
		//box.RenderGL();
		return;
	}
	
	// getting min max
	Vector3 belowMax(box.Max());
	Vector3 aboveMin(box.Min());

	// getting split plane
	belowMax[node->axis] = node->plane_pos;
	aboveMin[node->axis] = node->plane_pos;

	// get bounding boxes
	BoundingBox below(box.Min(),belowMax);
	BoundingBox above(aboveMin,box.Max());

	// render this split plane
	RenderSplitPlane(node->axis,aboveMin,belowMax);	

	RenderNode(left,below,boxTimes,depth+1);
	RenderNode(right,above,boxTimes,depth+1);

}

// render the objects in the scene (and optionally the tree)
void BSPTree::RenderGL()
{
	ObjectList::iterator oit = m_kObjects.begin();
    while (oit != m_kObjects.end())
    {
        Object* pObj = *oit;
        pObj->RenderGL();
        oit++;
    }

    const LightList* lights = g_pScene->GetLights();
	LightList::const_iterator l;
	for (l=lights->begin();l!=lights->end();l++)
	{
		(*l)->RenderGL();
	}

	if (render_tree){
		float boxTimes = 0;
		box.RenderGL();
		RenderNode(root,box,boxTimes,0);
	}
}

// ------------------------------------------------------------------------
// BSP Tree Intersect
// ------------------------------------------------------------------------
bool BSPTree::Intersect (HitInfo& result, const Ray& ray,
                    float tMin, float tMax)
{
	// intersect tree and return
	return IntersectTree(result,ray,tMin,tMax);
}

// BSPTree Simple Intersection
bool BSPTree::IntersectSimple (HitInfo& result, const Ray& ray,
                    float tMin, float tMax)
{
	bool has_hit = false;
	ObjectList::iterator o;
	
	for (o=m_kObjects.begin();o!=m_kObjects.end();o++){
		HitInfo hit;
		if ((*o)->Intersect(hit,ray)){
			if (!has_hit || hit.t<result.t){
				result = hit;
				has_hit = true;
			}
		}
	}
	return has_hit;	
}

// intersect the bsp tree
bool BSPTree::IntersectTree(HitInfo& result, const Ray& ray,
                    float tMin, float tMax)
{
	bool have_one = false;

	// this is the bsp tree traversal technique
	std::stack<BSP_stack_item> bspStack;
	BSP_node *node = root;
	float isect = MIRO_TMAX;
	result.t = MIRO_TMAX;
	float tmin,tmax;

	// setting all tags to false


	if (!box.intersect(ray,tmin,tmax))
		return have_one;

	while (node!=0){
		
		if (isect<tmin)
			break;

		if (!node->is_leaf){
			// process interior node here

			// computing ray and split plane interseciton
			float tsplit = (node->plane_pos - ray.o[node->axis]) * (1 / ray.d[node->axis]);

			// order children
			BSP_node *first,*second;
			if (ray.o[node->axis] < node->plane_pos){
				first = node->left;
				second = node->right;
			}else{
				first = node->right;
				second = node->left;
			}


			// process children
			if ( tsplit>tmax || tsplit<0 || (tsplit==0 && (ray.d[node->axis]>0))
				  || (ray.d[node->axis]==0)){
				node = first;
			}else if ( tsplit<tmin || (tsplit==0 && (ray.d[node->axis]<0))){
				node = second;
			}else{
				node = first;
				BSP_stack_item item;
				item.node = second;
				item.tmin = tsplit;
				item.tmax = tmax;
				bspStack.push(item);
				tmax = tsplit;
			}

		}else{
			// checking for intersection in the leaf
			ObjectList::iterator o;
			for (o=node->obj_array.begin();o!=node->obj_array.end();o++)
			{
				HitInfo hit;
				if ( mail_boxing && (*o)->getTAG()==ray.rayId)
					continue;

					

				if (mail_boxing){
					hits_with_mailboxing++;
					(*o)->setTAG(ray.rayId);
				}
				// else
				// 	hitsWoMailboxing++;

				if ((*o)->Intersect(hit,ray)){
					if (!have_one || hit.t<result.t){
						result=hit;
						have_one = true;
					}
				}
			}
			isect = result.t;

			// geting items from stack
			if (!bspStack.empty()){
				BSP_stack_item bspItem = bspStack.top();
				bspStack.pop();
				node = bspItem.node;
				tmin = bspItem.tmin;
				tmax = bspItem.tmax;
			}else{
				node = 0;
			}
		}
	}
	return have_one;
}

// ------------------------------------------------------------------------
// BSP Tree Creation
// ------------------------------------------------------------------------
void BSPTree::clearTAG()
{
	ObjectList::iterator o;

	for (o=m_kObjects.begin();o!=m_kObjects.end();o++)
	{
		(*o)->clearTAG();
	}
}

// ------------------------------------------------------------------------
// BSP Tree Creation
// ------------------------------------------------------------------------
void BSPTree::buildBSPTree()
{
	// get starting time
	srand(time(NULL));
	time_t begin,end;
	time(&begin);
	
	// find max depth
	float max_depth = 3+1.3*(log((float)m_kObjects.size()) / log((float)2));
	// float max_depth = 2;
	
	// starting tree
	Debug("Initializing tree with max depth %d \n",(int)max_depth);

	Debug("Splits to check are %d \n",nSplits);

	// create tree
	root = split_node(m_kObjects,box,max_depth);

	// finishing making tree
	time(&end);
	Debug("Time Taken to build tree %d \n",(int)difftime(end,begin));
}

// BSP Splitting nodes function
BSP_node* BSPTree::split_node(ObjectList objects, BoundingBox box,int depth)
{
	// creating a new node and root (if not already made)
	BSP_node *node = new BSP_node();
	if ((depth<=0) || (objects.size()<=MaxObjsPerNode)){
		node->is_leaf = true;
		node->obj_array = objects;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	// find the split position
	Plane_Cut bestCut = getBestCut(objects,box);
	
	// bad axis if cost is higher to split
	if (bestCut.axis<0){
		node->is_leaf = true;
		node->obj_array = objects;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	// assign cut
	node->axis = bestCut.axis;
	node->plane_pos = bestCut.pos;
	node->is_leaf = false;

	// get above and blow bounding box
	BoundingBox below = getBelowBoundingBox(box,node->axis,node->plane_pos);
	BoundingBox above = getAboveBoundingBox(box,node->axis,node->plane_pos);

	// finding objects in each box
	ObjectList objsAbove = objsInBox(objects,above);
	ObjectList objsBelow = objsInBox(objects,below);
	
	// split further
	node->left = split_node(objsBelow,below,depth-1);
	node->right = split_node(objsAbove,above,depth-1);

	// return this node (thats now been split into a tree)
	return node;
}

// get the best cut possible for this bounding box
Plane_Cut BSPTree::getBestCut(ObjectList objects, BoundingBox box)
{
	// initialize struct
	Plane_Cut bestCut;
	bool random_cut = false;
	int cost_per_object = 8;
	int cost_per_plane = 1;
	
	// cost of the total
	float cost_no_split = cost_per_object * objects.size();

	// get random cut
	if (random_cut){
		bestCut.axis = std::rand()%3;
		float dist = (box.Max())[bestCut.axis]- (box.Min())[bestCut.axis];
		bestCut.pos = (box.Min())[bestCut.axis] + dist/2;
	}

	// other wise
	else{
		// implementing hueristics
		int lowestCost = std::numeric_limits<int>::max();

		// if too many objects, check few splits
		// if (objects.size()>500){
		// 	nSplits = 1;
		// }

		// check along all three axis
		for (int i=0;i<3;i++){

			// generate checking positions
			for (int j=1;j<=nSplits;j++){

				// generate splitting positions
				float dist = (box.Max())[i] - (box.Min())[i];
				float splitPos = box.Min()[i] + (j*(1.0/(nSplits+1.0)))*dist;

				// find bounding boxes at these split pos
				BoundingBox below = getBelowBoundingBox(box,i,splitPos);
				BoundingBox above = getAboveBoundingBox(box,i,splitPos);

				// find objects in the box
				ObjectList objsAbove = objsInBox(objects,above);
				ObjectList objsBelow = objsInBox(objects,below);

				// find the difference
				int diff = std::abs( (int) (objsAbove.size()-objsBelow.size()) );

				// find the probability of hitting
				float pBelow = below.Area()/box.Area();
				float pAbove = above.Area()/box.Area();

				// find the cost
				float cost_split = 2*cost_per_plane +
									pBelow * objsBelow.size() * cost_per_object +
									pAbove * objsAbove.size() * cost_per_object;

				// // if lower save
				if (cost_split < lowestCost){
					lowestCost = cost_split;
					bestCut.axis = i;
					bestCut.pos = splitPos;
					// noObjsAbove = objsAbove.size();
					// noObjsBelow = objsBelow.size();
				} 

				// clear both lists
				objsAbove.clear();
				objsBelow.clear();
			}
		}

		if (lowestCost >= cost_no_split){
			bestCut.axis = -1;
		}
	}

	return bestCut;
}

// get the bounding box below
BoundingBox BSPTree::getBelowBoundingBox(BoundingBox box, int axis, float split_pos)
{
	// finding max position
	Vector3 belowMax(box.Max());

	// splitting positions at split plane
	belowMax[axis] = split_pos;

	// creating the below box after splitting
	BoundingBox below(box.Min(),belowMax);

	return below;
}

// get the bounding box Above
BoundingBox BSPTree::getAboveBoundingBox(BoundingBox box, int axis, float split_pos)
{
	// finding min vector
	Vector3 aboveMin(box.Min());

	// splitting positions at split plane
	aboveMin[axis] = split_pos;

	// creating the above bounding box after splitting
	BoundingBox above(aboveMin,box.Max());

	return above;
}

// find which objects are in the box
ObjectList BSPTree::objsInBox(ObjectList objects,BoundingBox box)
{
	ObjectList objsInBox;

	ObjectList::iterator o;

	for (o=objects.begin();o!=objects.end();o++)
	{
		if ((*o)->intersectBox(box))
		{
			objsInBox.push_back(*o);
		}
	}
	return objsInBox;
}

// ------------------------------------------------------------------------
// Print current stats
// ------------------------------------------------------------------------
void BSPTree::printStats()
{
	std::cout<<"no of rays "<<no_of_rays<<std::endl;
	std::cout<<"hits with mailboxing "<<hits_with_mailboxing<<std::endl;
	std::cout<<"Intersections per ray with mailboxing "<<(float)hits_with_mailboxing/(float)no_of_rays<<std::endl;
}

int BSPTree::getCurrentId()
{
	no_of_rays++;
	return no_of_rays;
}