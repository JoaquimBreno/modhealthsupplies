#ifndef VACINA_H
#define VACINA_H
#include "Insumo.h"
#include <iostream>
#include <fstream>
class Vacina  : public Insumo{
	protected:
		std::string tipoVac;
		int quantDoses;
		int intervalo;	
	public:
		void getDescricao();
		std::string getTipoVac();
		int getQuantDoses();
		int getIntervalo();
		
		void setTipoVac(std::string tVac);
		void setQuantDoses(int quant);
		void setIntervalo(int intervalo);
		Vacina(Insumo *vac);
		void insereEspecificos(std::string tipoVac, int quantDoses, int intervalo);
		void salvaAtributos(std::ofstream &file);
		Vacina();
		~Vacina();

};
#endif