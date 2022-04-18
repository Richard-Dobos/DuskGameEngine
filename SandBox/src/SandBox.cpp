#include <Dusk.h>

class ExampleLayer : public Dusk::Layer
{
public:
	void OnUpdate()
	{
		DK_INFO("ExampleLayer::Update");
	}

	void OnEvent(Dusk::Event& event) override
	{
		DK_TRACE("{0}", event);
	}
};

class Sandbox : public Dusk::Application
{
public:
	Sandbox()
	{
		Dusk::ImGuiLayer* ImGuiLayer = new Dusk::ImGuiLayer();

		PushOverelay(ImGuiLayer);
	}

	~Sandbox()
	{

	}

};

Dusk::Application* Dusk::CreateApplication()
{
	return new Sandbox();
}