#include "insumo.h"
#include <iostream>
using namespace std;

Insumo::Insumo()//construtor de insumos
{

}

Insumo::~Insumo()
{

}

//get's do tipo Insumo
int Insumo::getTipoInsumo()
{
    return tipoInsumo;
}
std::string Insumo::getNome(){
    return nome;
}

int Insumo::getQuantidade(){
    return quantidade;
}

double Insumo::getValorUnit(){
    return valorUnit;
}

std::string Insumo::getDtVencimento(){
    return dtVencimento;
}

std::string Insumo::getNomeFabricante(){
    return nomeFabricante;
}

//set´s do tipo Insumo
void Insumo::setQuantidade(int quant)
{
    this->quantidade = quant;
}

void Insumo::setNome(std::string n)
{
    this->nome = n;
}

void Insumo::setValorUnit(double valor)
{
    this->valorUnit = valor;
}

void Insumo::setDtVencimento(std::string dt)
{
    this->dtVencimento = dt;
}

void Insumo::setNomeFabricante(std::string nomeFabri)
{
    this->nomeFabricante = nomeFabri;
}

void Insumo::setTipoInsumo(int tipo)
{
    this->tipoInsumo = tipo;
}

void Insumo::salvaAtributos(ofstream &file)
{

}

void Insumo::setAtributos(std::string nome, long quantidade, double valorUnit, std::string dtVencimento, std::string nomeFabricante, int tipoInsumo)
{
    this->nome = nome;
    this->quantidade = quantidade;
    this->valorUnit = valorUnit;
    this->dtVencimento = dtVencimento;
    this->tipoInsumo = tipoInsumo;
    this->nomeFabricante = nomeFabricante;
}

std::string Insumo::getDescricao(){
    //descrição fixa de todos os insumos
    std::string descricao = "Nome: " + getNome() + "\n"
    +	"Quantidade: " + to_string(getQuantidade()) + "\n"
    +	"Valor unitario: R$ " + to_string(getValorUnit()) + "\n"
    + "Data de vencimento: " + getDtVencimento() + "\n"
    +	"Fabricante: " + getNomeFabricante() + "\n";
    return descricao;
}
