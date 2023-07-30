#include "shader.h"
#include <iostream>

const char *readFile(std::string_view filepath) {
        FILE *file = fopen(filepath.data(), "r");
        if (file == nullptr) {
                printf("Failed to open the file.\n");
                std::exit(1);
        }
        
        fseek(file, 0, SEEK_END); // Move the file pointer to the end of the file
        size_t fileSize = ftell(file); // Get the current position of the file pointer (which is the file size)
        fseek(file, 0, SEEK_SET); // Move the file pointer back to the beginning of the file
        
        char *buffer = (char *) malloc(fileSize + 1); // Allocate memory to store the file contents
        if (buffer == nullptr) {
                printf("Failed to allocate memory.\n");
                fclose(file);
                std::exit(1);
        }
        
        size_t bytesRead = fread(buffer, 1, fileSize, file); // Read the file contents into the buffer
        if (bytesRead != fileSize) {
                printf("Failed to read the file.\n");
                free(buffer);
                fclose(file);
                std::exit(1);
        }
        
        buffer[fileSize] = '\0'; // Null-terminate the buffer to treat it as a C string
        
        fclose(file);
        return buffer;
}

Shader::Shader(std::string_view vertex_shader_filepath, std::string_view fragment_shader_filepath) {
        const char *vertex_shader_source = readFile("assets/shaders/world/world.vert");
        uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
        glCompileShader(vertex_shader);
        
        const char *fragment_shader_source = readFile("assets/shaders/world/world.frag");
        uint32_t fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
        glCompileShader(fragment_shader);
        
        m_shader_program = glCreateProgram();
        glAttachShader(m_shader_program, vertex_shader);
        glAttachShader(m_shader_program, fragment_shader);
        glLinkProgram(m_shader_program);
        
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
}
void Shader::use() const {
        glUseProgram(m_shader_program);
}
