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

void Locais::deletaInsumos(int i){
    std::cout << i << std::endl;
    insumos.erase(insumos.begin()+(i+1));
    for(int i = 0; i<)
    //{
    //int main ()
    //std::vector<int> myvector;
    //myvector.push_back (100);
    //myvector.push_back (200);
    //myvector.push_back (300);

    //std::cout << "myvector contains:";
    //for (unsigned i=0; i<myvector.size(); i++)
    //    std::cout << ' ' << myvector[i];
    //std::cout << '\n';

    //myvector.clear();
    //myvector.push_back (1101);
    //myvector.push_back (2202);

    //std::cout << "myvector contains:";
    //for (unsigned i=0; i<myvector.size(); i++)
    //    std::cout << ' ' << myvector[i];
    //std::cout << '\n';

    //return 0;
    //}
    //Editar e executar
}
