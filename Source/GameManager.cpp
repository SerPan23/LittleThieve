#include "GameManager.h"

GameManager::GameManager()
{
    SDL_Init(SDL_INIT_EVERYTHING);
	Graphics graphics(true);
	this->graphics = graphics;
	Input input;
	this->input = input;
	Alphabet alphabet;
    alphabet.loadAlphabet("..\\..\\Source\\Sprites\\alphabet\\alphabet_24px.png");
    this->alphabet = alphabet;
	mQuit = false;
	mTimer = Timer::Instance();

	currentScreen = start;
	newScreen = currentScreen;

	Game game(graphics, alphabet);
	this->game = game;

	this->startScreen = StartScreen();

	Run();
}

GameManager::~GameManager() {
    Timer::Release();
    mTimer = NULL;
}


void GameManager::Update() {
    if(newScreen != currentScreen)
    {
        currentScreen = newScreen;
    }
    switch(currentScreen)
    {
        case start:
            startScreen.update(mouse, events, newScreen);
            break;
        case play:
            game.update(mTimer->DeltaTime(), input);
            break;
    }
}
void GameManager::Render() {
    switch(currentScreen)
    {
        case start:
            startScreen.draw(graphics);
            break;
        case play:
            game.draw(graphics);
            break;
    }
}

void GameManager::Run() {

    while(!mQuit) {
        input.beginNewFrame();
        mTimer->Update();

        while(SDL_PollEvent(&events)) {
            if(events.type == SDL_QUIT) {

					mQuit = true;
            }
            if (events.type == SDL_KEYDOWN) {
				if (events.key.repeat == 0) {
					input.keyDownEvent(events);
				}
			}
			else if (events.type == SDL_KEYUP) {
				input.keyUpEvent(events);
			}
			if(events.type == SDL_MOUSEMOTION)
            {
                mouse.x = events.motion.x;
                mouse.y = events.motion.y;
            }
        }
        //if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)) {
            Update();
            Render();
        //}
    }
}