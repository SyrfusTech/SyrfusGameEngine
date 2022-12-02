#ifndef WINDOW_EVENTS_GUARD
#define WINDOW_EVENTS_GUARD

#include "Event.hpp"

#include <sstream>

namespace SyrfusGameEngine
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		~WindowCloseEvent() = default;

		inline Event::Type GetType() const override { return Event::Type::WINDOW_CLOSE; }
		inline Event::Category GetCategory() const override { return Event::Category::WINDOW; }

		inline std::string ToString() const override { return "WindowCloseEvent"; }
	
	private:
		WindowCloseEvent(const WindowCloseEvent& other) = delete;
		WindowCloseEvent& operator=(const WindowCloseEvent& other) = delete;
		WindowCloseEvent(WindowCloseEvent&&) = delete;
		WindowCloseEvent& operator=(WindowCloseEvent&&) = delete;
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}
		~WindowResizeEvent() = default;

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		inline Event::Type GetType() const override { return Event::Type::WINDOW_RESIZE; }
		inline Event::Category GetCategory() const override { return Event::Category::WINDOW; }

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

	private:
		WindowResizeEvent(const WindowResizeEvent& other) = delete;
		WindowResizeEvent& operator=(const WindowResizeEvent& other) = delete;
		WindowResizeEvent(WindowResizeEvent&&) = delete;
		WindowResizeEvent& operator=(WindowResizeEvent&&) = delete;

	private:
		unsigned int m_Width, m_Height;
	};
}

#endif