#ifndef EPI_H
#define EPI_H
#include <iostream>
#include "Insumo.h"

class Epi : public Insumo 
{
	private:
	int tipo;
	std::string descricao;

	public:
		std::string getDescrição();
		Epi();
		~Epi();

};
#endif