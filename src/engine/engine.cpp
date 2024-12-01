// Yes, we are using define macros. I don't fucking care what you say.
#define KEYSYM(event) (event.key.keysym.sym)
#include "engine.hpp"
#include "utilities/shaders/shaders.hpp"
#include <iostream>

Engine::Engine() :
        _fps(0),
        _frameTime(0.0),
        _deltaTime(0.0),
        _running(false) {
            if (_init() != 0) {
                std::cout << "Initiaalisastion failed." << std::endl;
                SDL_Quit();
            }
        }

Engine::~Engine() {
    if (_glContext) {
        SDL_GL_DeleteContext(_glContext);
        _glContext = nullptr;
    }

    if (_window) {
        SDL_DestroyWindow(_window);
        _window = nullptr;
    }

    SDL_Quit();
}

int Engine::_init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        return 1;
    _window = SDL_CreateWindow("Gamping engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    if (!_window)
        return 1;
    _glContext = SDL_GL_CreateContext(_window);
    if (!_glContext)
        return 1;

    _running = true;
    return 0;
}

void Engine::pollEvents() {
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            _running = false;
        }

        if (_event.type == SDL_KEYDOWN) {
            if (KEYSYM(_event) == SDLK_ESCAPE) {
                _running = false;
            }
        }
    }
}

void Engine::clearBuffers() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

GLuint Engine::debugShaders() {
    GLuint vertShader;
    vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &sh::vertexShaderSource, NULL);
    glCompileShader(vertShader);

    GLuint fragShader;
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &sh::fragmentShaderSource, NULL);
    glCompileShader(fragShader);

    GLuint shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return shaderProgram;
}
