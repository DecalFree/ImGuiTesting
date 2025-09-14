#include "Gui.h"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Gui::Gui(GLFWwindow* window) : m_Window(window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    m_WindowFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

Gui::~Gui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Gui::RenderGui() {
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

    ImGui::Begin("ImGui Testing", nullptr, m_WindowFlags);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("View")) {
            if (ImGui::MenuItem("Settings"))
                m_showSettings = true;

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    if (m_showSettings) {
        ImGui::Begin("Settings", nullptr, m_WindowFlags);
        ImGui::SetWindowFocus("Settings");

        if (ImGui::BeginMenuBar()) {
            if (ImGui::MenuItem("Close"))
                m_showSettings = false;

            ImGui::EndMenuBar();
        }

        if (ImGui::Checkbox("Dark Mode", &m_useDarkMode)) {
            if (m_useDarkMode)
                ImGui::StyleColorsDark();
            else
                ImGui::StyleColorsLight();
        }

        ImGui::End();
    }

    ImGui::Text("You should use arch btw");

    ImGui::End();
}
