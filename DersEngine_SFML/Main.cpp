#include "core\GameApplication.h"

using namespace DersEngine;
using namespace core;

int main(int c, char* args[])
{
	GameApplication game(800, 600, "DersEngine", false, false);
	std::unique_ptr<Scene> startScene = std::make_unique<Scene>("MainScene");
	GameApplication::LoadScene(std::move(startScene));
	game.Start();
	return 0;
}