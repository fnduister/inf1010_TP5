/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"
#include "Gestionnaire.h"

GestionnaireUsagers::GestionnaireUsagers(): GestionnaireGenerique()
{
}

void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}