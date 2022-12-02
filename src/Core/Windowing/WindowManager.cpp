#include "WindowManager.hpp"

#if SYRFUS_GAME_ENGINE_WINDOWS
#include "Core/WindowsPlatform/WindowsWindow.hpp"
#elif SYRFUS_GAME_ENGINE_LINUX
#include "Core/LinuxPlatform/LinuxWindow.hpp"
#elif SYRFUS_GAME_ENGINE_MAC
#include "Core/MacPlatform/MacWindow.hpp"
#endif

#include "Core/Engine.hpp"

namespace SyrfusGameEngine
{
	WindowManager* WindowManager::s_Instance = nullptr;


	int WindowManager::Init()
	{
		if (s_Instance)
			return -1;
		s_Instance = new WindowManager();
		return 0;
	}

	int WindowManager::Shutdown()
	{
		if (!s_Instance)
			return -1;
		delete s_Instance;
		return 0;
	}

	int WindowManager::CreateSyrfusWindow()
	{
		WindowProperties windowProps = { "Syrfus Game Engine", 100, 100, 1720, 880, WindowState::Windowed };
#if SYRFUS_GAME_ENGINE_WINDOWS
		s_Instance->m_Window = new WindowsWindow(windowProps);
#elif SYRFUS_GAME_ENGINE_LINUX
		std::cout << "Linux currently not supported\n";
#elif SYRFUS_GAME_ENGINE_MAC
		std::cout << "Mac currently not supported\n";
#else
		std::cout << "No supported platform defined (check CMakeLists.txt)\n";
#endif
		if (s_Instance->m_Window)
			return 0;
		return -1;
	}

	int WindowManager::DestroySyrfusWindow()
	{
		if (s_Instance->m_Window)
		{
			delete s_Instance->m_Window;
			s_Instance->m_Window = nullptr;
		}
		Engine::Stop();
		return 0;
	}

	int WindowManager::DispatchEvents()
	{
		s_Instance->m_Window->DispatchEvents();
		return 0;
	}

	WindowManager::WindowManager()
		: m_Window(nullptr)
	{
	}

	WindowManager::~WindowManager()
	{
		DestroySyrfusWindow();
	}

}