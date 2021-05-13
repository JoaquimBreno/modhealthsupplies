#ifndef EPI_H
#define EPI_H

#include "Insumo.h"

class Epi : public Insumo 
{
	private:
	int tipo;
	std::string string;

	public:

		Epi();
		~Epi();

};
#endif