#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    public:
       void plotPixel(int a,int b);
       void plotPixel(int x,int y,int x0,int y0);
       void makeCircle(int x0,int y0, int r);

};

#endif


