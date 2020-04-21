#pragma once
#include <SDL.h>
#include "Character.h"
#include "Commons.h"
#include "GameScreen.h"

class Texture2D;

class Character;


class GameScreenLevel1 : GameScreen {
	private:
		Texture2D* mBackgroundTexture;
		bool SetUpLevel();
		Character* myCharacter;


	public:
		GameScreenLevel1(SDL_Renderer* renderer);
		~GameScreenLevel1();

		void Render();
		void Update(float deltaTime,SDL_Event e);
};
