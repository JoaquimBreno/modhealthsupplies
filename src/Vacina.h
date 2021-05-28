#ifndef VACINA_H
#define VACINA_H
#include "Insumo.h"
#include <iostream>
	
class Vacina  : public Insumo{
	private:
		std::string tipoVac;
		int quantDoses;
		int intervalo;	
	public:
		void getDescricao();
		Vacina();
		~Vacina();

};
#endif