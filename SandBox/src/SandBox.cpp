#include <Dusk.h>

class Sandbox : public Dusk::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Dusk::Application* Dusk::CreateApplication()
{
	return new Sandbox();
}