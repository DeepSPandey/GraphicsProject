#include <GL/glut.h>
#include<iostream>
#include<vector>
#include"Cube.h"
#ifndef Base_H
#define Base_H

class Base:public Cube{
	public:
	    double rColor,gColor,bColor;
        std::vector<Cube*> baseCubes;
	    Base(int,int);
	    void drawBase();
	    void setBaseColor(double,double,double);
};

#endif
//collision detection with Base is done in a preety complex manner
