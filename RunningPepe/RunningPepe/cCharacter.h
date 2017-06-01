#ifndef CCHARACTER_H
#define CCHARACTER_H

#include "LTexture.h"


class cCharacter :public LTexture{
public:
	cCharacter();
	~cCharacter();
	cCharacter::cCharacter(double _posX, double _posY);
	void jump();
	void changeSkok();
	void changeOpadanie();
	bool returnSkok();
	bool returnOpadanie();
	

private:
	bool skok = false;
	bool opadanie = false;
	
};
#endif
