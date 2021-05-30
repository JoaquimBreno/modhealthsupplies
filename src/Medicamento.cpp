#include "Medicamento.h"  
using namespace std;

Medicamento::Medicamento()
{
    nome = "Juliette";
    quantidade = 10000;
    valorUnit = 150;
    dtVencimento = "21/12/2080";
    nomeFabricante = "Mae dela";
    tipoInsumo = MEDICAMENTO;
    dosagem = "18mg";
    administracao = "Venosa";
    disponibilizacao = "Garrafa Pet";
}
	
Medicamento::~Medicamento()
{
	
}

void Medicamento::getDescricao()
{
    Insumo::getDescricao();
    cout << "Dosagem: " << dosagem << endl;
    cout << "Administracao: " << administracao << endl;
    cout << "Disponibilizacao: " << disponibilizacao << endl;
    cout << "--------------------------------------" << endl << endl;
}

std::string Medicamento::getDosagem()
{
    return dosagem;
}

std::string Medicamento::getAdministracao()
{
    return administracao;
}

std::string Medicamento::getDisponibilizacao()
{
    return disponibilizacao;
}

void Medicamento::setDosagem(std::string dosagem)
{
    this->dosagem = dosagem;
}

void Medicamento::setAdministracao(std::string administracao)
{
    this->administracao = administracao;
}


void Medicamento::setDisponibilizacao(std::string disp)
{
    this->disponibilizacao = disp;
}
