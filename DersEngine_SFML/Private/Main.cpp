#include "core\GameApplication.h"

using namespace DersEngine;
using namespace core;

int main(int c, char* args[])
{
	GameApplication app(800, 600, "DersEngine", false, false);
	std::unique_ptr<Scene> startScene = std::make_unique<Scene>("MainScene");
	GameApplication::LoadScene(std::move(startScene));
	app.Start();
	return 0;
}