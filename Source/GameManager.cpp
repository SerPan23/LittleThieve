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
    Audio a(true);
    this->audio = a;

	mQuit = false;
	mTimer = Timer::Instance();

	Game game(graphics, alphabet, currentLevel, audio);
	this->game = game;

	this->startScreen = StartScreen(audio);
    this->infoScreen = InfoScreen(audio);
    this->selectLevelScreen = SelectLevelScreen(audio);
	this->endLevelScreen = EndLevelScreen(this->game.isWin, alphabet, audio);

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
        if(newScreen == play)
            game.gameReset(currentLevel);
    }
    switch(currentScreen)
    {
        case start:
            startScreen.update(mouse, events, newScreen);
            break;
        case info:
            infoScreen.update(mouse, events, newScreen);
            break;
        case selectLevel:
            selectLevelScreen.update(mouse, events, newScreen, currentLevel);
            break;
        case play:
            game.update(mTimer->DeltaTime(), input, newScreen);
            break;
        case levelend:
            endLevelScreen.isWin = game.isWin;
            endLevelScreen.update(mouse, events, newScreen, currentLevel, numberOfLevel);
            break;
    }
}
void GameManager::Render() {
    switch(currentScreen)
    {
        case start:
            startScreen.draw(graphics);
            break;
        case info:
            infoScreen.draw(graphics);
            break;
        case selectLevel:
            selectLevelScreen.draw(graphics);
            break;
        case play:
            game.draw(graphics);
            break;
        case levelend:
            endLevelScreen.draw(graphics);
            break;
    }
}

void GameManager::Run() {
    audio.playPausedMusic(audio.music);
    while(!mQuit) {
        input.beginNewFrame();
        mTimer->Update();
        while(SDL_PollEvent(&events)) {
            if(events.type == SDL_QUIT)
					mQuit = true;
            if (events.type == SDL_KEYDOWN)
				if (events.key.repeat == 0)
					input.keyDownEvent(events);
			else if (events.type == SDL_KEYUP)
				input.keyUpEvent(events);
			if(events.type == SDL_MOUSEMOTION)
            {
                mouse.pos.x = events.motion.x;
                mouse.pos.y = events.motion.y;
            }
            if(events.type == SDL_MOUSEBUTTONDOWN && events.button.button == SDL_BUTTON_LEFT)
                mouse.leftBtnPressed = true;
            else
                mouse.leftBtnPressed = false;
        }
        Update(); Render();
    }
}
