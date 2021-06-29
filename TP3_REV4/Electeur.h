/*
 * Electeur.h
 *
 *  Created on: 2020-11-24
 *      Author: etudiant
 */

#include <string>
#include <vector>
#include "Adresse.h"
#include "Date.h"
#include "Personne.h"
#include "Candidat.h"

using namespace std;

#ifndef ELECTEUR_H_
#define ELECTEUR_H_

//REMPLACER PAR ENUM?

namespace elections
{
	class Electeur : public Personne
	{
		public:
		Electeur(string p_nas, string p_prenom, string p_nom, util::Date p_dateNaissance, util::Adresse p_adresse);
			virtual ~Electeur(){};
			virtual Electeur* clone() const;
			string reqPersonneFormate() const;

		private:
			void verifieInvariant() const;
	};
}


#endif /* ELECTEUR_H_ */
