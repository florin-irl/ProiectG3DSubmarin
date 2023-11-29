#include <iostream>
#include <stdlib.h> // necesare pentru citirea shaderStencilTesting-elor

#include <iostream>
#include <glfw3.h>

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	GLFWwindow* window = glfwCreateWindow(800, 800, "Submarin", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "FAILED TO CREATE GLFW WINDOW!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwTerminate();
	return 0;
}
