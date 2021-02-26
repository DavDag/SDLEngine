#include <App.hpp>

class MainState : public MSE::BaseState {

    void onEvent(const SDL_Event &event) override {

    }

    void onUpdate(float dt) override {

    }

    void onDraw() override {

    }
};

int WinMain() {
    auto app = MSE::App::create("DemoWindow", {
            .window_size_x = 1200,
            .window_size_y = 600,
            .fps_cap = 60
    });
    app->init();
    app->push<MainState>();
    app->run();
    return 0;
}
