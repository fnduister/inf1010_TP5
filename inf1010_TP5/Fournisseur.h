#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "GestionnaireProduits.h"

using namespace std;

/**
*  @brief Classe qui contient les informations d'un fournisseur
*  @remark classe derivé d'usager
*/
class Fournisseur : public Usager
{
  public:
	/**
	*   @brief  constructeur par défaut
	*	@remark constructor
	*/
	Fournisseur();

	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*/
	Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);
	
	/**
	 *	@remark Destructeur
	 */
	~Fournisseur();

	/**
	*   @brief  retourne l'attribut demandé
	*	@remark fonction constante
	*/
	GestionnaireProduits* obtenirCatalogue() const;

	/**
	*   @brief  affiche la liste de produit dans le catalogue
	*	@remark fonction constante
	*	@return void
	*/
	void afficherCatalogue() const;

	/**
	*   @brief  affiche les informations du fournisseur
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual void afficher() const;

	/**
	*   @brief  vide le catalogue
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual void reinitialiser();

	/**
	*   @brief  ajoute le produit en parametre à notre fournisseur
	*   @param  {Produit*} prod - un pointeur au produit que l'on ajoute
	*   @remark fonction virtuelle
	*   @return void
	*/
	virtual void ajouterProduit(Produit *produit);

	/**
	*   @brief  retire le produit en parametre à notre fournisseur
	*   @param  {Produit*} prod - un pointeur au produit que l'on retire
	*   @remark fonction virtuelle
	*   @return void
	*/
	void enleverProduit(Produit *produit);

	/**
	*   @brief  Retourne le produit le plus cher du catalogue
	*   @return Produit*
	*/
	Produit* trouverProduitPlusCher() const;

	/**
	*   @brief  reduit le prix de tous les produits du taux fourni en parametre
	*   @param  {int} pourcent - le pourcentage de reduction
	*   @return void
	*/
	void DiminuerPrix(int pourcent) const;

  private:
    GestionnaireProduits* catalogue_;
};

#endif
