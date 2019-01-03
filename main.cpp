#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include"makeCube.h"
#include"dynamic.h"
#include"Wall.h"
#include"axes.h"
#include"Line.h"
#include"Rect.h"
#include"Cube.h"
#include"Wall.h"
#include"Base.h"
#include<math.h>

#include"Robot.h"

#include "Bresenhams.h"
#include "DDA2.h"
#include "Circle.h"
#include "Ellipse.h"
#define PI 3.14159265

using namespace std;
const float BOX_SIZE = 7.0f; //The length of each side of the cube
float _angle = 0;            //The rotation of the box


void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
}
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 20000.0);
}
bool leftCollisionX(Cube m1,Cube m2){
    //m1 is the cube to the right
         if(m1.xStart<= m2.xEnd){
        cout<<"xLeftSideCollision"<<endl;
        return true;
        }
    return false;
}
bool rightCollisionX(Cube m1,Cube m2){
    //m1 is the cube to the left
         if(m1.xEnd >= m2.xStart){
        cout<<"xRightSideCollision"<<endl;
        return true;
        }
    return false;
}
bool collisionZ(Cube m1,Cube m2){
    //m1 is the cube to the front , movingCube

         if(m1.zEnd >= m2.zStart && (leftCollisionX(m1,m2))){
        cout<<"zFrontSideCollision"<<endl;
        return true;
        }
    return false;

}

int zoomX = 0,zoomY = 0,zoomZ = 0;
int lookX = 0,lookY = 0,lookZ = 0;
bool movement = false;
bool xLeftCollisionOccured = false,xRightCollisionOccured = false,zFrontCollisionOccured = false;
Wall wall(300,1);
Base base(300,5);
Cube man(100,0,100,150,50,200);
void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	     //   axes abc;
     //   abc.drawAxes();
if(lookZ == 0){
glTranslatef(-300,300,0);
	DDA2 line ;//= new DDA();
	line.rotateAngle(-_angle);
	line.makeLine(0,0,0,50);

	Bresenhams bLine (0,0,0,95);
	bLine.rotateAngle(-_angle*2);
	//bLine.translateLine(100,100);
	bLine.makeLine();

  //  glRotatef(angle,0,0,1);
	Ellipse ellipse (0,0,20,100);

	//ellipse.rotateEllipse(angle);
	ellipse.makeEllipse();
		Ellipse ellipse2 (0,0,100,20);
	//ellipse.rotateEllipse(angle);
	ellipse2.makeEllipse();
	Circle circle;
	circle.makeCircle(0,0,100);
    glTranslatef(300,-300,0);
}

    glTranslatef( zoomX , zoomY ,  zoomZ);

	 //
	if(lookZ == 1) {
	     int angle = 0;
	     if(movement)angle = (int) _angle;
	   angle = angle;
	   angle = angle%3;
	   angle -= 3;
	    Robot robot;
	    glTranslatef(0,0,-60 - zoomZ);
	    robot.Prepare(angle%3);
        robot.DrawRobot(0,0,0);
        glTranslatef(20,0,60 + zoomZ);
	 }
	 glTranslatef(-500,-250,-1000);

      if(lookZ == 1)  gluLookAt( 0, 0 ,0,0,0,-500,0,1,0);
      else gluLookAt( -100, 1500 ,-1500,100,1000,-1500,1,0,0);
       //gluLookAt(0,0,0,100,100,100+zoomZ,0,1,0);

        wall.setWallColor(0.5,0,0);
        wall.drawWall();
        glTranslatef(-200,0,500);

        base.setBaseColor(1,1,1);
        base.drawBase();

        glutSwapBuffers();
}


int keypressed = 0;
    using namespace std;
    bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)
    void keyOperations (void) {

         if (keyStates['q']) {
          if(!zFrontCollisionOccured)  zoomZ += 10;
        }

   //  zoomX += 0; zoomY += 0; zoomZ += 0;
      if (keyStates['w']) {
             zoomX += 0; zoomY += 10; zoomZ += 0;
            //
    }
     if (keyStates['e']) {
            zoomZ -= 10;
    }
     if (keyStates['a']) {
           if(!xLeftCollisionOccured)  zoomX -= 20; zoomY += 0; zoomZ += 0;
    }
    else if (keyStates['s']) {
            zoomX += 0; zoomY -= 10; zoomZ += 0;
    }
    if (keyStates['d']) {
            if(!xRightCollisionOccured) zoomX += 20; zoomY += 0; zoomZ += 0;
    }
     if (keyStates['r']) {
             zoomX = 0; zoomY = 0; zoomZ = 0;
    }
       if (keyStates['t']) {
            if(lookZ == 1)lookZ = 0;
            else lookZ = 1;
    } if (keyStates['f']) {
           if(movement) movement = false;
           else movement = true;
    }




//    else;

    }

    void keyPressed (unsigned char key, int x, int y) {
    keyStates[key] = true; // Set the state of the current key to pressed
    keyOperations();
   // glutDisplayFunc(drawScene);
    }

    void keyUp (unsigned char key, int x, int y) {
    keyStates[key] = false; // Set the state of the current key to not pressed
    }

//Called every 25 milliseconds
void update(int value) {
	_angle += 1.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	if(movement){
        if(lookZ == 1)zoomZ += 10;
        else zoomX += 10;
	}

	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);

	glutCreateWindow("GAME");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	 glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
    glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events

	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}
