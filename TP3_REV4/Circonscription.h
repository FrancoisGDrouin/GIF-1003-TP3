/*
 * Circonscription.h
 *
 *  Created on: 2020-11-24
 *      Author: etudiant
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_

#include <string>
#include <sstream>
#include "Adresse.h"
#include "Date.h"
#include "ContratException.h"
#include "Personne.h"
#include "Candidat.h"
#include "Electeur.h"

namespace elections
{
    class Circonscription

    {
        public:

    		Circonscription(std::string p_nomCirconscription, Candidat p_deputeElu);

            ~Circonscription();

            std::string reqNomCirconscription() const;

            Candidat reqDeputeElu() const;

            std::string reqCirconscriptionFormate() const;

            void inscrire (const Personne& p_nouvelInscrit);

            Circonscription(const Circonscription& p_nomCirconscription);
            const Circonscription& operator=(const Circonscription& p_nomCirconscription);

        private:

                std::string m_nomCirconscription;
                Candidat m_deputeElu;
                //Electeur m_nouvelInscrit;
                void verifieInvariant() const;
                std::vector<Personne*> m_vInscrits;
    };

} /* namespace std */

#endif /* PERSONNE_H_ */
