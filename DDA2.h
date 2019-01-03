#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "giruRotate.h"
#ifndef DDA2_H
#define DDA2_H

class DDA2:private giruRotate
{
    int angle;
    public:
        DDA2();
       void plotPixel(int a,int b);
       void makeLine(int x0,int y0, int x1, int y1);
       void rotateAngle(int);
};

#endif


