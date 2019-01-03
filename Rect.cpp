#include<iostream>
#include<math.h>
#include "Rect.h"
Rect::Rect(){
    for(int i = 0;i<4;i++)
     line[i] = Line(0,0,0,100,100,100);
     rColor = 0.5;gColor = 0.5;bColor = 0.5;
}
Rect::Rect(int x0,int y0,int z0,int x1,int y1,int z1){
    rColor = 0.5;gColor = 0.5;bColor = 0.5;
    if(z0 == z1){
        line[0] = Line(x0,y0,z0,x1,y0,z0);
        line[1] = Line(x1,y0,z0,x1,y1,z0);
        line[2] = Line(x1,y1,z0,x0,y1,z0);
        line[3] = Line(x0,y1,z0,x0,y0,z0);
    }else if( y0 == y1){
        line[0] = Line(x0,y0,z0,x1,y0,z0);
        line[1] = Line(x1,y0,z0,x1,y0,z1);
        line[2] = Line(x1,y0,z1,x0,y0,z1);
        line[3] = Line(x0,y0,z1,x0,y0,z0);
    }else{
        line[0] = Line(x0,y0,z0,x0,y0,z1);
        line[1] = Line(x0,y0,z1,x0,y1,z1);
        line[2] = Line(x0,y1,z1,x0,y1,z0);
        line[3] = Line(x0,y1,z0,x0,y0,z0);
    }

}
void Rect::drawRect(){
    float in[4];
    int a = 0;

    for(int i = 0;i<4;i++){
         line[i].drawLine();
         float sx=1500;
         float tempVer1 = (line[i].zEnd * line[i].zStart)*10000000;
         float tempVer2 = (sx-(line[i].xEnd + line[i].xStart)/2)*10;
         if(tempVer2<0) tempVer2 = -tempVer2;
        in[i]=0.6-0.5*1*(tempVer2)/sqrt(tempVer1+(tempVer2)*(tempVer2));

    }


        glBegin(GL_QUADS);
        glColor3f(in[0],a,a);
        glVertex3f(line[0].xStart,line[0].yStart,line[0].zStart);
        glColor3f(in[1],a,a);
        glVertex3f(line[1].xStart,line[1].yStart,line[1].zStart);
        glColor3f(in[2],a,a);
        glVertex3f(line[2].xStart,line[2].yStart,line[2].zStart);
        glColor3f(in[3],a,a);
        glVertex3f(line[3].xStart,line[3].yStart,line[3].zStart);
        glEnd();


}
void Rect::rotateRectAroundAxis(int axis,int angle){
    //axis = 0 -> x axis axis  = 1 ->y-axis asis = 2->z-axis
    for(int i = 0;i<4;i++){
        line[i].rotateAroundAxis(axis, angle);
    }
}
void Rect::translateMyRect(int x,int y,int z){

    for(int i = 0;i<4;i++){
        line[i].translateMyLine(x,y,z);
    }
}

void Rect::setRectColor(double r,double g, double b){
    rColor = r;gColor = g;bColor = b;
}
