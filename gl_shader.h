#include <string>

namespace renderer
{
	struct shader_data
	{
		std::string vert_data = "";
		std::string frag_data = "";
	};

	class gl_shader
	{
	public:
		gl_shader() = default;
		virtual ~gl_shader() = default;

		void create();

		int uniform(const std::string& name);
		void set_float(const std::string& name, float var);
		void set_vec2(const std::string& name, float x, float y);
		void set_vec3(const std::string& name, float x, float y, float z);
		void set_vec4(const std::string& name, float x, float y, float z, float w);
		void set_mat4(const std::string& name, float* matPtr);

		void bind() const;
		void unbind() const;

		shader_data m_data;
	private:
		unsigned int program;

		void check_errors(unsigned int shader);
	};
}
