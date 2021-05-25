#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include "Insumo.h"	
class Medicamento  : public Insumo
{
	private:
		std::string dosagem;
		std::string administracao;
		std::string disponibilizacao;
	public:
		void getDescricao();
		Medicamento();
		~Medicamento();

};
#endif