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

void Scena::addObjects(cCharacter *_bohater, std::vector<cClouds*> _chmury, std::vector<LTexture*> _cars, std::vector<LTexture*> _tla,LTexture *_celownik)
{
	bohater = *_bohater;
	chmury = _chmury;
	cars = _cars;
	tla = _tla;
	celownik = *_celownik;
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
	for (auto c : cars)
		c->render(gRenderer);
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

	for (auto c : cars)
	{
		c->carSpeed();	//przyspieszenie auta
	}//dodaj warunek ze jezeli auta sie zderzaja to wtedy dodaje sie np 200 do pozycji

	for (auto c : cars)
	{
		if (SDL_HasIntersection(c->getCollider(), (c + 1)->getCollider()))
			c->moveX(300);
	}
	
	

	for (auto c:chmury)//poruszanie chmurami
		c->MoveClouds();

	for (auto b : tla)
		b->moveBackground(); //poruszanie tlem

	if (bohater.returnSkok()==true) //skok
	{
		bohater.jump();
	}

	for (auto c : cars)
	{
		if (SDL_HasIntersection(bohater.getCollider(), c->getCollider())) //kolizja
		{
			//koniec = true;
			//std::cout << "Kolizja" << std::endl;
		}
	}
			
	
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

	

	for (auto c : cars)
		c->render(gRenderer);
	int x, y;
	SDL_GetMouseState(&x, &y);
	celownik.mousePos(x, y);
	celownik.render(gRenderer);

	SDL_RenderPresent(gRenderer);
	return interval;
}

void Scena::addPoints(int add)
{
	punkty += add;
	std::cout << punkty << std::endl;
}

void Scena::handleEvent(SDL_Event* e)
{
	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		std::cout << "Kliknieto " << x << " " << y << std::endl;
		if (bohater.returnSkok() == true)
		{
			for (auto c : cars)
			{
				if (x<(c->getX() + c->getWidth()) && x>c->getX() && y<c->getY() + c->getHeight() && y>c->getY() && (SDL_GetTicks() - CzasOstatniegoStrzalu) > 3000)
				{
					std::cout << "Trafiono auto" << std::endl;
					c->setX((rand() % 1000));
					punkty = punkty + 20;
					std::cout << punkty << std::endl;
					CzasOstatniegoStrzalu = SDL_GetTicks();
				}
			}
		}
	}
}
