#include "SyrfusGameEngine.hpp"
#include <iostream>

class MyApplication : public SyrfusGameEngine::Application
{
public:
	MyApplication(const std::string& name = "Test Application") : Application(name) {}
	virtual ~MyApplication() = default;

	void init() override
	{

	}

	void shutdown() override
	{

	}

	void update() override
	{
		std::cout << "Update from SyrfusTestApp" << std::endl;
	}

};

int main()
{
	MyApplication app;
	SyrfusGameEngine::Engine::init(app);
	SyrfusGameEngine::Engine::run();
	SyrfusGameEngine::Engine::shutdown();
}