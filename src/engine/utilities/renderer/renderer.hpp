#pragma once
#include <chrono>
#include "../common.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void limitFPS(const double& delta);
    void setMaxFPS(float FPS);

    uint getMaxFPS() const;
    uint getFPS() const;

    void updateFPS();
private:
    uint _maxFPS;
    uint _FPS;

    uint _frameCount;
    std::chrono::steady_clock::time_point _previousTime;
};
