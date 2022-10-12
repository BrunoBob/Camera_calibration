cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)

project( Camera_Calibration )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

enable_testing()
find_package(GTest REQUIRED)
include_directories(test_simple_tree ${GTEST_INCLUDE_DIR})

set(CONTROLLER_DIR src/Controller)
set(MODEL_DIR src/Model)
set(VIEW_DIR src/View)

add_executable(
    Camera_Calibration
    src/main.cpp
    ${MODEL_DIR}/camera.cpp
    ${CONTROLLER_DIR}/calibrator.cpp
    ${VIEW_DIR}/viewer.cpp
)

target_link_libraries(Camera_Calibration ${OpenCV_LIBS})
target_compile_features(Camera_Calibration PRIVATE cxx_std_17)


#Testing
add_executable(
    code_test
    src/code_test.cpp
    ${MODEL_DIR}/camera.cpp
    ${CONTROLLER_DIR}/calibrator.cpp
    ${VIEW_DIR}/viewer.cpp
)
target_link_libraries(
    code_test
    PUBLIC
    ${OpenCV_LIBS}
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES}
    -lpthread
    -lm
)
gtest_discover_tests(code_test)