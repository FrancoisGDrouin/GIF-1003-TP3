#ifndef PERSONNE_H_
#define PERSONNE_H_

#include <string>
#include <sstream>
#include "Adresse.h"
#include "Date.h"
#include "ContratException.h"

namespace elections
{
    class Personne

    {
        public:

            Personne(std::string p_nas, std::string p_prenom, std::string p_nom, util::Date p_dateNaissance, util::Adresse p_adresse);
           
            virtual ~Personne(){};
            virtual Personne* clone() const=0;

            std::string reqNas() const;

            std::string reqPrenom() const;
           
            std::string reqNom() const;

            util::Date reqDateNaissance() const;
           
            util::Adresse reqAdresse() const;
            void asgAdresse(const util::Adresse& p_adresse);

            virtual std::string reqPersonneFormate() const = 0;

        private:

                std::string m_nas;
                std::string m_prenom;
                std::string m_nom;
                util::Adresse m_adresse;
                util::Date m_dateNaissance;
                void verifieInvariant() const;
    };

} /* namespace std */

#endif /* PERSONNE_H_ */
