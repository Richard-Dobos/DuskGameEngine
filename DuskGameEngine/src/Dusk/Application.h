#pragma once

#include"Core.h"
#include"Window.h"

namespace Dusk
{
	class DUSK_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Runnig = true;
	};

	Application* CreateApplication();
}

