#include "camera.h"

int Camera::getConfig(){
    return 15;
}

float* Camera::getPos(){
    static float a[3];
    a[0] = a[1] = a[2] = 6;
    return a;
}

float* Camera::getAngle(){
    static float a[3];
    a[0] = a[1] = a[2] = 9;
    return a;
}