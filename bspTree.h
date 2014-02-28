#ifndef __BSP_TREE_H__
#define __BSP_TREE_H__

#include "miro.h"
#include "object.h"
#include "material.h"
#include "ray.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <cmath>

#define MaxTreeDepth 100
#define MaxObjsPerNode 3

struct BSP_node{
	float plane_pos;
	int axis;
	BSP_node *left,*right;
	bool is_leaf;
	ObjectList obj_array;
};

struct BSP_stack_item{
	BSP_node *node;
	float tmin,tmax;
};

struct Plane_Cut{
    int axis;
    float pos;
};

class BSPTree : public Object
{
public:
    BSPTree();
    virtual ~BSPTree();

    // helper functions
    void AddObject (Object* pObj);
    void PreCalc() ;

    // setting options
    void setRenderTree(bool render) {render_tree = render;}
    bool isRenderTree() {return render_tree;}

    // render functions
    void RenderGL() ;
    void RenderNode(BSP_node* node,BoundingBox box,float &boxTimes,int depth);
    void RenderSplitPlane(int node_axis, Vector3 aboveMin, Vector3 belowMax);

    // intersect functions
    bool Intersect (HitInfo& result, const Ray& ray,
                    float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);
    bool IntersectSimple(HitInfo& result, const Ray& ray,
                    float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);
    bool IntersectTree(HitInfo& result, const Ray& ray,
                    float tMin = MIRO_TMIN, float tMax = MIRO_TMAX);

    // bsp creation
    void buildBSPTree();
    BSP_node* split_node(ObjectList objects, BoundingBox box,int depth);
    ObjectList objsInBox(ObjectList objects,BoundingBox box);
    Plane_Cut getBestCut(ObjectList objects,BoundingBox box);
    
    // get bounding boxes after split
    BoundingBox getBelowBoundingBox(BoundingBox box, int axis, float split_pos);
    BoundingBox getAboveBoundingBox(BoundingBox box, int axis, float split_pos);

    // get total bounding box
    virtual BoundingBox getBoundingBox();

    // tagging for mail boxing
    virtual void clearTAG();
    int getCurrentId();

    // print stats
    void printStats();

protected:
    // bspTree data
	BSP_node* root;

	// all the objects in the scene
    ObjectList m_kObjects;

    // options
    static bool render_tree;
    static bool mail_boxing;

    // counting rays
    long int no_of_rays;
    static int hits_without_mailboxing;
    static long int hits_with_mailboxing;
};

#endif
