//"Running Pepe" Created by Arkadiusz Mula
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
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
	bool zacznijLogike=false;

	if (!init(scena)) //Start up SDL and create window
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		
		if (!loadMedia(scena,background,police,character,cloud,background2)) //Load media
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
			std::vector<cClouds*> vecClouds;
			std::vector<LTexture*> vecBackgrounds;
			vecBackgrounds.push_back(backg1);
			vecBackgrounds.push_back(backg2);
			vecClouds.push_back(cloud1);
			vecClouds.push_back(cloud2);
			vecClouds.push_back(cloud3);
			vecClouds.push_back(cloud4);

			//adding objects to scene
			scena.addObjects(&character, vecClouds, &police, vecBackgrounds);

			bool quit = false; //Main loop flag
			
			
			SDL_Event e; //Event handler
			zacznijLogike = true;
			while (!quit) // while application is running
			{
				
				while (SDL_PollEvent(&e) != 0)
				{
				if (e.type == SDL_QUIT)
					{
						scena.zmienKoniec();
						quit = true;
					}
			/*	if (e.type == SDL_KEYDOWN)
					if (e.key.keysym.sym == SDLK_SPACE)
					{
						character.changeSkok();
						std::cout << "spacja" << std::endl;
					}*/
					
				}

				if (SDL_GetTicks()>500&&zacznijLogike==true)
				{
					gamelogic(100, &scena);//game logic
					drawing(100, &scena);//drawing
					zacznijLogike = false;
				}

				

				//Moving objects//
				/*character.jump();

				for (auto b : vecBackgrounds)
					b->moveBackground();
				police.movePolice();
				for (auto c : vecClouds)
					c->MoveClouds();

				//Collision detection//
				if (SDL_HasIntersection(character.getCollider(), police.getCollider()))
					std::cout << "Kolizja" << std::endl;*/

				//Start renderning//
				
				/*SDL_SetRenderDrawColor(scena.returnRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(scena.returnRenderer());
				for (auto b : vecBackgrounds)
				{
					b->render(scena.returnRenderer());
				}
				
				for (auto c:vecClouds)
				{
					c->render(scena.returnRenderer());
				} 
				character.render(scena.returnRenderer());
				police.render(scena.returnRenderer());
				SDL_RenderPresent(scena.returnRenderer());*/

				//scena.draw();
			}
				
			
			for (int i = 0; i < vecClouds.size(); i++)
				delete vecClouds[i];
			for (int i = 0; i < vecBackgrounds.size(); i++)
				delete vecBackgrounds[i];
		}
	}
	close(scena,background,police,character,cloud,background2);
	
	return 0;
}



//gdy przy funkcji gamelogic usune static to nie moge jej jeszcze raz wywolac