#shader vertex
#version 330 core


out uniform vec3 uColor;
void main() {

}


#shader fragment
#version 330 core

in vec3 uColor;

void main() {
	color = uColor;
}