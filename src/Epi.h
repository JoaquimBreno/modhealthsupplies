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
		void getDescricao();
		std::string getTipo();
		std::string getAtDescricao();
		void setTipo(std::string tipo);
		void setAtDescricao(std::string desc);
		Epi();
		Epi(Insumo *epi, std::string tipo, std::string descricao);
		~Epi();

};
#endif