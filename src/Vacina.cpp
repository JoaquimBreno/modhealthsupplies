#include "Vacina.h"

using namespace std;

Vacina::Vacina()
{
	nome = "Lepo Lepo";
    quantidade = 10000;
    quantDoses = 10;
    tipoInsumo = VACINA;
    valorUnit = 21;
    dtVencimento = "12/12/2012";
    nomeFabricante= "Rastafari";
    tipoVac = "Vacina de cerdas";
    intervalo = 15;
}

Vacina::Vacina(Insumo *vac){

    this->nome = vac->getNome();
    this->quantidade = vac->getQuantidade();
    this->tipoInsumo = vac->getTipoInsumo();
    this->valorUnit = vac->getValorUnit();
    this->dtVencimento = vac->getDtVencimento();
    this->nomeFabricante= vac->getNomeFabricante();
   

}


void Vacina::insereEspecificos(std::string tipoVac, int quantDoses, int intervalo)
{
    this->tipoVac = tipoVac;
    this->quantDoses = quantDoses;
    this->intervalo = intervalo;
}

void Vacina::getDescricao() 
{
    Insumo::getDescricao();
    cout << "Quantidade de doses: " << quantDoses << endl;
    cout << "Tipo da vacina: " << tipoVac << endl;
    cout << "Intervalo de doses: " << intervalo << " dias" << endl;
    cout << "--------------------------------------" << endl << endl;
    
}

Vacina::~Vacina()
{
	
}

std::string Vacina::getTipoVac()
{
    return tipoVac;
}

int Vacina::getQuantDoses()
{
    return quantDoses;
}

int Vacina::getIntervalo()
{
    return intervalo;
}

void Vacina::setTipoVac(std::string tVac)
{
    this->tipoVac = tVac;
}

void Vacina::setQuantDoses(int quant)
{
    this->quantDoses = quant;
}

void Vacina::setIntervalo(int intervalo)
{
    this->intervalo = intervalo;
}

void Vacina::salvaAtributos(ofstream &file){
    file << tipoVac << ",";
    file << quantDoses << ",";
    file << intervalo << endl;
}

void Vacina::setAtributos(std::vector<std::string> atributos){
    tipoInsumo = stoi(atributos[0]);
    nome = atributos[1];
    quantidade = stol(atributos[2]);
    valorUnit = stod(atributos[3]);
    dtVencimento = atributos[4];
    nomeFabricante = atributos[5];
    tipoVac = atributos[6];
    quantDoses = stoi(atributos[7]);
    intervalo = stoi(atributos[8]);
}