#pragma once
#include <string_view>

class Shader {
public:  // public constructors/destructors/overloads
        Shader() = default;
        Shader(std::string_view vertex_shader_filepath, std::string_view fragment_shader_filepath);
public:  // public member functions
        void use() const;
public:  // public member variables
private: // private member functions
private: // private member variables
        uint32_t m_shader_program = 0;
};