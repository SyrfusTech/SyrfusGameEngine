#ifndef WINDOW_GUARD
#define WINDOW_GUARD

#include <string>

namespace SyrfusGameEngine
{
	enum WindowState
	{
		Windowed = 0,
		FullScreen,
		Borderless
	};

	struct WindowProperties
	{
		std::string windowTitle;
		int xPos, yPos, width, height;
		WindowState state;
	};

	class Window
	{
	public:
		inline Window(WindowProperties windowProps) : m_WindowProps(windowProps) {}
		virtual ~Window() = default;

		virtual int DispatchEvents() = 0;

	protected:
		WindowProperties m_WindowProps;

	private:
		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;
		Window(Window&&) = delete;
		Window& operator=(Window&&) = delete;
	};
}

#endif