#include <GL/glut.h>
#include<iostream>
#include"Line.h"
#include"Rotation.h"
#ifndef RECT_H
#define RECT_H

class Rect:public Line
{
	public:
	    double rColor,gColor,bColor;
	    Line line[4];
	    Rect();
	    Rect(int ,int ,int,int ,int ,int);
	    void drawRect();
	    void rotateRectAroundAxis(int axis,int angle);
	    void translateMyRect(int x,int y,int z);
	    void setRectColor(double r,double g, double b);

};

#endif





