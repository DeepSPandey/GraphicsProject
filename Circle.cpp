
using namespace std;
#include "Circle.h"

void Circle::plotPixel(int x,int y,int x0,int y0){

        //cout<<"point: "<<x<<" , "<<y<<endl;
        glPointSize(4.0);

        glBegin(GL_POINTS);
        glColor3f(1,0,1);
        glVertex3f( x0 + x, y0 + y,-1000);

        glVertex3f( x0 + x, y0 - y,-1000);
        glVertex3f( x0 - x, y0 + y,-1000);
        glVertex3f( x0 - x, y0 - y,-1000);

        glVertex3f( x0 + y,y0 + x,-1000);
        glVertex3f( x0 + y,y0 - x,-1000);
        glVertex3f( x0 - y,y0 + x,-1000);
        glVertex3f( x0 - y,y0 - x,-1000);

        glEnd();
        glFlush(); //executes all OpenGL functions as quickly as possible

       }
void Circle::plotPixel(int x,int y){

        //cout<<"point: "<<x<<" , "<<y<<endl;
        glPointSize(4.0);

        glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex3f( x, y,-1000);
        glColor3f(1,0,1);
        glVertex3f( x,-y,-1000);
        glVertex3f(-x, y,-1000);
        glVertex3f(-x,-y,-1000);

        glVertex3f( y, x,-1000);
        glVertex3f( y,-x,-1000);
        glVertex3f(-y, x,-1000);
        glVertex3f(-y,-x,-1000);

        glEnd();
        glFlush(); //executes all OpenGL functions as quickly as possible

       }
void Circle::makeCircle(int x0,int y0, int r){
    int x,y;
    int dParameter;

    x = 0, y = r;
    dParameter = 5/4 - r;
    plotPixel(x,y,x0,y0);
    while(x < y){
            dParameter += 2 * x + 3;
            x += 1;
        if(dParameter >= 0){
            dParameter -=  2* y;
            y -= 1;
        }
       // plotPixel(x,y);
        plotPixel(x,y,x0,y0);
    }
}
