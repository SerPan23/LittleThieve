#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "LittleThieve.h"
#include "TextureFuncs.h"
#include "Graphics.h"
#include "Alphabet.h"
#include "Timer.h"
#include "Game.h"
#include "Input.h"
#include "StartScreen.h"
#include "EndLevelScreen.h"

class GameManager {
public:
    GameManager();
	~GameManager();

    Graphics graphics;
	Alphabet alphabet;
	bool mQuit;
	const int FRAME_RATE = 120;
	Timer* mTimer;

	SDL_Event events;
	Input input;
	Vector2 mouse;

	SCREENS currentScreen;
	SCREENS newScreen;

	Game game;
	StartScreen startScreen;
	EndLevelScreen endLevelScreen;


	void Run();

	void Update();
	void Render();

};

#endif // GAMEMANAGER_H_INCLUDED
