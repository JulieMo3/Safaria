
#include<thread>



#include "header.h"
#include "terrain.h"
#include "joueur.h"



using namespace std;

Joueur::Joueur() {

	this->name = "jean-michel crapaud";
	this->statut = 1;
	this->score = 0;
}

Joueur::~Joueur() {

}



Joueur::Joueur(std::string name, int statut) {
	this->name = name;
	this->statut = statut;
	this->score = 0;
	
}





std::string Joueur :: GetName() {
	return this->name;
}

Chasseur::Chasseur() {

	this->x = 0;
	this->y = 0;

}

Chasseur::~Chasseur() {

}

int Chasseur::deplacementC(Terrain* tab) {
	
	int ok = 0;
	int temp;
	cout << "1: piege  2: Deplacement" << endl;  //choix de l'action se deplacer de 1 ou poser un piege dans une case adjacente
	cin >> temp;
	if (temp == 2)     //implementation de la position en fonction du choix du joueur
	{
		cout << "1 : Haut   2 : Bas  3 : Gauche   4 : Droite" << endl; //choix position de déplacement
		while (ok == 0) {
			cin >> temp;
			switch (temp) {
			case 1:
				this->x--;
				if ((this->x < 0) && (tab->tab[this->x][this->y] != 2)) {
					this->x++;
					cout<<"impossible vous quittez le plateau, recommencez!"<< endl;
				}
				else {
					ok = 1;
					if (tab->tab[this->x][this->y] == 4) {
						this->score = this->score + 2;       // verification si on arrive sur une case animal, si oui implementation du score
					}
					if (tab->tab[this->x][this->y] == 5) {
						this->score = this->score + 3;
					}
					if (tab->tab[this->x][this->y] == 6) {
						this->score = this->score + 1;
					}
					tab->tab[this->x][this->y] = 1;
					tab->tab[this->x + 1][this->y] = 0;

				}
				break;
			case 2:
				this->x++;
				if ((this->x > 9) && (tab->tab[this->x][this->y] != 2)) {
					this->x--;
					cout<< "impossible vous quittez le plateau, recommencez!" << endl;
				}
				else {
					ok = 1;
					if (tab->tab[this->x][this->y] == 4) {                        // verification si on arrive sur une case animal, si oui implementation du score
						this->score = this->score + 2;
					}
					if (tab->tab[this->x][this->y] == 5) {
						this->score = this->score + 3;
					}
					if (tab->tab[this->x][this->y] == 6) {
						this->score = this->score + 1;
					}
					tab->tab[this->x][this->y] = 1;
					tab->tab[this->x - 1][this->y] = 0;
				}
				break;
			case 3:
				this->y--;
				if ((this->y < 0) && (tab->tab[this->x][this->y] != 2)) {
					this->y++;
					cout << "impossible vous quittez le plateau, recommencez! " << endl;
				}
				else {
					ok = 1;
					if (tab->tab[this->x][this->y] == 4) {                   // verification si on arrive sur une case animal, si oui implementation du score
						this->score = this->score + 2;
					}
					if (tab->tab[this->x][this->y] == 5) {
						this->score = this->score + 3;
					}
					if (tab->tab[this->x][this->y] == 6) {
						this->score = this->score + 1;
					}
					tab->tab[this->x][this->y] = 1;
					tab->tab[this->x][this->y + 1] = 0;
				}
				break;
			case 4:
				this->y++;
				if ((this->y > 9) && (tab->tab[this->x][this->y] != 2)) {
					this->y--;
					cout << "impossible vous quittez le plateau, recommencez! " << endl;
				}
				else {
					ok = 1;
					if (tab->tab[this->x][this->y] == 4) {                      // verification si on arrive sur une case animal, si oui implementation du score
						this->score = this->score + 2;
					}
					if (tab->tab[this->x][this->y] == 5) {
						this->score = this->score + 3;
					}
					if (tab->tab[this->x][this->y] == 6) {
						this->score = this->score + 1;
					}
					tab->tab[this->x][this->y] = 1;
					tab->tab[this->x][this->y - 1] = 0;
				}
				break;

			}

		}
		return 0;
	}
	if (temp == 1) {         //choix de positionnement du piege et implementation dans le tableau
		cout << "1 : Haut   2 : Bas    3 : Gauche   4 : Droite" << endl;
		while (ok == 0) {
			cin>> temp;
			switch (temp) {
			case 1:

				if (this->x == 0) {

					cout << "impossible vous quittez le plateau, recommencez!" << endl;
				}
				else {
					return 1;
				}
				break;
			case 2:

				if (this->x == 9) {

					cout << "impossible vous quittez le plateau, recommencez!" << endl;
				}
				else {
					return 2;
				}
				break;
			case 3:

				if (this->y == 0) {

					cout << "impossible vous quittez le plateau, recommencez!"  << endl;
				}
				else {
					return 3;
				}
				break;
			case 4:

				if (this->y == 9) {

					cout << "impossible vous quittez le plateau, recommencez! " << endl;
				}
				else {
					return 4;
				}
				break;

			}

		}
		return 0;
	}
	return 0;
}



Soigneur::Soigneur(std::string name, int statut) {

	this->x = 9;
	this->y = 9;
}

Soigneur::~Soigneur() {

}

int Soigneur::deplacementS(Terrain* tab) {

		int ok = 0;
		int temp;
		int block = 0;
		cout << "1: boost \n2: Deplacement" << endl;  //choix de l'action se deplacer de 1 ou poser un piege dans une case adjacente
		cin >> temp;
		if (temp == 2)     //implementation de la position en fonction du choix du joueur
		{
			cout<< "1 : Haut \n2 : Bas\n3 : Gauche \n4 : Droite" << endl; //choix position de deplacement
			while (ok == 0) {
				cin >> temp;
				switch (temp) {
				case 1:
					
					this->x--;
					if ((this->x < 0) && (tab->tab[this->x][this->y] != 2)) {
						this->x++;
						cout << "impossible vous quittez le plateau, recommencez! " << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {
							this->score = this->score + 2;       // verification si on arrive sur une case animal, si oui implementation du score
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x + 1][this->y] = 0;

					}
					break;
				case 2:
					this->x++;
					if ((this->x > 9) && (tab->tab[this->x][this->y] != 2)) {
						this->x--;
						cout << "impossible vous quittez le plateau, recommencez! " << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {                        // verification si on arrive sur une case animal, si oui implementation du score
							this->score = this->score + 2;
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x - 1][this->y] = 0;
					}
					break;
				case 3:
					this->y--;
					if ((this->y < 0) && (tab->tab[this->x][this->y] != 2)) {
						this->y++;
						cout << "impossible vous quittez le plateau, recommencez!"  << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {                   // verification si on arrive sur une case animal, si oui implementation du score
							this->score = this->score + 2;
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x][this->y + 1] = 0;
					}
					break;
				case 4:
					this->y++;
					if ((this->y > 9) && (tab->tab[this->x][this->y] != 2)) {
						this->y--;
						cout << "impossible vous quittez le plateau, recommencez!" << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {                      // verification si on arrive sur une case animal, si oui implementation du score
							this->score = this->score + 2;
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x][this->y - 1] = 0;
					}
					break;

				}

			}

		}
		if (temp == 1)  // deplacement d'une case dans une direction choisi

		{
			cout << "1 : Haut \n2 : Bas\n3 : Gauche \n4 : Droite" << endl; //choix position de deplacement
			while (ok == 0) {
				cin >> temp;
				switch (temp) {
				case 1:
					this->x--;
					this->x--;
					if ((this->x < 0) && (tab->tab[this->x][this->y] != 1)) {
						this->x++;
						cout << "impossible vous quittez le plateau, recommencez! " << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {
							this->score = this->score + 2;       // verification si on arrive sur une case animal, si oui implementation du score
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x + 2][this->y] = 0;

					}
					break;
				case 2:
					this->x++;
					this->x++;
					if ((this->x > 9) && (tab->tab[this->x][this->y] != 1)) {
						this->x--;
						cout << "impossible vous quittez le plateau, recommencez!" << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {                        // verification si on arrive sur une case animal, si oui implementation du score
							this->score = this->score + 2;
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x - 2][this->y] = 0;
					}
					break;
				case 3:
					this->y--;
					this->y--;

					if ((this->y < 0) && (tab->tab[this->x][this->y] != 1)) {
						this->y++;
						cout << "impossible vous quittez le plateau, recommencez!"  << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {                   // verification si on arrive sur une case animal, si oui implementation du score
							this->score = this->score + 2;
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x][this->y + 2] = 0;
					}
					break;
				case 4:
					this->y++;
					this->y++;
					if ((this->y > 9) && (tab->tab[this->x][this->y] != 1)) {
						this->y--;
						cout << "impossible vous quittez le plateau, recommencez! " << endl;
					}
					else {
						ok = 1;
						if (tab->tab[this->x][this->y] == 4) {                      // verification si on arrive sur une case animal, si oui implementation du score
							this->score = this->score + 2;
						}
						if (tab->tab[this->x][this->y] == 5) {
							this->score = this->score + 3;
						}
						if (tab->tab[this->x][this->y] == 6) {
							this->score = this->score + 1;
						}
						tab->tab[this->x][this->y] = 2;
						tab->tab[this->x][this->y - 2] = 0;
					}
					break;

				}


			}

		}
		return block;
	
}

