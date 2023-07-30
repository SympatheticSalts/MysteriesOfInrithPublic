#pragma once
#include "window.h"
#include "sprite_renderer.h"
#include "shader.h"

namespace Shaders {
        enum {
                World,
                Max
        };
}

class Application {
public:  // public constructors/destructors/overloads
        Application();
public:  // public member functions
        Window &window();
public:  // public member variables
        void run();
        void update();
        void render();
private: // private member functions
private: // private member variables
        Window m_window;
        SpriteRenderer<2> m_tile_renderer;
        std::array<Shader, Shaders::Max> m_shaders;
};
