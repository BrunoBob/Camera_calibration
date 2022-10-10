#include "camera.h"

Camera::Camera(){
    
}

void Camera::set_config(int conf){
    this->config = conf;
}

int Camera::get_config(){
    return this->config;
}

float* Camera::get_pos(){
    static float a[3];
    a[0] = a[1] = a[2] = 6;
    return a;
}

float* Camera::get_angle(){
    static float a[3];
    a[0] = a[1] = a[2] = 9;
    return a;
}