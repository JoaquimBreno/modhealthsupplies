#include "epi.h"
#include <iostream>
using namespace std;

Epi::Epi()
{

}

Epi::Epi(Insumo *epi)
{
    this->nome = epi->getNome();
    this->quantidade = epi->getQuantidade();
    this->tipoInsumo = epi->getTipoInsumo();
    this->valorUnit = epi->getValorUnit();
    this->dtVencimento = epi->getDtVencimento();
    this->nomeFabricante= epi->getNomeFabricante();
    //atributos relacionados a epi
    this->tipo = ((Epi*)epi)->getTipo();
    this->descricao = ((Epi*)epi)->getAtDescricao();

}

Epi::Epi(vector<string> atributos){

    this->tipoInsumo = std::stoi(atributos[0]);
    this->nome = atributos[1];
    this->quantidade = std::stol(atributos[2], nullptr, 10);
    this->valorUnit = std::stod(atributos[3]);
    this->dtVencimento = atributos[4];
    this->nomeFabricante= atributos[5];
    this->tipo = atributos[6];
    this->descricao = atributos[7];
}

Epi::~Epi()
{

}

std::string Epi::getTipo()
{
    return tipo;
}

std::string Epi::getAtDescricao()
{
    return descricao;
}

std::string Epi::getDescricao()
{
    //acrescimo da descrição relacionada a Vacina
    std::string frase = Insumo::getDescricao() +
    + "Tipo: " + tipo + "\n"
    + "Descrição: " + descricao +  "\n"
     "--------------------------------------" + "\n" + "\n";
    return frase;
}


void Epi::setTipo(std::string tipo)
{
    this->tipo = tipo;
}

void Epi::setAtDescricao(std::string desc)
{
    this->descricao = desc;
}

void Epi::salvaAtributos(ofstream &file){

    //adiciona ao final da linha do arquivo, oa atributos refeentes apenas a epi
    file << tipo << ",";
    file << descricao << endl;
}
