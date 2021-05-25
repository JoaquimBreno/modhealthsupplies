#include "Vacina.h"
using namespace std;
	
Vacina::Vacina()
{
	nome = "Lepo Lepo";
    quantidade = 10;
    quantDoses = 10;
    tipoInsumo = VACINA;
    valorUnit = 21;
    dtVencimento = "12/12/2012";
    nomeFabricante= "Rastafari";
    tipo = "Vacina de cerdas";
    intervalo = 15;
}

void Vacina::getDescricao() 
{
    Insumo::getDescricao();
    cout << "Quantidade de doses: " << quantDoses << endl;
    cout << "Tipo da vacina: " << tipo << endl;
    cout << "Intervalo de doses: " << intervalo << " dias" << endl;
    cout << "--------------------------------------" << endl << endl;
    
}

Vacina::~Vacina()
{
	
}