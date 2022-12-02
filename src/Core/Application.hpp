#ifndef APPLICATION_GUARD
#define APPLICATION_GUARD

#include <string>

namespace SyrfusGameEngine
{
	class Application
	{
	public:
		Application(const std::string& name = "Application") : m_Name(name) {}
		virtual ~Application() = default;

		virtual void init() {}
		virtual void shutdown() {}
		virtual void update() {}

		const std::string& getName() const { return m_Name; }

	private:
		std::string m_Name;
	};
}

#endif