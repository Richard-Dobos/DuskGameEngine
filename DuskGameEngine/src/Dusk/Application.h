#pragma once

#include"Core.h"

namespace Dusk
{
	class DUSK_API Application
	{
	public:
		Application();
		virtual ~Application();


		void Run();
	};

	Application* CreateApplication();
}

