#ifndef _VIEWER_CAMERA_
#define _VIEWER_CAMERA_

#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;

typedef std::pair<std::vector<Point2d>, int> data_holder_type;

class Viewer{
    private:
        Mat image_calibration;
        int cpt_click;

    public:
        Viewer();

        void display_camera();
        void set_image(Mat image_calibration);

        static void HandleClick(int event, int x, int y, int flags, void* userdata);
        void test();

};

#endif