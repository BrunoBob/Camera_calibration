/**
 * \file main.cpp
 * \brief File containing the main fonction
 * \author Bruno Tessier
 * \version 1.0
 *
 * Programm to detect the position of a camera from the camera parameter and a calibration picture
 *
 */

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "Model/camera.h"
#include "View/viewer.h"
#include "Controller/calibrator.h"

using namespace cv;

/*!
     *  \brief main function
     *
     *  Main function launched by the execution of the programm
     *
     */
int main(int argc, char** argv){
    
    // Check if image to display is passed as argument
    if (argc != 2) {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    // Try to read image
    Mat image;
    image = imread(argv[1], 1);
    if (!image.data) {
        printf("This image does not exist \n");
        return -1;
    }

    Camera camera;
    Viewer viewer;

    viewer.set_image(image);
    
    Calibrator calibrator(viewer, camera);

    calibrator.launch_display();

    return 0;
}
