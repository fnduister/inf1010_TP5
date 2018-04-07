/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include <numeric>
#include <functional>
#include <iostream>
#include "ProduitAuxEncheres.h"

GestionnaireProduits::GestionnaireProduits():GestionnaireGenerique()
{
}

void GestionnaireProduits::reinitialiserClient()
{
	for (const auto pairProduit : conteneur_)
	{
		ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(pairProduit.second);
		if (produit) {
			produit->modifierEncherisseur(nullptr);
			produit->modifierPrix(produit->obtenirPrixInitial());
		}
	}
	conteneur_.clear();
}

void GestionnaireProduits::reinitialiserFournisseur()
{
	for (const pair<int, Produit*> pairProduit : conteneur_)
		pairProduit.second->modifierFournisseur(nullptr);
	conteneur_.clear();
}

void GestionnaireProduits::afficher()
{
	for (const auto pairProduit : conteneur_) {
		pairProduit.second->afficher();
		cout << "\t\texemplaire:\t" << conteneur_.count(pairProduit.first) << std::endl;
	}
}

double GestionnaireProduits::obtenirTotalAPayer()
{
	return std::accumulate(
		conteneur_.begin(),
		conteneur_.end(),0.0,
		[](double total, auto produitpair)
		{
			return total + produitpair.second->obtenirPrix();
		}
	);
}

double GestionnaireProduits::obtenirTotalApayerPremium()
{
	return 0.0;
}

Produit* GestionnaireProduits::trouverProduitPlusCher() const
{
	if (conteneur_.size() != 0) {
		return 
		std::max_element(
			conteneur_.begin(),
			conteneur_.end(),
			[](pair<int, Produit*> a, pair<int, Produit*> b)
			{
				return a.second->obtenirPrix() < b.second->obtenirPrix();
			}
		)->second;
	}
	return nullptr;

}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneInf, double borneSup)
{
	vector<pair<int, Produit*>> temp;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(temp), FoncteurIntervalle(borneInf,borneSup));
	return temp;
}

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* prod)
{
	return find_if(conteneur_.begin(), conteneur_.end(),
		std::bind(std::greater<int>(),bind(&multimap<int,Produit*>::value_type::first,placeholders::_1),prod->obtenirReference()))->second;
}
