#include <SDL.h>
#include <iostream>
#include "lesson02.h"

// Starts SDL and creates a window
bool init(SDL_Window*&, SDL_Surface*&, int, int);
// Loads media
bool loadMedia(SDL_Surface*&, std::string);
// Frees media and shutsdown SDL
void close(SDL_Surface*&, SDL_Window*&);

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gHelloWorld = nullptr;

int main(int argc, char* argv[]) {

	std::cout << "hello" << std::endl;

	if (!init(gWindow, gScreenSurface, SCREEN_WIDTH, SCREEN_HEIGHT)) {
		std::cout << "Failed to initialize!" << std::endl;
	}
	else {
		if (!loadMedia(gHelloWorld, "resources/hello_penguin.bmp")) {
			std::cout << "Failed to load media!" << std::endl;
		}
		else {
			// Apply image onto screen surface
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			std::cout << gScreenSurface << std::endl;
			std::cout << gHelloWorld << std::endl;
		}
	}

	SDL_Delay(5000);
	close(gHelloWorld, gWindow);

	return 0;
}