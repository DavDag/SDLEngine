//
// MySDLEngine
// Created by Davide Risaliti on 26/02/2021.
// Copyright (c) 2021 Davide Risaliti <davdag24@gmail.com>.
// Under GNU GENERAL PUBLIC LICENSE, Version 3
//

#include "App.hpp"

#include <cstdio>
#include <SDL.h>

namespace MSE {

    App::App(const std::string &title, AppConfig configs) {
        _title = title;
        _configs = configs;
        _window = nullptr;
        _windowSurface = nullptr;
        _quit = false;
    }

    bool App::init() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            _quit = true;
            return false;
        }

        // Create window
        _window = SDL_CreateWindow(
                _title.c_str(),
                _configs.window_pos_x,
                _configs.window_pos_y,
                _configs.window_size_x,
                _configs.window_size_y,
                _configs.flags);
        // Error check
        if (_window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            _quit = true;
            return false;
        }

        // Get window surface
        _windowSurface = SDL_GetWindowSurface(_window);
        // Error check
        if (_windowSurface == nullptr) {
            printf("Window's surface could not be created! SDL_Error: %s\n", SDL_GetError());
            _quit = true;
            return false;
        }

        // Initialization completed
        return true;
    }

    void App::run() {
        // Event
        SDL_Event e;

        // Main loop
        while (!_quit) {
            // 1. Handle events
            while (SDL_PollEvent(&e) != 0) {
                // Quit
                if (e.type == SDL_EventType::SDL_QUIT) {
                    _quit = true;
                }
                // Others
            }

            // 2. Update

            // 3. Draw
            SDL_UpdateWindowSurface(_window);
        }

        // Quit safely
        close();
    }

    void App::pop() {
        // TODO
    }

    void App::close() {
        // Destroy window (destroy its surface too)
        SDL_DestroyWindow(_window);

        // Quit SDL subsystems
        SDL_Quit();
    }

} // MSE