/**
 * \file calibrator.cpp
 * \brief Implemantation of the Calibrator class
 * \author Bruno Tessier
 * \version 1.0
 *
 */

#include "calibrator.h"

#define CV_C_KEY 99
#define CV_R_KEY 114
#define CV_ESC_KEY 27

/*!
     *  \brief Constructor
     *
     *  Constructor of the Calibrator class
     *
     */
Calibrator::Calibrator(const Viewer &viewer, const Camera &camera){
    this->viewer = viewer;
    this->camera = camera;
}

/*!
     *  \brief Start the display part of the programm
     *
     *  This function ask the viewer to start the display of the calibration image
     *  It wait for a keyboard event to either process the position of the camera, reset the chosen points of the calibation paper or stop the programm
     *
     */
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
            this->calibration();
        }
    }
}
/*!
     *  \brief Compute the position of the camera
     *
     *  Ask to the Viewer the position of the chosen calibration points and to the Camera the intrisic parameter end the distorsion of the camera
     *  Then it compute the position of the camera in the real world
     *
     */
void Calibrator::calibration(){
    Mat intrisic_parameter = this->camera.get_intrisic_parameter();
    Mat distorsion_parameter = this->camera.get_distorsion_parameter();
    std::vector<cv::Point3f> objectPoints = this->camera.get_world_point();
    std::vector<cv::Point2f> imagePoints = this->viewer.get_corner_points();
    Mat rotation_vector, translation_vector, rotation_matrix, rotation_matrix_T ;
    Mat camera_position;

    solvePnP(objectPoints,imagePoints,intrisic_parameter,distorsion_parameter,rotation_vector,translation_vector);
    Rodrigues(rotation_vector, rotation_matrix);
    transpose(rotation_matrix, rotation_matrix_T);

    camera_position = -rotation_matrix_T * translation_vector;
    
    std::cout << camera_position << std::endl;
}