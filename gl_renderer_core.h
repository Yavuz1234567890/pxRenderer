#pragma once

#ifdef PX_GL_RENDERER_ENGINE
	#include <cmath>

	#if defined(_WIN32)
		#define WINDOWS
	#elif defined(__linux__)
		#define LINUX
	#elif defined(__APPLE__) || defined(__MACH__)
		#define APPLE
	#elif defined(__ANDROID__)
		#define ANDROID
	#endif
	
	#if defined(WINDOWS) || defined(LINUX) || defined(APPLE) || defined(ANDROID)
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
				#elif __has_include(<stbi/stbi_image.h>)
					#define PX_IMPL_STBI_IMAGE
				#endif
			#endif
		#endif
		
		#ifndef PX_IMPL
			#define PX_IMPL
		#endif
		
		#ifdef PX_IMPL
			#if defined(PX_IMPL_GLFW)
				#include <GLFW/glfw3.h>
			#elif defined(PX_IMPL_GLEW)
				#define GLEW_STATIC
				#include <GL/glew.h>
				#define GL_EXT_INIT()	glewInit()
			#elif defined(PX_IMPL_GLAD)
				#include <glad/glad.h>
				#if !defined(PX_IMPL_GLFW)
				#define GL_EXT_INIT()	gladLoadGL()
				#else
				#define GL_EXT_INIT() gladLoadGLLoader(glfwGetProcAddress())
				#endif
			#elif defined(PX_IMPL_STBI_IMAGE)
				#include <stbi/stbi_image.h>
			#endif
		#endif
	#endif
#endif
