#include "engine.hpp"
#include "shapes.hpp"

int Engine::run() {
    GLuint shaderProgram = debugShaders();
    shapes::Rectangle rect;

    while (_running) {
        pollEvents();
        clearBuffers();

        rect.draw(shaderProgram);
        SDL_GL_SwapWindow(_window);

        SDL_Delay(16);
    }
    return 0;
}
