#ifndef SOLDE_H
#define SOLDE_H

#include <string>
#include <iostream>

using namespace std;

/**
*  @brief Classe definissant le pourcentage d'une solde
*  @remark Classe de base abstraite
*/
class Solde
{
public:

	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*/
	Solde(int pourcentageRabais);

	/**
	*	@remark destructeur
	*	@methode virtuelle pure
	*/
	virtual ~Solde() = 0; // par convention, pour rendre une classe abstraite lorsque celle-ci
						  // n'a aucune méthode qui mériterait d'être virtuelle pure, on préfère
						  // généralement rendre le destructeur de la classe virtuel pur.

						  /**
						  *   @brief  retourne le pourcentage de rabais
						  *	@remark fonction constante
						  */
	double obtenirPourcentageRabais() const;

	/**
	*   @brief  modifie le pourcentage de rabais
	*   @param {int} pourcentageRabais - pourcentage de rabais à modifier
	*/
	void modifierPourcentageRabais(int pourcentageRabais);
protected:
	int pourcentageRabais_;
};

#endif
