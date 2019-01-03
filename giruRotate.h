#include<iostream>
#include<math.h>
#ifndef GIRUROTATE_H
#define GIRUROTATE_H

class giruRotate
{

public:
    float * rotateMyPoints(float pointsArray[3] ,int angle );
    float * translateMyPoints(float PointsArray[3],int translationArray[3]);

    float * multiplyMatrices(float pointsArray[3] ,float rotateArray[3][3] );




};

#endif // BULLET_H




