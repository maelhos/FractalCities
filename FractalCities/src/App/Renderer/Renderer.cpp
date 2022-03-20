#include "Renderer.h"

FCRenderer::FCRenderer(GLFWwindow* window) :
	p_window(window) {
	buffer = 0;
	fps = 0;
	ticks = 0;
}

FCRenderer::~FCRenderer(){}

void FCRenderer::Init() {
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 2 * 3 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	ticks = clock();
	fps = 0;
	
	glClear(GL_COLOR_BUFFER_BIT);
}

void FCRenderer::Frame() {
	glDrawArrays(GL_TRIANGLES, 0, 3);


	// FPS Management
	if (clock()-ticks > CLOCKS_PER_SEC){
		printd(std::to_string(fps) + " FPS", e_ErrorLevel::d_Info);
		fps = 0;
		ticks = clock();
	}
	else {
		fps++;
	}
}