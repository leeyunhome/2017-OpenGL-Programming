// Week2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>			// srand, rand
#include <thread>			// std::this_thread::sleep_for
#include <chrono>			// std::chrono::seconds
#include "math.h"

const int width_window = 640; //*2;
const int height_window = 480; //*2;

int main()
{
	GLFWwindow* window = nullptr;

	/* Initialize the liabrary */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width_window, height_window, "Hello Seyeon", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// callbacks here

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(255.0/255.0, 153.0/255.0, 51.0/255.0, 1);	// white background
	// default color for display buffer

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	// your frame buffer is two dimensional array x-, y-
	// your frame buffer is three dimensional array x-, y-, d-
	//glOrtho(0, 1, 0, 1, -1.0, 1.0);
	// You are going to study later in Viewing class.

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// TODO: draw here
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);	// == glVertex2f(0.0, 0.0); in 2D drawing
		glVertex3f(0.5, 0.0, 0.0);	// == glVertex2f(0.0, 0.0); in 2D drawing
		glVertex3f(0.25, 0.5, 0.0);	// == glVertex2f(0.0, 0.0); in 2D drawing

		glEnd();
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	return 0;
}

