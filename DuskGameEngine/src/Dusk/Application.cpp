#include"dkpch.h"
#include "Application.h"

#include"Dusk/Log.h"
#include"Events/ApplicationEvent.h"

namespace Dusk
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(m_Window->GetHeight(), m_Window->GetHeight());

		while (m_Runnig)
		{
			m_Window->OnUpdate();
		}
	}
}
