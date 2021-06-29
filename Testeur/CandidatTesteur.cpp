#include <gtest/gtest.h>
#include "Candidat.h"
#include "ContratException.h"

using namespace util;
using namespace std;
using namespace elections;

TEST(Candidat, ConstructeurValide)
{
	Adresse uneAdresse(235, "rue de l'Université", "Québec", "G1V 0A7", "QC");
	ASSERT_EQ(uneAdresse.reqNumeroCivic(),235);
	ASSERT_EQ(uneAdresse.reqNomRue(),"rue de l'Université");
	ASSERT_EQ(uneAdresse.reqVille(),"Québec");
	ASSERT_EQ(uneAdresse.reqCodePostal(),"G1V 0A7");
	ASSERT_EQ(uneAdresse.reqProvince(),"QC");
}

