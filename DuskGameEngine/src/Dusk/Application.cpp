#include"dkpch.h"
#include "Application.h"

#include"Dusk/Log.h"

namespace Dusk
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		DK_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Runnig = false;
		return true;
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
