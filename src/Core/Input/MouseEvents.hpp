#ifndef MOUSE_EVENTS_GUARD
#define MOUSE_EVENTS_GUARD

#include "Event.hpp"

#include <sstream>

namespace SyrfusGameEngine
{
	enum MouseCode
	{
		UNDEFINED_BUTTON = 0x00,
		BUTTON_1 = 0x01,
		BUTTON_2 = 0x02,
		BUTTON_3 = 0x03,
		BUTTON_4 = 0x04,
		BUTTON_5 = 0x05,
		BUTTON_6 = 0x06,
		BUTTON_7 = 0x07,
		BUTTON_8 = 0x08,
		CONTROL_BREAK = 0x09,
		BUTTON_LEFT = BUTTON_1,
		BUTTON_RIGHT = BUTTON_2,
		BUTTON_MIDDLE = BUTTON_3
	};

	class MouseButtonDownEvent : public Event
	{
	public:
		MouseButtonDownEvent(const MouseCode code) : m_Button(code) {}
		~MouseButtonDownEvent() = default;

		inline MouseCode GetButton() const { return m_Button; }

		inline Event::Type GetType() const override { return Event::Type::MOUSE_BUTTON_DOWN; }
		inline Event::Category GetCategory() const override { return Event::Category::MOUSE; }

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonDownEvent: (" << m_Button << ")";
			return ss.str();
		}

	private:
		MouseButtonDownEvent(const MouseButtonDownEvent& other) = delete;
		MouseButtonDownEvent& operator=(const MouseButtonDownEvent& other) = delete;
		MouseButtonDownEvent(MouseButtonDownEvent&&) = delete;
		MouseButtonDownEvent& operator=(MouseButtonDownEvent&&) = delete;

	private:
		MouseCode m_Button;
	};

	class MouseButtonUpEvent : public Event
	{
	public:
		MouseButtonUpEvent(const MouseCode code) : m_Button(code) {}
		~MouseButtonUpEvent() = default;

		inline MouseCode GetButton() const { return m_Button; }

		inline Event::Type GetType() const override { return Event::Type::MOUSE_BUTTON_UP; }
		inline Event::Category GetCategory() const override { return Event::Category::MOUSE; }

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonUpEvent: (" << m_Button << ")";
			return ss.str();
		}

	private:
		MouseButtonUpEvent(const MouseButtonUpEvent& other) = delete;
		MouseButtonUpEvent& operator=(const MouseButtonUpEvent& other) = delete;
		MouseButtonUpEvent(MouseButtonUpEvent&&) = delete;
		MouseButtonUpEvent& operator=(MouseButtonUpEvent&&) = delete;

	private:
		MouseCode m_Button;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const uint16_t x, const uint16_t y) : m_X(x), m_Y(y) {}
		~MouseMovedEvent() = default;

		inline uint16_t GetX() const { return m_X; }
		inline uint16_t GetY() const { return m_Y; }

		inline Event::Type GetType() const override { return Event::Type::MOUSE_MOVE; }
		inline Event::Category GetCategory() const override { return Event::Category::MOUSE; }

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_X << ", " << m_Y << ")";
			return ss.str();
		}

	private:
		MouseMovedEvent(const MouseMovedEvent& other) = delete;
		MouseMovedEvent& operator=(const MouseMovedEvent& other) = delete;
		MouseMovedEvent(MouseMovedEvent&&) = delete;
		MouseMovedEvent& operator=(MouseMovedEvent&&) = delete;

	private:
		uint16_t m_X, m_Y;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const double xOffset, const double yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}
		~MouseScrolledEvent() = default;

		inline double GetXOffset() const { return m_XOffset; }
		inline double GetYOffset() const { return m_YOffset; }

		inline Event::Type GetType() const override { return Event::Type::MOUSE_SCROLL; }
		inline Event::Category GetCategory() const override { return Event::Category::MOUSE; }

		inline std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_XOffset << ", " << m_YOffset << ")";
			return ss.str();
		}

	private:
		MouseScrolledEvent(const MouseScrolledEvent& other) = delete;
		MouseScrolledEvent& operator=(const MouseScrolledEvent& other) = delete;
		MouseScrolledEvent(MouseScrolledEvent&&) = delete;
		MouseScrolledEvent& operator=(MouseScrolledEvent&&) = delete;

	private:
		double m_XOffset, m_YOffset;
	};
}

#endif