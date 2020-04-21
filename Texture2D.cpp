#include "Texture2D.h" 
#include <SDL_image.h>
#include <iostream>

using namespace::std;


Texture2D::Texture2D(SDL_Renderer* renderer) {
	mRenderer = renderer;
	
}
Texture2D::~Texture2D() {
	// Free up the memory
	Free();

	mRenderer = NULL;
};

bool Texture2D::LoadFromFile(string path) {

	//remove the memory for previous texture
	Free();

	// load the Image
	SDL_Surface* pSurface = IMG_Load(path.c_str());
	if (pSurface != NULL) {
		SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0, 0xFF, 0xFF));
		// create the texture from the pixels on the surface 
		mTexture = SDL_CreateTextureFromSurface(mRenderer, pSurface);
		if (mTexture == NULL) {
			cout << " Unable to crete texture from surface.Error: " << SDL_GetError() << endl;

		}
		else {
			mWidth = pSurface->w;
			mHeight = pSurface->h;
		}

		// remove the loade surface we now have the texture
		SDL_FreeSurface(pSurface);
	}
	else {
		cout << " Unable to create texture from Surface.Error:: " << SDL_GetError() << endl;
	}

	return mTexture != NULL;
}

void Texture2D::Free() {
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}


void Texture2D::Render(Vector2D newPosition, SDL_RendererFlip flip, double angle ) {
	 //Clear the screen - Black

	SDL_Rect renderLocation = { newPosition.x, newPosition.y, mWidth, mHeight };

	// Render to the screen 
	SDL_RenderCopyEx(mRenderer, mTexture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);
	


}



