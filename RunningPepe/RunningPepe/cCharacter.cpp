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

void cCharacter::jump()
{
	
	/*if (posY > 290 && opadanie == false)
		posY -= posY*0.003;
	if (posY <= 290 && posY > 190 && opadanie == false)
		posY -= posY*0.0022;
	if (posY <= 190 && posY > 140 && opadanie == false)
		posY -= posY*0.0017;
	if (posY <= 140 && posY > 120 && opadanie == false)
		posY -= posY*0.001;
	if (posY <= 120 && posY > 110 && opadanie == false)
		posY -= posY*0.0004;
	if (posY == 110)
		opadanie = true;
	if (posY >= 110 && posY < 110.1)
	{
		posY += posY*0.00006;
		opadanie = true;
	}
	if (posY >= 110.1 && posY < 120 && opadanie == true)
		posY += posY*0.0004;
	if (posY >= 120 && posY < 140 && opadanie == true)
		posY += posY*0.001;
	if (posY >= 140 && posY < 190 && opadanie == true)
		posY += posY*0.0017;
	if (posY >= 190 && posY < 290 && opadanie == true)
		posY += posY*0.0022;
	if (posY >= 290 && posY <= 470 && opadanie == true)
		posY += posY*0.0025;
	if (posY >= 470 && opadanie == true)
	{

		std::cout << "Wyladowal" << std::endl;
		opadanie = false;
		skok = false;
	}*/
	if (posY > 290 && opadanie == false)
		posY -= posY*0.0035;
	if (posY <= 290 && posY > 270 && opadanie == false)
		posY -= posY*0.0022;
	if (posY <= 270 && posY > 230 && opadanie == false)
		posY -= posY*0.0017;
	if (posY <= 230 && posY > 200 && opadanie == false)
		posY -= posY*0.001;
	if (posY <= 200 && posY > 190 && opadanie == false)
		posY -= posY*0.0004;
	if (posY == 190)
		opadanie = true;
	if (posY >= 190 && posY < 190.1)
	{
		posY += posY*0.00006;
		opadanie = true;
	}
	if (posY >= 190.1 && posY < 185 && opadanie == true)
		posY += posY*0.0001;
	if (posY >= 185 && posY < 170 && opadanie == true)
		posY += posY*0.0005;
	if (posY >= 170 && posY < 200 && opadanie == true)
		posY += posY*0.0010;
	if (posY >= 200 && posY < 250 && opadanie == true)
		posY += posY*0.0013;
	if (posY >= 250 && posY <= 470 && opadanie == true)
		posY += posY*0.0015;
	if (posY >= 470 && opadanie == true)
	{

		//std::cout << "Wyladowal" << std::endl;
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