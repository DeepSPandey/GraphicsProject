#include "dynamic.h"
using namespace std;
dynamic::dynamic(){
    cout<<"default constructor of dynamic"<<endl;
     int xStart = -10,xEnd = 10,yStart = -10,yEnd = 10,zStart = 0,zEnd = 10;
    increaseX = 0,increaseY = 0,increaseZ = 0;


     //drawCube();
}
dynamic::dynamic(int x0,int y0,int z0,int x1,int y1,int z1){
    cout<<"parametized constructor of dynamic"<<endl;
    drawCube();
   xStart = x0 ; xEnd = x1;
    yStart = y0 ; yEnd = y1 ;
    zStart = z0 ; zEnd = z1 ;
    increaseX = 0,increaseY = 0,increaseZ = 0;
}
dynamic::~dynamic(){

    cout<<"default destructor of dynamic"<<endl;
}

void dynamic::drawCube(){
    xStart += increaseX; xEnd += increaseX;
    yStart += increaseY; yEnd += increaseY;
    zStart += increaseZ; zEnd += increaseZ;

        zStart = -zStart;
        zEnd = - zEnd;

        glLineWidth(2.0);
        glBegin(GL_LINES);
                   glColor3f(1,1,0);
        // z plot
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xStart,yStart,zEnd);

        glVertex3f(xStart,yEnd,zStart);
        glVertex3f(xStart,yEnd,zEnd);

        glVertex3f(xEnd,yStart,zStart);
        glVertex3f(xEnd,yStart,zEnd);

        glVertex3f(xEnd,yEnd,zStart);
        glVertex3f(xEnd,yEnd,zEnd);

        // x plot
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xEnd,yStart,zStart);

        glVertex3f(xStart,yEnd,zStart);
        glVertex3f(xEnd,yEnd,zStart);

        glVertex3f(xStart,yStart,zEnd);
        glVertex3f(xEnd,yStart,zEnd);

        glVertex3f(xStart,yEnd,zEnd);
        glVertex3f(xEnd,yEnd,zEnd);

        //y plot
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xStart,yEnd,zStart);

        glVertex3f(xStart,yStart,zEnd);
        glVertex3f(xStart,yEnd,zEnd);

        glVertex3f(xEnd,yStart,zStart);
        glVertex3f(xEnd,yEnd,zStart);

        glVertex3f(xEnd,yStart,zEnd);
        glVertex3f(xEnd,yEnd,zEnd);
        glEnd();

/*
        glBegin(GL_QUADS);
        //front face
        glColor3f(0,0,1);
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xEnd,yStart,zStart);
        glVertex3f(xEnd,yEnd,zStart);
        glVertex3f(xStart,yEnd,zStart);
        //glColor3f(0,1,0);;
        //back face
        glVertex3f(xStart,yStart,zEnd);
        glVertex3f(xEnd,yStart,zEnd);
        glVertex3f(xEnd,yEnd,zEnd);
        glVertex3f(xStart,yEnd,zEnd);

        //right side face
        //glColor3f(0,1,1);
        glVertex3f(xEnd,yStart,zStart);
        glVertex3f(xEnd,yStart,zEnd);
        glVertex3f(xEnd,yEnd,zEnd);
        glVertex3f(xEnd,yEnd,zStart);
         //left side face
        //glColor3f(1,0,0);
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xStart,yStart,zEnd);
        glVertex3f(xStart,yEnd,zEnd);
        glVertex3f(xStart,yEnd,zStart);

        //top side
        //glColor3f(1,0,1);
        glVertex3f(xStart,yEnd,zStart);
        glVertex3f(xStart,yEnd,zEnd);
        glVertex3f(xEnd,yEnd,zEnd);
        glVertex3f(xEnd,yEnd,zStart);
        //bottom face
        //glColor3f(1,1,0);
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xStart,yStart,zEnd);
        glVertex3f(xEnd,yStart,zEnd);
        glVertex3f(xEnd,yStart,zStart);
           glEnd();
           */

}



