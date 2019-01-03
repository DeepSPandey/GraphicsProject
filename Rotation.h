#include<iostream>
#include<math.h>
#ifndef ROTATION_H
#define ROTATION_H

class Rotation
{

public:
    float * rotatePointAlongX(float pointsArray[4] ,int angle );
    float * rotatePointAlongY(float pointsArray[4] ,int angle );
    float * rotatePointAlongZ(float pointsArray[4] ,int angle );

    float * translateMyPoints(float PointsArray[4],int translationArray[3]);
    float * ScaleMyPoints(float PointsArray[4],int scalingArray[3]);

    float * multiplyMatrices(float pointsArray[4] ,float rotationArray[4][4] );




};

#endif // BULLET_H




