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
#include "AppConfig.hpp"

#include <type_traits>
#include <string>
#include <queue>
#include <SDL.h>
#include <memory>

namespace MSE {

    class App {

    public:
        explicit App(const std::string &title, AppConfig configs);

        bool init();

        void run();

        template<class T, std::enable_if_t<std::is_base_of<BaseState, T>::value, bool> = true>
        void push() {
            // TODO
        }

        void pop();

    private:
        void close();

    private:
        std::string _title;
        AppConfig _configs;
        SDL_Window *_window;
        SDL_Surface *_windowSurface;

        bool _quit;
        std::queue<std::shared_ptr<BaseState>> _states;
    };

} // MSE

#endif //SDLENGINE_APP_HPP
