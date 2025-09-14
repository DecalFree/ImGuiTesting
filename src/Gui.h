#pragma once
#include "imgui.h"
#include "GLFW/glfw3.h"

class Gui {
public:
    explicit Gui(GLFWwindow* window);
    ~Gui();

    void RenderGui();

private:
    GLFWwindow* m_Window;
    ImGuiWindowFlags m_WindowFlags;

    bool m_showSettings = false;
    bool m_useDarkMode = true;
};
