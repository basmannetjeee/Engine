#include "renderer.hpp"
#include <SDL2/SDL.h>

#include <chrono>
#include <iostream>

Renderer::Renderer() : _maxFPS(144), _previousTime(std::chrono::steady_clock::now()), _frameCount(0), _FPS(0) {}
Renderer::~Renderer() {}

void Renderer::limitFPS(const double& delta) {
    float frameTime = 1000.0f / static_cast<float>(_maxFPS);
    float delayTime = frameTime - delta;

    if (delta < frameTime)
        SDL_Delay(static_cast<Uint32>(delayTime));

#ifdef _ENGINE_DEBUG
    if (delayTime > 0.0f)
        std::cout << "Delay time: " << delayTime << "\n";
    else
        std::cout << "No delay, delayTime was negative.\n";
#endif
}

unsigned int Renderer::getMaxFPS() const {
    return _maxFPS;
}

void Renderer::setMaxFPS(float FPS) {
   _maxFPS = FPS;
}

unsigned int Renderer::getFPS() const {
    return _FPS;
}

void Renderer::updateFPS() {
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
    double elapsedTime = std::chrono::duration<double>(currentTime - _previousTime).count();

    ++_frameCount;

    if (elapsedTime > 1.0) {
        _FPS = _frameCount / elapsedTime;
        _frameCount = 0;
        _previousTime = currentTime;
    }
}
