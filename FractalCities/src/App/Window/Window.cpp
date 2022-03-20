#include "Window.h"

FCWindow::FCWindow(const std::string& title) 
	: p_title(title) {
	window = NULL;
	p_renderer = NULL;
	running = true;
	error_state = 0;
}

FCWindow::~FCWindow(){
}

int32_t FCWindow::Init() {
	// Initialize OpenGL window
	window = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, p_title.c_str(), NULL, NULL);
	if (window == NULL)
		return printd("Failed to open GLFW window.", e_ErrorLevel::d_Error);

	p_renderer = new FCRenderer(window);
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK)
		return printd("Failed to initialize GLEW.", e_ErrorLevel::d_Error);

	// Ensure we can capture the keys being pressed
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	p_renderer->Init();

	std::string version;
	version = (char*)glGetString(GL_VERSION);
	printd(version, e_ErrorLevel::d_Info);
	return MainLoop();
	
}

int32_t FCWindow::MainLoop() {
	do {

		// Draw the things
		OnFrame();

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (HandleEvents());

	return Close();
}

void FCWindow::OnFrame() {
	p_renderer->Frame();
}

bool FCWindow::HandleEvents() {
	return glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0 && running;
}

int32_t FCWindow::Close() {
	running = false;
	glfwTerminate();
	return error_state;
}