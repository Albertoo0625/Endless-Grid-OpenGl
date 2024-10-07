#pragma once

#include <string>
#include <GLEW/include/glew.h>
#include <unordered_map>

struct ShaderStrings {
	std::string vertexshader;
	std::string fragmentshader;
};

class Shader {
private :
	unsigned int m_Renderer_Id;
	std::string m_Filepath;
	std::unordered_map<std::string, int>m_LocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();
	void Bind() const;
	void UnBind() const;
	ShaderStrings parseShader(const std::string& filepath);
	unsigned int createShader(const std::string& vertexshader, const std::string& fragmentshader);
	unsigned int compileShader(unsigned int type, const std::string& source);
	int GetUniform(const std::string& name);
};
