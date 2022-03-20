#include "App.h"

extern "C" {
	_declspec(dllexport) uint32_t NvOptimusEnablement = 1;
	_declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

Application::Application(){
	mainWindow = new FCWindow(WINDOW_TITLE);
}

Application::~Application(){
	delete mainWindow;
}
int Application::Run(){

	if (!glfwInit())
		return printd("Failed to initialize GLFW.",e_ErrorLevel::d_Error);

	return mainWindow->Init();
}