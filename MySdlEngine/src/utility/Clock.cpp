//
// MySDLEngine
// Created by Davide Risaliti on 26/02/2021.
// Copyright (c) 2021 Davide Risaliti <davdag24@gmail.com>.
// Under GNU GENERAL PUBLIC LICENSE, Version 3
//

#include "utility/Clock.hpp"

namespace MSE {

    Clock::Clock() {
        // Start timer
        _ticks = SDL_GetTicks();
    }

    Uint32 Clock::restart() {
        // Retrieve current ticks count
        Uint32 now = SDL_GetTicks();

        // Calc ticks since last reset
        Uint32 passed = now - _ticks;

        // Update and return
        _ticks = now;

        // Return time passed as milliseconds
        return passed;
    }

} // MSE