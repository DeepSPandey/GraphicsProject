#include "makeCube.h"
makeCube::makeCube(){
     int xStart = -10,xEnd = 10,yStart = -10,yEnd = 10,zStart = 0,zEnd = 10;
    increaseX = 0,increaseY = 0,increaseZ = 0;
//    dynamics.size() = 1;
  //  dynamic.
}
makeCube::makeCube(int x0,int y0,int z0,int x1,int y1,int z1){
    xStart = x0 ; xEnd = x1;
    yStart = y0 ; yEnd = y1 ;
    zStart = z0 ; zEnd = z1 ;
    increaseX = 0,increaseY = 0,increaseZ = 0;
//    dynamics.push_back(new dynamic());
}
makeCube::~makeCube(){

}
void makeCube::drawCube(){
    xStart += increaseX; xEnd += increaseX;
    yStart += increaseY; yEnd += increaseY;
    zStart += increaseZ; zEnd += increaseZ;

        zStart = -zStart;
        zEnd = - zEnd;

        glLineWidth(2.0);
        glBegin(GL_LINES);
                   glColor3f(1,0,1);
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
        // dynamic d(0,0,0,10,10,10);
      //d.drawCube();


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

void makeCube::moveCube(int x,int y,int z){
    increaseX = x,increaseY = y,increaseZ = z;
    //if(x>5 && dynamics.size()<5)
}

void makeCube::addDynamicObject(int i){
     //while(dynamics.size()<i) dynamics.push_back(new makeCube(i + 2,0,0,10 + 10+i,10,10));
     //std::cout<<dynamics.size()<<std::endl;
   // for(int i =0; i<dynamics.size();i++){
       //  dynamics[i]->drawCube();
    //}

}
void makeCube::deleteDynamicObject(){
    if(zStart<-50){
        for(int i =0; i<dynamics.size();i++){
        delete dynamics[i];
    }
    }

}

