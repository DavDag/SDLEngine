//
// MySDLEngine
// Created by Davide Risaliti on 26/02/2021.
// Copyright (c) 2021 Davide Risaliti <davdag24@gmail.com>.
// Under GNU GENERAL PUBLIC LICENSE, Version 3
//

#pragma once

#ifndef SDLENGINE_APPCONFIG_HPP
#define SDLENGINE_APPCONFIG_HPP

#include <SDL.h>
#include <SDL_stdinc.h>

namespace MSE {

    const int DefaultAppFlags = SDL_WindowFlags::SDL_WINDOW_SHOWN | SDL_WindowFlags::SDL_WINDOW_RESIZABLE | SDL_WindowFlags::SDL_WINDOW_OPENGL;

    struct AppConfig {
        Uint32 window_size_x = 1024;                    // Window size
        Uint32 window_size_y = 600;                     //
        Uint32 window_pos_x = SDL_WINDOWPOS_UNDEFINED;  // Window starting position
        Uint32 window_pos_y = SDL_WINDOWPOS_UNDEFINED;  //
        Uint8 fps_cap = 0;                              // FPS cap (0 for unlimited fps)
        int flags = DefaultAppFlags;                    // Window flags
    };

} // MSE

#endif //SDLENGINE_APPCONFIG_HPP
