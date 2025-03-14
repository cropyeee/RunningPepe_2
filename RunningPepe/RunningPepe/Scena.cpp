#include "Scena.h"


Scena::Scena()
{
	gRenderer = NULL;
	gWindow = NULL;
	koniec = false;
}

Scena::~Scena()
{

}

void Scena::createWindow()
{
	gWindow = SDL_CreateWindow("Running Pepe!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
}

void Scena::createRenderer()
{
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
}

void Scena::destroyRenderer()
{
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
}

void Scena::destroyWindow()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
}

SDL_Renderer* Scena::returnRenderer()
{
	return gRenderer;
}

SDL_Window* Scena::returnWindow()
{
	return gWindow;
}

int Scena::returnScreenHeight()
{
	return SCREEN_HEIGHT;
}

int Scena::returnScreenWidth()
{
	return SCREEN_WIDTH;
}

void Scena::addObjects(cCharacter *_bohater, std::vector<cClouds*> _chmury, LTexture *_car, std::vector<LTexture*> _tla)
{
	bohater = *_bohater;
	chmury = _chmury;
	car = *_car;
	tla = _tla;
}

void Scena::draw()
{
	//std::cout << "draw" << std::endl;
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
	for (auto b : tla)
	{
		b->render(gRenderer);
	}

	for (auto c : chmury)
	{
		c->render(gRenderer);
	}
	bohater.render(gRenderer);
	car.render(gRenderer);
	SDL_RenderPresent(gRenderer);
}

bool Scena::czyKoniec()
{
	return koniec;
}

void Scena::zmienKoniec()
{
	koniec =true;
}


Uint32 Scena::gamelogic(Uint32 interval)
{
	//std::cout << "gamelogic" << std::endl;
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_SPACE] && bohater.returnSkok() == false&&bohater.returnOpadanie()==false) // klikniecie spacji
	{
		
		bohater.changeSkok();
		currentKeyStates = SDL_GetKeyboardState(NULL);
	}

	car.carSpeed(); //przyspieszenie auta

	for (auto c:chmury)//poruszanie chmurami
		c->MoveClouds();

	for (auto b : tla)
		b->moveBackground(); //poruszanie tlem

	if (bohater.returnSkok()==true) //skok
	{
		bohater.jump();
	}

	if (SDL_HasIntersection(bohater.getCollider(), car.getCollider())) //kolizja
		//std::cout << "Kolizja" << std::endl; 
	
	return interval;

}

Uint32 Scena::draws(Uint32 interval)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
	for (auto b : tla)
	{
		b->render(gRenderer);
	}

	for (auto c : chmury)
	{
		c->render(gRenderer);
	}
	bohater.render(gRenderer);
	car.render(gRenderer);
	SDL_RenderPresent(gRenderer);
	return interval;
}

