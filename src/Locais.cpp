#include "Locais.h"  
	
Locais::Locais()
{
    
}
	
Locais::~Locais()
{

}
//get´s e set´s relacionados a Locais 
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

std::string Locais::getNome()
{
    return nome;
}

int Locais::getIndex()
{
    return index;
}

void Locais::deletaInsumos(){
    //função para retornar apenas o determinado insumo
    //que estiver com a quantidade menor ou igual que 0
    for(int i = 0; i<insumos.size(); i++){ // i=1 c =1
        if(insumos[i]->getQuantidade() <= 0){
            delete insumos[i];
            insumos.erase(insumos.begin()+i);
            i = -1;   
        }
    }

}

void Locais::deletaTodosInsumos(){
    //função para deletar todos os insumos
    for(int i = 0; i<insumos.size(); i++){
        delete insumos[i];
        insumos.erase(insumos.begin()+i);
        i = -1;   
    }

}