#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;

	// Must call SDL_Init before any other SDL_() functions
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		// SDL_GetError() returns errors from within SDL_() functions
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else {
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			std::cout << "Window could not be created! SDL_Error: %s" << SDL_GetError() << std::endl;
		}
		else {
			// Get the Window screen surface
			screenSurface = SDL_GetWindowSurface(window);
			// Color it white
			SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			// Update the surface to display the color
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}