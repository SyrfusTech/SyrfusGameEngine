#ifndef WINDOW_MANAGER_GUARD
#define WINDOW_MANAGER_GUARD

#include "Core/Windowing/Window.hpp"

namespace SyrfusGameEngine
{
	class WindowManager
	{
	public:
		static int Init();
		static int Shutdown();

		static int CreateSyrfusWindow();
		static int DestroySyrfusWindow();

		static int DispatchEvents();

	private:
		WindowManager();
		~WindowManager();
		WindowManager(const WindowManager& other) = delete;
		WindowManager& operator=(const WindowManager& other) = delete;
		WindowManager(WindowManager&&) = delete;
		WindowManager& operator=(WindowManager&&) = delete;

	private:
		static WindowManager* s_Instance;
		Window* m_Window;
	};
}

#endif