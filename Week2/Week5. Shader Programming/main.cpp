// Week5. Shader Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/GLU.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <iostream>
#include "math.h"
#include <vector>
#include "Matrix4.h"
#include <fstream>
#include <string>
#include <sstream>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const int width_window = 640;
const int height_window = 640;

class Vector3
{
public:
	union {
		struct { float x_, y_, z_; };
		float v_[3];
	};

	Vector3(const float& _x, const float& _y, const float& _z)
		: x_(_x), y_(_y), z_(_z)
	{}
};

const int num_vertices = 24;
const int num_quads = 6;

const Vector3 colors[num_vertices] =
{
	Vector3(0, 0, 0.8),
	Vector3(0, 0, 0.8),
	Vector3(0, 0, 0.8),
	Vector3(0, 0, 0.8),

	Vector3(1, 0, 0),
	Vector3(1, 0, 0),
	Vector3(1, 0, 0),
	Vector3(1, 0, 0),

	Vector3(0, 1, 0),
	Vector3(0, 1, 0),
	Vector3(0, 1, 0),
	Vector3(0, 1, 0),

	Vector3(1, 1, 0),
	Vector3(1, 1, 0),
	Vector3(1, 1, 0),
	Vector3(1, 1, 0),

	Vector3(0.2, 0.2, 1),
	Vector3(0.2, 0.2, 1),
	Vector3(0.2, 0.2, 1),
	Vector3(0.2, 0.2, 1),

	Vector3(1, 0, 1),
	Vector3(1, 0, 1),
	Vector3(1, 0, 1),
	Vector3(1, 0, 1)
};

Vector3 positions[num_vertices] =
{
	Vector3(0.0, 0.0, 0.5),
	Vector3(0.5, 0.0, 0.5),
	Vector3(0.5, 0.0, 0.0),
	Vector3(0.0, 0.0, 0.0),

	Vector3(0.0, 0.0, 0.5),
	Vector3(0.5, 0.0, 0.5),
	Vector3(0.5, 0.5, 0.5),
	Vector3(0.0, 0.5, 0.5),

	Vector3(0.5, 0.0, 0.5),
	Vector3(0.5, 0.0, 0.0),
	Vector3(0.5, 0.5, 0.0),
	Vector3(0.5, 0.5, 0.5),

	Vector3(0.0, 0.0, 0.5),
	Vector3(0.0, 0.0, 0.0),
	Vector3(0.0, 0.5, 0.0),
	Vector3(0.0, 0.5, 0.5),

	Vector3(0.0, 0.0, 0.0),
	Vector3(0.5, 0.0, 0.0),
	Vector3(0.5, 0.5, 0.0),
	Vector3(0.0, 0.5, 0.0),

	Vector3(0.0, 0.5, 0.5),
	Vector3(0.5, 0.5, 0.5),
	Vector3(0.5, 0.5, 0.0),
	Vector3(0.0, 0.5, 0.0)
};

const unsigned int indices[num_quads * 4] = {
	0, 1, 2, 3,
	4, 5, 6, 7,
	8, 9, 10, 11,
	12, 13, 14, 15,
	16, 17, 18, 19,
	20, 21, 22, 23
};

std::string readFromTxt(const char* filename)
{
	using namespace std;
	ifstream inFile;
	inFile.open(filename);	// open the input file

	stringstream strStream;
	strStream << inFile.rdbuf();	// read the file
	string str = strStream.str();	// str holds the content

	//cout << str << endl;// you can do anything with the string!!!

	return str;
}

int main(void)
{
	std::string vertex_shader = 
		readFromTxt("vertex_shader.glsl");

	//std::cout << vertex_shader << std::endl;

	std::string fragment_shader =
		readFromTxt("fragment_shader.glsl");

	//std::cout << fragment_shader << std::endl;

	/*std::this_thread::sleep_for(std::chrono::milliseconds(10000));

	exit(1);*/

	GLFWwindow* window = nullptr;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	//glfwWindowHint(GLFW_SAMPLES, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width_window, height_window, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// callbacks here

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glClearColor(1, 1, 1, 1); // while background

	printf("%s\n", glGetString(GL_VERSION));

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	//glOrtho(-0.2, 1.2, -0.2, 1.2, -10.0, 10.0);
	glOrtho(-1.2, 1.2, -1.2, 1.2, -10.0, 10.0);
	//TODO: consider anisotropic view
	gluLookAt(1.2, 0.8, 1.2, 0.5, 0.5, 0.5, 0, 1, 0);
	glm::vec3 eye(1.2, 0.8, 1.2);
	glm::vec3 center(0.5, 0.5, 0.5);
	glm::vec3 up(0, 1, 0);
	glm::mat4 m_modelViewMatrix = glm::lookAt(eye, center, up);
	glm::mat4 m_projectionMatrix = glm::perspective(1.0, 1.333, -10.0, 10.0);
	//glLoadIdentity();
	//gluLookAt(1, 1, 1, 0.5, 0.5, 0.5, 0, 1, 0);
	//gluLookAt(0, 0, 0, 0.25, 0.25, 0.25, 0, 1, 0);
	//glEnableVertexAttribArray(0);
	//GLuint VertexArrayID;
	//glGenVertexArrays(1, &VertexArrayID);
	//glBindVertexArray(VertexArrayID);

	// from last week
	GLuint vbo[3];
	glGenBuffers(3, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//std::string vertex_shader;
	//std::string fragment_shader;

	//{std::ifstream inFile;
	//inFile.open("./vertex_shader.glsl");//open the input file
	//std::stringstream strStream;
	//strStream << inFile.rdbuf();//read the file
	//vertex_shader = strStream.str();//str holds the content of the file
	//std::cout << vertex_shader << std::endl;//you can do anything with the string!!!
	//}

	//{std::ifstream inFile;
	//inFile.open("./fragment_shader.glsl");//open the input file
	//std::stringstream strStream;
	//strStream << inFile.rdbuf();//read the file
	//fragment_shader = strStream.str();//str holds the content of the file
	//std::cout << fragment_shader << std::endl;//you can do anything with the string!!!
	//}

	// initialize shader programs
	// http://antongerdelan.net/opengl/hellotriangle.html
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	char const* vertex_source_pointer = vertex_shader.c_str();
	glShaderSource(vs, 1, &vertex_source_pointer, NULL);
	//glShaderSource(vs, 1, &vertex_shader, NULL);

	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	char const* fragment_source_pointer = fragment_shader.c_str();
	glShaderSource(fs, 1, &fragment_source_pointer, NULL);
	//glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glBindAttribLocation(shader_programme, 0, "a_pos");
	//glBindAttribLocation(shader_programme, 1, "a_color");
	glLinkProgram(shader_programme);

	// Check the link status
	GLint linked = 0;
	glGetProgramiv(shader_programme, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		GLint infoLen = 0;

		glGetProgramiv(shader_programme, GL_INFO_LOG_LENGTH, &infoLen);

		if (infoLen > 1)
		{
			char* infoLog = (char*)malloc(sizeof(char) * infoLen);

			glGetProgramInfoLog(shader_programme, infoLen, NULL, infoLog);
			printf("Error linking program:\n%s\n", infoLog);

			free(infoLog);
		}

		glDeleteProgram(shader_programme);
		return false;
	}

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // <- depth test

		// We are using built-in shaders (we cann't modify it)
		glUseProgram(shader_programme);	// activate your shader!

		// draw here
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer
		(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size (r, y, z)
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		//glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		//glEnableVertexAttribArray(1);
		//glVertexAttribPointer
		//(
		//	1,                  // attribute 1. Must match the layout in the shader.
		//	3,                  // size (x, y, z)
		//	GL_FLOAT,           // type
		//	GL_FALSE,           // normalized?
		//	0,                  // stride
		//	(void*)0            // array buffer offset
		//);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawElements(GL_QUADS, num_quads * 4, GL_UNSIGNED_INT, 0);

		//glDisableClientState(GL_COLOR_ARRAY);
		//glDisableClientState(GL_VERTEX_ARRAY);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glDeleteBuffersARB(3, vbo);

	glfwTerminate();

	return 0;
}

