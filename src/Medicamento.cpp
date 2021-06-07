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
    this->dosagem = ((Medicamento*)med)->getDosagem();
    this->administracao = ((Medicamento*)med)->getAdministracao();
    this->disponibilizacao= ((Medicamento*)med)->getDisponibilizacao();

}

Medicamento::Medicamento(vector<string> atributos){

    this->tipoInsumo = std::stoi(atributos[0]);    
    this->nome = atributos[1];
    this->quantidade = std::stol(atributos[2], nullptr, 10);
    this->valorUnit = std::stod(atributos[3]);
    this->dtVencimento = atributos[4];
    this->nomeFabricante= atributos[5];
    this->dosagem = atributos[6];
    this->administracao = atributos[7];
    this->disponibilizacao= atributos[8];
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
