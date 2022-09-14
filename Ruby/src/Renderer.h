#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Log.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() {
            //const char* vertexShaderSource = "#version 330 core\n"
            //    "layout (location = 0) in vec3 aPos;\n"
            //    "void main()\n"
            //    "{\n"
            //    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            //    "}\0";
            //const char* fragmentShaderSource = "#version 330 core\n"
            //    "out vec4 FragColor;\n"
            //    "void main()\n"
            //    "{\n"
            //    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            //    "}\n\0";

            //unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
            //glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
            //glCompileShader(vertexShader);
            //// check for shader compile errors
            //int success;
            //char infoLog[512];
            //glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
            //if (!success) {
            //    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            //    LOG("Vertex shader failed to compile. " + std::string(infoLog));
            //}
            //// fragment shader
            //unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            //glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
            //glCompileShader(fragmentShader);
            //// check for shader compile errors
            //glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
            //if (!success) {
            //    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            //    LOG("Fragment shader failed to compile. " + std::string(infoLog));
            //}
            //// link shaders
            //shaderProgram = glCreateProgram();
            //glAttachShader(shaderProgram, vertexShader);
            //glAttachShader(shaderProgram, fragmentShader);
            //glLinkProgram(shaderProgram);
            //// check for linking errors
            //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
            //if (!success) {
            //    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            //    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
            //}
            //glDeleteShader(vertexShader);
            //glDeleteShader(fragmentShader);
		}

		void render() {

		}

        unsigned int shaderProgram;
	};
}