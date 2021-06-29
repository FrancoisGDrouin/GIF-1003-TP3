/*
 * validationFormat.h
 *
 *  Created on: 2020-10-01
 *      Author: etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

bool validerNas(const std::string& p_nas);
bool validerFormatFichier(std::istream& p_is);

#endif /* VALIDATIONFORMAT_H_ */
