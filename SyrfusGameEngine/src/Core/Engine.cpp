#include "Engine.hpp"

#include <iostream>
#include <chrono>
#include <thread>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace SyrfusGameEngine
{
	Engine* Engine::s_Instance = nullptr;

	int Engine::Init(Application& app)
	{
		if (s_Instance)
			return -1;
		s_Instance = new Engine();
		s_Instance->m_AppStack.Push(&app);
		app.Init();
		return 0;
	}

	int Engine::Shutdown()
	{

		if (!s_Instance)
			return -1;
		for (Application* app : s_Instance->m_AppStack)
		{
			app->Shutdown();
		}
		delete s_Instance;
		return 0;
	}

	int Engine::Run()
	{

		s_Instance->m_Running = true;
		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			return -1;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		while (!glfwWindowShouldClose(window))
		{
			glClearColor(1.0f, 0.5f, 0.3f, 1.0f);
			/* Loop until the user closes the window */
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();

			for (Application* app : s_Instance->m_AppStack)
			{
				app->Update();
			}
		}
		glfwTerminate();
		return 0;
	}

	int Engine::Stop()
	{
		s_Instance->m_Running = false;
		return 0;
	}
}