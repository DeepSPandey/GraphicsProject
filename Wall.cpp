#include "Wall.h"
#include"math.h"
using namespace std;
Wall::Wall(int cubesInZ,int cubesInY){
      int x0 = 0,y0 = 0,z0 = 0,xinc = 20,yinc = 500,zinc = 100;
    int m  = -1;
    int noOfZCubes = 20,noOfXCubes = 10;
    //cubeData.push_back(0);
    //cubeData.push_back(0);
    for(int k = 0;k<cubesInZ;k++){
        for(int j = 0;j<cubesInY;j++){
             y0 = 100*j;
             if(k%30 == 0){
                 noOfZCubes = rand()%10 + 15;
                 noOfXCubes = 30 - noOfZCubes;
                 cubeData.push_back(noOfXCubes);
                 cubeData.push_back(noOfZCubes);

             }
             if(k%30<noOfXCubes){
                z0 += 0;
                if(noOfZCubes%2 == 0)  x0 += xinc;
                else x0 -= xinc;
             }else{
                 z0 += zinc;
                x0 += 0;
             }
             Cube c1(x0,y0,z0,x0+xinc,y0+yinc,z0+zinc);
             dynamicCubes.push_back(new Cube(c1));
}
}
    }
void Wall::drawWall(){

     for(int i =0;i<dynamicCubes.size();i++) {
            dynamicCubes[i]->setCubeColor(rColor,gColor,bColor);
            dynamicCubes[i]->drawCube();
            //for right side collision repeat the same as left side, only few
            //parameters need to be changed.
                dynamicCubes[i]->translateMyCube(600,0,0);
                dynamicCubes[i]->drawCube();
                dynamicCubes[i]->translateMyCube(-600,0,0);
     }


}
void Wall::rotateWallAroundAxis(int axis,int angle){

    for(int i = 0;i<6;i++){
        rect[i].rotateRectAroundAxis(axis, angle);
    }
}
void Wall::translateMyWall(int x,int y,int z){

    for(int i = 0;i<6;i++){
        rect[i].translateMyRect(x,y,z);
    }
}

void Wall::setWallColor(double r,double g, double b){
    rColor = r;gColor = g;bColor = b;
}
