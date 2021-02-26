//
// MySDLEngine
// Created by Davide Risaliti on 26/02/2021.
// Copyright (c) 2021 Davide Risaliti <davdag24@gmail.com>.
// Under GNU GENERAL PUBLIC LICENSE, Version 3
//

#pragma once

#ifndef SDLENGINE_BASESTATE_HPP
#define SDLENGINE_BASESTATE_HPP

#include <memory>

namespace MSE {

    class App;

    class BaseState {

    public:
        virtual void onCreate() = 0;
        virtual void onResume() = 0;

        virtual void onPause() = 0;
        virtual void onDestroy() = 0;

        virtual void onEvent() = 0;
        virtual void onUpdate() = 0;
        virtual void onDraw() = 0;

    };

} // MSE

#endif //SDLENGINE_BASESTATE_HPP
