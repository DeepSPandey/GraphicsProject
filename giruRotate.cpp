
#include "giruRotate.h"

#define PI 3.14159265


float * giruRotate::rotateMyPoints(float pointsArray[3] ,int angle ){
    float rotateArray[3][3] =  {  cos( angle * PI / 180 ) ,  -sin( angle * PI / 180 ) , 0,
                                    sin( angle * PI / 180 ) ,   cos( angle * PI / 180 ) , 0,
                                                        0   ,                       0   , 1,
                                 };
    float a[3]  = {0,0,0};
    float * p;
    p = multiplyMatrices(pointsArray,rotateArray);
    for(int  i=0;i<3;i++)         a[i] = *(p+i);
    return a;
}
float * giruRotate::translateMyPoints(float PointsArray[3],int translationArray[2]){

    float translationsArray[3][3] =  { 1,0, translationArray[0],
                                       0,1, translationArray[1],
                                       0,0, 1,
                                    };
    float a[3]  = {0,0,0};
    float * p;
    p = multiplyMatrices(PointsArray,translationsArray);
    for(int  i=0;i<3;i++)         a[i] = *(p+i);
    return a;


}

float * giruRotate::multiplyMatrices(float pointsArray[3] ,float rotateArray[3][3] ){
    float a[3]  = {0,0,0};
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            a[i] += rotateArray[i][j] * pointsArray[j];
        }
    }
    return a;
}


