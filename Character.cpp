#include "Character.h"
#include "Texture2D.h"

Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D startPosition,FACING mfacingDirection)
{
	mRenderer = renderer;
	startPosition  = mPosition;



	mMovingLeft = false;
	mMovingRight = false;

	mTexture = new Texture2D(renderer);
	if (!mTexture->LoadFromFile(imagePath))
	{
		std::cout << "Character not loaded!" << std::endl;
	}

	setPosition(mPosition);
}

void  Character::MoveLeft(float deltaTime) {
	mfacingDirection = FACING_LEFT;
}

void Character::MoveRight(float deltaTime) {
	mfacingDirection = FACING_RIGHT;

}

void Character::Render() {

	if (mfacingDirection == FACING_RIGHT) {
		mTexture->Render(Vector2D(), SDL_FLIP_NONE);
	}

	if (mfacingDirection == FACING_LEFT) {
		mTexture->Render(Vector2D(), SDL_FLIP_HORIZONTAL);
	}
}

void Character::setPosition(Vector2D newPosition)
{
	newPosition = mPosition;
}

Vector2D Character::GetPosition()
{
	return mPosition;
}

void Character::Update(float deltaTime, SDL_Event e) {
	if (mMovingLeft) {
		MoveLeft(deltaTime);
	}
	else if (mMovingRight) {
		MoveLeft(deltaTime);
	}

	switch (e.type) {
	case SDL_KEYUP:
		switch (e.key.keysym.sym) {
		case SDLK_a:
			mPosition.x -= deltaTime;
			break;
		case SDLK_d:
			mPosition.x += deltaTime;
		default:
			break;
		}
		break;

	default:
		break;
	}

}

Character::~Character() {
	delete mRenderer;
	mRenderer = NULL;
	delete mTexture;
	mTexture = NULL;
}