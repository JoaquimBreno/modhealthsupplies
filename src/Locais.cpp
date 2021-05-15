#include "Locais.h"  
	
Locais::Locais()
{
    
}
	
Locais::~Locais()
{
	
}

void Locais::setAtributos(std::string nome, int index)
{
    this->nome = nome;
    this->index = index;
}

void Locais::setInsumo(Insumo *ptr)
{
    insumos.push_back(ptr);
}