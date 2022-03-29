#include "Application.h"

#include"Dusk/Log.h"
#include"Events/ApplicationEvent.h"

namespace Dusk
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(720, 480);

		DK_CORE_ERROR(e);

		while (true);
	}
}
