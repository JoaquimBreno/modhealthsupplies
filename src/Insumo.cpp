#include "Insumo.h"  
	
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
float Insumo::valorUnitario(){
    return valorUnitario;
}

std::string Insumo::getDtVencimento(){
    return dtVencimento;
}

std::string Insumo::getNomeFabricante(){
    return nomeFabricante;
}