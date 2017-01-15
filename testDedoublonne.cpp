/* @brief: Fichier test pour la fonction dedoublonne
*  @author: Anasse Zougarh, Thomas Gouhier, 402
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <fstream>

// inclure soit Anneau_file soit Anneau_pile

#include "AnneauFile/Anneau_file.hpp"     
//#include "AnneauPile/Anneau_pile.hpp"

clock_t chrono;
#define START chrono=clock();
#define STOP chrono=clock()-chrono;
#define TEMPS double(chrono)/(CLOCKS_PER_SEC/1000)

using namespace std;




template <typename T>
bool contient(Anneau<T> an, T elt){

	for(int i=0; i<an.taille();i++){

		if( an.courant() == elt ){
			return true;
		}
		 an.avance();
	}

	return false;
}


template <typename T>
Anneau<T> dedoublonne(Anneau<T> an){


	Anneau<T> annTemp;

	for (int i = 0;i<an.taille();i++ ){

		if( !(contient(annTemp,an.courant())) ){
			annTemp.ajoute(an.courant());
		}

		an.avance();
	}


	return annTemp;
}

// Creer un anneau avec taille éléments qui vont de 0 à x-1
// Il fallait faire un choix nous avons choisis des anneaux de Int et char.
Anneau<int> creerAnneau( int taille, int x){

	Anneau<int> an;

	for(int i = 0; i<taille; i++){
		an.ajoute(rand() % x);
	}


	return an;

}

// Fonction qui creer un anneau de char
Anneau<char> creerAnneauChar( int taille){

	Anneau<char> an;

	for(int i = 0; i<taille; i++){
		an.ajoute((char)(rand() % 26 + 65));
	}


	return an;

}


void testDedoublonne(){

	cout << "-------------------------------------------------" << endl;
    cout << "              Jeu de test de dedoublonne() " << endl;
    cout << "-------------------------------------------------" << endl;

    cout << " ****** Anneau d'entiers ****** " << endl;
 	Anneau<int> anneau;
 	anneau = creerAnneau(20,30); // Anneau de 20 éléments allant de 0 à 29
	Anneau<int> anneauInt;
	anneauInt = dedoublonne(anneau); 
	cout << " L'anneau passé en paramètre : ";
	anneau.affiche();
	cout << endl;
	cout << " L'anneau sans les doublons : ";
	anneauInt.affiche();
	cout << endl;

	cout << " ****** Anneau de caractères ****** " << endl;
 	Anneau<char> anneau2;
 	anneau2 = creerAnneauChar(20); // Anneau de 20 caractères
	Anneau<char> anneauChar;
	anneauChar = dedoublonne(anneau2); 
	cout << " L'anneau passé en paramètre : ";
	anneau2.affiche();
	cout << endl;
	cout << " L'anneau sans les doublons : ";
	anneauChar.affiche();
	cout << endl;


}

void calculTempsMoyen(){

	cout << "-------------------------------------------------" << endl;
    cout << " Calcul du temps moyen selon le nombre d'éléments " << endl;
    cout << "-------------------------------------------------" << endl;
	Anneau<int> ann;
	const char* datafname = "Valeursmoyennes.txt";
	ofstream data(datafname);
    int nombreDElements[] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
    double temps_moyen[10]; 
    for (int i = 0; i < 10; i++){ // le 10 represente le fait qu'on essaye avec 10 valeurs différentes
    	double max = 0;
		for (int j = 0; j < 100; ++j) { // Le 100 represente le nombre de test
        	ann = creerAnneau(nombreDElements[i],10000);
        	START;  
        	ann = dedoublonne(ann);
        	STOP;

        	max+=TEMPS;   
    	}

    	temps_moyen[i] = max/100;
    	cout << "Pour un anneau avec "<< nombreDElements[i] << " élément(s)" << " on met " << temps_moyen[i] << " millisecondes" << endl; 
    	data << nombreDElements[i] << " \t" << temps_moyen[i] << endl; // on écrit dans notre fichier pour récupérer plus facilement les valeurs
    }
	
	data.close() ;
}

int main(){

 	srand((int)time(NULL)); //Pour avoir des valeurs aléatoires différentes entre chaque exécution
 	
 	testDedoublonne();
 	calculTempsMoyen();
    
 	
 	

	return 0;
}
