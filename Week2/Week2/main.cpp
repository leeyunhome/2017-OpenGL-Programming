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
#include <vector>			// do not use list

const int width_window = 640; //*2;
const int height_window = 480; //*2;

float circle_center_x = 0.0;
float circle_center_y = 0.0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
		//activate_airship();
		std::cout << "Key pressed" << std::endl;
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
		//activate_airship();
	{
		circle_center_x -= 0.05;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
		//activate_airship();
	{
		circle_center_x += 0.05;
	}
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	std::cout << xpos << " " << ypos << std::endl;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		//popup_menu();
	{
		std::cout << "button clicked" << std::endl;
	}
}

class Vector3
{
public:
	union
	{
		struct { float x_, y_, z_; };
		float values_[3];
	};
	Vector3(const float _x, const float _y, const float& _z)
		: x_(_x), y_(_y), z_(_z)
	{}
};

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
	/*glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);*/

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	printf("%s\n", glGetString(GL_VERSION));

	glClearColor(255.0/255.0, 153.0/255.0, 51.0/255.0, 1);	// white background
	// default color for display buffer

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	// your frame buffer is two dimensional array x-, y-
	// your frame buffer is three dimensional array x-, y-, d-
	const float aspect_ratio = (float)width / (float)height; // 1.66, 1.9 TV display
	glOrtho(-1, 1, -1 / aspect_ratio, 1 / aspect_ratio, -1.0, 1.0);

	Vector3 colors[3] = {
		Vector3(1.0, 0.0, 0.0),
		Vector3(0.0, 1.0, 0.0),
		Vector3(0.0, 0.0, 1.0),
	};


	// You are going to study later in Viewing class.
	//float color[3][3]
	//{
	//	{1.0, 0.0, 0.0},	// the color of the first vertex
	//	{0.0, 1.0, 0.0},	// the color of the second vertex
	//	{0.0, 0.0, 1.0},	// the color of the third vertex
	//};
	float vertex[3][3]
	{ 
					{ 0.0, 0.0, 0.0 },	// first vertex
					{ 0.5, 0.0, 0.0 },	// second vertex
					{ 0.25, 0.5, 0.0},	// third vertex
	};

	int num_vertices = 3;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// TODO: draw here
		// In this example, we draw only one triangle
		// this is for massive polygons.

		glBegin(GL_TRIANGLE_FAN);

		for (int v = 0; v < num_vertices; v++)
		{
			//glColor3f(colors[v].x_, colors[v].y_, colors[v].z_);
			glColor3fv(colors[v].values_);
			//glColor3fv(&color[v][0]);
			
			glVertex3fv(vertex[v]);
		}
		//glColor3f(1.0, 0.0, 0.0);
		////glVertex3f(0.0, 0.0, 0.0);	// == glVertex2f(0.0, 0.0); in 2D drawing
		//glVertex3fv(first_vertex);

		//glColor3f(0.0, 1.0, 0.0);
		//glVertex3f(0.5, 0.0, 0.0);	// == glVertex2f(0.0, 0.0); in 2D drawing
		//
		//glColor3f(0.0, 0.0, 1.0);
		//glVertex3f(0.25, 0.5, 0.0);	// == glVertex2f(0.0, 0.0); in 2D drawing
		
		// center of polygonized circle
		// center vertex
		//glVertex2f(circle_center_x, circle_center_y);

		//const int num_triangles = 1000;
		//const float dtheta = 2.0 * 3.141592 / (float)num_triangles;
		//const float radius = 0.5;

		//float theta = 0.0;
		//for (int i = 0; i <= num_triangles; i++, theta += dtheta)
		////for (float theta = 0.0; theta < 2.0 * 3.141592; theta += dtheta)
		//{
		//	const float x = radius * cos(theta) + circle_center_x;
		//	const float y = radius * sin(theta) + circle_center_y;
		//	glVertex2f(x, y);	// == glVertex2f(0.0, 0.0); in 2D drawing

		//}
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

