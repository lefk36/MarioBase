#pragma once
#include <SDL.h>
#include <iostream>
#include "Commons.h"

class Texture2D;

class Character {
	protected:
		SDL_Renderer* mRenderer;
		Vector2D mPosition;
		Texture2D* mTexture;

		virtual void MoveLeft(float deltaTime);
		virtual void MoveRight(float deltaTime);

	public:
		Character(SDL_Renderer* renderer, std::string  imagePath, Vector2D startposition,FACING mfacingDirection);
		~Character();

		virtual void Render();
		virtual void Update(float deltaTime, SDL_Event e);
		void setPosition(Vector2D newPosition);
		Vector2D GetPosition();
	private:
		FACING mfacingDirection;
		bool mMovingLeft;
		bool mMovingRight;
};