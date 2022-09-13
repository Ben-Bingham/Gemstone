#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

void makeWindow() {
	GLFWwindow* window;
	window = glfwCreateWindow(480, 640, "Window", glfwGetPrimaryMonitor(), NULL);
}