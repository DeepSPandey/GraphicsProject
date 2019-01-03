#include <GL/glut.h>
#include<iostream>
#include<vector>
#include"Cube.h"
#ifndef Wall_H
#define Wall_H

class Wall:public Cube{
    int lRange,uRange;
	public:
	    double rColor,gColor,bColor;
        std::vector<Cube*> dynamicCubes;
        std::vector<int> cubeData;
	    Wall(int,int);
	    void drawWall();
	    void rotateWallAroundAxis(int axis,int angle);
	    void translateMyWall(int x,int y,int z);
	    void setWallColor(double r,double g, double b);

};

#endif
//collision detection with wall is done in a preety complex manner.








