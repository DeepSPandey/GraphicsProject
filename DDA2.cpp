
using namespace std;
#include "DDA2.h"
#define PI 3.14159265

DDA2::DDA2(){
    angle = 40;
}

void DDA2::rotateAngle(int a){
    angle  = a;
}
void DDA2::plotPixel(int x,int y){

        glPointSize(4.0);
        glColor3f(0,0,1);
        glBegin(GL_POINTS);
        //uncomment this to plot only a line without any rotation
        //glVertex3f(x,y,-1000);

        float pointsArray[3] = { x, y, 1 };
        float * m;
        m = rotateMyPoints(pointsArray,angle);
        for(int  i=0;i<3;i++)
        pointsArray[i] = *(m+i);
        glVertex3f(pointsArray[0],pointsArray[1],-1000);
        glEnd();
        glFlush(); //executes all OpenGL functions as quickly as possible

       }
void DDA2::makeLine(int x0,int y0, int x1, int y1){
 float dx,dy,steps;
    float x,y;

    dx = x1 - x0;
    dy = y1 - y0;
    steps = max(dx,dy);

    x = x0, y = y0;
    plotPixel(x,y);


    while(x<x1 || y<y1){
        x += dx/steps;
        y += dy/steps;
        plotPixel(x,y);
    }

}

