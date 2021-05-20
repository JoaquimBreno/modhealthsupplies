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

std::string Insumo::getDescricao(){
    cout << "Nome: " << getNome() << endl;
    cout <<	"Quantidade: " << getQuantidade() << endl;
	cout <<	"Valor unitario: R$ " << getValorUnit() << endl;
	cout << "Data de vencimento: " <<	getDtVencimento() << endl;
	cout <<	"Fabricante: " << getNomeFabricante() << endl;
}