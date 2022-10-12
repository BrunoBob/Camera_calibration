/**
 * \file camera.h
 * \brief Header of the camera.cpp file
 * \author Bruno Tessier
 * \version 1.0
 *
 */

#ifndef _MODEL_CAMERA_
#define _MODEL_CAMERA_

#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

//Intrisic camera parameter
constexpr auto fx{3751.937744f};
constexpr auto fy{3821.977539f};
constexpr auto cx{1280.0f};
constexpr auto cy{960.0f};

//Camera distorsion parameter
constexpr auto k1{-1.20933f};
constexpr auto k2{-1.041786f};
constexpr auto k3{64.013991f};
constexpr auto k4{-0.556802f};
constexpr auto k5{-3.66386f};
constexpr auto k6{-78.030670f};
constexpr auto p1{-0.004819f};
constexpr auto p2{-0.002720f};

//A4 paper dimension
constexpr auto dx{290.7f};
constexpr auto dy{210.0f};

/*! \class Camera
   * \brief Class that manage the data of the software
   *
   *  This class can give stored data to the controller (Calibrator)
   */
class Camera {

    private:

    public:
        Camera();

        Mat get_intrisic_parameter();
        Mat get_distorsion_parameter();
        std::vector<Point3f> get_world_point();
};

#endif