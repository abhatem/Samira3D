#pragma once
#include <GL/glew.h>
class RenderPass {
public:
	RenderPass();
	void init(bool DEPTH = 0);
	void bind();
	void unbind();
	void bindTexture(int order = 0);
private:
	GLuint m_framebuffer;
	GLuint m_renderedTexture;
	GLuint m_depthRenderbuffer;

};