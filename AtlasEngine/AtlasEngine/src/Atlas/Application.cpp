#include "atpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Atlas/Log.h"

namespace Atlas
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
			AT_CORE_TRACE(e);
		}
		else
		{
			AT_CORE_ERROR("Wrong Event For Application Category");
		}

		while (true);
	}
}