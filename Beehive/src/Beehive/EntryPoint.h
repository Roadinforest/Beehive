#pragma once

#ifdef BH_PLATFORM_WINDOWS

extern Beehive::Application* Beehive::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Beehive::CreateApplication();
	app->Run();
	delete app;

}

#endif
