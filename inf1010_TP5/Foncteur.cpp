#include "Foncteur.h"

FoncteurGenerateurId::FoncteurGenerateurId()
{
}

int FoncteurGenerateurId::operator()()
{
	return  ++id_;
}

