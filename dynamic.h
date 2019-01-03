#include <GL/glut.h>
#include<iostream>
#ifndef DYNAMIC_H
#define DYNAMIC_H

//Represents an image
class dynamic {
    int increaseX,increaseY,increaseZ;
    int xStart,xEnd ,yStart ,yEnd ,zStart ,zEnd ;


	public:

	    dynamic();
	    ~dynamic();
	    dynamic(int ,int ,int,int ,int ,int);
	    void drawCube();
	  //  void moveCube(int x,int y,int z);


};

#endif





