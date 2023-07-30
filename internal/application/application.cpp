#include "application.h"
#include "gl_debug.h"

Application::Application() {
#ifndef NDEBUG
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(message_callback, nullptr);
#endif
        glViewport(0, 0, m_window.width(), m_window.height());
        
        // Shader Creation
        m_shaders[Shaders::World] = Shader("assets/shaders/world/world.vert", "assets/shaders/world/world.frag");
}
Window &Application::window() {
        return m_window;
}
void Application::run() {
        while (m_window.isRunning()) {
                update();
                render();
        }
}
void Application::update() {
        glfwPollEvents();
        m_window.proccessInput();
}
void Application::render() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        m_shaders[Shaders::World].use();
        m_tile_renderer.render();
        
        m_window.swapBuffer();
}
