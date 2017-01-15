/* @brief: Header de l'anneau implémenté avec deux piles
*  @author: Anasse Zougarh, Thomas Gouhier, 402
*
*/

#ifndef ANNEAU_PILE
#define ANNEAU_PILE

#include <stack> // Pour les piles
#include <string> // Pour le type std::string

template<typename T> 
class Anneau{


    private:
    	std::stack<T> laPileA; //Premiere pile où le sommet de la pile est le courant
    	std::stack<T> laPileB; //Deuxieme pile permettant de gerer les methodes avance et recule 
    	int nbElementsA; //Nombre d'element present dans la pile A
        int nbElementsB; //Nombre d'element present dans la pile B
    	

    public:

        /* Constructeur de l'anneau
        *  Initialise nbElementsA et nbElementsB à 0
        *
        */ 
    	Anneau();

        /* Destructeur de l'anneau
        *  
        *
        */        
    	~Anneau();

        /* @role : Test si l'anneau est vide
        *  @param : Aucun
        *  @return : 1 si nbElementsA est egale à 0 : l'anneau est vide, 0 sinon
        */
    	bool estVide() const;

        /* @role : Ajoute l'élement t à la position courante
        *  @param : T t
        *  @return : rien
        */
    	void ajoute(T t);

        /* @role : Supprime l'élement à la position courante
        *  @param : Aucun
        *  @return : Rien
        */ 
    	void supprime();

        /* @role : Renvoie l'élement courant (le sommet de laPileA)
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : L'élement courant
        */  
    	T courant() const;

        /* @role : Avance l'anneau, le courant est ajouté au sommet de laPileB, puis supprimé de laPileA, le second devient le courant
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : Rien
        */
    	void avance();

        /* @role : Fait reculer l'anneau, le sommet de laPileB est ajouté au somment de laPileA (devient alors le courant), puis on supprime le sommet de laPileB
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : Rien
        */
    	void recule();

        /* @role : Retourne la taille de l'anneau
        *  @param : Aucun
        *  @return : nbElementsA + nbElementsB
        */
        int taille() const;

        /* @role : Affichage les éléments de l'anneau
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : Rien
        */
        void affiche();

        

};

#include "Anneau_pile.tpp"
#endif
