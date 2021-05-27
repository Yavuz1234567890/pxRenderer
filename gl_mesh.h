namespace renderer
{
	struct mesh_data
	{
		float* vertices = nullptr;
		float* texture_coords = nullptr;
		unsigned int* indices = nullptr;
	};

	enum class mesh_type
	{
		INDICES,
		TEX_COORDS
	};

	class gl_mesh
	{
	public:
		gl_mesh() = default;
		virtual ~gl_mesh() = default;

		void disable(const mesh_data& data);
		void enable(const mesh_data& data);
		void create();
		void add_buffer(unsigned int buffer, int index, int size);

		void bind() const;
		void unbind() const;

		mesh_data m_data;
	private:
		unsigned int vertex_array = 0, vertex_buffer = 0, index_buffer = 0, texture_buffer = 0;
		int tex_coords_enable = 0, indices_enable = 0;
	};
}
