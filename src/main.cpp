#include <opencv2/opencv.hpp>
#include <stdio.h>
#include "Controller/camera.h"

using namespace cv;
int main(int argc, char** argv)
{
    Camera cametest;
    printf("Config = %d\n", cametest.getConfig());
    printf("Config = %f\n", cametest.getPos()[0]);
    printf("Config = %f\n", cametest.getAngle()[1]);
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
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}
