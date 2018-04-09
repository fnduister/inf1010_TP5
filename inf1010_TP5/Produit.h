#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

using namespace std;

class Fournisseur;


/**
*  @brief Classe qui contient les informations d'un produit
*  @remark classe de base
*/
class Produit
{
public:
	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*   @return void
	*/
	Produit(Fournisseur *fournisseur = nullptr, const string &nom = "outil",
		int reference = 0, double prix = 0.0);

	/**
	*   @brief  retourne l'attribut demandé
	*	@remark fonction constante
	*/
	string obtenirNom() const;
	int obtenirReference() const;
	Fournisseur *obtenirFournisseur() const;

	/**
	*   @brief  affiche les informations du produit ( Produit ou ProduitAuxEnchere ou ProduitSolde)
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual double obtenirPrix() const;

	/**
	*   @brief  affiche les informations du produit ( Produit ou ProduitAuxEnchere ou ProduitSolde)
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual void afficher() const;

	/**
	*   @brief  modifie l'attribut demandé avec le parametre
	*	@remark fonction constante
	*/
	void modifierNom(const string &nom);
	void modifierReference(int reference);
	void modifierPrix(double prix);
	virtual void modifierFournisseur(Fournisseur *fournisseur);


private:
	Fournisseur * fournisseur_;
	string nom_;
	int reference_;

protected:
	double prix_;
};

#endif
