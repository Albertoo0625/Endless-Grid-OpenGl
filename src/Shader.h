#pragma once

#include <string>

struct ShaderStrings {
	std::string vertexshader;
	std::string fragmentshader;
};

class Shader {
private :
	unsigned int m_Renderer_Id;
	std::string m_Filepath;

public:
	Shader(const std::string filepath);
	~Shader();
	ShaderStrings parseShader(const std::string filepath);

};
