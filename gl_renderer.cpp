#include "gl_renderer.h"
#include "gl_renderer_core.h"

namespace renderer
{
	void gl_renderer::create_context()
	{
		GL_EXT_INIT();
	}

	void gl_renderer::draw_mesh(gl_mesh* mesh, const draw_mode& mode)
	{
		mesh->bind();

		switch (mode)
		{
		case draw_mode::ARRAY: glDrawArrays(GL_TRIANGLES, 0, sizeof(mesh->m_data.vertices));
		case draw_mode::ELEMENT: glDrawElements(GL_TRIANGLES, sizeof(mesh->m_data.indices), GL_UNSIGNED_INT, 0);
		}
	}
}
