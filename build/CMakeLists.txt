cmake_minimum_required(VERSION 3.16)
project(mysteries_of_inrith)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lglfw -ggdb")
set(CMAKE_EXPORT_COMPILE_COMMANDS )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../output)

set(VENDOR_HEADER_FILES
                ../vendor/glad/khrplatform.h
                ../vendor/glad/glad.h
                )

set(INTERNAL_HEADER_FILES
                ../internal/sprite_renderer/sprite_renderer.h
                ../internal/gl_debug/gl_debug.h
                ../internal/window/window.h
                ../internal/config/config.h
                ../internal/application/application.h
                ../internal/shader/shader.h
                ../internal/buffer/buffer.h
                )

set(VENDOR_SOURCE_FILES
                ../vendor/glad/glad.c
                )

set(INTERNAL_SOURCE_FILES
                ../internal/sprite_renderer/sprite_renderer.cpp
                ../internal/gl_debug/gl_debug.cpp
                ../internal/window/window.cpp
                ../internal/application/application.cpp
                ../internal/shader/shader.cpp
                ../internal/buffer/buffer.cpp
                )

set(SOURCE_FILES ../src/main.cpp
                ${INTERNAL_SOURCE_FILES}
                ${VENDOR_SOURCE_FILES}
                ${INTERNAL_HEADER_FILES}
                ${VENDOR_HEADER_FILES}
                )

include_directories(../vendor
                ../vendor/glad
                ../internal/sprite_renderer
                ../internal/gl_debug
                ../internal/window
                ../internal/config
                ../internal/application
                ../internal/shader
                ../internal/buffer
                )

add_executable(mysteries_of_inrith ${SOURCE_FILES})
target_precompile_headers(mysteries_of_inrith PRIVATE ${VENDOR_HEADER_FILES})
