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
		ASSERT(window);
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


	

	//float positions[8] = {
	//	-0.5,-0.5,
	//	-0.5,0.5,
	//	 0.5,0.5,
	//	 0.5,-0.5
	//};

	float vertices[] = {
		// Positions      // Colors (RGBA)
		-0.5f, -0.5f,     1.0f, 0.0f, 0.0f, 1.0f,  // Bottom left, Red
		-0.5f,  0.5f,     0.0f, 1.0f, 0.0f, 1.0f,  // Top left, Green
		 0.5f,  0.5f,     0.0f, 0.0f, 1.0f, 1.0f,  // Top right, Blue
		 0.5f, -0.5f,     1.0f, 1.0f, 1.0f, 1.0f   // Bottom right, White
	};


	int indices[] = {
	0, 1, 2,
	0, 3, 2
	};


	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	//glEnableVertexAttribArray(0);

	// Position attribute
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // 2 floats for position
	glEnableVertexAttribArray(0);

	// Color attribute
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float))); // 4 floats for color
	glEnableVertexAttribArray(1);

	unsigned int IBO;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	Shader shader("res/shaders/Basic.shader");
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);	

		shader.Bind();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}