#include "Insumo.h" 
#include <iostream>
using namespace std;
	
Insumo::Insumo()
{
	
}

Insumo::~Insumo()
{
   
}


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

void Insumo::getDescricao(){
    cout << "Nome: " << getNome() << endl;
    cout <<	"Quantidade: " << getQuantidade() << endl;
	cout <<	"Valor unitario: R$ " << getValorUnit() << endl;
	cout << "Data de vencimento: " <<	getDtVencimento() << endl;
	cout <<	"Fabricante: " << getNomeFabricante() << endl;
}

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

void Insumo::insereEspecificos()
{

}
void Insumo::salvaAtributos(ofstream &file)
{
    
}

void Insumo::setAtributos(std::vector<string> atributos){

}