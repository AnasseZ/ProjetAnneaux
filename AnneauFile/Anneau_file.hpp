/* @brief: Header de l'anneau implémenté avec une file
*  @author: Anasse Zougarh, Thomas Gouhier, 402
*
*/

#ifndef ANNEAU_FILE
#define ANNEAU_FILE
 
#include <string>
#include <queue>

template<typename T>
class Anneau{


	private:

		std::queue<T> laFile; // Anneau avec une seule file où le sommet de la file est le courant
		int nbElements; 


	public:

        /* Constructeur de l'anneau
        *  Initialise nbElements à 0
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
        *  @return : 1 si l'anneau est vide, 0 sinon
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

        /* @role : Renvoie l'élement courant (le sommet)
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : L'élement courant
        */           
        T courant() const; 

        /* @role : Avance l'anneau, le courant devient le dernier, le second devient le courant
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : Rien
        */
        void avance();

        /* @role : Fait reculer l'anneau, le courant devient le deuxième, le dernier devient le courant
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : Rien
        */
        void recule();

        /* @role : Affichage les éléments de l'anneau
        *  @param : Aucun
        *  @precond: L'anneau est non vide 
        *  @return : Rien
        */
        void affiche(); 

        /* @role : Retourne la taille de l'anneau
        *  @param : Aucun
        *  @return : nbElements
        */
        int taille() const;


};



#include "Anneau_file.tpp"
#endif
