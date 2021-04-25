#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED

#include "LittleThieve.h"
#include "TextureFuncs.h"
#include "Graphics.h"
#include "Alphabet.h"
#include "Audio.h"
#include "Timer.h"
#include "Game.h"
#include "Input.h"
#include "StartScreen.h"
#include "EndLevelScreen.h"
#include "InfoScreen.h"
#include "SelectLevelScreen.h"

class GameManager {
public:
    GameManager();
	~GameManager();

    Graphics graphics;
	Alphabet alphabet;
    Audio audio;
	bool mQuit;
	const int FRAME_RATE = 120;
	Timer* mTimer;

	SDL_Event events;
	Input input;
	Mouse mouse;

	SCREENS currentScreen  = start;
	SCREENS newScreen = currentScreen;

	Game game;
	StartScreen startScreen;
	InfoScreen infoScreen;
	SelectLevelScreen selectLevelScreen;
	EndLevelScreen endLevelScreen;

	int currentLevel = 1;
	int numberOfLevel = 3;

	void Run();

	void Update();
	void Render();

};

#endif // GAMEMANAGER_H_INCLUDED
