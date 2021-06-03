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

void Medicamento::setAtributos(std::vector<string> atributos){ 
    
    tipoInsumo = stoi(atributos[0]); // Converte string para inteiro
    nome = atributos[1];
    quantidade = stol(atributos[2]); // Converte string para long
    valorUnit = stod(atributos[3]); // Converte string para double
    dtVencimento = atributos[4];
    nomeFabricante = atributos[5];
    dosagem = atributos[6];
    administracao = atributos[7];
    disponibilizacao = atributos[8];
    
}