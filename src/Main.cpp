#include<iostream>
#define ASSERT(x) if(!(x)) __debugbreak();
#define GLEW_STATIC
#include "GLEW/include/glew.h"
#include "GLFW/include/glfw3.h"
#include "Shader.h"


int main(void) {

	GLFWwindow* window;

	int width=640;
	int height=480;

	if (!glfwInit()) {
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Endless Grid OpenGl", NULL, NULL);

	
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	
	if (glewInit() == GLEW_OK) {
		std::cout << "GLEW INITIALIZED" << std::endl;
	}
	else {
		std::cout << "GLEW UNINITIALIZED" << std::endl;
	}

	glViewport(0, 0, width, height);
	glClearColor(0.3f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	Shader shader("res/shaders/Basic.shader");

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}