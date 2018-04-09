/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Usager.h"
#include <set>
#include "Foncteur.h"

class ProduitAuxEncheres;
class Client;

/**
*  @brief Classe qui contient les informations d'un gestionnaire
*/
class GestionnaireUsagers:public GestionnaireGenerique<Usager, set<Usager*>, SupprimerUsager, AjouterUsager>
{
public:
	GestionnaireUsagers();

	/**
	*   @brief  Permet d'encherir sur un produit aux encheres
	*	@param {Client*} client - Pointeur vers le client qui encherie
	*	@param {ProduitAuxEncheres*} produit (OUT)- Pointeur du produit sur lequel on encherie
	*	@param {double} montant - Montant que le client propose
	*	@return void
	*/
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	
	/**
	*	@brief	reinitialise les paniers ou catalogues des usagers géré par le gestionnaire
	*   @remark Appel la methode virtuelle reinitialiser de Client et Fournisseur
	*	@return void
	*/
	void reinitialiser();

	/**
	*   @brief  Calcul le chiffre d'affaires des usagers géré par ce gestionnaire
	*   @remark Appel la methode virtuelle obtenirTotalAPayer qui retourne 0 si
	*			il s'agit d'un fournisseur ou le total des prix des produits
	*			du client
	*	@remark fonction constante
	*	@return double - montant du chiffre d'affaire
	*/
	double obtenirChiffreAffaires() const;

	/**
	*   @brief  Appel la methode virtuelle afficherProfil qui affiche
	*			les informations de l'usager dependament si
	*			c'est un fournisseur ou un client
	*	@remark fonction constante
	*	@return void
	*/
	void afficherProfils() const;
private:
};
