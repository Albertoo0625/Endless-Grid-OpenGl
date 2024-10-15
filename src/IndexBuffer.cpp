#include "IndexBuffer.h"
#include "GLEW/include/glew.h"
#include "GLFW/include/glfw3.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int count)
	:m_Renderer_id(0),m_count(0)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	glGenBuffers(1, &m_Renderer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Renderer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_Renderer_id);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Renderer_id);
}

void IndexBuffer::UnBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
