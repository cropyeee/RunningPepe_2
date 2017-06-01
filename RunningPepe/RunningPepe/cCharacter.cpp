#include "cCharacter.h"

cCharacter::~cCharacter()
{
	free();
}

cCharacter::cCharacter()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

cCharacter::cCharacter(double _posX, double _posY)
{
	posX = _posX;
	posY = _posY;
}


void cCharacter::changeSkok()
{
	if (skok==false)
		skok = true;
	else skok = false;
}

void cCharacter::changeOpadanie()
{
	if (opadanie == true)
		opadanie = false;
	else opadanie = true;
}

bool cCharacter::returnSkok()
{
	return skok;
}

bool cCharacter::returnOpadanie()
{
	return opadanie;
}

void cCharacter::jump(int czas)
{
	/*if (posY > 250)
		posY -= 1;
	if (posY <= 250 && posY > 130)
		posY -= 0.5;
	if (posY <= 200 && posY > 130)
		posY -= 0.25;
	if (posY <= 150 && posY > 130)
		posY -= 0.1;*/
	if (posY > 290 && opadanie == false)
		posY -= posY*0.002;
	if (posY <= 290 && posY > 190 && opadanie == false)
		posY -= posY*0.0015;
	if (posY <= 190 && posY > 140 && opadanie == false)
		posY -= posY*0.001;
	if (posY <= 140 && posY > 120 && opadanie == false)
		posY -= posY*0.0005;
	if (posY <= 120 && posY > 110 && opadanie == false)
		posY -= posY*0.0001;
	if (posY == 110)
		opadanie = true;
	if (posY >= 110 && posY < 112)
	{
		posY += posY*0.00005;
		opadanie = true;
	}
	if (posY >= 112 && posY < 120 && opadanie == true)
		posY += posY*0.0001;
	if (posY >= 120 && posY < 140 && opadanie == true)
		posY += posY*0.005;
	if (posY >= 140 && posY < 190 && opadanie == true)
		posY += posY*0.001;
	if (posY >= 190 && posY < 290 && opadanie == true)
		posY += posY*0.0015;
	if (posY >= 290 && posY < 470 && opadanie == true)
		posY += posY*0.002;
	if (posY == 470 && opadanie == true)
	{
		opadanie = false;
		skok = false;
	}


}


/*void cCharacter::jump()
{		
	if (down == false)
	{
		posY += VelY;
		if (posY < 130)
		{
			posY = 130;
			down = true;
		}
	}
	if (down == true)
	{
		posY += -VelY;
		if (posY > 470)
		{
			posY = 470;
			VelY = 0;
			down == false;
		}
	}
}
*/