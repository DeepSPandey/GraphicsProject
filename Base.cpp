#include "Base.h"
#include"math.h"
using namespace std;
Base::Base(int cubesInZ,int cubesInX){
        rColor = 1;gColor = 1;bColor = 1;
      int x0 = 0,y0 = -10,z0 = 0,xinc = 400,yinc = 0,zinc = 100;

    for(int k = 0;k<cubesInZ;k++){
        for(int i = 0;i<cubesInX;i++){
             x0 = 400*i;
             z0 = 100*k;
             Cube c1(x0,y0,z0,x0+xinc,y0+yinc,z0+zinc);
             baseCubes.push_back(new Cube(c1));
             }
             }
    }
void Base::drawBase(){

     for(int i =0;i<baseCubes.size();i++) {
//            baseCubes[i]->setCubesColor(rColor,gColor,bColor);
            baseCubes[i]->drawCube();
     }
}
void Base::setBaseColor(double r,double g, double b){
    rColor = r;gColor = g;bColor = b;
}
