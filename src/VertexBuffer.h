#pragma once
#include "VertexBufferLayout.h"
class VertexBuffer {
private:
	unsigned int m_Renderer_id;
public:
	VertexBuffer(const void* data,unsigned int size);
	~VertexBuffer();
	void Bind() const;
	void UnBind() const;
};
