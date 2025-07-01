#pragma once

#ifdef BH_PLATFORM_WINDOWS

extern Beehive::Application* Beehive::CreateApplication();

int main(int argc, char** argv)
{
	Beehive::Log::Init();
	BH_CORE_ERROR("error test");
	BH_CORE_DEBUG("debug test");
	BH_CORE_TRACE("trace test");
	BH_CORE_INFO("info test");
	BH_CORE_WARN("warn test");
	BH_CORE_CRITICAL("critical test");
	auto app = Beehive::CreateApplication();
	app->Run();
	delete app;
}

#endif
