#ifndef EVENT_GUARD
#define EVENT_GUARD

#include <string>

namespace SyrfusGameEngine
{
	class Event
	{
	public:
		enum class Type
		{
			NONE = 0,
			WINDOW_CLOSE, WINDOW_RESIZE,
			KEY_DOWN, KEY_UP,
			MOUSE_BUTTON_DOWN, MOUSE_BUTTON_UP, MOUSE_MOVE, MOUSE_SCROLL
		};

		enum class Category
		{
			NONE = 0,
			WINDOW,
			KEYBOARD,
			MOUSE
		};

		Event() = default;
		virtual ~Event() = default;

		virtual Type GetType() const = 0;
		virtual Category GetCategory() const = 0;
		virtual std::string ToString() const = 0;

		inline bool IsInCategory(Category category) { return GetCategory() == category; }

		bool m_Handled = false;

	private:
		Event(const Event& other) = delete;
		Event& operator=(const Event& other) = delete;
		Event(Event&&) = delete;
		Event& operator=(Event&&) = delete;
	};
}

#endif