#include "Anneau_pile.hpp"
#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
Anneau<T>::Anneau()
{
    // initialisation des attributs d'une pile vide
    nbElementsA = 0; nbElementsB = 0;
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
    return (nbElementsA == 0);
}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::ajoute(T c)
{
	laPileA.push(c);
	nbElementsA++;
}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::supprime()
{
    assert( !estVide() ); // précondition
    
	laPileA.pop();

  	if(nbElementsA==0 && laPileB.empty()!=true){
  		while(laPileB.empty() != true){
  			laPileA.push(laPileB.top());
  			laPileB.pop();	
        nbElementsA++;
        nbElementsB--;
  		}
  	}
    nbElementsA--;
}

//----------------------------------------------------------------------
template <typename T>
T Anneau<T>::courant() const
{
    assert( !estVide() ); // précondition
    
    return laPileA.top();
}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::avance()
{
    assert(!estVide()); // précondition
    
	if(nbElementsA==1){
		laPileB.push(laPileA.top());
		laPileA.pop();
    nbElementsA--;
    nbElementsB++;

		while(laPileB.empty()==false){
		  laPileA.push(laPileB.top());
			laPileB.pop();
      nbElementsA++;
      nbElementsB--;
    }
	} else {
		laPileB.push(laPileA.top());
		laPileA.pop();
    nbElementsA--;
    nbElementsB++;
	}
    
}

//----------------------------------------------------------------------
template <typename T>
void Anneau<T>::recule()
{
    assert(!estVide()); // précondition
    
    if(laPileB.empty()==true){
    	while(nbElementsA!=1){
		    laPileB.push(laPileA.top());
		    laPileA.pop();
        nbElementsA--;
        nbElementsB++;
      }	 
    } else {
		  laPileA.push(laPileB.top());
		  laPileB.pop();
      nbElementsA++;
      nbElementsB--;
	}
    
}

//-----------------------------------------------------------------------
template <typename T>
int Anneau<T>::taille() const
{
  return (nbElementsA +  nbElementsB);
}


//------------------------------------------------------------------------
template <typename T>
void Anneau<T>::affiche()
{
  for (int i=0; i<taille(); i++){
    cout << courant() << " ";
    avance();
  }
  cout << endl;

}


