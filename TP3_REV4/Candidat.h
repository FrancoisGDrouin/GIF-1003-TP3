/*
 * Candidat.h
 *
 *  Created on: 2020-11-24
 *      Author: etudiant
 */

#include <string>
#include <vector>
#include "Adresse.h"
#include "Date.h"
#include "Personne.h"

using namespace std;

#ifndef CANDIDAT_H_
#define CANDIDAT_H_

static std::vector <string> PartisPolitiques = {"BLOC_QUEBECOIS", "CONSERVATEUR", "INDEPENDANT", "LIBERAL", "NOUVEAU_PARTI_DEMOCRATIQUE"};

//REMPLACER PAR ENUM?

namespace elections
{
	class Candidat : public Personne
	{
		public:
			Candidat(string p_nas, string p_prenom, string p_nom, util::Date p_dateNaissance, util::Adresse p_adresse, int p_partiPolitique);
			virtual ~Candidat(){};
			virtual Candidat* clone() const;
			string reqPartiPolitique() const;
			string reqPersonneFormate() const;

		private:
			int m_partiPolitique;
			void verifieInvariant() const;
	};
}


#endif /* CANDIDAT_H_ */
