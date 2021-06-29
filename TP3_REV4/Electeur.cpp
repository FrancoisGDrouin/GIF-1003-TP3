/*
 * Electeur.cpp
 *
 *  Created on: 2020-11-24
 *      Author: etudiant
 */

#include "Electeur.h"
#include "ContratException.h"
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
using namespace util;

namespace elections
{
Electeur::Electeur(string p_nas, string p_prenom, string p_nom, util::Date p_dateNaissance, util::Adresse p_adresse):
		Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
		{
		}

	//Electeur::~Electeur() {};

	Electeur* Electeur::clone() const
	{
		return new Electeur(*this); //Appel du constructeur copie
	}

	string Electeur::reqPersonneFormate() const
	{
		ostringstream os;
		os << "Electeur" <<
		"\n----------------------------------------------"
		<< Personne::reqPersonneFormate()
		return os.str();
	}

    void Electeur::verifieInvariant() const
    {
		ASSERTION(this->reqNas() == m_nas);
		ASSERTION(this->reqPrenom() == m_prenom);
		ASSERTION(this->reqNom() == m_nom);
    }
}
