#include "gl_mesh.h"
#include "gl_renderer_core.h"

namespace renderer
{
	void gl_mesh::disable(const mesh_data& data)
	{
		switch (data)
		{
		case mesh_type::TEX_COORDS:		tex_coords_enable	=	0; break;
		case mesh_type::INDICES:		indices_enable		=	0; break;
		}
	}

	void gl_mesh::enable(const mesh_data& data)
	{
		switch (data)
		{
		case mesh_type::TEX_COORDS:		tex_coords_enable	=	1; break;
		case mesh_type::INDICES:		indices_enable		=	1; break;
		}
	}

	void gl_mesh::create()
	{
		glGenVertexArrays(1, &vertex_array);
		glBindVertexArray(vertex_array);

		glGenBuffers(1, &vertex_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_data.vertices) * sizeof(float), m_data.vertices, GL_STATIC_DRAW);
		add_buffer(vertex_buffer, 0, 3);

		if (tex_coords_enable)
		{
			glGenBuffers(1, &texture_buffer);
			glBindBuffer(GL_ARRAY_BUFFER, texture_buffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(m_data.texture_coords) * sizeof(int), m_data.texture_coords, GL_STATIC_DRAW);
			add_buffer(texture_buffer, 1, 2);
		}

		if (indices_enable)
		{
			glGenBuffers(1, &index_buffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_data.indices) * sizeof(int), m_data.indices, GL_STATIC_DRAW);
		}
	}

	void gl_mesh::add_buffer(unsigned int buffer, int index, int size)
	{
		glBindVertexArray(0);
		glBindVertexArray(vertex_array);
		
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, 0, 0);
	}

	void gl_mesh::bind() const
	{
		glBindVertexArray(vertex_array);
	}

	void gl_mesh::unbind() const
	{
		if (!vertex_array)return;
		glBindVertexArray(0);
	}
}
