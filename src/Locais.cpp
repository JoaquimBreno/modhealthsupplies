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
    return this->insumos;
}

std::vector<Insumo*> Locais::deletaInsumos(){
    insumos.erase(std::remove(insumos.begin(), insumos.end(), "map"), insumos.end());
}