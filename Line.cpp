#include "Line.h"
using namespace std;
struct Point
{
  double x, y, z;
};
Line::Line(){
     xStart = 0,xEnd = 100,yStart = 0,yEnd = 100,zStart = 0,zEnd = 100;
       zStart = -zStart;
        zEnd = - zEnd;

}
Line::Line(int a,int b,int c,int x,int y,int z){
     xStart = a,xEnd = x,yStart = b,yEnd = y,zStart = c,zEnd = z;
       zStart = -zStart;
        zEnd = - zEnd;

}
void Line::drawLine(){


        glLineWidth(2.0);
        glBegin(GL_LINES);
        glColor3f(1,0,1);
        glVertex3f(xStart,yStart,zStart);
        glColor3f(1,1,0);
        glVertex3f(xEnd,yEnd,zEnd);

        glEnd();
}

float * Line::rotateThePoint(float point[4],int axis,int angle){
    if(axis == 0)     return rotatePointAlongX(point,angle);
   else if(axis == 1) return rotatePointAlongY(point,angle);
   return rotatePointAlongZ(point,angle);

}
void Line::rotateAroundAxis(int axis,int angle){

   float * ptr;

    float matrixToPass[4] = {xStart,yStart,zStart,1};
    ptr = rotateThePoint(matrixToPass,axis,angle);
    float a[4] = {0,0,0,0},b[4] = {0,0,0,0};
     for(int i = 0;i<4;i++){
        matrixToPass[i]= *(ptr + i);
        //cout<<matrixToPass[i]<<endl;
    }
         xStart = matrixToPass[0];
         yStart = matrixToPass[1];
         zStart = matrixToPass[2];

             float secondMatrixToPass[4] = {xEnd,yEnd,zEnd,1};
    ptr = rotateThePoint(secondMatrixToPass,axis,angle);
     for(int i = 0;i<4;i++){
        secondMatrixToPass[i]= *(ptr + i);
        //cout<<matrixToPass[i]<<endl;
    }
         xEnd = secondMatrixToPass[0];
         yEnd = secondMatrixToPass[1];
         zEnd = secondMatrixToPass[2];

}
void Line::translateMyLine(int x,int y,int z){
     float matrixToPass[4] = {xStart,yStart,zStart,1};
     int xDiff = xEnd - xStart, yDiff = yEnd - yStart, zDiff = zEnd - zStart;
    int translatingMatrix[3] ={x,y,z};
    float * m;
    int a[4] = {0,0,0,0};
    m = translateMyPoints(matrixToPass,translatingMatrix);

    for(int i = 0;i<4;i++)
         a[i]= *(m + i);
         xStart = a[0];
         yStart = a[1];
         zStart = a[2];

         xEnd = xStart + xDiff;
         yEnd = yStart + yDiff;
         zEnd = zStart + zDiff;
}




