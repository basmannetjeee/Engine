#include "deltatime.hpp"

// Using steady clock because we shouldn't need anything more precise.

DeltaTime::DeltaTime() : delta(0.0) {
    previousTime = std::chrono::steady_clock::now();
}

void DeltaTime::update() {
    auto currentTime = std::chrono::steady_clock::now();
    delta = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - previousTime).count();
    previousTime = currentTime;
}
