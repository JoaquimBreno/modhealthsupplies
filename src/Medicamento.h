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
		std::string getDosagem();
		std::string getAdministracao();
		std::string getDisponibilizacao();
		void setDosagem(std::string dosagem);
		void setAdministracao(std::string administracao);
		void setDisponibilizacao(std::string disp);

		Medicamento();
		~Medicamento();

};
#endif