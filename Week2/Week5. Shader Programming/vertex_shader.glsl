#version 330

uniform mat4 transform;
uniform float Scale;

uniform mat4 m_modelViewMatrix;
uniform mat4 m_projectionMatrix;

in vec3 a_pos;

out vec4 v_color;

void main()
{
	gl_Position = vec4(a_pos * Scale, 1.0);
//	gl_Position = m_projectionMatrix * vec4(a_pos * Scale, 1.0);
	//gl_Position = transform * vec4(a_pos * Scale, 1.0);

	v_color = vec4(	a_pos, 1.0);
};