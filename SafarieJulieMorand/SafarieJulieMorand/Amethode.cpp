#include "animaux.h"
#include "terrain.h"
#include "header.h"

using namespace std;

Animaux::Animaux() {

}

Animaux::Animaux(Terrain* tab) {

	srand(time(0));
	this->categorie = rand() % (3);     // placement d'un animal au hasard entre zebre==4  elephant==5   suricate==6    dans une position aleatoire
	this->posX = rand() % 10;
	this->posY = rand() % 10;
	while (tab->tab[this->posX][this->posY] != 0) {
		
		this->posX = rand() % 10;
		this->posY = rand() % 10;
	}
	switch (this->categorie) {
	case 0:
		tab->tab[this->posX][this->posY] = 4;
		break;
	case 1:
		tab->tab[this->posX][this->posY] = 5;
		break;
	case 2:
		tab->tab[this->posX][this->posY] = 6;
		break;
	}
	
}

Animaux::~Animaux() {

}







