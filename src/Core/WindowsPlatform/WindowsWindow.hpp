#ifndef WINDOWS_WINDOW_GUARD
#define WINDOWS_WINDOW_GUARD

#include "Core/Windowing/Window.hpp"

#include <Windows.h>
#include <WinUser.h>

namespace SyrfusGameEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowProperties windowProps);
		~WindowsWindow();

		int DispatchEvents() override;

	private:
		WindowsWindow(const WindowsWindow& other) = delete;
		WindowsWindow& operator=(const WindowsWindow& other) = delete;
		WindowsWindow(WindowsWindow&&) = delete;
		WindowsWindow& operator=(WindowsWindow&&) = delete;

	private:
		HINSTANCE m_hInstance;
		HWND m_hWnd;
	};
}

#endif