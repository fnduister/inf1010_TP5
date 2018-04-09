#ifndef PRODUIT_SOLDE_H
#define PRODUIT_SOLDE_H

#include <string>
#include <iostream>
#include "Solde.h"
#include "Produit.h"

using namespace std;

/**
*  @brief Classe qui contient les informations d'un produit sold�
*  @remark classe de d�riv� de Produit
*  @remark classe d�riv� de Solde
*/
class ProduitSolde : public Produit, public Solde
{
public:

	/**
	*   @brief  constructeur par param�tre
	*	@remark constructor
	*   @return void
	*/
	ProduitSolde(int pourcentageRabais = 0);

	/**
	*   @brief  constructeur par param�tre
	*	@remark constructor
	*   @return void
	*/
	ProduitSolde(Fournisseur *fournisseur, const string &nom, int reference,
		double prix, int pourcentageRabais = 0);

	/**
	*   @brief  affiche les informations du produit ProduitSolde
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual double obtenirPrix() const;

	/**
	*   @brief  affiche les informations du produit ProduitSolde
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual void afficher() const;

};

#endif
