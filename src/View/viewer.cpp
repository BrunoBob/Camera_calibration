/**
 * \file viewer.cpp
 * \brief Implemantation of the Viewer class
 * \author Bruno Tessier
 * \version 1.0
 *
 */

#include "viewer.h"

/*!
     *  \brief Constructor
     *
     *  Constructor of the Viewer class
     *
     */
Viewer::Viewer(){
    this->cpt_click = 0;
    this->checkBoard_corners = {{0,0},{0,0},{0,0},{0,0}};
}

/*!
     *  \brief Handle function for a click event
     *
     *  This function is called for each mouse event in the opencv window
     *  If the event is a left click it will select the position of the mouse as one of the corner of the calibration paper.
     * 
     *  \param event : id of the mouse event
     *  \param x : X position of the mouse int the window
     *  \param y : Y position of the mouse int the window
     *
     */
void Viewer::HandleClick(int event, int x, int y, int flags, void* ptr){

    Viewer *viewer = (Viewer*) ptr;

    if  ( event == EVENT_LBUTTONDOWN ){
        viewer->add_corner_point(x,y);
    }
}

/*!
     *  \brief start the display of the image
     *
     *  Create an opencv window that display the calibration image
     *
     */
void Viewer::display_camera(){
    namedWindow("Camera_calibration", WINDOW_NORMAL);
    resizeWindow("Camera_calibration", 1000, 750);
    setMouseCallback("Camera_calibration", HandleClick, this);
    imshow("Camera_calibration", this->image_calibration);
}

/*!
     *  \brief Set the calibration image
     *
     *  Set the calibration image that will be displayed in the window
     *
     *  \param image_calibration : Image chosen for the calibration
     */
void Viewer::set_image(Mat image_calibration){
    this->image_calibration  = image_calibration;
    this->original_image_calibration = image_calibration.clone();
}

/*!
     *  \brief Add a corner position
     *
     *  Add the position of a chosen corner of the calibration paper to the list of saved corners
     *
     *  \param x : x position of the corner
     *  \param y : y position of the corner
     */
void Viewer::add_corner_point(int x, int y){
    if(this->cpt_click < 4){
        this->draw_point({x,y});
        this->checkBoard_corners[this->cpt_click] = {(float)x,(float)y};
        this->cpt_click++;
        printf("%d : \tX = %d\tY = %d\n", this->cpt_click, x, y);
    }
}

/*!
     *  \brief Return the list of saved corners
     *
     *  \return The list of saved corners of the calibration paper
     */
std::vector<Point2f> Viewer::get_corner_points(){
    return this->checkBoard_corners;
}

/*!
     *  \brief Reset the chosen corners of the calibration paper
     *
     *  Reset the list of saved corners of the calibration paper and refresh the window with a clean image
     *
     */
void Viewer::reset_corners_points(){
    this->checkBoard_corners = {{0,0},{0,0},{0,0},{0,0}};
    this->cpt_click = 0;
    //Reset displayed image with original image 
    this->image_calibration = this->original_image_calibration.clone();
    imshow("Camera_calibration", this->original_image_calibration);
}

/*!
     *  \brief Draw a point
     *
     * Draw a point where the user has clicked 
     * 
     * \param center : Center of the chosen point
     *
     */
void Viewer::draw_point(Point center){
    circle(this->image_calibration, center, 5, {0,0,255}, -1);
    imshow("Camera_calibration", this->image_calibration);
}

/*!
     *  \brief Draw the contour of the selected calibration paper
     *
     * Draw lines between the four selected corners of the selected calibration paper
     * 
     */
void Viewer::draw_lines(){
    this->image_calibration = this->original_image_calibration.clone();
    for(int i=0 ; i<4 ; i++){
        line(this->image_calibration, this->checkBoard_corners[i],this->checkBoard_corners[(i+1)%4], {0,0,255}, 4);
    }
    imshow("Camera_calibration", this->image_calibration);
}