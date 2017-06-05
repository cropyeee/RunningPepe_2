#ifndef SCENA_H
#define SCENA_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"
#include "cClouds.h"
#include "cCharacter.h"



class Scena{
public:
	Scena();
	~Scena();
	SDL_Renderer* returnRenderer();
	SDL_Window* returnWindow();
	void createWindow();
	void createRenderer();
	void destroyWindow();
	void draw();
	Uint32 gamelogic(Uint32 interval);
	Uint32 draws(Uint32 interval);
	void destroyRenderer();
	void addObjects(cCharacter *_bohater, std::vector<cClouds*> _chmury, std::vector<LTexture*> _cars, std::vector<LTexture*> _tla,LTexture *_celownik);
	int returnScreenWidth();
	int returnScreenHeight();
	bool czyKoniec();
	void zmienKoniec();
protected:
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	bool koniec;
	SDL_Renderer* gRenderer;
	SDL_Window* gWindow;
	cCharacter bohater;
	LTexture celownik;
	std::vector<cClouds*> chmury;
	std::vector<LTexture*> tla;
	std::vector<LTexture*> cars;
};
#endif

