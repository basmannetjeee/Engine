#pragma once
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <SDL2/SDL.h>

#include "utilities/renderer/renderer.hpp"
#include "utilities/framemanager/framemanager.hpp"
#include "utilities/deltatime/deltatime.hpp"

class Engine {
public:
    Engine();
    ~Engine();

    int run();

    void pollEvents();

    void clearScreen();

    GLuint debugShaders();

    Renderer renderer;
    FrameManager frame;
    DeltaTime delta;
private:
    bool _running;

    SDL_Window* _window;
    SDL_GLContext _glContext;
    SDL_Event _event;

    int _init();
};
