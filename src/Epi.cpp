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
	descricao = "Tudo de bom para vc , querido cliente amigo";
}

Epi::Epi(Insumo *epi, std::string tipo, std::string descricao)
{
    this->nome = epi->getNome();
    this->quantidade = epi->getQuantidade();
    this->tipoInsumo = epi->getTipoInsumo();
    this->valorUnit = epi->getValorUnit();
    this->dtVencimento = epi->getDtVencimento();
    this->nomeFabricante= epi->getNomeFabricante();
    this->tipo = tipo;
    this->descricao = descricao;
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