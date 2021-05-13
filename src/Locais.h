#ifndef LOCAIS_H
#define LOCAIS_H
#include <string>
#include "Insumo.h"

class Locais 
{
	private:
	std::string nome;
	int index;
	Insumo insumos[];

	public:

		Locais();
		~Locais();

};
#endif