#include "Engine.hpp"

#include "Core/Windowing/WindowManager.hpp"
#include "Core/Input/KeyboardEvents.hpp"
#include "Core/Input/MouseEvents.hpp"
#include "Core/Input/WindowEvents.hpp"

#include <iostream>
#include <chrono>
#include <thread>

namespace SyrfusGameEngine
{
	Engine* Engine::s_Instance = nullptr;

	int Engine::Init(Application& app)
	{
		if (s_Instance)
			return -1;
		s_Instance = new Engine();
		WindowManager::Init();
		s_Instance->m_AppStack.Push(&app);
		app.Init();
		return 0;
	}

	int Engine::Shutdown()
	{
		WindowManager::Shutdown();

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
		WindowManager::CreateSyrfusWindow();

		s_Instance->m_Running = true;
		while (s_Instance->m_Running)
		{
			WindowManager::DispatchEvents();
			for (Application* app : s_Instance->m_AppStack)
			{
				app->Update();
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		return 0;
	}

	int Engine::Stop()
	{
		s_Instance->m_Running = false;
		return 0;
	}

	int Engine::DispatchEvent(Event& e)
	{
		if (e.GetType() == Event::Type::WINDOW_CLOSE)
		{
			s_Instance->m_Running = false;
			e.m_Handled = true;
		}
		for (Application* app : s_Instance->m_AppStack)
		{
			if (e.m_Handled)
				break;
			app->HandleEvent(e);
		}
		return 0;
	}
}