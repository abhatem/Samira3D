#include "RenderPass.h"
#include "Globals.h"
RenderPass::RenderPass()
{
	
}

void RenderPass::init(bool DEPTH)
{
	m_framebuffer = 0;
	glGenFramebuffers(1, &m_framebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);



	glGenTextures(1, &m_renderedTexture);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, m_renderedTexture);

	if (!DEPTH) {
		// Give an empty image to OpenGL ( the last "0" )
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, GLOBAL::width, GLOBAL::height, 0, GL_RGB, GL_FLOAT, 0);
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_, 800, 600, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, GLOBAL::width, GLOBAL::height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 800, 600, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	}

	

	if (!DEPTH) {
		// The depth buffer
		GLuint m_depthRenderbuffer;

		glGenRenderbuffers(1, &m_depthRenderbuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, m_depthRenderbuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, GLOBAL::width, GLOBAL::height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthRenderbuffer);

		glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_renderedTexture, 0);

		// Set the list of draw buffers.
		GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
		glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers
	}
	else {


		// The depth buffer
		//GLuint m_depthRenderbuffer;

		//glGenRenderbuffers(1, &m_depthRenderbuffer);
		//glBindRenderbuffer(GL_RENDERBUFFER, m_depthRenderbuffer);
		//glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, 800, 600);
		//glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthRenderbuffer);

		//glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, m_renderedTexture, 0);

		//// Set the list of draw buffers.
		//GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
		//glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers


		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
		glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, m_renderedTexture, 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);

	}
	unbind();
}

void RenderPass::bind()
{
	//bindTexture();
	glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
	glViewport(0, 0, GLOBAL::width, GLOBAL::height); // Render on the whole framebuffer, complete from the lower left corner to the upper right
	
}

void RenderPass::unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, GLOBAL::width, GLOBAL::height); // Render on the whole framebuffer, complete from the lower left corner to the upper right
}

void RenderPass::bindTexture(int order)
{
	glActiveTexture(GL_TEXTURE0 + order);
	glBindTexture(GL_TEXTURE_2D, m_renderedTexture);
}
