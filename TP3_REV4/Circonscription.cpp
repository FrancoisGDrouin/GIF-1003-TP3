/*
 * Circonscription.cpp
 *
 *  Created on: 2020-11-24
 *      Author: etudiant
 */

#include "Circonscription.h"
#include "Personne.h"
#include "Electeur.h"
#include "Candidat.h"
#include <string>

using namespace std;

namespace elections
{
	Circonscription::Circonscription(std::string p_nomCirconscription, Candidat p_deputeElu):m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
	{
		PRECONDITION(!p_nomCirconscription.empty());
		PRECONDITION(!p_deputeElu.reqPersonneFormate().empty());

		POSTCONDITION(p_nomCirconscription == reqNomCirconscription());
		POSTCONDITION(p_deputeElu.reqPersonneFormate() == reqDeputeElu().reqPersonneFormate());

		INVARIANTS();
	}

	Circonscription::~Circonscription(){}

	std::string Circonscription::reqNomCirconscription() const
	{
		ASSERTION(!m_nomCirconscription.empty());
		return m_nomCirconscription;
	}

	Candidat Circonscription::reqDeputeElu() const
	{
		ASSERTION(!m_deputeElu.reqPersonneFormate().empty());
		return m_deputeElu;
	}

	std::string Circonscription::reqCirconscriptionFormate() const
	{
		ostringstream os;
		os << "Circonscription" << reqNomCirconscription()
		<< "\nDepute sortant :\n" << m_deputeElu.reqPersonneFormate() << endl;

		for (int i=0; i<m_vInscrits.size(); i++)
		{
		        os << m_vInscrits[i]->reqPersonneFormate() << endl;
		}
		return os.str();
	}

	void Circonscription::inscrire (const Personne& p_nouvelInscrit)
	{

		m_vInscrits.push_back(p_nouvelInscrit.clone());
	}

	Circonscription::Circonscription(const Circonscription& p_nomCirconscription):m_deputeElu(p_nomCirconscription.reqDeputeElu())
	{
		m_nomCirconscription = p_nomCirconscription.reqNomCirconscription();
		copy(p_nomCirconscription.m_vInscrits.begin(), p_nomCirconscription.m_vInscrits.end(), back_inserter(m_vInscrits));
	}
	const Circonscription& Circonscription::operator=(const Circonscription& p_nomCirconscription)
	{

		Circonscription A(p_nomCirconscription);
		return A;
	}

    void Circonscription::verifieInvariant() const
    {
		ASSERTION(m_nomCirconscription == reqNomCirconscription());
		ASSERTION(m_deputeElu.reqPersonneFormate() == reqDeputeElu().reqPersonneFormate());
    }
}

