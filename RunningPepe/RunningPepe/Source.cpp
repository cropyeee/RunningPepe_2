//"Running Pepe" Created by Arkadiusz Mula
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>
#include "Scena.h"
#include "Funkcje.h"
//#include "LTexture.h"
//#include "cClouds.h"
//#include "cCharacter.h"



int main(int argc, char* args[])
{
	//Creating models;
	Scena scena;
	cCharacter character(0, 470);
	LTexture background(0,0);
	LTexture background2(1280,0);
	LTexture police(1120, 530);
	
	cClouds cloud(1000, 100);
	LTexture crosshair(1, 0);
	//int czas = -3000;
	bool zacznijLogike=false;

	if (!init(scena)) //Start up SDL and create window
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		LTexture tekst(1, 0);
		if (!loadMedia(scena,background,police,character,cloud,background2,crosshair,tekst)) //Load media
		{
			std::cout << "Failed to load media!" << std::endl;
		}
		else
		{
			//creating additional objects;
			cClouds *cloud1 = new cClouds(600, 120,cloud.getTexture(),cloud.getWidth(),cloud.getHeight());
			cClouds *cloud2=new cClouds(205, 49, cloud.getTexture(),cloud.getWidth(),cloud.getHeight());
			cClouds *cloud3=new cClouds(1301, 30, cloud.getTexture(), cloud.getWidth(), cloud.getHeight());
			cClouds *cloud4 = new cClouds(1000, 100, cloud.getTexture(), cloud.getWidth(), cloud.getHeight());
			LTexture *backg1 = new LTexture(0, 0, background.getTexture(), background.getWidth(), background.getHeight());
			LTexture *backg2 = new LTexture(1280, 0, background2.getTexture(), background2.getWidth(), background2.getHeight());
			LTexture *police1 = new LTexture(1120, 530, police.getTexture(), police.getWidth(), police.getHeight());
			LTexture *police2 = new LTexture(8000, 530, police.getTexture(), police.getWidth(), police.getHeight());

			std::vector<cClouds*> vecClouds;
			std::vector<LTexture*> vecBackgrounds;
			std::vector<LTexture*> vecPolice;
			
			vecPolice.push_back(police1);
			vecPolice.push_back(police2);
			vecBackgrounds.push_back(backg1);
			vecBackgrounds.push_back(backg2);
			vecClouds.push_back(cloud1);
			vecClouds.push_back(cloud2);
			vecClouds.push_back(cloud3);
			vecClouds.push_back(cloud4);
			

			//adding objects to scene
			scena.addObjects(&character, vecClouds, vecPolice, vecBackgrounds,&crosshair,&tekst);

			bool quit = false; //Main loop flag
			
			
			SDL_Event e; //Event handler
			zacznijLogike = true; //starting logic after everything is loaded.
			srand(time(NULL));
			while (!quit) // while application is running
			{
				
				while (SDL_PollEvent(&e) != 0)
				{
				if (e.type == SDL_QUIT)
					{
						scena.zmienKoniec();
						quit = true;
					}
				scena.handleEvent(&e); //mouse clicking;
				
				}
				
				if (SDL_GetTicks()>500&&zacznijLogike==true)
				{
					gamelogic(100, &scena);//game logic
					drawing(100, &scena);//drawing
					zacznijLogike = false;
				}

			/*	if (SDL_GetTicks()>500&&SDL_GetTicks() % 1000 == 0)
				{
					scena.addPoints();
					std::cout << SDL_GetTicks() << std::endl;
				}*/

				//if (scena.czyKoniec() == true)
				//	quit = true; 
				
				
			}
				
			
			for (int i = 0; i < vecClouds.size(); i++)
				delete vecClouds[i];
			for (int i = 0; i < vecBackgrounds.size(); i++)
				delete vecBackgrounds[i];
			for (int i = 0; i < vecPolice.size(); i++)
				delete vecPolice[i];
		}
		close(scena, background, police, character, cloud, background2, crosshair, tekst);
	}
	
	
	return 0;
}



//1) gra zawiesza sie na amen po kilkunastu skokach 
//2) gra zaczyna strasznie lagowac gdy auta jada szybko
//3) dynamiczne wyswietlanie tekstu