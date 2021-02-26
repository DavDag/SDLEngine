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

    std::shared_ptr<App> App::create(const std::string &title, AppConfig configs) {
        return std::make_shared<App>(App(title, configs));
    }

    App::App(const std::string &title, AppConfig configs) {
        _title = title;
        _configs = configs;
        _window = nullptr;
        _windowSurface = nullptr;
        _isRunning = false;
        _quit = false;
    }

    bool App::init() {
        if (_isRunning) return false;

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
        _quit = false;
        return true;
    }

    void App::run() {
        if (_isRunning) return;
        _isRunning = true;

        // Main loop
        SDL_Event e;
        Clock fpsClock;
        Clock frameClock;
        while (!_quit) {
            // Restart clock for frame time
            frameClock.restart();

            // Check for empty queue
            if (_states.empty()) {
                printf("Application error. Unable to retrieve current state. Empty queue\n");
                quit();

                // Trick to get a clean exit
                continue;
            }

            // Current state
            auto state = _states.top();

            // 1. Handle events
            while (SDL_PollEvent(&e) != 0) {
                // Quit
                if (e.type == SDL_EventType::SDL_QUIT) {
                    quit();
                }
                // Forward to state
                state->onEvent(e);
            }

            // Calc delta time
            float dt = fpsClock.restart() / 1000.f;

            // 2. Update
            state->onUpdate(dt);

            // 3. Draw
            state->onDraw();
            SDL_UpdateWindowSurface(_window);

            // Frame cap
            float realFrameTime = frameClock.restart() / 1000.f;
            float reqFrameTime = (1000.f / (float) _configs.fps_cap);
            if (_configs.fps_cap != 0 && realFrameTime < reqFrameTime) {
                SDL_Delay(reqFrameTime - realFrameTime);
            }
        }

        // Quit safely
        _isRunning = false;
        close();
    }

    void App::updateTitle(const std::string &newTitle) {
        SDL_SetWindowTitle(_window, newTitle.c_str());
    }

    void App::updateFpsCap(int newFpsCap) {
        _configs.fps_cap = newFpsCap;
    }

    void App::quit() {
        _quit = true;
    }

    void App::close() {
        if (_isRunning) return;

        // Destroy window (destroy its surface too)
        SDL_DestroyWindow(_window);

        // Quit SDL subsystems
        SDL_Quit();
    }

} // MSE