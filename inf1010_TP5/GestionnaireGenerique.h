/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

template<typename T, typename C, typename S, typename A>
class GestionnaireGenerique
{
public:
//	GestionnaireGenerique();
	void ajouter(T* donnee);
protected:
	C conteneur_;
};

// TODO : Méthodes :

/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/