#ifndef PRODUIT_AUX_ENCHERES_H
#define PRODUIT_AUX_ENCHERES_H

#include <string>
#include <iostream>
#include "Produit.h"
#include "Client.h"

using namespace std;

/**
*  @brief Classe qui contient les informations d'un produit aux enchéres
*  @remark classe de dérivé de Produit
*/
class ProduitAuxEncheres : public Produit
{
public:
	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*   @return void
	*/
	ProduitAuxEncheres(double prix = 0.0);

	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*   @return void
	*/
	ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom, int reference = 0,
		double prix = 0.0);

	/**
	*   @brief  retourne l'attribut demandé
	*	@remark fonction constante
	*/
	double obtenirPrixInitial() const;
	Client *obtenirEncherisseur() const;

	/**
	*   @brief  affiche les informations du produit aux enchéres
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual void afficher() const;

	/**
	*   @brief  modifie l'attribut demandé avec le parametre
	*   @param {double} prixInitial - prix initial du produit
	*/
	void modifierPrixInitial(double prixInitial);
	void modifierEncherisseur(Client *encherisseur);


	/**
	*   @brief  modifie l'attribut demandé avec le parametre
	*   @param {Client*} encherisseur - client qui veut encherir sur le produit
	*   @param {double} nouveauPrix - prix que propose l'encherisseur
	*/
	void mettreAJourEnchere(Client *encherisseur, double nouveauPrix);
private:
	double prixInitial_;
	Client *encherisseur_;
};

#endif
