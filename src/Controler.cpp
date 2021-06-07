#include "Controler.h"  
#include <iostream>
#include <vector>
using namespace std;

Controler::Controler()
{
	string nomesLocais[28] = {"Ministerio da Saude", "Acre","Alagoas","Amapa","Amazonas","Bahia","Ceara","Distrito Federal","Espirito Santo",
    "Goias","Maranhao","Mato Grosso","Mato Grosso do Sul","Minas Gerais","Para","Paraiba","Parana","Pernambuco","Piaui",
    "Rio de Janeiro","Rio Grande do Norte","Rio Grande do Sul","Rondonia","Roraima","Santa Catarina","Sao Paulo","Sergipe",
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

Locais & Controler::getLocal(int index)
{
    return locais[index];
}

void Controler::consultaInsumosDescricao(Locais loc)
{   
    //Verifica se no local passado existe algum insumo cadastrado
    cout << loc.getInsumos().size() << endl;
    if(loc.getInsumos().size() > 0){

        //Se sim, faça 3 fors percorrendo os insumos
        //Na ordem vacina, medicamento e epi
        
        for(Insumo *ins : loc.getInsumos()){// For each insumo em insumos
            if(ins->getTipoInsumo() == VACINA){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
                std::cout << "Vacina: " << endl << endl;
                ins->getDescricao();
            }
        }

        for(Insumo *ins : loc.getInsumos()){ 
            if(ins->getTipoInsumo() == MEDICAMENTO){ 
                std::cout << "Medicamento: " <<endl << endl;
                ins->getDescricao();
            }
        }

        for(Insumo *ins : loc.getInsumos()){
            if(ins->getTipoInsumo() == EPI){
                std::cout << "EPI: " << endl << endl;
                ins->getDescricao();
            }
        }   
    }
    else{
        cout << "Nao ha insumos nesse local..." << endl;
    }
}

vector <Insumo*> Controler::consultaInsumoPorTipo(Locais loc, int tipoInsumo)
{
    cout << "ENTROU !" << endl;
    vector<Insumo*> vec;
    for(Insumo *ins : loc.getInsumos()){// For each insumo em locais
        if(ins->getTipoInsumo() == tipoInsumo){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
            vec.push_back(ins); // FAZER UMA EXCEPTION AQUI
        }
        cout << "PASSOU!" << endl;
    }

    //for(unsigned int i = 0; i < vec.size(); i++){
    //    vec[i]->getDescricao();
    //}
    
    return vec;
    
}


void Controler::distribuiInsumo(Locais &dest, Insumo *insumo, long quantidade){
    
    for(Insumo *ins : locais[0].getInsumos()){

        if(ins == insumo){

            if(ins->getQuantidade() < quantidade){
                std::cout << "Nao ha insumos suficientes no estoque MS." << std::endl; 
            }
            else{
                int iterator = 1;
                ins->setQuantidade(ins->getQuantidade() - quantidade);
                
                if(dest.getInsumos().size()){
                    for(Insumo *dins : dest.getInsumos()){ // Varre os insumos do destino
                        if(dins->getNome() == insumo->getNome()){ // Verifica se o nome é igual ao insumo do MS
                            std::cout << "chegou aqui1"<< std::endl; 
                            dins->setQuantidade(dins->getQuantidade() + quantidade); // Soma a quantidade;
                            break;
                        }
                        iterator++;
                    }
                }
                
                if(iterator == dest.getInsumos().size() || !dest.getInsumos().size()){ // Gera um novo insumo caso a verificação não encontrar insumos compatíveis
    
                    Insumo *copia;
                    switch (insumo->getTipoInsumo()){
                        case 1:
                            copia = new Vacina(ins);
                            break;
                        case 2:
                            copia = new Medicamento(ins);
                            break;
                        case 3:
                            copia = new Epi(ins);
                            break;               
                    }
                    copia->setQuantidade(quantidade);
                    dest.setInsumo(copia);     
                }  
            }
            
            break;
        }

    }
  
}


void Controler::delecaoDeInsumo(Locais &loc)
{   
    
    loc.deletaInsumos();//deleta o insumo dentro do vetor insumos

}

