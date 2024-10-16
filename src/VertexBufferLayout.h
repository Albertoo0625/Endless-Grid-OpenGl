#pragma once
#include <vector>
#include "GLEW/include/glew.h"
#include "GLFW/include/glfw3.h"

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned int normalized;
};
class VertexBufferLayout {
private:
	std::vector<VertexBufferElement>m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout():m_Stride(0){}

	template<typename T>
	void push(unsigned int count){}

	template<>
	void push<int>(unsigned int count) {
		m_Elements.push_back({ GL_INT, count, GL_FALSE });
		m_Stride = count * sizeof(int);
	}

	template<>
	void push<float>(unsigned int count) {
		m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride = count * sizeof(float);
	}

	template<>
	void push<char>(unsigned int count) {
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride = count * sizeof(GL_UNSIGNED_BYTE);
	}

	inline unsigned int GetStride() const { return m_Stride; }
	inline std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
};
