#include <GL/glut.h>
#include<iostream>
#include"Rect.h"
#ifndef CUBE_H
#define CUBE_H

//Represents an image
class Cube:public Rect {

	public:
	     int xStart,yStart,zStart,xEnd,yEnd,zEnd;
	     double rColor,gColor,bColor;
	    Rect rect[6];
	    Cube();
	    Cube(int ,int ,int,int ,int ,int);
	    void drawCube();
	    void rotateCubeAroundAxis(int axis,int angle);
	    void translateMyCube(int x,int y,int z);
	    void setCubeColor(double r,double g, double b);

};

#endif







