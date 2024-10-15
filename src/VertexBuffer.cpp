#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	:m_Renderer_id(0)
{
	glGenBuffers(1,&m_Renderer_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_Renderer_id);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_Renderer_id);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_Renderer_id);
}

void VertexBuffer::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
