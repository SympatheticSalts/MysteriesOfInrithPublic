#pragma once
#include <glm/glm.hpp>
#include <array>
#include "buffer.h"

template <uint32_t MaxSpriteCount>
struct SpriteRenderer {
        struct SpriteVertex {
                glm::vec3 pos;
//                glm::vec2 uv;
        };
public:  // public constructors/destructors/overloads
        SpriteRenderer();
public:  // public member functions
public:  // public member variables
        void render() {
                m_vao.bind();
                glDrawElements(GL_TRIANGLES, MaxSpriteCount * 6, GL_UNSIGNED_INT, nullptr);
        };
private: // private member functions
private: // private member variables
        HostBuffer<sizeof(uint32_t) * MaxSpriteCount * 6> m_index_buffer;
        MappedBuffer<sizeof(SpriteVertex) * MaxSpriteCount * 4> m_vertex_buffer;
        VertexAttributeObject m_vao;
};
template<uint32_t MaxSpriteCount>
SpriteRenderer<MaxSpriteCount>::SpriteRenderer() {
        static constexpr uint32_t index_offsets[] = {0, 2, 1, 0, 3, 2};
        std::array<uint32_t, MaxSpriteCount * 6> indices;
        for (int i = 0; i < MaxSpriteCount; i++)
                for (int j = 0; j < 6; j++)
                        indices[i*6 + j] = i*4 + index_offsets[j];
        m_index_buffer.write(indices.data(), sizeof(indices));
        
        float vertices[][3] = {
                {-0.25f, -0.25f + 0.5f, 0.0f},
                {-0.25f, 0.25f + 0.5f,  0.0f},
                {0.25f,  0.25f + 0.5f,  0.0f},
                {0.25f,  -0.25f + 0.5f, 0.0f},
                {-0.25f, -0.25f - 0.5f, 0.0f},
                {-0.25f, 0.25f - 0.5f,  0.0f},
                {0.25f,  0.25f - 0.5f,  0.0f},
                {0.25f,  -0.25f - 0.5f, 0.0f},
        };
        m_vertex_buffer.write(vertices, sizeof(vertices));
        m_vertex_buffer.push(sizeof(vertices));
        
        m_vao.addAttribute<GL_FLOAT, 3>();
        m_vao.vertexBuffer(m_vertex_buffer.host_buffer());
        m_vao.indexBuffer(m_index_buffer.buffer());
}
