#include "Epi.h"  
#include <iostream>
using namespace std;
	
Epi::Epi()
{
    nome = "Cleitinho";
    quantidade =  10000;
	valorUnit = 90.5;
	dtVencimento = "15/10/2001";
	nomeFabricante = "Joca Cornelio";
	tipoInsumo = EPI;
	tipo = "Mascara P95";
	descricao = "Tudo de bom para vc querido cliente amigo";
}

Epi::Epi(Insumo *epi)
{
    this->nome = epi->getNome();
    this->quantidade = epi->getQuantidade();
    this->tipoInsumo = epi->getTipoInsumo();
    this->valorUnit = epi->getValorUnit();
    this->dtVencimento = epi->getDtVencimento();
    this->nomeFabricante= epi->getNomeFabricante();
    this->tipo = ((Epi*)epi)->getTipo();
    this->descricao = ((Epi*)epi)->getAtDescricao();

}	
Epi::~Epi()
{
	
}

void Epi::getDescricao()
{
    Insumo::getDescricao();
    cout << "Tipo de EPI: " << tipo << endl;
    cout << "Descricao: " << descricao << endl;
    cout << "--------------------------------------" << endl << endl;
}

std::string Epi::getTipo()
{
    return tipo;
}

std::string Epi::getAtDescricao()
{
    return descricao;
}

void Epi::setTipo(std::string tipo)
{
    this->tipo = tipo;
}   

void Epi::setAtDescricao(std::string desc)
{
    this->descricao = desc;
}
void Epi::insereEspecificos(std::string tipo, std::string descricao)
{
    this->tipo = tipo;
    this->descricao = descricao;
}

void Epi::salvaAtributos(ofstream &file){
    file << tipo << ",";
    file << descricao << endl;
}

void Epi::setAtributos(std::vector<string> atributos){
    tipoInsumo = stoi(atributos[0]);
    nome = atributos[1];
    quantidade = stol(atributos[2]);
    valorUnit = stod(atributos[3]);
    dtVencimento = atributos[4];
    nomeFabricante = atributos[5];
    tipo = atributos[6];
    descricao = atributos[7];
}