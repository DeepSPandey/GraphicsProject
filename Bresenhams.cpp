using namespace std;
#include "Bresenhams.h"
Bresenhams::Bresenhams(int c, int d){
    x0 = 0,y0= 0,x1 = c,y1 = d;
    angle = 0;
    translateMatrix[0] = 0;
    translateMatrix[1] = 1;
}
Bresenhams::Bresenhams(int a,int b, int c, int d){
    x0 = a,y0= b,x1 = c,y1 = d;
    angle = 0;
    translateMatrix[0] = 0;
    translateMatrix[1] = 1;
}
void Bresenhams::translateLine(int a,int b){
    translateMatrix[0] = a;
    translateMatrix[1] = b;
}

void Bresenhams::rotateAngle(int a){
    angle  = a;
}

void Bresenhams::plotPixel(int x,int y){

      //  cout<<"point: "<<x<<" , "<<y<<endl;
        glPointSize(3.0);
        glColor3f(0,1,1);
        glBegin(GL_POINTS);
        //uncomment this to see only a line
        //glVertex3f(x,y,-1000);

        float pointsArray[3] = { x, y, 1 };
        float * m;
        m = rotateMyPoints(pointsArray,angle);
        for(int  i=0;i<3;i++)
        pointsArray[i] = *(m+i);
        m = translateMyPoints(pointsArray,translateMatrix);
        for(int  i=0;i<3;i++)
        pointsArray[i] = *(m+i);
        glVertex3f(pointsArray[0],pointsArray[1],-1000);

        glEnd();
        glFlush(); //executes all OpenGL functions as quickly as possible

       }
void Bresenhams::makeLine(){
    int dx,dy;
    int x,y;
    int dParameter;

    dx =  x1 - x0;
    dy = y1 - y0;
    if(dx > dy ) dParameter = 2 * dy - dx;
    else dParameter = 2 * dx - dy;

//cout<<"(x0,y0) = "<<"("<<x0<<","<<y0<<")"<<"\t and "
  //  <<"(x1,y1) = "<<"("<<x1<<","<<y1<<")"<<endl;
    x = x0, y = y0;
   //  cout<<"points: "<<x<<" , "<<y<<endl;
    plotPixel(x,y);

    while(x<x1 || y<y1){
            if(dx>dy){
                x += 1;
                if(dParameter > 0){
                        y += 1;
                        dParameter -= 2 * dx;
                }
                dParameter += 2 * dy;
            }else{
                 y += 1;
                if(dParameter > 0){
                        x += 1;
                        dParameter -= 2 * dy;
                }
                dParameter += 2 * dx;
            }

         //        cout<<"points: "<<x<<" , "<<y<<endl;
                plotPixel(x,y);
    }

}

