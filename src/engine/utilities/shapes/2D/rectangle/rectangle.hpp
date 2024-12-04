#pragma once
#include <OpenGL/gl3.h>

//  TODO:
//      Make this not suck. AKA create shared Vertex buffers n shit :thumbs_up:

namespace shapes {
    class Rectangle {
    public:
        Rectangle();
        ~Rectangle();
        void draw(unsigned int shaderProgram);

    private:
        GLuint _VAO, _VBO, _EBO;
        void _initializeBuffers();
    };
}
