//
// MySDLEngine
// Created by Davide Risaliti on 26/02/2021.
// Copyright (c) 2021 Davide Risaliti <davdag24@gmail.com>.
// Under GNU GENERAL PUBLIC LICENSE, Version 3
//

#pragma once

#ifndef SDLENGINE_APP_HPP
#define SDLENGINE_APP_HPP

#include "states/BaseState.hpp"
#include "utility/Clock.hpp"
#include "AppConfig.hpp"

#include <type_traits>
#include <string>
#include <stack>
#include <SDL.h>
#include <memory>

namespace MSE {

    /**
     * Application class.
     *
     * Instantiate it via the create method.
     *
     * example usage:
     *  auto app = MSE::App::create("Demo", { .fps_cap = 60 });
     *  app->init();
     *  app->push<ExampleState>();
     *  app->run();
     */
    class App: public std::enable_shared_from_this<App> {

    private:
        // Private constructor
        App(const std::string &title, AppConfig configs);

    public:
        // Create method
        static std::shared_ptr<App> create(const std::string& title, AppConfig configs);

        // Initialize SDL & others
        bool init();

        // Main loop
        void run();

        // Add state to state's stack
        template<class T, std::enable_if_t<std::is_base_of<BaseState, T>::value, bool> = true>
        void push() {
            // OnPause
            if (!_states.empty()) {
                _states.top()->onPause();
            }

            // Push new state
            _states.push(std::make_shared<T>());

            // OnCreate & OnResume
            auto newState = _states.top();
            newState->_app = shared_from_this();
            newState->onCreate();
            newState->onResume();
        }

        // Remove current state from stack
        void pop() {
            // OnPause & OnDestroy
            if (!_states.empty()) {
                auto state = _states.top();
                state->onPause();
                state->onDestroy();
                _states.pop();
            } else {
                printf("Application error. Unable to call pop with less than two states.\n");
                return;
            }

            // OnResume
            if (!_states.empty()) {
                _states.top()->onResume();
            }
        }

        // Close application correctly
        void quit();

        // Update window title
        void updateTitle(const std::string& newTitle);

        // Update application fps cap
        void updateFpsCap(int newFpsCap);

    private:
        // Free resources
        void close();

    private:
        std::string _title;
        AppConfig _configs;
        SDL_Window *_window;
        SDL_Surface *_windowSurface;

        bool _isRunning, _quit;
        std::stack<std::shared_ptr<BaseState>> _states;
    };

} // MSE

#endif //SDLENGINE_APP_HPP
