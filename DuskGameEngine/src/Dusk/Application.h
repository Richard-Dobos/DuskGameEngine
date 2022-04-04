#pragma once

#include"Core.h"
#include"Window.h"

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
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Runnig = true;
	};

	Application* CreateApplication();
}

