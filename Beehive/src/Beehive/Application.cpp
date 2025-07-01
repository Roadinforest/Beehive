#include "Application.h"

#include "Beehive/Log.h"
#include "Beehive/Events/ApplicationEvent.h"

namespace Beehive
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			BH_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			BH_TRACE(e.ToString());
		}

		while (true);
		while (1);
	}
}
