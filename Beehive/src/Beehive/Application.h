#pragma once

#include "Core.h"
#include "Events/Event.h"

#include <iostream>

namespace Beehive
{
	class BH_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}
