#include "Medicamento.h"  
using namespace std;

Medicamento::Medicamento()
{
    nome = "Juliette";
    quantidade = 0;
    valorUnit = 150;
    dtVencimento = "21/12/2080";
    nomeFabricante = "Mae dela";
    tipoInsumo = MEDICAMENTO;
    dosagem = "18mg";
    administracao = "Venosa";
    disponibilizacao = "Garrafa Pet";
}

Medicamento::Medicamento(Insumo *med)
{
    this->nome = med->getNome();
    this->quantidade = med->getQuantidade();
    this->tipoInsumo = med->getTipoInsumo();
    this->valorUnit = med->getValorUnit();
    this->dtVencimento = med->getDtVencimento();
    this->nomeFabricante= med->getNomeFabricante();
    
}

void Medicamento::insereEspecificos(std::string dos, std::string adm, std::string disp)
{
    this->dosagem = dosagem;
    this->administracao = administracao;
    this->disponibilizacao = disponibilizacao;
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

void Medicamento::salvaAtributos(ofstream &file)
{
    file << dosagem << ",";
    file << administracao <<",";
    file << disponibilizacao << endl;
}
