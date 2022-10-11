#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "Model/camera.h"
#include "View/viewer.h"
#include "Controller/calibrator.h"

using namespace cv;
int main(int argc, char** argv)
{
    
    // Check if image to display is passed as argument
    if (argc != 2) {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread(argv[1], 1);
    if (!image.data) {
        printf("No image data \n");
        return -1;
    }

    Camera camera;
    Viewer viewer;

    viewer.set_image(image);
    
    Calibrator calibrator(viewer, camera);

    calibrator.launch_display();
    //viewer.set_image(image);
    //viewer.display_camera();

    return 0;
}
