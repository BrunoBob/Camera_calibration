/**
 * \file camera.cpp
 * \brief Implemantation of the Camera class
 * \author Bruno Tessier
 * \version 1.0
 *
 */

#include "camera.h"

/*!
     *  \brief Constructor
     *
     *  Constructor of the Camera class
     *
     */
Camera::Camera(){
    
}

/*!
     * \brief Return a matrix of the intrisic parameter of the camera
     *
     * \return The instrisic parameter of the camera
     *
     */
Mat Camera::get_intrisic_parameter(){
    Mat intrisic_parameter = (Mat_<float>(3,3) << fx, 0.0, cx, 0.0, fy, cy, 0.0, 0.0, 1.0);
    return intrisic_parameter;
}

/*!
     * \brief Return a matrix of the distorsion parameter of the camera
     *
     * \return The distorsion parameter of the camera
     *
     */
Mat Camera::get_distorsion_parameter(){
    Mat distorsion_parameter = (Mat_<float>(1,8) << k1, k2, p1, p2, k3, k4, k5, k6);
    return distorsion_parameter;
}

/*!
     * \brief Return a list of world coordinate points of the A4 calibration paper in the calibration image
     *
     * \return A vector of 3D world coordinates
     *
     */
std::vector<Point3f> Camera::get_world_point(){
    std::vector<Point3f> world_points = {{0,0,0},{dx,0,0},{dx,dy,0},{0,dy,0}};
    return world_points;
}