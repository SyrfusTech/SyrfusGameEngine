#include "SyrfusGameEngine.hpp"

#include <iostream>

class MyApplication : public SyrfusGameEngine::Application
{
public:
	MyApplication(const std::string& name = "Test Application") : Application(name) {}
	virtual ~MyApplication() = default;

	void Init() override
	{

	}

	void Shutdown() override
	{

	}

	void Update() override
	{

	}

	void HandleEvent(SyrfusGameEngine::Event& e)
	{
		std::cout << e.ToString() << std::endl;
	}

};

int main()
{
	MyApplication app;
	SyrfusGameEngine::Engine::Init(app);
	SyrfusGameEngine::Engine::Run();
	SyrfusGameEngine::Engine::Shutdown();
}