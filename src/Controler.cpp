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
    //Verifica se no local passado existe algum insumo cadastrado
    if(loc.getInsumos().size() > 0){
        //Se sim, faça 3 fors percorrendo os insumos e printando nome do insumo e quantidade
        //Na ordem vacina, medicamento e epi
        
        for(Insumo *ins : loc.getInsumos()){// For each insumo em locais
            if(ins->getTipoInsumo() == VACINA){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
                cout << "Vacina: ";
                cout << ins->getNome() << endl << "Quantidade: "  << ins->getQuantidade() << endl << endl;
            }
        }

        for(Insumo *ins : loc.getInsumos()){ 
            if(ins->getTipoInsumo() == MEDICAMENTO){ 
                cout << "Medicamento: ";
                cout << ins->getNome() << endl << "Quantidade: "  << ins->getQuantidade() << endl << endl;
            }
        }

        for(Insumo *ins : loc.getInsumos()){
            if(ins->getTipoInsumo() == EPI){
                cout << "EPI: ";
                cout << ins->getNome() << endl << "Quantidade: "  << ins->getQuantidade() << endl << endl;
            }
        }
    }
    else{
        cout << "Nao ha insumos nesse local..." << endl;
    }
}

Locais Controler::getLocal(int index)
{
    return locais[index];
}

void Controler::consultaInsumosDescricao(Locais loc)
{
    /Verifica se no local passado existe algum insumo cadastrado
    if(loc.getInsumos().size() > 0){
        //Se sim, faça 3 fors percorrendo os insumos e printando nome do insumo e quantidade
        //Na ordem vacina, medicamento e epi
        
        for(Insumo *ins : loc.getInsumos()){// For each insumo em locais
            if(ins->getTipoInsumo() == VACINA){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
                cout << "Vacina: ";
                cout << ins->getNome() << endl << "Quantidade: "  << ins->getQuantidade() << endl << endl;
            }
        }

        for(Insumo *ins : loc.getInsumos()){ 
            if(ins->getTipoInsumo() == MEDICAMENTO){ 
                cout << "Medicamento: ";
                cout << ins->getNome() << endl << "Quantidade: "  << ins->getQuantidade() << endl << endl;
            }
        }

        for(Insumo *ins : loc.getInsumos()){
            if(ins->getTipoInsumo() == EPI){
                cout << "EPI: ";
                cout << ins->getNome() << endl << "Quantidade: "  << ins->getQuantidade() << endl << endl;
            }
        }
    }
    else{
        cout << "Nao ha insumos nesse local..." << endl;
    }
}

Insumo Controler::consultaInsumo(Locais loc, int tipoInsumo)
{

}
void Controler::distribuiInsumo(Locais dest, Insumo insumo)
{

}



