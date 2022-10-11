#include "calibrator.h"

#define CV_C_KEY 99
#define CV_R_KEY 114
#define CV_ESC_KEY 27

Calibrator::Calibrator(const Viewer &viewer, const Camera &camera){
    this->viewer = viewer;
    this->camera = camera;
}


void Calibrator::launch_display(){
    //viewer.set_image(image);
    viewer.display_camera();
    while(1){
        int key = waitKey(50) & 0XFF;
        if(key == CV_ESC_KEY){
            printf("QUIT\n");
            break;
        }
        else if(key == CV_R_KEY){
            this->viewer.reset_corners_points();
        }
        else if(key == CV_C_KEY){
            printf("CALIBRATION\n");
            this->viewer.draw_lines();
        }
    }
}