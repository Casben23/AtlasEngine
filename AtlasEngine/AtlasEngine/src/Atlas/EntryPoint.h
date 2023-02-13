#pragma once

#ifdef AT_PLATFORM_WINDOWS
	
extern Atlas::Application* Atlas::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Atlas::CreateApplication();
	app->Run();
	delete app;
}

#endif // AL_PLATFORM_WINDOWS