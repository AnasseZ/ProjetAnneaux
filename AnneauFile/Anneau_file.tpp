#include "Anneau_file.hpp"
#include <cassert>  
#include <iostream>

using namespace std; 

template <typename T>
Anneau<T>::Anneau()
{
    nbElements = 0; 
}

//----------------------------------------------------------------------
template <typename T>
Anneau<T>::~Anneau()
{
     
}
//----------------------------------------------------------------------

template <typename T>
bool Anneau<T>::estVide() const
{
    return nbElements == 0;
}
//----------------------------------------------------------------------

template <typename T>
int Anneau<T>::taille() const
{
    return nbElements;
}
//----------------------------------------------------------------------

template <typename T>
void Anneau<T>::ajoute(T t)
{
	if(nbElements > 0){
    	queue<T> fileTemporaire;
		fileTemporaire.push(t);
		for(int i =0; i<nbElements; i++){
			fileTemporaire.push(laFile.front());
			laFile.pop();
		}

        
        swap(fileTemporaire,laFile);

	}

	else {laFile.push(t);}

    nbElements++;

    	
}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::supprime()
{
    assert( !estVide() ); // Notre précondition

    laFile.pop(); // on supprime la tête 
    nbElements--;
}

//----------------------------------------------------------------------
template <typename T>
T Anneau<T>::courant() const // Courant = tête
{
    assert( !estVide() ); // précondition
    
    return laFile.front();
}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::avance() // le deuxième devient le sommet(courant), le premier -> dernier
{
    assert(!estVide()); 
    
    T temporaire = laFile.front();
    laFile.pop();
    laFile.push(temporaire);
    
}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::recule() // le dernier prends la place du sommet(courant)
{
    assert(!estVide());
    
   
   for(int i=0; i<nbElements-1; i++){

        T temporaire = laFile.front();
        laFile.pop();
        laFile.push(temporaire);
   }


}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::affiche() {

    assert(!estVide());
       
    for(int i=0; i<nbElements; i++){

        cout << laFile.front() << " ";
        avance();
    }
    
    cout << endl;    
}
