#include "viewer.h"

Viewer::Viewer(){
    this->cpt_click = 1;
}

void Viewer::HandleClick(int event, int x, int y, int flags, void* userdata){
    //int* cpt_click = static_cast<int*>(userdata);
    data_holder_type *dholder = static_cast<data_holder_type *>(userdata);
    
    //int* cpt_click = (int*)userdata;
    if  ( event == EVENT_LBUTTONDOWN ){
        printf("%d\n", dholder->second);
        if(dholder->second < 4){
            dholder->second = dholder->second + 1 ;
        }
        else{
            dholder->second = 1;
        }
    }
}

void Viewer::display_camera(){
    namedWindow("Camera_calibration", WINDOW_NORMAL);
    setMouseCallback("Camera_calibration", HandleClick, &cpt_click);
    imshow("Camera_calibration", this->image_calibration);
    waitKey(0);
}

void Viewer::set_image(Mat image_calibration){
    this->image_calibration = image_calibration;
}

