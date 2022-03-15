#pragma once
#include "../stdinc.h"
#include "Window/Window.h"

class Application
{
public:
	Application();
	~Application();

	int32_t Run();
private:
	FCWindow* mainWindow;
};