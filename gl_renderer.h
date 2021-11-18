#include "gl_mesh.h"
#include "gl_shader.h"

namespace renderer
{
	enum class draw_mode
	{
		ELEMENT,
		ARRAY
	};

	class gl_renderer
	{
	public:
		gl_renderer() = default;
		virtual ~gl_renderer() = default;

		static void create_context();
		static void draw_mesh(gl_mesh* mesh, const draw_mode& mode = draw_mode::ARRAY);
		static void draw_mesh_with_shader(gl_mesh* mesh, gl_shader* shader, const draw_mode& mode = draw_mode::ARRAY);
	};
}
