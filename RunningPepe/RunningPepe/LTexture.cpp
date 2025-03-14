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


void LTexture::setX(double _posX)
{
	posX = _posX;
}

void LTexture::moveX(int dx)
{
	posX = posX + dx;
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

/*Uint32 LTexture::PoliceMove(Uint32 interval, void*param)
{
	LTexture*self = reinterpret_cast<LTexture *>(param);
	self->movePolice();
	SDL_TimerID timerID = SDL_AddTimer(60, PoliceMove, self);
	return interval;
}*/

void LTexture::carSpeed()
{
	
		if (posX < (-mWidth))
			posX = 1280+mWidth;
		else
		{
			if (SDL_GetTicks() % (modulo * 1000) < 50)
			{
				dx = dx + 0.02;
				modulo += 3;
			}
			else
				posX = posX - dx;
		}
		
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