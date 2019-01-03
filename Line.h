#include <GL/glut.h>
#include<iostream>
#include"Rotation.h"
#ifndef LINE_H
#define LINE_H

//Represents an image
class Line:public Rotation
{
	public:
	     int xStart,xEnd ,yStart ,yEnd ,zStart ,zEnd ;
	    Line();
	    Line(int a,int b,int c,int x,int y,int z);
	    void drawLine();
	    //axis are defined by 0 = around x axis,1= around y axis and 2  = around z axis
        void rotateAroundAxis(int axis,int angle);
        float * rotateThePoint(float point[4],int axis,int angle);

        void translateMyLine(int x,int y,int z);

};

#endif







