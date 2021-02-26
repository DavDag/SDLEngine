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
#include <SDL.h>

namespace MSE {

    // Forwarding declaration
    class App;

    /**
     * Base State class.
     *
     * Every State must derive from this class.
     *
     * State lifecycle is:
     *  (1) onCreate
     *  (2) onResume
     *      # if another state is pushed above it
     *      (3a) onPause
     *          # if the state above is popped from the stack
     *          (4a) onResume
     *      # if state is popped from the stack
     *      (3b) onPause
     *      (4b) onDestroy
     */
    class BaseState {

        friend class App;

    private:
        std::shared_ptr<App> _app;

    protected:
        // Retrieve app
        std::shared_ptr<App> app() { return _app; }

    public:
        // Called once at creation
        virtual void onCreate() { };

        // Called every time the state is 'Resumed'
        virtual void onResume() { };

        // Called every time the state is 'Paused'
        virtual void onPause() { };

        // Called once at destruction
        virtual void onDestroy() { };

        // Called every time an event is received
        virtual void onEvent(const SDL_Event& event) = 0;

        // Called every frame to handle application logic
        virtual void onUpdate(float dt) = 0;

        // Called every frame to draw application content
        virtual void onDraw() = 0;
    };

} // MSE

#endif //SDLENGINE_BASESTATE_HPP
