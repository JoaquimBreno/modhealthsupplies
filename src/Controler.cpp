#include "Controler.h"  
#include <iostream>
#include <vector>
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


void Controler::distribuiInsumo(Locais dest, Insumo *insumo, long quantidade){
    
    Insumo *copia;

    //Verificando se há insumos suficientes:

    for(Insumo *ins : locais[0].getInsumos()){              //Percorre o vector de insumos do MS

        //Se achar o insumo que estamos distribuindo, faça:
        if(ins == insumo){
            if(ins->getQuantidade() < quantidade){
                std::cout << "Nao ha insumos suficientes no estoque MS." << std::endl; 
            }
        }
    }

    switch(insumo->getTipoInsumo()){

        case VACINA:
        copia = copiaVacina(insumo);
    }

    //copia.recebeAtributos();

    dest.setInsumo(copia);                                        //Coloca o insumo no destino
    dest.getInsumos().back()->setQuantidade(quantidade);          //Muda a quantidade do insumo no destino para a quant que queremos mandar
    cout << locais[0].getInsumos()[0]->getQuantidade() << endl;
    
    //Agora vamos subtrair o insumo mandado lá do MS

    for(Insumo *ins : locais[0].getInsumos()){              //Percorre o vector de insumos do MS

        //Se achar o insumo que estamos distribuindo, faça:
        if(ins == insumo){
            long quantidadeMS = ins->getQuantidade();
            ins->setQuantidade(ins->getQuantidade() - quantidade);  //Muda a qunatidade para a que existia menos a que foi distribuída
        }

    }

    locais[0].getInsumos()[0]->getDescricao();

}


void Controler::delecaoDeInsumo(Locais &loc)
{   
    
    loc.deletaInsumos();//deleta o insumo dentro do vetor insumos

}

Insumo* copiaVacina(Vacina *insumo)
{
    Insumo *copia;

    copia = new Vacina(insumo, insumo->getQuantDoses(), insumo->getTipoVac(), insumo->getIntervalo());
        
    return copia;
}

Insumo* copiaMedicamento(Medicamento *insumo)
{
    Insumo *copia;

    copia = new Medicamento(insumo,insumo->getDosagem(), insumo->getAdministracao(), insumo->getDisponibilizacao());
        
    return copia;
}

Insumo* copiaEpi(Epi *insumo)
{
    Insumo *copia;

    copia = new Epi(insumo,insumo->getTipo(), insumo->getAtDescricao());
        
    return copia;
}
