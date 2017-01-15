/* @brief: Fichier test de l'anneau 
*  @author: Anasse Zougarh, Thomas Gouhier, 402D
*
*/

#include <iostream>

// inclure soit Anneau_file soit Anneau_pile

#include "AnneauFile/Anneau_file.hpp"     
//#include "AnneauPile/Anneau_pile.hpp"

using namespace std;


void testAnneau(){

    
    Anneau<char> an; // Ici on test avec un anneau de char

    cout << "-------------------------------------------------" << endl;
    cout << "              Jeu de test de l'Anneau " << endl;
    cout << "-------------------------------------------------" << endl;

    // Ajout du mot bonjour dans l'anneau 
    an.ajoute('r');  
    an.ajoute('u');
    an.ajoute('o');
    an.ajoute('j');
    an.ajoute('n');
    an.ajoute('o');
    an.ajoute('b');
    

    // test de la méthode estVide()
    cout << "L'anneau est-il vide? 0 si faux, 1 si vrai" << endl;
    cout << "Valeur: " << an.estVide() << endl;
    cout << "-------------------------------------------------" << endl;

    // test de la méthode taille()
    cout << "La taille de l'anneau est " << an.taille() << "." << endl;
    cout << "-------------------------------------------------" << endl;

    // test de la méthode supprime()
    an.supprime();
    an.supprime();
    an.supprime();
    cout << "Resultat attendu : jour " << endl;
    cout << "Resultat:";
    an.affiche();
    cout << "-------------------------------------------------" << endl;


    // test de la méthode courant()
    cout << "Courant est la tête, ici le résultat attendu est : j " << endl;
    cout << "Le courant est " << an.courant() << endl;
    cout << "-------------------------------------------------" << endl;

    // test de la méthode avance()
    cout << "Resultat attendu : ourj" << endl;
    an.avance();
    an.affiche();
    cout << "-------------------------------------------------" << endl;

    // test de la méthode recule()
    cout << "Resultat attendu : jour" << endl;
    an.recule();
    an.affiche();
    cout << "-------------------------------------------------" << endl;

}




int main()
{

    testAnneau();

    return 0;
}
