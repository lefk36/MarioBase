#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Constants.h"
#include "Texture2D.h"
#include "Commons.h"
#include <iostream>
#include "GameScreenManager.h"

using namespace::std;




// Globals 
GameScreenManager* gameScreenManager;

Uint32 goldTime;

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;



// Function Prototypes
bool InitSDL();
void CloseSDL();
bool Update();
void Render();
SDL_Texture* LoadFromFile(string Path);

int main(int argc, char* args[]) {
	// Check if SDL was set up correctly
	if (InitSDL()) {
		// Flag to check if we wish to quit

	}


	bool quit = false;

	// Set up the game Screen manager - start with Level1
	gameScreenManager = new GameScreenManager(gRenderer, SCREEN_LEVEL1);
	// set the start time
	goldTime = SDL_GetTicks();


	// Game Loop
	while (!quit) {
		Render();
		quit = Update();
	}



	// Close Window and free resources 
	CloseSDL();

	return 0;


}

bool InitSDL() {
	// Set up SDL 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << " SDL did not Initialize.Error : " << SDL_GetError();
		return false;
	}
	else {
		// All good so attempt to create the window
		gWindow = SDL_CreateWindow("Games Engine Creation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		// Did the window get created?
		if (gWindow == NULL) {
			// nope.
			cout << " Window was not created. Error : " << SDL_GetError();
			return false;
		}


		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);


		if (gRenderer != NULL) {
			// Initialize PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags)) {
				cout << " SDL.Image could not Initialize. Error: " << IMG_GetError() << endl;
				return false;
			}
			// Load the Background Texture.


		}
		else {
			cout << " Renderer could not initialize Error :" << SDL_GetError() << endl;
			return false;
		}


		return true;




	}
}


void CloseSDL() {
	// Release the Window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;



	// Release the Renderer.
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	// Quit SDL SubSystems 
	IMG_Quit();
	SDL_Quit();

	// destroy the game screen manager
	delete gameScreenManager;
	gameScreenManager = NULL;
}

bool Update() {
	// Get the new time
	Uint32 newTime = SDL_GetTicks();
	// Event Handler
	SDL_Event e;
	// Get the events
	SDL_PollEvent(&e);
	// Handle any events
	switch (e.type) {
		// Click the X. to quit
	case SDL_QUIT:
		return true;
		break;

	}
	gameScreenManager->Update((float)(newTime - goldTime) / 1000.0f, e);
	// Set the current time to be the old one
	goldTime = newTime;
	return false;
}


void Render() {

	//Clear the screen - Black
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	gameScreenManager->Render();

	SDL_RenderPresent(gRenderer);
}
