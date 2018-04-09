#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "GestionnaireProduits.h"

using namespace std;

/**
*  @brief Classe qui contient les informations d'un client
*  @remark derive de la class Usager
*/
class Client : public Usager
{
  public:
	  /**
	  *   @brief  constructeur par paramètre
	  *	@remark constructor
	  */
    Client(unsigned int codeClient = 0);

	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*/
    Client(const string &nom, const string &prenom, int reference, const string &codePostal, unsigned int codeClient = 0);
	
	/**
	*	@remark destructeur
	*/
	~Client();

	/**
	*   @brief  retourne l'attribut demandé
	*	@remark fonction constante
	*/
    unsigned int obtenirCodeClient() const;
	GestionnaireProduits* obtenirPanier() const;
    virtual double obtenirTotalAPayer() const;

	/**
	*   @brief  modifie l'attribut demandé avec le parametre
	*	@remark fonction constante
	*/
	void modifierCodeClient(unsigned int codeClient);

	/**
	*   @brief  affiche la liste de produit dans le panier
	*	@remark fonction constante
	*	@return void
	*/
    void afficherPanier() const;

	/**
	*   @brief  affiche les informations du client
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
    virtual void afficher() const;

	/**
	*   @brief  retire le produit en parametre au panier du client
	*   @param  {Produit*} prod - un pointeur au produit que l'on retire
	*   @remark fonction virtuelle
	*   @return void
	*/
    virtual void enleverProduit(Produit *produit);

	/**
	*   @brief  ajoute le produit en parametre au panier du client
	*   @param  {Produit*} prod - un pointeur au produit que l'on ajoute
	*   @remark fonction virtuelle
	*   @return void
	*/
    virtual void ajouterProduit(Produit *produit);

	/**
	*   @brief  vide le panier et initialise les produits aux enchères
	*			et nullifie le fournisseur pour tous les produits
	*	@remark fonction virtuelle
	*	@return void
	*/
    virtual void reinitialiser();

	// --------------------------------------------------

	/**
	*   @brief  Retourne le produit le plus cher
	*	@return Produit*
	*/
	Produit* trouverProduitPlusCher() const;
  
  protected:
    GestionnaireProduits* panier_;

  private:
    unsigned int codeClient_;
};

#endif
