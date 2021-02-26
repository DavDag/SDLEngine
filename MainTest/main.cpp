#include <App.hpp>

class MainState: public MSE::BaseState {

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
