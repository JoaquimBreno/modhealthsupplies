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
		std::string getTipoVac();
		int getQuantDoses();
		int getIntervalo();
		void setTipoVac(std::string tVac);
		void setQuantDoses(int quant);
		void setIntervalo(int intervalo);
		Vacina(Insumo *vac, int quantDoses, std::string tipoVac, int interv);
		Vacina();
		~Vacina();

};
#endif