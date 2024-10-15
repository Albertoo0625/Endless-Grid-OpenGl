#pragma once
#include "VertexBuffer.h"

class VertexArray {
private:
	unsigned int m_Renderer_id;
public:
	VertexArray();
	~VertexArray();
	void Bind() const;
	void UnBind() const;
	void addBuffer(const VertexBuffer& vb,const VertexBufferLayout& layout);
};