#ifndef EPI_H
#define EPI_H

#include "Insumo.h"

class Epi : public Insumo 
{
	private:
	int tipo;
	std::string descricao;

	public:

		Epi();
		~Epi();

};
#endif