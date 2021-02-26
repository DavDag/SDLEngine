//
// MySDLEngine
// Created by Davide Risaliti on 26/02/2021.
// Copyright (c) 2021 Davide Risaliti <davdag24@gmail.com>.
// Under GNU GENERAL PUBLIC LICENSE, Version 3
//

#pragma once

#ifndef SDLENGINE_CLOCK_HPP
#define SDLENGINE_CLOCK_HPP

#include <SDL_timer.h>

namespace MSE {

    /**
     * Clock class.
     *
     * It measures time in milliseconds between calls.
     */
    class Clock {
    public:
        // Constructor
        Clock();

        // Return milliseconds passed since clock creation or last call to restart.
        Uint32 restart();

    private:
        Uint32 _ticks;
    };

} // MSE

#endif //SDLENGINE_CLOCK_HPP
