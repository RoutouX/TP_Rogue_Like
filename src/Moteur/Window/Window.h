//
// Created by thoma on 06/08/2023.
//

#ifndef TP_ROGUE_LIKE_WINDOW_H
#define TP_ROGUE_LIKE_WINDOW_H

#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "../../Utility/Thread.h"


class Window : public Thread{
public:
    Window(bool* shutdown);
    ~Window();
    void run(std::future<void> const& stop_token) override;

private:
    bool* shutdown;

    GLFWmonitor* monitor;
    const GLFWvidmode* mode;
    GLFWwindow* window;

};


#endif //TP_ROGUE_LIKE_WINDOW_H
