cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)

project( Camera_Calibration )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CONTROLLER_DIR src/Controller)
set(MODEL_DIR src/Model)
set(VIEW_DIR src/View)

add_executable(
    Camera_Calibration
    src/main.cpp
    ${CONTROLLER_DIR}/camera.cpp
    ${CONTROLLER_DIR}/image.cpp
    ${MODEL_DIR}/calibrator.cpp
    ${VIEW_DIR}/viewer.cpp
)

target_link_libraries(Camera_Calibration ${OpenCV_LIBS})
target_compile_features(Camera_Calibration PRIVATE cxx_std_17)
