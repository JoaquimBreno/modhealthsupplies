#ifndef EPI_H
#define EPI_H
#include <iostream>
#include "Insumo.h"

class Epi : public Insumo 
{
	private:
	std::string tipo;
	std::string descricao;

	public:
		std::string getDescricao();
		std::string getAtDescricao();
		Epi();
		~Epi();

};
#endif