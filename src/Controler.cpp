#include "Controler.h"  
using namespace std;

Controler::Controler()
{
	string nomesLocais[28] = {"Ministério da Saude", "Acre","Alagoas","Amapá","Amazonas","Bahia","Ceará","Distrito Federal","Espírito Santo",
    "Goiás","Maranhão","Mato Grosso","Mato Grosso do Sul","Minas Gerais","Pará","Paraíba","Paraná","Pernambuco","Piauí",
    "Rio de Janeiro","Rio Grande do Norte","Rio Grande do Sul","Rondônia","Roraima","Santa Catarina","São Paulo","Sergipe",
    "Tocantins"};
	for(int i=0; i<28; i++){
        locais[i].setAtributos(nomesLocais[i], i);
    }
}
	
Controler::~Controler()
{
	
}

void Controler::cadastraInsumosMS(Insumo *insFilho)
{
    locais[0] = insFilho;
}

void Controler::consultaInsumos(Locais loc)
{

}
void Controler::consultaInsumosDescricao(Locais loc)
{

}
Insumo Controler::consultaInsumo(Locais loc, int tipoInsumo)
{

}
void Controler::distribuiInsumo(Locais dest, Insumo insumo)
{

}

