#include "Epi.h"  
#include <iostream>
using namespace std;
	
Epi::Epi()
{
    nome = "Cleitinho";
    quantidade =  40;
	valorUnit = 90.5;
	dtVencimento = "15/10/2001";
	nomeFabricante = "Joca Cornelio";
	tipoInsumo = EPI;
	tipo = "Mascara P95";
	descricao = "Tudo de bom para vc , querido cliente amigo";
}
	
Epi::~Epi()
{
	
}

std::string Epi::getDescricao()
{
    Insumo::getDescricao();
    cout << "Tipo de EPI: " << tipo << endl;
    cout << "Descricao: " << descricao << endl;
    cout << "--------------------------------------" << endl << endl;
}

std::string Epi::getAtDescricao()
{
    return descricao;
}