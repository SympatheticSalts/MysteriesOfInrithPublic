#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Window {
public:  // public constructors/destructors/overloads
        Window();
        ~Window();
        
        Window(const Window &other);
        Window(Window &&other) noexcept;
        Window &operator=(const Window &other);
        Window &operator=(Window &&other) noexcept;
        
        explicit operator GLFWwindow *();
public:  // public member functions
public:  // public member variables
        [[nodiscard]] int32_t width() const;
        [[nodiscard]] int32_t height() const;
        bool isRunning();
        void swapBuffer();
        void updateDimensions(int32_t width, int32_t height);
        void proccessInput();
private: // private member functions
private: // private member variables
        GLFWwindow *m_window;
        int32_t m_width;
        int32_t m_height;
};
