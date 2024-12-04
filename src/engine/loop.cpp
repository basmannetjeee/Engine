#define _ENGINE_DEBUG
#include "engine.hpp"
#include "shapes.hpp"
#include <iostream>

int Engine::run() {
    GLuint shaderProgram = debugShaders();
    shapes::Rectangle rect;

    while (_running) {
        pollEvents();
        clearScreen();
        delta.update();
        renderer.updateFPS();

        rect.draw(shaderProgram);
        SDL_GL_SwapWindow(_window);

#ifdef _ENGINE_DEBUG
        std::cout << "Delta: " << delta.delta << "\n";
        std::cout << "FPS: " << renderer.getFPS() << "\n";
#endif
        renderer.limitFPS(delta.delta);
    }
    return 0;
}
