#include "Vacina.h"
	
Vacina::Vacina()
{
	nome = "Lepo Lepo";
    quantidade = 10;
    quantDoses = 10;
    tipoInsumo = 1;
    
}

std::string Insumo::getDescricao(){
    std::cout << "Nome: " << nome << "/n" << "Quantidade:" << quantidade << " unidades" << "/n" <<
    "Valor Unitario: " << "R$ " << valorUnit << "/n" << "Data de Vencimento: " << dtVencimento << "/n" <<
    "Nome do Fabricante: " << nomeFabricante << std::endl;
}

Vacina::~Vacina()
{
	
}