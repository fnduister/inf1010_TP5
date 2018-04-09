/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <algorithm>

/**
*  @brief Classe template qui permet la gestion d'objets
*  T - Type d'objet qu'on prend en charge
*  C - Type de conteneur qu'on utilise pour conserver les objets
*  S - Foncteur de suppression d'objet
*  A - Foncteur d'ajout d'objet
*/
template<typename T, typename C, typename S, typename A>
class GestionnaireGenerique
{
public:
	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*/
	GestionnaireGenerique()
	{
	};

	/**
	*   @brief  ajoute  un nouvel objet au conteneur
	*	@return {T*} donnee - un objet qu'on ajoute grace au foncteur d'ajout
	*/
	void ajouter(T* donnee)
	{
		//creation foncteur
		A ajouterFoncteur(conteneur_);
		//Ajout de l'objet
		ajouterFoncteur(donnee);
	};

	/**
	*   @brief  supprime un objet du conteneur
	*	@return {T*} donnee - un objet qu'on supprime grace au foncteur de suppression
	*/
	void supprimer(T* donnee)
	{
		//creation foncteur
		S supprimerFoncteur(conteneur_);
		//Suppression de l'objet
		supprimerFoncteur(donnee);
	}

	/**
	*   @brief  retourne le conteneur
	*/
	C& obtenirConteneur()
	{
		return conteneur_;
	}

	/**
	*   @brief  applique l'action fourni avec le predicat a chaque element du conteneur
	*	@return void
	*/
	template<typename Predicat>
	void pourChaqueElement(Predicat predicat)
	{
		for_each(conteneur_.begin(), conteneur_.end(), predicat);
	}

protected:
	C conteneur_;
};
