#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "giruRotate.h"
#ifndef BRESENHAMS_H
#define BRESENHAMS_H
class Bresenhams:public giruRotate
{
    int angle;
    int x0,y0,x1,y1;
    int translateMatrix[2];
    public:
        Bresenhams(int x,int y);
        Bresenhams(int,int,int ,int);
        void rotateAngle(int);
        void translateLine(int ,int );
        void plotPixel(int ,int );
        void makeLine();

};



#endif


