#include <iostream>
#include "window.h"
#include "config.h"

void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
        auto *user_window = static_cast<Window *>(glfwGetWindowUserPointer(window));
        user_window->updateDimensions(width, height);
        glViewport(0, 0, width, height);
}

Window::Window() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        m_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", nullptr, nullptr);
        if (m_window == nullptr) {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                std::exit(1);
        }
        
        glfwSetWindowUserPointer(m_window, this);
        
        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
        m_width = WINDOW_WIDTH;
        m_height = WINDOW_HEIGHT;
        
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
                std::cout << "Failed to initialize GLAD" << std::endl, std::exit(1);
}
Window::~Window() {
        glfwTerminate();
}
Window::Window(const Window &other) {
        this->m_window = other.m_window;
        this->m_width = other.m_width;
        this->m_height = other.m_height;
}
Window::Window(Window &&other) noexcept {
        this->m_window = other.m_window;
        this->m_width = other.m_width;
        this->m_height = other.m_height;
        other.m_window = nullptr;
        other.m_width = 0;
        other.m_height = 0;
}
Window &Window::operator=(const Window &other) = default;
Window &Window::operator=(Window &&other) noexcept {
        this->m_window = other.m_window;
        this->m_width = other.m_width;
        this->m_height = other.m_height;
        other.m_window = nullptr;
        other.m_width = 0;
        other.m_height = 0;
        return *this;
}
bool Window::isRunning() {
        return !glfwWindowShouldClose(m_window);
}
void Window::swapBuffer() {
        glfwSwapBuffers(m_window);
}
void Window::updateDimensions(int32_t width, int32_t height) {
        m_width = width;
        m_height = height;
}
int32_t Window::width() const {
        return m_width;
}
int32_t Window::height() const {
        return m_height;
}
void Window::proccessInput() {
        if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(m_window, true);
}
Window::operator GLFWwindow *() {
        return this->m_window;
}
