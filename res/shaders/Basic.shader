#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 shaderColor;


out vec4 uColor;

void main() {
	gl_Position = position;
	uColor = shaderColor;
}


#shader fragment
#version 330 core
layout(location = 0) out vec4 color;

in vec4 uColor;

void main() {
	color = uColor;
}