#ifndef LOCAIS_H
#define LOCAIS_H
#include <string>
#include "Insumo.h"

class Locais 
{
	private:
		std::string nome;
		int index;
		Insumo *insumos[100];
		
	public:
		void setAtributos(std::string nome, int index);
		void setInsumo(Insumo *ptr);
		
		Locais();
		~Locais();

};
#endif