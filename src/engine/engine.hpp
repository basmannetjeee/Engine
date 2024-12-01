#pragma once
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <SDL2/SDL.h>

class Engine {
public:
    Engine();
    ~Engine();

    int run();

    void pollEvents();

    void clearScreen();

    GLuint debugShaders();
private:
    void updateMetrics();
    int _fps;
    float _frameTime;
    float _deltaTime;

    bool _running;

    SDL_Window* _window;
    SDL_GLContext _glContext;
    SDL_Event _event;

    int _init();
};
