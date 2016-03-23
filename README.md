# miro
Ray Tracer

This is a ray tracer I started making as a personal project during my last year at undergrad. I have since update it several times, adding several features over the year. This ray tracer is capable of loading object files, displaying them in an OpenGL viewer, moving the camera around in the scene, rendering with depth of field, soft shadows, motion blur and some simple lights. Global illumination is added through path tracing or photon mapping. BSP Trees are used for accelerating ray intersections (incredible speedup). The scene is represented through a custom made scene file which is parse using flex and bison and can be easily extended. Please see the Images folder for some sample images and a presentation I gave for a class on two of the advanced features.

Note that photonmap code was taken from Henrick Wann Jenson's implementation and bitmap writing was taken off the internet. Almost all of the rest is my code (the bison/flex parser was started from a sample implementation). Please contact me at madil90@gmail.com before using this code. Thank you.
