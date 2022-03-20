#pragma once
#include "../../stdinc.h"
#include "../Renderer/Renderer.h"

class FCWindow
{
private:
	const std::string p_title;
	bool running;
	int32_t error_state;

	GLFWwindow* window;
	FCRenderer* p_renderer;
public:
	FCWindow(const std::string& title);
	~FCWindow();

	int32_t Init();
	int32_t Close();
private:
	bool HandleEvents();
	int32_t MainLoop();
	void OnFrame();
};