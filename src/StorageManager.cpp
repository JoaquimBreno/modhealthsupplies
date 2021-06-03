#include "StorageManager.h"  
using namespace std;

StorageManager::StorageManager()
{
	
}
	
void StorageManager::lerInsumos(Locais &loc)
{
    ifstream file;
    file.open("Estoque.csv", fstream::in);
    
    if(file.is_open())
    {
        bool existeInsumo = false;
        
        while(!file.eof()){
            string aux;
            vector<string> atributos;
            string palavra;
            int x = 9;
            bool verificaLocal = false;

            getline(file, aux);     //Lê linha por linha, colocando em aux
        
            istringstream linhaInsumo(aux); //Transforma em uma stream
            
            //Lê a linha do insumo e vai colocando cada palavra em um vector para ser usada como atributo
            //o número x corresponde ao número de atributos de cada insumo 
            for(int i=0; i<x; i++){
                getline(linhaInsumo, palavra, ',');
            
                if(i==0 && (stoi(palavra) == loc.getIndex()) ){
                    verificaLocal = true;
                }
                if( verificaLocal && i!=0){ // Verifica se a primeira palavra da linha tem o mesmo index do local
                    
                    if(!existeInsumo){
                        loc.deletaTodosInsumos();
                        existeInsumo = true;
                    }

                    if(i==1){
                        switch(stoi (palavra)){

                            case VACINA:
                                x = 10;
                                break;
                            case MEDICAMENTO:
                                x = 10;
                                break;
                            case EPI:
                                x = 9;
                                break;
                        }
                    }
                    
                   atributos.push_back(palavra);
                }
            }

            switch(stoi(atributos[0])){ // Verifica a coluna do tipo
                case VACINA:
                {
                    Insumo *vac = new Vacina();
                    vac->setAtributos(atributos);
                    loc.setInsumo(vac);
                    delete vac;
                    break;
                }
                case MEDICAMENTO:
                {
                    Insumo *med = new Medicamento();
                    med->setAtributos(atributos);
                    loc.setInsumo(med);
                    delete med;
                    break;
                }
                case EPI:
                {
                    Insumo *epi = new Epi();
                    epi->setAtributos(atributos);
                    loc.setInsumo(epi);
                    delete epi;
                    break;
                }
            }
            
        }

    }
    else{
        cout<< "Não foi possivel abrir o arquivo!" << endl;
    }

}

void StorageManager::salvarInsumos(vector<Insumo*> ins, Locais loc)
{   
    
    ofstream file;
    file.open("Estoque.csv", fstream::out);
    
    if(file.is_open())
    {

        for(int i = 0; i < ins.size(); i++){
            file << loc.getIndex() << ",";
            file << ins[i]->getTipoInsumo() << ",";
            file << ins[i]->getNome() << ",";
            file << ins[i]->getQuantidade() << ",";
            file << ins[i]->getValorUnit() << ",";
            file << ins[i]->getDtVencimento() << ",";
            file << ins[i]->getNomeFabricante() << ",";
            
            ins[i]->salvaAtributos(file);
        }
       
    }
    else{
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }
     file.close();
}
