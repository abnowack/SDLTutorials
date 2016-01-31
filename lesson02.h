#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

bool init(SDL_Window*& window, SDL_Surface*& screenSurface, int width, int height) {
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else {
		// Create Window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else {
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}

bool loadMedia(SDL_Surface*& imageSurface, std::string str) {
	bool success = true;

	// Loads a bitmap relative to the location of the executable
	imageSurface = SDL_LoadBMP(str.c_str());
	if (imageSurface == nullptr) {
		std::cout << "Unable to load image " << str << " SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}

void close(SDL_Surface*& screenSurface, SDL_Window*& window) {
	SDL_FreeSurface(screenSurface);
	screenSurface = nullptr;

	// SDL_DestroyWindow also destroys the screen surface
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}