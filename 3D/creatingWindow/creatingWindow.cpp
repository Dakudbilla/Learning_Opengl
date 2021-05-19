
#include <iostream>

#define GLEW_STATIC

#include <GL/glew.h>
  
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

//constant width and height values
const GLuint WIDTH = 800, HEIGHT = 600;

int main()
{
	//Initialize glfw
	glfwInit();

	//Hints on how window should be
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE
	);

	//Create glfw window
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "MY OWN WINDOW", nullptr, nullptr);

	//Make window context current
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	glewInit();

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	glViewport(0, 0, WIDTH, HEIGHT);




	//Game Loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClearColor(0.5f, 0.4f, 0.3f,0.7f);
		glClear(GL_COLOR_BUFFER_BIT);	
		glfwSwapBuffers(window);
		glfwSwapInterval(3);

	}

	glfwTerminate();
	return 0;
}


//Function to respond to key presses
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {

	if (key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}







