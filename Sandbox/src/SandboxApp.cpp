#include <Beehive.h>

class Sandbox : public Beehive::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Beehive::Application* Beehive::CreateApplication()
{
	std::cout << "This is sandbox" << std::endl;
	
	return new Sandbox();
}
