#include "LTexture.h"

LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::LTexture(double _posX, double _posY, SDL_Texture* _texture, int _width, int _height)
{
	posX = _posX;
	posY = _posY;
	mTexture = _texture;
	mWidth = _width;
	mHeight = _height;
}


void LTexture::setX(double rand)
{
	posX = 1280 + mWidth + rand;
}

void LTexture::moveX(int dx)
{
	posX = posX - dx;
}

LTexture::LTexture(double _posX, double _posY)
{
	posX = _posX;
	posY = _posY;
}


LTexture::~LTexture()
{
	free();
}

double LTexture::getX()
{
	return posX;
}

double LTexture::getY()
{
	return posY;
}
bool LTexture::loadFromFile(std::string path, SDL_Renderer *Renderer)
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image " << IMG_GetError() << std::endl;
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));

		newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
		if (newTexture == NULL)
		{
			std::cout << "Unable to create texture" << SDL_GetError() << std::endl;
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

bool LTexture::loadFromRenderedText(int punkty, SDL_Renderer *Renderer)
{
	free();
	
	std::string points = std::to_string(punkty);
	TTF_Font* gFont = TTF_OpenFont("GoodDog.ttf", 24);
	SDL_Color textColor = { 255, 255, 255 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, points.c_str(), textColor);
	if (textSurface == NULL)
	{
		std::cout << "Unable to render text surface!" << std::endl;
	}
	else
	{
		mTexture = SDL_CreateTextureFromSurface(Renderer, textSurface);
		if (mTexture == NULL)
		{
			std::cout << "Unable to create texture from rendered text!" << std::endl;
		}
		else
		{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	return mTexture != NULL;
}

void LTexture::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
		posX = 0;
		posY = 0;
	}
}

void LTexture::render(SDL_Renderer *Renderer)
{
	
	SDL_Rect renderQuad = { posX, posY, mWidth, mHeight };
	Collider = renderQuad;
	SDL_RenderCopy(Renderer, mTexture, NULL, &renderQuad);
}



int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

SDL_Texture* LTexture::getTexture()
{
	return mTexture;
}


void LTexture::carSpeed()
{
	
		if (posX < (-mWidth))
			posX = 1280+mWidth+(rand()%1000);
		else
		{
			if ((SDL_GetTicks() - poprzedniePrzyspieszenie) > 10000)
			{
				dx = dx + 0.05;
				std::cout << "Przyspieszenie " << dx << std::endl;
				poprzedniePrzyspieszenie = SDL_GetTicks();
			}
			else
			{
				posX = posX - dx;
			}
		}
		/*else
		{
			if (SDL_GetTicks() % (modulo * 1000) < modulo * 50)
			{
				dx = dx + 0.05; //sprobuj uzaleznic to od tego ile razy auto wyjechalo z ekranu;
				std::cout << "Przyspieszono!" << dx << std::endl;
				modulo += 3;
			}
			else
				posX = posX - dx;
		}*/
		
}

SDL_Rect* LTexture::getCollider()
{
	return &Collider;
}

void LTexture::moveBackground()
{
	posX -= 0.02;
	if (posX < -mWidth)
		posX = 1280;
}

void LTexture::mousePos(double x, double y)
{
	posX = x-mWidth/2.0;
	posY = y-mHeight/2.0;
}

