#include "gl_mesh.h"

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

		void create_context();
		void draw_mesh(gl_mesh* mesh, const draw_mode& mode);
	};
}
