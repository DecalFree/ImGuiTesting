cmake_minimum_required(VERSION 4.0)
project(ImGuiTesting)

set(CMAKE_CXX_STANDARD 26)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

set(SRC
        src/main.cpp
        src/Gui.cpp
        src/Gui.h
)

set(IMGUI_SRC
        external/imgui/imgui.cpp
        external/imgui/imgui_demo.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_opengl3.cpp
)

add_executable(${PROJECT_NAME} ${SRC} ${IMGUI_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/external/imgui
        ${CMAKE_SOURCE_DIR}/external/imgui/backends
)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE
            glfw
            OpenGL::GL
            opengl32
    )
else ()
    target_link_libraries(${PROJECT_NAME} PRIVATE
            glfw
            OpenGL::GL
    )
endif ()
