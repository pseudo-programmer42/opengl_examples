#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

int main()
{
	glfwInit();

	glm::ivec2 windowSize = { 200, 150 };

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	int count = 0;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	GLFWmonitor* fullscreen_monitor = monitors[0];

	GLFWwindow* window = glfwCreateWindow(
		windowSize.x,
		windowSize.y,
		"triangle",
		fullscreen_monitor,
		nullptr
	);
	if (!window)
	{
		throw std::runtime_error("Failed to create window");
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		throw std::runtime_error("Failed to initialize GLAD");
	}

	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(window, true);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

}