#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
Shader::Shader(const std::string filepath)
{
	ShaderStrings values=parseShader(filepath);
	std::cout << values.vertexshader << std::endl;

}

Shader::~Shader()
{
}

ShaderStrings Shader::parseShader(const std::string filepath)
{
	std::ifstream stream(filepath);

	std::string line;
	std::stringstream strings[2];

	enum class ShaderType {
		NONE=-1 , VERTEX=0, FRAGMENT=1
	};

	ShaderType shaderType = ShaderType::NONE;

	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex")) {
				shaderType = ShaderType::VERTEX;
				strings[(int)shaderType] << line << '\n';
			}
			else if (line.find("fragment") != (std::string::npos))
			{
				shaderType = ShaderType::FRAGMENT;
				strings[(int)shaderType] << line << '\n';
			}
		}
		else {
			strings[(int)shaderType] << line << '\n';
		}
	}
	 
	return { strings [0].str(),strings [1].str()};

}
