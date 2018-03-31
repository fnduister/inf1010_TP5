/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include <numeric>
#include <functional>

GestionnaireProduits::GestionnaireProduits():GestionnaireGenerique()
{
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
