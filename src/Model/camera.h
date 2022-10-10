#ifndef _MODEL_CAMERA_
#define _MODEL_CAMERA_

#include <stdio.h>

class Camera {

    private:
        int config;
        float pos[3];
        float angle[3];

    public:
        Camera();

        void set_config(int conf);
        int get_config();
        float* get_pos();
        float* get_angle();
};

#endif