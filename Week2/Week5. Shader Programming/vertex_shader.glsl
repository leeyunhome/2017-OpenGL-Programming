#version 330

uniform float Scale;

//uniform mat4 modelViewMatrix;
//uniform mat4 projectionMatrix;

in vec3 a_pos;

out vec4 v_color;

void main()
{
	gl_Position = vec4(a_pos * Scale, 1.0);
	v_color = vec4(	a_pos, 1.0);
};