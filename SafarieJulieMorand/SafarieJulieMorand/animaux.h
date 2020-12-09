#ifndef DEF_ANIMAUX
#define DEF_ANIMAUX


#pragma once

#include "header.h"
#include "terrain.h"




using namespace std; 

class Animaux
{
public:
	Animaux();
	Animaux(Terrain* tab);
	~Animaux();
	int posX;
	int posY;

private:
	int categorie;

};


#endif
