#include "Controler.h"  
#include <iostream>
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
    //No local MS, coloca no array de Insumos o insumo "insFilho"
    locais[0].setInsumo(insFilho);
}

void Controler::consultaInsumos(Locais loc)
{
    if(loc.getInsumos().size() > 0){

        for(Insumo *ins : loc.getInsumos()){
            if(ins->getTipoInsumo() == VACINA){
                cout << ins
            }
        }
    }
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

