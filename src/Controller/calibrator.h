#ifndef _CONTROLLER_CAMERA_
#define _CONTROLLER_CAMERA_

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "../View/viewer.h"
#include "../Model/camera.h"

using namespace cv;

class Calibrator{
    private:
        Viewer viewer;
        Camera camera;

    public:
        Calibrator(const Viewer &viewer, const Camera &camera);
        
        void launch_display();
        void launch_calibration();
        int check_corners();
        std::vector<Point2i> setup_corners(std::vector<Point2i> corners);
        void calibration();
        
};

#endif