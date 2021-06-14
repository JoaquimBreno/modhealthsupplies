#ifndef LOCAIS_H
#define LOCAIS_H
#include <string>
#include "Insumo.h"
#include <vector>
#include <algorithm>

class Locais 
{
	private:
		std::string nome;
		int index;
		std::vector<Insumo*> insumos;

	public:
		void setAtributos(std::string nome, int index);
		void setInsumo(Insumo *ptr);
		void deletaInsumos();
		void deletaTodosInsumos();
		std::vector<Insumo*> getInsumos();
		std::string getNome();
		int getIndex();
		
		
		Locais();
		~Locais();

};
#endif