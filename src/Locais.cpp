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
    insumos.erase(insumos.begin()+(i));
    this->insumos=insumos;
    // for(int x = 0; x<insumos.size(); x++){
    //     insumos[x]->getDescricao();
    // }
}
