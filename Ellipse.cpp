
using namespace std;
#include "Ellipse.h"

 Ellipse::Ellipse(int a,int b, int rX,int rY){
     x0 = a; y0 = b; rx = rX; ry = rY;
}
void Ellipse::rotateEllipse(int angle){
    float pDEllipse[3] = { rx,ry,1};
    float * m;
    int a[3] = {0,0,0};
    m = rotateMyPoints(pDEllipse,angle);
    for(int i = 0;i<3;i++)
         a[i]= *(m + i);
         rx = a[0];
         ry = a[1];
       //  makeEllipse(0,0,rX,rY);

}

void Ellipse::plotPixel(int x,int y){

        //cout<<"point: "<<x<<" , "<<y<<endl;
        glPointSize(2.0);

        glBegin(GL_POINTS);
        glColor3f(1,1,0);
        glVertex3f( x, y,-1000);
        glColor3f(1,1,1);
       glVertex3f( x,-y,-1000);
        glVertex3f(-x, y,-1000);
        glVertex3f(-x,-y,-1000);

        glEnd();
        glFlush(); //executes all OpenGL functions as quickly as possible

       }
void Ellipse::makeEllipse(){

        float x,y;
        float dParameter0,dParameter1;

        x = 0, y = ry;

        dParameter0 = ry*ry  -  rx*rx*ry  +  rx*rx/4;
        plotPixel(x,y);
        while(ry*ry*x < rx*rx*y){
            if(dParameter0 <0 ){
                x += 1;
                dParameter0 += 2*ry*ry*x  +  ry*ry;

            }else{
                x += 1;
                y -= 1;
                dParameter0 += 2*ry*ry*x  +  ry*ry  -  2*rx*rx*y  ;
            }

            plotPixel(x,y);
        }
         dParameter1  = ry*ry*(x+1/2)*(x+1/2) +rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
        while(ry*ry*x >= rx*rx*y && y>0){
            if(dParameter1 >= 0 ){
                y -= 1;
                dParameter1 += -2*rx*rx*y  +2*rx*rx;
            }
           if(dParameter1 <0 ){
                x += 1;
                y -= 1;
                dParameter1 += -2*rx*rx*y  +2*rx*rx + 2*ry*ry*x;

            }
            plotPixel(x,y);
        }

}

