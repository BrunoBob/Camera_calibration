#include "calibrator.h"

Calibrator::Calibrator(const Viewer &viewer, const Camera &camera){
    this->calibrator_viewer = viewer;
    this->calibrator_camera = camera;
}