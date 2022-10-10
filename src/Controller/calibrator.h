#ifndef _CONTROLLER_CAMERA_
#define _CONTROLLER_CAMERA_

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "../View/viewer.h"
#include "../Model/camera.h"

using namespace cv;

class Calibrator{
    private:
        Viewer calibrator_viewer;
        Camera calibrator_camera;

    public:
        Calibrator(const Viewer &viewer, const Camera &camera);
        //Calibrator(Viewer viewer, Camera camera);
        
};

#endif