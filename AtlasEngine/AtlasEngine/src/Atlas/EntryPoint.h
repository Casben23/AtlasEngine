#pragma once

#ifdef AT_PLATFORM_WINDOWS
	
extern Atlas::Application* Atlas::CreateApplication();

int main(int argc, char** argv)
{
	Atlas::Log::Init();

	AT_CORE_INFO("WELCOME TO ATLAS!");

	auto app = Atlas::CreateApplication();
	app->Run();
	delete app;
}

#endif // AT_PLATFORM_WINDOWS
