#ifndef _VIEWER_CAMERA_
#define _VIEWER_CAMERA_

#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;

class Viewer{
    private:
        Mat image_calibration;
        Mat original_image_calibration;
        int cpt_click;
        std::vector<Point2i> checkBoard_corners;
        int test;
        //CornersSetHandler set_corners_event;
        //Calibrator *calibrator;

    public:
        Viewer();

        void display_camera();
        void set_image(Mat image_calibration);

        static void HandleClick(int event, int x, int y, int flags, void* ptr);

        void add_corner_point(int x, int y);
        std::vector<Point2i> get_corner_points();
        void get_corner_points(const int &test);
        void reset_corners_points();

        void draw_point(Point center);
        void draw_lines();

};

#endif