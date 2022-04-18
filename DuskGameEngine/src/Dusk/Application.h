#pragma once

#include"Core.h"

#include"Window.h"
#include"Dusk/LayerStack.h"
#include"Events/ApplicationEvent.h"

namespace Dusk
{
	class DUSK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverelay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Runnig = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

