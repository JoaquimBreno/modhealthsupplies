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
//print
std::vector<Insumo*> Locais::getInsumos()
{
    return insumos;
}

void Locais::deletaInsumos(int i){
     
    delete [] insumos[i];
    insumos.erase(insumos.begin()+(i));
}
