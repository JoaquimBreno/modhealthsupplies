#ifndef VACINA_H
#define VACINA_H
#include "Insumo.h"
#include <iostream>
	
class Vacina  : public Insumo{
	private:
		int tipo;
		int quantDoses;
		int intervalo;	
	public:
		std::string getDescrição();
		Vacina();
		~Vacina();

};
#endif