#include "gl_shader.h"
#include "gl_renderer_core.h"

namespace renderer
{
	void gl_shader::create()
	{
		program = glCreateProgram();
		if (!program)return;
		
		unsigned int vert = 0;
		const char* vertSrc = m_data.vert_data.c_str();
		vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert, 1, &vertSrc, NULL);
		glCompileShader(vert);
		check_errors(vert);
		glAttachShader(program, vert);

		unsigned int frag = 0;
		const char* fragSrc = m_data.frag_data.c_str();
		frag = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag, 1, &fragSrc, NULL);
		glCompileShader(frag);
		check_errors(frag);
		glAttachShader(program, frag);

		glLinkProgram(program);
		glValidateProgram(program);
	}

	int gl_shader::uniform(const std::string& name)
	{
		int location = glGetUniformLocation(program, name);
		if (!location)std::cerr << "[Shader Error] " << name << " var is not found" << std::endl;
		else return location;
		return 0;
	}

	void gl_shader::set_float(const std::string& name, float var)
	{
		glUniform1f(uniform(name), var);
	}

	void gl_shader::set_vec2(const std::string& name, float x, float y)
	{
		glUniform2f(uniform(name), x, y);
	}

	void gl_shader::set_vec3(const std::string& name, float x, float y, float z)
	{
		glUniform3f(uniform(name), x, y, z);
	}

	void gl_shader::set_vec4(const std::string& name, float x, float y, float z, float w)
	{
		glUniform4f(uniform(name), x, y, z, w);
	}

	void gl_shader::set_mat4(const std::string& name, float* matPtr)
	{
		glUniformMatrix4fv(uniform(name), GL_FALSE, matPtr);
	}

	void gl_shader::bind() const
	{
		glUseProgram(program);
	}

	void gl_shader::unbind() const
	{
		if (!program) return;
		glUseProgram(0);
	}

	void gl_shader::check_errors(unsigned int shader)
	{
		GLint success;
		GLchar infoLog[1024];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cerr << "[Shader Error] " << infoLog << std::endl;
		}
	}
}
