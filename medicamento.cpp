#include "medicamento.h"
using namespace std;

Medicamento::Medicamento()
{

}

Medicamento::Medicamento(Insumo *med)
{
    this->nome = med->getNome();
    this->quantidade = med->getQuantidade();
    this->tipoInsumo = med->getTipoInsumo();
    this->valorUnit = med->getValorUnit();
    this->dtVencimento = med->getDtVencimento();
    this->nomeFabricante= med->getNomeFabricante();
    //atributos relacionados a medicamentos
    this->dosagem = ((Medicamento*)med)->getDosagem();
    this->administracao = ((Medicamento*)med)->getAdministracao();
    this->disponibilizacao= ((Medicamento*)med)->getDisponibilizacao();

}

Medicamento::Medicamento(vector<string> atributos){
    //construtor que inicializa os atributos a partir de um vetor de string que vem do arquivo
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

std::string Medicamento::getDescricao()
{
    //acrescimo da descrição relacionada a Vacina
    std::string frase = Insumo::getDescricao() +
    + "Dosagem: " + dosagem + "\n"
    + "Administração: " + administracao +  "\n"
    + "Disponibilização: " + disponibilizacao + " dias" + "\n" +
     "--------------------------------------" + "\n" + "\n";
    return frase;
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
    //adiciona ao final da linha do arquivo, os atributos referentes apenas aos medicamentos, seguido por virgulas.
    file << dosagem << ",";
    file << administracao <<",";
    file << disponibilizacao << endl;
}
