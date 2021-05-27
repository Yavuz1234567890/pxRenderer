#pragma once

#ifdef __cplusplus
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <map>
	#include <hash_map>
	#include <unordered_map>
	#include <fstream>
	#include <cmath>
#endif

#if defined(_WIN32)
	#define WINDOWS
#elif defined(__linux__)
	#define LINUX
#elif defined(__APPLE__)
	#error Renderer not support this platform
#endif

#ifdef WINDOWS
	#define Cos(x)			std::cos(x)
	#define Sin(x)			std::sin(x)
	#define Tan(x)			std::tan(x)
	#define Atan(x)			std::atan(x)
	#define Atan2(y, x)		std::atan2(y, x)

	#if !defined(PX_IMPL_GLEW) | !defined(PX_IMPL_GLAD) | !defined(PX_IMPL_GLFW) | !defined(PX_IMPL_STBI_IMAGE)
		#ifdef __has_include
			#if __has_include(<GL/glew.h>)
				#define PX_IMPL_GLEW
			#elif __has_include(<glad/glad.h>)
				#define PX_IMPL_GLAD
			#elif __has_include(<GLFW/glfw3.h>)
				#define PX_IMPL_GLFW
<<<<<<< HEAD
			#elif __has_include(<stbi/stbi_image>)
=======
			#elif __has_include(<windows.h>)
				#define PX_IMPL_WIN32
			#elif __has_include(<stbi/stbi_image.h>)
>>>>>>> 3334489f8263426fd50f6e6eecba3a6e4193873a
				#define PX_IMPL_STBI_IMAGE
			#endif
		#endif
	#endif
	
	#ifndef PX_IMPL
		#define PX_IMPL
	#endif
	
	#ifdef PX_IMPL
		#if defined(PX_IMPL_GLEW)
			#include <GL/glew.h>
			#define GL_EXT_INIT()	glewInit()
		#elif defined(PX_IMPL_GLAD)
			#include <glad/glad.h>
				#if defined(PX_IMPL_GLFW)
					#define GL_EXT_INIT()	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)
				#endif
		#elif defined(PX_IMPL_GLFW)
			#include <GLFW/glfw3.h>
<<<<<<< HEAD
=======
		#elif defined(PX_IMPL_WIN32)
			#include <windows.h>
			#include <windowsx.h>
>>>>>>> 3334489f8263426fd50f6e6eecba3a6e4193873a
		#elif defined(PX_IMPL_STBI_IMAGE)
			#include <stbi/stbi_image.h>
		#endif
	#endif
#endif
