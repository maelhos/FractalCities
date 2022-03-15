#pragma once
#include "../../stdinc.h"

class FCWindow
{
private:
	const std::string p_title;
	GLFWwindow* window;
	bool running;
	int32_t error_state;
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