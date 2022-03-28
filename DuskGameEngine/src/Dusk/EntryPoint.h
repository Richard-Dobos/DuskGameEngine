#pragma once

#ifdef DK_PLATFORM_WINDOWS

extern Dusk::Application* Dusk::CreateApplication();

int main(int argc, char** argv)
{

	auto Application = Dusk::CreateApplication();
	Application->Run();
	delete Application;
}

#endif