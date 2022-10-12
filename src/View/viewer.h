/**
 * \file viewer.h
 * \brief Header of the viewer.cpp file
 * \author Bruno Tessier
 * \version 1.0
 *
 */

#ifndef _VIEWER_CAMERA_
#define _VIEWER_CAMERA_

#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;

/*! \class Viewer
   * \brief Class that manage the graphical part of the sofware
   *
   *  This class show the calibration picture and allow the user to select the four corners of the A4 calibration paper. 
   *  Once the corners are selected it will display the border of the paper.
   */
class Viewer{
    private:
        Mat image_calibration;
        Mat original_image_calibration;
        int cpt_click;
        std::vector<Point2f> checkBoard_corners;
        int test;
        //CornersSetHandler set_corners_event;
        //Calibrator *calibrator;

    public:
        Viewer();

        void display_camera();
        void set_image(Mat image_calibration);

        static void HandleClick(int event, int x, int y, int flags, void* ptr);

        void add_corner_point(int x, int y);
        std::vector<Point2f> get_corner_points();
        void reset_corners_points();

        void draw_point(Point center);
        void draw_lines();

};

#endif