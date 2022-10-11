#include "viewer.h"

Viewer::Viewer(){
    this->cpt_click = 0;
    this->checkBoard_corners = {{0,0},{0,0},{0,0},{0,0}};
}

void Viewer::HandleClick(int event, int x, int y, int flags, void* ptr){

    Viewer *viewer = (Viewer*) ptr;

    if  ( event == EVENT_LBUTTONDOWN ){
        viewer->add_corner_point(x,y);
    }
}

void Viewer::display_camera(){
    namedWindow("Camera_calibration", WINDOW_NORMAL);
    resizeWindow("Camera_calibration", 1000, 750);
    setMouseCallback("Camera_calibration", HandleClick, this);
    imshow("Camera_calibration", this->image_calibration);
}

void Viewer::set_image(Mat image_calibration){
    this->image_calibration  = image_calibration;
    this->original_image_calibration = image_calibration.clone();
}

void Viewer::add_corner_point(int x, int y){
    if(this->cpt_click < 4){
        this->draw_point({x,y});
        this->checkBoard_corners[this->cpt_click] = {x,y};
        this->cpt_click++;
        printf("%d : \tX = %d\tY = %d\n", this->cpt_click, x, y);
    }
}

std::vector<Point2i> Viewer::get_corner_points(){
    for(Point2i n:this->checkBoard_corners){
        printf("Corner x:%d y:%d", n.x,n.y);
    }
    return this->checkBoard_corners;
}

void Viewer::reset_corners_points(){
    this->checkBoard_corners = {{0,0},{0,0},{0,0},{0,0}};
    this->cpt_click = 0;
    this->image_calibration = this->original_image_calibration.clone();
    imshow("Camera_calibration", this->original_image_calibration);
}

void Viewer::draw_point(Point center){
    circle(this->image_calibration, center, 5, {0,0,255}, -1);
    imshow("Camera_calibration", this->image_calibration);
}

void Viewer::draw_lines(){
    this->image_calibration = this->original_image_calibration.clone();
    for(int i=0 ; i<4 ; i++){
        line(this->image_calibration, this->checkBoard_corners[i],this->checkBoard_corners[(i+1)%4], {0,0,255}, 4);
    }
    imshow("Camera_calibration", this->image_calibration);
}