/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Usager.h"
#include <set>
#include "Foncteur.h"

class ProduitAuxEncheres;
class Client;

class GestionnaireUsagers:public GestionnaireGenerique<Usager, set<Usager*>, SupprimerUsager, AjouterUsager>
{
public:
	GestionnaireUsagers();
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	void reinitialiser();
	double obtenirChiffreAffaires() const;
	void afficherProfils() const;
private:
};

// TODO : Cr�er la classe GestionnaireUsager

// TODO : La classe ressemble beaucoup � la classe Gestionnaire
