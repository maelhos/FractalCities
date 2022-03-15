#include "App.h"

Application::Application(){
	mainWindow = new FCWindow(WINDOW_TITLE);
}

Application::~Application(){
	delete mainWindow;
}

int Application::Run(){
	if (!glfwInit())
		return printd("Failed to initialize GLFW.",e_ErrorLevel::d_Error);

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	return mainWindow->Init();
}