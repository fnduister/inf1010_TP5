#ifndef CLIENT_PREMIUM_H
#define CLIENT_PREMIUM_H

#include <string>
#include "Client.h"

using namespace std;

/**
*  @brief Classe qui contient les informations d'un client premium
*  @remark derive de la class Client
*/
class ClientPremium : public Client
{
public:
	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*/
	ClientPremium(unsigned int joursRestants = 0);

	/**
	*   @brief  constructeur par paramètre
	*	@remark constructor
	*/
	ClientPremium(const string &nom, const string &prenom, int identifiant, const string &codePostal, unsigned int codeClient, unsigned int joursRestants = 0);

	/**
	*   @brief  retourne l'attribut demandé
	*	@remark fonction constante
	*/
	unsigned int obtenirJoursRestants() const;
	virtual double obtenirTotalAPayer() const;

	/**
	*   @brief  affiche les informations du client premium
	*	@remark fonction constante
	*	@remark fonction virtuelle
	*	@return void
	*/
	virtual void afficher() const;

	/**
	*   @brief  modifie les jours restants à son abonnement
	*   @param {unsigned int} joursRestants - nombre de jours qu'il reste avant la fin de son abonnement
	*	@return void
	*/
	void modifierJoursRestants(unsigned int joursRestants);

private:
	unsigned int joursRestants_; // avant la fin de l'abonnement
};
#endif
