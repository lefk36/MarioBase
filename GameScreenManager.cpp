#include "GameScreen.h"
#include "GameScreenLevel1.h"
#include "GameScreenManager.h"

GameScreenLevel1* tempScreen;

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen) {
	mRenderer = renderer;
	mCurrentScreen = NULL;
	// Ensure the first screen is set up
	ChangeScreen(startScreen);
}



void GameScreenManager::Render() {
	mCurrentScreen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e) {
	mCurrentScreen->Update(deltaTime, e);
}


void GameScreenManager::ChangeScreen(SCREENS newScreen) {
	//Clear up the old screen
	if (mCurrentScreen != NULL) {
		delete mCurrentScreen;
	}

	switch (newScreen) {
		case SCREEN_LEVEL1:
			tempScreen = new GameScreenLevel1(mRenderer);
			mCurrentScreen = (GameScreen*)tempScreen;
			tempScreen = NULL;
		break;
	}
	
}

GameScreenManager::~GameScreenManager() {
	mRenderer = NULL;
	delete mRenderer;
}