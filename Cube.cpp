#include "Cube.h"
Cube::Cube(){
     for(int i  = 0;i<6;i++) rect[i] = Rect();
     xStart = 0; yStart = 0; zStart = 0;
     xEnd = 0; yEnd = 0; zEnd = 0;
     rColor = 0.5,gColor = 0.5,bColor = 0.5;
}
Cube::Cube(int x0,int y0,int z0,int x1,int y1,int z1){
  rect[0] = Rect(x0,y0,z0,x1,y1,z0); //front
  rect[1] = Rect(x0,y0,z1,x1,y1,z1); //back
  rect[2] = Rect(x0,y0,z0,x0,y1,z1); //base
  rect[3] = Rect(x1,y0,z0,x1,y1,z1); //top
  rect[4] = Rect(x0,y0,z0,x1,y0,z1); //left
  rect[5] = Rect(x0,y1,z0,x1,y1,z1); //right
    xStart = x0; yStart = y0; zStart = z0;
    xEnd = x1; yEnd = y1; zEnd = z1;
     rColor = 0.5,gColor = 0.5,bColor = 0.5;
   // std::cout<<"xStart = "<<xStart<<" xEnd = "<<xEnd<<" yStart= "<<yStart<<" yEnd = "<<yEnd<<" zStart = "<<zStart
     //       <<" zEnd = "<<zEnd<<std::endl;
}
void Cube::drawCube(){
    for(int i =0;i<6;i++){
        rect[i].setRectColor(rColor,gColor,bColor);
        rect[i].drawRect();
    }

}
void Cube::rotateCubeAroundAxis(int axis,int angle){
    for(int i = 0;i<6;i++){
        rect[i].rotateRectAroundAxis(axis, angle);
    }
}
void Cube::translateMyCube(int x,int y,int z){

    for(int i = 0;i<6;i++){
        rect[i].translateMyRect(x,y,z);
    }
    xStart += x; yStart += y; zStart += z;
        xEnd += x; yEnd += y; zEnd += z;
}
void Cube::setCubeColor(double r,double g, double b){
    rColor = r;gColor = g;bColor = b;
}
