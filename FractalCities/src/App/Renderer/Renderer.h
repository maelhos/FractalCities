#pragma once
#include "../../stdinc.h"
#include <time.h>

class FCRenderer
{
	const float positions[6] = {
		-0.5f, -0.3f,
		 0.5f, -0.3f,
		 0.0f,  0.6f
	};
private:
	GLFWwindow* p_window;
	uint32_t buffer;
	uint32_t fps;
	uint32_t ticks;
public:
	FCRenderer(GLFWwindow* window);
	~FCRenderer();
	void Init();
	void Frame();
private:

};

