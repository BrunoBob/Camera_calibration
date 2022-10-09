
class Camera {

    private:
        int config;
        float pos[3];
        float angle[3];

    public:

        int getConfig();
        float* getPos();
        float* getAngle();
};