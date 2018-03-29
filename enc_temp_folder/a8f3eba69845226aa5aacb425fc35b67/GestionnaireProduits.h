/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Produit.h"
#include "Foncteur.h"
#include <vector>

class GestionnaireProduits:public GestionnaireGenerique<Produit, multimap<int,Produit*>, SupprimerProduit, AjouterProduit>
{
public:
	GestionnaireProduits();
//	void reinitialiserClient();
//	void reinitialiserFournisseur();
//	void afficher();
	int obtenirTotalAPayer();
//	int obtenirTotalApayerPremium();
	Produit* trouverProduitPlusCher() const;
	vector<pair<int, Produit*>> obtenirProduitsEntre(double begin,double end);
//	multimap<int, Produit*> obtenirProduitSuivant();
private:	
};
