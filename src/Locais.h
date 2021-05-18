#ifndef LOCAIS_H
#define LOCAIS_H
#include <string>
#include "Insumo.h"
#include <vector>

class Locais 
{
	private:
		std::string nome;
		int index;
		std::vector<Insumo*> insumos;

	public:
		void setAtributos(std::string nome, int index);
		void setInsumo(Insumo *ptr);
		std::vector<Insumo*> getInsumos();
		
		Locais();
		~Locais();

};
#endif