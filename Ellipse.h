#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "giruRotate.h"
#ifndef ELLIPSE_H
#define ELLIPSE_H

class Ellipse:private giruRotate
{
private:
    int x0,y0,rx,ry;
    public:
        Ellipse();
        Ellipse(int x0,int y0, int rx,int ry );
       void plotPixel(int a,int b);
       void makeEllipse();
       void rotateEllipse(int);
};

#endif



