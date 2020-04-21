#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "Character.h"


GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer) {
	SetUpLevel();
};


void GameScreenLevel1::Render() {
	// Draw the Background
	mBackgroundTexture->Render(Vector2D(), SDL_FLIP_NONE);

	// Draw the player Character
	myCharacter->Render();

}

bool GameScreenLevel1::SetUpLevel() {
	// Set up the player character
	myCharacter = new Character(mRenderer, "Images/Mario.png", Vector2D(64, 330), FACING_RIGHT);

	 //Set up the background
	mBackgroundTexture = new Texture2D(mRenderer);
	if (!mBackgroundTexture->LoadFromFile("Images/BackgroundMB.png")) {
		cout << " Failed to load background texture!";
		return true;
	}

	
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e) {

	myCharacter->Update(deltaTime, e);
}

GameScreenLevel1::~GameScreenLevel1() {
	delete mBackgroundTexture;
	mBackgroundTexture = NULL;

	delete myCharacter;
	myCharacter = NULL;


}