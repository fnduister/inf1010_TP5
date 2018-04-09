#ifndef USAGER_H
#define USAGER_H

#include "Produit.h"
#include <string>

using namespace std;

/**
*  @brief Classe qui contient les informations d'un usager
*  @remark classe de base abstraite
*/
class Usager
{
public:
	/**
	*   @brief  destructeur
	*   @return void
	*/
	virtual ~Usager() = default;

	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*   @return void
	*/
	Usager(const string &nom = "Doe", const string &prenom = "John",
		int identifiant = 0, const string &codePostal = "A1A A1A");

	/**
	*   @brief  retourne l'attribut demandé
	*	@remark fonction constante
	*/
	string obtenirNom() const;
	string obtenirPrenom() const;
	int obtenirReference() const;
	string obtenirCodePostal() const;
	virtual double obtenirTotalAPayer() const;

	/**
	*   @brief  affiche les informations de l'usager ( client ou fournisseur )
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
	void modifierPrenom(const string &prenom);
	void modifierReference(int identifiant);
	void modifierCodePostal(const string &codePostal);

	/**
	*   @brief  fonction virtuelle de base: elle ne fait rien
	*	@remark fonction virtuelle pure
	*	@return void
	*/
	virtual void reinitialiser() = 0;

	/**
	*   @brief  virtuelle permettant d'ajouter un produit a la classe derive
	*   @param  {Produit*} prod - un pointeur au produit que l'on ajoute
	*   @remark fonction virtuelle
	*   @return void
	*/
	virtual void ajouterProduit(Produit *produit) = 0;

	/**
	*   @brief  virtuelle permettant de retirer un produit à la classe dérivée
	*   @param  {Produit*} prod - un pointeur au produit que l'on ajoute
	*   @remark fonction virtuelle
	*   @return void
	*/
	virtual void enleverProduit(Produit *produit) = 0;

  private:
    string nom_;
    string prenom_;
    int reference_;
    string codePostal_;
};

#endif
