#include <GL/glut.h>
#include<iostream>
#include"dynamic.h"
#include<vector>
#ifndef MAKECUBE_H
#define MAKECUBE_H

//Represents an image
class makeCube {
    int increaseX,increaseY,increaseZ;
    std::vector<makeCube*> dynamics;


	public:
	        int xStart,xEnd ,yStart ,yEnd ,zStart ,zEnd ;
	    makeCube();
	    ~makeCube();
	    makeCube(int ,int ,int,int ,int ,int);
	    void drawCube();
	    void moveCube(int x,int y,int z);
	    void addDynamicObject(int);
	    void deleteDynamicObject();

};

#endif




