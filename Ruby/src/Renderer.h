#pragma once

#include <GL/glew.h>

#include "Log.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() {
            if (glewInit() != GLEW_OK) {
                LOG("GLEW failed to initialize.", Lazuli::LogLevel::TERMINAL);
            }

            const char* vertexShaderSource = "#version 330 core\n"
                "layout (location = 0) in vec3 aPos;\n"
                "void main()\n"
                "{\n"
                "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                "}\0";
            const char* fragmentShaderSource = "#version 330 core\n"
                "out vec4 FragColor;\n"
                "void main()\n"
                "{\n"
                "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                "}\n\0";

            unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
            glCompileShader(vertexShader);
            // check for shader compile errors
            int success;
            char infoLog[512];
            glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
                LOG("Vertex shader failed to compile.\n" + std::string(infoLog));
            }

            // fragment shader
            unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
            glCompileShader(fragmentShader);
            // check for shader compile errors
            glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
            if (!success) {
                glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
                LOG("Fragment shader failed to compile.\n" + std::string(infoLog));
            }

            // link shaders
            shaderProgram = glCreateProgram();
            glAttachShader(shaderProgram, vertexShader);
            glAttachShader(shaderProgram, fragmentShader);
            glLinkProgram(shaderProgram);
            // check for linking errors
            glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
            if (!success) {
                glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
                LOG("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + std::string(infoLog));
            }
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            float vertices[] = {
                 0.5f,  0.5f, 0.0f,  // top right
                 0.5f, -0.5f, 0.0f,  // bottom right
                -0.5f, -0.5f, 0.0f,  // bottom left
                -0.5f,  0.5f, 0.0f   // top left 
            };
            unsigned int indices[] = {  // note that we start from 0!
                0, 1, 3,  // first Triangle
                1, 2, 3   // second Triangle
            };
            
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            glGenBuffers(1, &EBO);
            // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
            glBindVertexArray(VAO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
            //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
            // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
            glBindVertexArray(0);
		}

		void render() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // draw our first triangle
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
            
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

        unsigned int shaderProgram;
        unsigned int VBO, VAO, EBO;
	};
}