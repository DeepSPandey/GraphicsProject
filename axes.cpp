#include "axes.h"
axes::axes(){
     xStart = 0,xEnd = 100,yStart = 0,yEnd = 100,zStart = 0,zEnd = 100;
       zStart = -zStart;
        zEnd = - zEnd;

}
void axes::drawAxes(){


        glLineWidth(2.0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);
        // z plot
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xStart,yStart,zEnd);

        // x plot
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xEnd,yStart,zStart);

        //y plot
        glVertex3f(xStart,yStart,zStart);
        glVertex3f(xStart,yEnd,zStart);

        glEnd();
}



