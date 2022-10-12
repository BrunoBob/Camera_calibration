/**
 * \file calibrator.h
 * \brief Header of the calibrator.cpp file
 * \author Bruno Tessier
 * \version 1.0
 *
 */

#ifndef _CONTROLLER_CAMERA_
#define _CONTROLLER_CAMERA_

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "../View/viewer.h"
#include "../Model/camera.h"

using namespace cv;

/*! \class Calibrator
   * \brief Class that exchange with the Viewer and the Model (Camera) to compute the position of the camera
   *
   *  This class exchange with a Viewer and a Camera object to take data necessary to compute the position of the camera
   */
class Calibrator{
    private:
        Viewer viewer;
        Camera camera;

    public:
        Calibrator(const Viewer &viewer, const Camera &camera);
        
        void launch_display();
        void calibration();
        void compute_orientation(Mat rotation_matrix, Vec3d &orientation);
        
};

#endif