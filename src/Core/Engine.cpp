#include "Core/Engine.hpp"
#include <iostream>
#include <chrono>
#include <thread>

namespace SyrfusGameEngine
{
	Engine* Engine::s_Instance = nullptr;

	int Engine::init(Application& app)
	{
		if (s_Instance)
			return -1;
		s_Instance = new Engine();
		s_Instance->m_App = &app;
		s_Instance->m_App->init();
		return 0;
	}

	int Engine::shutdown()
	{
		if (!s_Instance)
			return -1;
		s_Instance->m_App->shutdown();
		delete s_Instance;
		return 0;
	}

	int Engine::run()
	{
		s_Instance->m_Running = true;
		while (s_Instance->m_Running)
		{
			s_Instance->m_App->update();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		return 0;
	}

	int Engine::stop()
	{
		s_Instance->m_Running = false;
		return 0;
	}

	Engine::Engine()
	{

	}

	Engine::~Engine()
	{

	}

}