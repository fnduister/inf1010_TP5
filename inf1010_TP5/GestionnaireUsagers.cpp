/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"
#include "Gestionnaire.h"
#include <numeric>

GestionnaireUsagers::GestionnaireUsagers(): GestionnaireGenerique()
{
}

void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}

void GestionnaireUsagers::reinitialiser()
{
	for (Usager* usager :conteneur_)
	{
		usager->reinitialiser();
	}
}

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	return std::accumulate(std::begin(conteneur_), std::end(conteneur_),0,
		[](int total, Usager* usager) {return total + usager->obtenirTotalAPayer(); });
}

void GestionnaireUsagers::afficherProfils() const
{
	cout << "PROFILS" << std::endl;
	for (Usager* usager : conteneur_)
	{
		usager->afficherProfil();
	}
}