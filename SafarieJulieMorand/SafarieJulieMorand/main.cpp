#include "header.h"
#include "terrain.h"
#include "joueur.h"
#include "animaux.h"



using namespace std;
void affichage(Chasseur* c, Soigneur* s, Terrain* tab);
void main()
{
	int temp;
	int ok;

	std::string nom;
	Terrain *tab = new Terrain();
	/*tab->SetJoueur(new Joueur());
	cout << "donnez le nom du 2nd joueur" << endl;
	cin >> nom;
	tab->SetJoueur(new Joueur(nom, 2));*/
	int dr;
	int i;
	int j;
	int tour = 0;
	int sautTour = 0;
	tab->SetTab();
	Chasseur *j1 = new Chasseur();
	cout << "donnez le nom du 2nd joueur" << endl;
	cin >> nom;
	Soigneur *j2 = new Soigneur(nom, 2);
	tab->tab[j1->x][j1->y] = 1;
	tab->tab[j2->x][j2->y] = 2;
	affichage(j1, j2, tab);
	while ((j1->score != 20) || (j2->score != 20)) {
		//boucle qui lance le tour par tour et actions du jeu jusqu'a ce qu'un joueur
		if (tour % 6 == 0) {                                // atteigne le scar de 20 ou plus. Le premier qui depasse 20 points gagne.
			Animaux *bete = new Animaux(tab);                                // positionnement d'un animal au hasard entre zerbre elephant ou surricate tout les 6 tours(3 tour de chasseurs 3 tours de ranger)
		}
		if (tour % 2 == 0) {                                 //tour du chasseur
			cout << "Au tour du Chasseur!" << endl;
			j1->deplacementC(tab);
			dr = tab->tab[j1->x][j1->y];
			switch (dr) {                                    //placement du piege demander par le joueur dans la fonction deplacementC
			case 1:
				tab->tab[j1->x - 1][j1->y] = 3;
				break;
			case 2:
				tab->tab[j1->x + 1][j1->y] = 3;
				break;
			case 3:
				tab->tab[j1->x][j1->y - 1] = 3;
				break;
			case 4:
				tab->tab[j1->x][j1->y + 1] = 3;
			}
			if (sautTour == 1) {  //implementation du compteur afin qu'au prochain tour de boucle le ranger saute son tour
				tour++;
				sautTour = 0;
			}
		}
		else {     // tour du ranger (veto=ranger)
			cout << "Au tour du Soigneur!"<< endl;
			sautTour = j2->deplacementS(tab); // si le ranger tombe sur un piege il saute son tour, donc implement le saut de tour si sautTour==1
			cout<< j2->x  << endl;
			cout << j2->y << endl;
			if (sautTour == 1) {
				cout << "Le soigneur est piege!!! Il passera son tour!!!" << endl;
			}


		}

		tour++;
		affichage(j1, j2, tab);

	}
	ofstream out; //ecriture
	ifstream monFlux("C:/test/test.txt"); //lecture
	int line=0;
	if (j2->score > 19) {   // fin du jeu
		//cout << "Felicitation!!! Le soigneur a gagne!!!"<< endl;
		if (monFlux) {
			//le fichier est bien la

			string ligne; //variable pour stocker les lignes lues
			while (getline(monFlux, ligne)) {
				if (line == 1) {
					cout << ligne << endl;
				}
				
				line++;
			}
		}
		else
		{
			cout << "ERREUR:fichier non trouver" << endl;
		}
		
		out.open("C:/Users/julie/OneDrive/Documents/LUDUS/3eme/C++/ safari.txt", ios::app); //app permet de mettre le mot a la suite du precedent dans le fichier
		if (out) {
			out << "Le gagnant s'appelle" << j2->GetName() << endl;
		}
		else {
			cout << "ERREUR:fichier non trouver" << endl;
		}
	}
	if (j1->score > 19) {  //fin du jeu
		//cout << "Felicitation!!! Le chasseur a gagne!!!" << endl;
		if (monFlux) {
			//le fichier est bien la

			string ligne; //variable pour stocker les lignes lues
			while (getline(monFlux, ligne)) {
				if (line == 0) {
					cout << ligne << endl;
				}

				line++;
			}
		}
		else
		{
			cout << "ERREUR:fichier non trouver" << endl;
		}

		out.open("C:/Users/julie/source/repos/SafarieJulieMorand/SafarieJulieMorand", ios::app); //app permet de mettre le mot a la suite du precedent dans le fichier
		if (out) {
			out << "Le gagnant s'appelle" << j1->GetName()<<endl;

		}
		else {
			cout << "ERREUR:fichier non trouver" << endl;
		}
	}
	out.close();
	
	
	

	


	system("pause");
}

void affichage(Chasseur* chasseur, Soigneur* soigneur, Terrain* tab) {
	int x = 0;
	int y = 0;
	cout << "                            SAVANE ADVENTURE" << endl;
	cout << endl;
	cout << "score du chasseur: " << chasseur->score << endl;
	cout << "score du Soigneur: " << soigneur->score << endl;
	cout << endl;
	cout << " +  - +  - +  - +  - +  - +  - +  - +  - +  - +  - + " << endl;
	
	for (x = 0; x < 10; x++) {
		for (y = 0; y < 10; y++) {
			cout << " |  " << tab->tab[x][y]; 
		}
		cout << " |" << endl;
		cout << " +  - +  - +  - +  - +  - +  - +  - +  - +  - +  - + " << endl;

	}




}