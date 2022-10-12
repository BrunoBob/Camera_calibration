#include <opencv2/opencv.hpp>
#include "Model/camera.h"
#include "View/viewer.h"
#include "Controller/calibrator.h"

#include <gtest/gtest.h>


TEST(Camera_test, check_output_format) {
  Camera camera;

  // Test if Camera::get_intrisic_parameter() return the right format of cv::Mat
  EXPECT_EQ(camera.get_intrisic_parameter().rows, 3);
  EXPECT_EQ(camera.get_intrisic_parameter().cols, 3);

  // Test if Camera::get_distorsion_parameter() return the right format of cv::Mat
  EXPECT_EQ(camera.get_distorsion_parameter().rows, 1);
  EXPECT_EQ(camera.get_distorsion_parameter().cols, 8);

  // Test if Camera::get_world_point() return the right format of vector
  EXPECT_EQ(camera.get_world_point().size(), 4);
}

TEST(Viewer_test, check_output_format) {
  Viewer viewer;

  // Test if Viewer::get_corner_points() return the right format of vector
  EXPECT_EQ(viewer.get_corner_points().size(), 4);
}