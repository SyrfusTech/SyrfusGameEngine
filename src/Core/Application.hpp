#ifndef APPLICATION_GUARD
#define APPLICATION_GUARD

#include "Core/Input/Event.hpp"

#include <string>

namespace SyrfusGameEngine
{
	class Application
	{
	public:
		Application(const std::string& name = "Application") : m_Name(name) {}
		virtual ~Application() = default;

		virtual void Init() {}
		virtual void Shutdown() {}
		virtual void Update() {}
		virtual void HandleEvent(Event& e) {}

		const std::string& GetName() const { return m_Name; }

	private:
		Application(const Application& other) = delete;
		Application& operator=(const Application& other) = delete;
		Application(Application&&) = delete;
		Application& operator=(Application&&) = delete;

	private:
		std::string m_Name;
	};
}

#endif