//#include <opencv2/opencv.hpp>
//#include <stdio.h>
//#include "Controller/camera.h"

#include <gtest/gtest.h>

//using namespace cv;

TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

/*int main(int argc, char** argv)
{
    Camera cametest;
    

    
    return 0;
}*/
