#pragma once
#include <chrono>

class DeltaTime {
public:
    DeltaTime();
    operator double() const { return delta; }

    void update();
    double delta;
private:
    std::chrono::steady_clock::time_point previousTime;
    std::chrono::steady_clock::time_point currentTime;
};
