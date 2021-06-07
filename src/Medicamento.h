#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include "Insumo.h"	
class Medicamento  : public Insumo
{
	protected:
		std::string dosagem;
		std::string administracao;
		std::string disponibilizacao;
	public:
		void getDescricao();
		std::string getDosagem();
		std::string getAdministracao();
		std::string getDisponibilizacao();

		void setDosagem(std::string dosagem);
		void setAdministracao(std::string administracao);
		void setDisponibilizacao(std::string disp);
		void salvaAtributos(std::ofstream &file);

		Medicamento(Insumo *med);
		Medicamento(std::vector<std::string> atributos);
		Medicamento();
		~Medicamento();

};
#endif