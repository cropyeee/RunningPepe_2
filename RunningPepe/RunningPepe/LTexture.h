#ifndef LTEXTURE_H
#define LTEXTURE_H


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>




class LTexture{
public:
	LTexture();
	LTexture(double _posX, double _posY);
	LTexture(double _posX, double _posY, SDL_Texture* _texture, int _width, int _height);
	~LTexture();

	bool loadFromFile(std::string path, SDL_Renderer *Renderer);

	void free();
	void moveX(int dx);
	void setX(double _posX);

	void carSpeed();
	void moveBackground();

	void render(SDL_Renderer *Renderer);

	int getWidth();
	int getHeight();
	double getX();
	double getY();
	SDL_Rect* getCollider();
	SDL_Texture* getTexture();
protected:
	SDL_Texture* mTexture;
	SDL_Renderer* gRenderer;

	int mWidth;
	int mHeight;
	double dx = 0.1;
	int modulo = 1;
	double posX;
	double posY;
	double VelY=0;
	SDL_Rect Collider;
	double posPoliceX;
};

#endif