#include <App.hpp>

class MainState : public MSE::BaseState {

    void onCreate() override {

    }

    void onResume() override {

    }

    void onPause() override {

    }

    void onDestroy() override {

    }

    void onEvent() override {

    }

    void onUpdate() override {

    }

    void onDraw() override {

    }

};

int WinMain() {
    MSE::App app("DemoWindow", {
            .window_size_x = 1200,
            .window_size_y = 600,
            .fps_cap = 60
    });
    app.init();
    app.push<MainState>();
    app.run();
    return 0;
}
