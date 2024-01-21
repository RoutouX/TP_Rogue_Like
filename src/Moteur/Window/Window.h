//
// Created by thoma on 06/08/2023.
//

#ifndef TP_ROGUE_LIKE_WINDOW_H
#define TP_ROGUE_LIKE_WINDOW_H

#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "../../Utility/Thread.h"
#include "../2D/Graphique/Camera.h"


class Window : public Thread{
public:
    Window(bool* shutdown);
    ~Window();
    void run(std::future<void> const& stop_token) override;
    void setPCamera(Camera *pCamera);

    void setDrawgame(bool drawgame);

private:
    void drawComponentHitBoxWithCamera();
    void drawCircle(float cx, float cy, float r, int num_segments);
    //void drawCircle(float cx, float cy, float r, int num_segments, float aspect_ratio);

    //test
    void setupOrthoProjection();

    bool* shutdown;
    bool drawgame = false;

    Camera* pCamera = nullptr;

    GLFWmonitor* monitor;
    const GLFWvidmode* mode;
    GLFWwindow* window;

    const int microToSeconds = 1000000;
    const double delay1 = microToSeconds;     //2 seconds

};


#endif //TP_ROGUE_LIKE_WINDOW_H
