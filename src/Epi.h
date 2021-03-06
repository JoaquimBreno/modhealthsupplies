#ifndef EPI_H
#define EPI_H
#include <iostream>
#include "Insumo.h"

class Epi : public Insumo 
{
	protected:
	std::string tipo;
	std::string descricao;

	public:
		void getDescricao();
		std::string getTipo();
		std::string getAtDescricao();

		void setTipo(std::string tipo);
		void setAtDescricao(std::string desc);
		void salvaAtributos(std::ofstream &file);

		Epi();
		Epi(Insumo *epi);
		Epi(std::vector<std::string> atributos);
		~Epi();


};
#endif