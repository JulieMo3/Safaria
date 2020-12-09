#ifndef DEF_JOUEUR
#define DEF_JOUEUR


#pragma once
#include "header.h"
#include "terrain.h"





using namespace std; 


class Joueur
{
public:
	Joueur();
	~Joueur();
	Joueur(std::string name, int statut);
	std::string GetName();
	int x;
	int y;
	int score;
	
	


protected:
	std::string name;
	int statut; //1 c'est un chasseur, 2 c'est un soigneur
	


};

class Chasseur : public Joueur
{
public:
	Chasseur();
	~Chasseur();
	int deplacementC(Terrain* tab);

private:
	int nb_piege;

};

class Soigneur : public Joueur
{
public:
	Soigneur(std::string name, int statut);
	~Soigneur();
	int deplacementS(Terrain* tab);

private:
	int nb_acceleration;
};






#endif 


