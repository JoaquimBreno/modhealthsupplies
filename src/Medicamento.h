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
		void insereEspecificos(std::string dos, std::string adm, std::string disp);
		void setAtributos(std::vector<std::string> atributos);
		void salvaAtributos(std::ofstream &file);
		Medicamento(Insumo *med);
		Medicamento();
		~Medicamento();

};
#endif