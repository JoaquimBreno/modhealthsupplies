#include "controler.h"
#include <math.h>
#include <iostream>
#include <QMessageBox>
using namespace std;

Controler::Controler()
{
    string nomesLocais[28] = {"Ministério da Saúde", "Acre","Alagoas","Amapá","Amazonas","Bahia","Ceará","Distrito Federal","Espírito Santo",
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

Locais *Controler::getLocais(){
    return locais;
}

void Controler::cadastraInsumosMS(Insumo *insFilho)
{
    //No local MS, coloca no array de Insumos o insumo "insFilho"
    locais[0].setInsumo(insFilho);
}

std::vector<std::string> Controler::consultaInsumos(Locais &loc)
{
    std::vector<std::string> insumosqtd;
    //Verifica se no local passado existe algum insumo cadastrado
    if(loc.getInsumos().size() > 0){
        //Se sim, faça 3 fors percorrendo os insumos e printando nome do insumo e quantidade
        //Na ordem vacina, medicamento e epi

        for(Insumo *ins : loc.getInsumos()){// For each insumo em locais
            if(ins->getTipoInsumo() == 1){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
                std::string qtde = std::to_string(ins->getQuantidade());
                std::string valor = std::to_string(ceilf(ins->getValorUnit()*((double)ins->getQuantidade()) * 100) / 100);
                insumosqtd.push_back("Vacina: " + ins->getNome() + " Quantidade: " + qtde + " Valor total: R$" + valor);
            }
        }

        for(Insumo *ins : loc.getInsumos()){
            if(ins->getTipoInsumo() == 2){
                std::string qtde = std::to_string(ins->getQuantidade());
                std::string valor = std::to_string(ceilf(ins->getValorUnit()*((double)ins->getQuantidade()) * 100) / 100);
                insumosqtd.push_back("Medicamento: " + ins->getNome() + " Quantidade: " + qtde + " Valor total: R$" + valor);
            }
        }

        for(Insumo *ins : loc.getInsumos()){
            if(ins->getTipoInsumo() == 3){
                std::string qtde = std::to_string(ins->getQuantidade());
                std::string valor = std::to_string(ceilf(ins->getValorUnit()*((double)ins->getQuantidade()) * 100) / 100);
                insumosqtd.push_back("Epi: " + ins->getNome() + " Quantidade: " + qtde + " Valor total: R$" + valor);
            }
        }

        return insumosqtd;
    }
    else{
        insumosqtd.clear();
        return {};
    }
}

std::vector<std::string> Controler::consultaInsumosDescricao()
{
    //Verifica se no local passado existe algum insumo cadastrado
    vector<string> frases;
    for(int i =0 ; i < 28; i++){
        if(getLocal(i).getInsumos().size() > 0){

            //Se sim, faça 3 fors percorrendo os insumos
            //Na ordem vacina, medicamento e epi

            for(Insumo *ins : getLocal(i).getInsumos()){// For each insumo em insumos
                if(ins->getTipoInsumo() == VACINA){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
                    std::string frase = "Local " + to_string(i) + "\n" + "Vacina: " + "\n" + ins->getDescricao();
                    frases.push_back(frase);
                }
            }

            for(Insumo *ins : getLocal(i).getInsumos()){
                if(ins->getTipoInsumo() == MEDICAMENTO){
                    std::string frase = "Local " + to_string(i) + "\n" + "Medicamento: " + "\n" + ins->getDescricao();
                    frases.push_back(frase);
                }
            }

            for(Insumo *ins : getLocal(i).getInsumos()){
                if(ins->getTipoInsumo() == EPI){
                    std::string frase = "Local " + to_string(i) + "\n" + "Epi: " + "\n" + ins->getDescricao();
                    frases.push_back(frase);
                }
            }
        }
   }
   return frases;
}

std::vector<std::string> Controler::consultaInsumosDescricaoLocal(Locais &loc)
{
    //Verifica se no local passado existe algum insumo cadastrado
    vector<string> frases;
        if(loc.getInsumos().size() > 0){

            //Se sim, faça 3 fors percorrendo os insumos
            //Na ordem vacina, medicamento e epi

            for(Insumo *ins : loc.getInsumos()){// For each insumo em insumos
                if(ins->getTipoInsumo() == VACINA){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
                    std::string frase = "Vacina: " + ins->getDescricao();
                    frases.push_back(frase);
                }
            }

            for(Insumo *ins : loc.getInsumos()){
                if(ins->getTipoInsumo() == MEDICAMENTO){
                    std::string frase = "Medicamento: " + ins->getDescricao();
                    frases.push_back(frase);
                }
            }

            for(Insumo *ins : loc.getInsumos()){
                if(ins->getTipoInsumo() == EPI){
                    std::string frase ="Epi: " + ins->getDescricao();
                    frases.push_back(frase);
                }
            }
        }
        else{
            return {};
        }
   return frases;
}

vector <Insumo*> Controler::consultaInsumoPorTipo(Locais loc, int tipoInsumo)
{

    vector<Insumo*> vec;
    for(Insumo *ins : loc.getInsumos()){// For each insumo em locais
        if(ins->getTipoInsumo() == tipoInsumo){ // Pega o tipo do Insumo e verifica se é igual ao insumo definido como VACINA
            vec.push_back(ins);
        }
    }
    return vec;

}

void Controler::distribuiInsumo(Locais &dest, Insumo *insumo, long quantidade){

    for(Insumo *ins : locais[0].getInsumos()){

        if(ins == insumo){
            bool validator = false;

            if(ins->getQuantidade() < quantidade){
                continue;
            }
            else{

                ins->setQuantidade(ins->getQuantidade() - quantidade);

                if(dest.getInsumos().size()){
                    for(Insumo *dins : dest.getInsumos()){ // Varre os insumos do destino
                        if(dins->getNome() == insumo->getNome()){ // Verifica se o nome é igual ao insumo do MS,0
                            dins->setQuantidade(dins->getQuantidade() + quantidade); // Soma a quantidade;
                            validator = true;
                            break;
                        }

                    }
                }

                if(!validator || !dest.getInsumos().size()){ // Gera um novo insumo caso a verificação não encontrar insumos compatíveis

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

Locais & Controler::getLocal(int index)
{
    return locais[index];
}

void Controler::delecaoDeInsumo(Locais &loc)
{

    loc.deletaInsumos();//deleta o insumo dentro do vetor insumos

}


