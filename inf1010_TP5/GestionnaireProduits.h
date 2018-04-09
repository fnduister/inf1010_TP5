/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Produit.h"
#include "Foncteur.h"
#include <vector>

/**
*  @brief Classe qui contient les informations d'un gestionnaire de produits
*/
class GestionnaireProduits:public GestionnaireGenerique<Produit, multimap<int,Produit*>, SupprimerProduit, AjouterProduit>
{
public:
	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*/
	GestionnaireProduits();

	/**
	*	@brief	reinitialise les paniers ou catalogues des usagers géré par le gestionnaire
	*   @remark Appel la methode virtuelle reinitialiser de Client et Fournisseur
	*			Pour produit aux enchere, met un nulltpr l'encherisseur reinitialise le prix
	*	@return void
	*/
	void reinitialiserClient();

	/**
	*	@brief	reinitialise les paniers ou catalogues des usagers géré par le gestionnaire
	*   @remark Appel la methode virtuelle reinitialiser de Fournisseur
	*	@return void
	*/
	void reinitialiserFournisseur();

	/**
	*   @brief  affiche les informations des produits du client
	*	@remark fonction constante
	*	@return void
	*/
	void afficher() const;

	/**
	*   @brief  retourne l'attribut demandé
	*	@remark fonction constante
	*/
	double obtenirTotalAPayer() const;
	double obtenirTotalApayerPremium() const;

	/**
	*   @brief  retourne le produit le plus cher
	*	@remark fonction constante
	*/
	Produit* trouverProduitPlusCher() const;

	/**
	*   @brief  retourne un vecteur de produit qui se trouve dans l'intervale demande
	*   @param  {double} begin - borne inferieur de l'intervale
	*   @param  {double} end - borne superieure de l'intervale
	*   @return vector<pair<int, Produit*>>
	*/
	vector<pair<int, Produit*>> obtenirProduitsEntre(double begin,double end) const;

	/**
	*   @brief  retourne le produit suivant
	*   @param  {Produit*} prod - produit dont on veut le suivant
	*   @return Produit*
	*/
	Produit* obtenirProduitSuivant(Produit* prod);
};
