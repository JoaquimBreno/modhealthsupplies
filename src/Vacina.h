#ifndef VACINA_H
#define VACINA_H
#include "Insumo.h"
#include <iostream>
	
class Vacina  : public Insumo{
	private:
		std::string tipo;
		int quantDoses;
		int intervalo;	
	public:
		std::string getDescricao();
		Vacina();
		~Vacina();

};
#endif