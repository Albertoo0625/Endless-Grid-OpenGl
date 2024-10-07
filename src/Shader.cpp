#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& filepath)
	:m_Renderer_Id(0),m_Filepath(filepath),m_LocationCache(0)
{
	ShaderStrings source=parseShader(filepath);
	m_Renderer_Id = createShader(source.vertexshader, source.fragmentshader);
}

Shader::~Shader()
{
	glDeleteProgram(m_Renderer_Id);
}

void Shader::Bind() const
{
	glUseProgram(m_Renderer_Id);
}

void Shader::UnBind() const
{
	glUseProgram(0);
}

ShaderStrings Shader::parseShader(const std::string& filepath)
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
			if (line.find("vertex") != (std::string::npos)) {
				shaderType = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != (std::string::npos))
			{
				shaderType = ShaderType::FRAGMENT;
			}
		}
		else {
			strings[(int)shaderType] << line << '\n';
		}
	}
	 
	return { strings [0].str(),strings [1].str()};

}

unsigned int Shader::createShader(const std::string& vertexshader, const std::string& fragmentshader)
{
	unsigned int program = glCreateProgram();
	unsigned int vertexprogram = compileShader(GL_VERTEX_SHADER, vertexshader);
	unsigned int fragmentprogram = compileShader(GL_VERTEX_SHADER, fragmentshader);

	glAttachShader(program, vertexprogram);
	glAttachShader(program, fragmentprogram);
	glLinkProgram(program);
	glValidateProgram(program);

	return program;
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

int Shader::GetUniform(const std::string& name)
{
	if (m_LocationCache.find(name) != m_LocationCache.end()) {
		return m_LocationCache[name];
	}
	unsigned int location= glGetUniformLocation(m_Renderer_Id, name.c_str());
	if (location == -1) {
		std::cout << "uniform does not exist" << std::endl;
	}
	return location;
}
