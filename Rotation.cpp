#include "Rotation.h"

#define PI 3.14159265


float * Rotation::rotatePointAlongX(float pointsArray[4] ,int angle ){
    float RotationArray[4][4] =  { 1 ,                          0 ,                       0 , 0,
                                   0 ,    cos( angle * PI / 180 ) , sin( angle * PI / 180 ) , 0,
                                   0 ,   -sin( angle * PI / 180 ) , cos( angle * PI / 180 ) , 0,
                                   0 ,                          0 ,                       0 , 1
                                 };
    float a[4]  = {0,0,0,0};
    float * p;
    p = multiplyMatrices(pointsArray,RotationArray);
    for(int  i=0;i<4;i++)         a[i] = *(p+i);
    return a;
}
float * Rotation::rotatePointAlongY(float pointsArray[4] ,int angle ){
    float RotationArray[4][4] =  {  cos( angle * PI / 180 ) ,  0 , -sin( angle * PI / 180 ), 0,
                                                        0   ,  1 ,                      0  , 0,
                                    sin( angle * PI / 180 ) ,  0 , cos( angle * PI / 180 ) , 0,
                                                        0   ,  0 ,                     0   , 1
                                 };
    float a[4]  = {0,0,0,0};
    float * p;
    p = multiplyMatrices(pointsArray,RotationArray);
    for(int  i=0;i<4;i++)         a[i] = *(p+i);
    return a;
}
float * Rotation::rotatePointAlongZ(float pointsArray[4] ,int angle ){
    float RotationArray[4][4] =  {  cos( angle * PI / 180 ) ,  -sin( angle * PI / 180 ) , 0,0,
                                    sin( angle * PI / 180 ) ,   cos( angle * PI / 180 ) , 0,0,
                                                        0   ,                       0   , 1,0,
                                                        0   ,                       0   , 0,1
                                 };
    float a[4]  = {0,0,0,0};
    float * p;
    p = multiplyMatrices(pointsArray,RotationArray);
    for(int  i=0;i<4;i++)         a[i] = *(p+i);
    return a;
}
float * Rotation::translateMyPoints(float PointsArray[4],int translationArray[3]){

    //translationsArray is a 4*4 matrix different than translationArray

    float translationsArray[4][4] =  { 1,0,0, translationArray[0],
                                       0,1,0, translationArray[1],
                                       0,0,1, -translationArray[2],
                                       0,0,0,                   1
                                    };
    float a[4]  = {0,0,0,0};
    float * p;
    p = multiplyMatrices(PointsArray,translationsArray);
    for(int  i=0;i<4;i++)         a[i] = *(p+i);
    return a;


}

float * Rotation::ScaleMyPoints(float PointsArray[4],int scalingArray[3]){
    //scalingsArray is a 4*4 matrix different than scalingArray

    float scalingsArray[4][4] =  { scalingArray[0],               0,               0, 0,
                                                     0, scalingArray[1],               0, 0,
                                                     0,               0, scalingArray[2], 0,
                                                     0,               0,               0, 1
                                    };
    float a[4]  = {0,0,0,0};
    float * p;
    p = multiplyMatrices(PointsArray,scalingsArray);
    for(int  i=0;i<4;i++)         a[i] = *(p+i);
    return a;


}

float * Rotation::multiplyMatrices(float pointsArray[4] ,float RotationArray[4][4] ){
    float a[4]  = {0,0,0,0};
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 4;j++){
            a[i] += RotationArray[i][j] * pointsArray[j];
        }
    }
    return a;
}
