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
        string aux;
        vector<string> atributos;
        string palavra;
        int x = 9;

        while(!file.eof()){
            getline(file, aux);     //Lê linha por linha, colocando em aux
            
            if(aux == loc.getNome()){   //Se achar uma linha igual ao nome do local desejado, faça:
                getline(file, aux);     //Lê a linha seguinte
                istringstream linhaInsumo(aux); //Transforma em uma stream
                
                //Lê a linha do insumo e vai colocando cada palavra em um vector para ser usada como atributo
                //o número x corresponde ao número de atributos de cada insumo 
                for(int i=0; i<x; i++){
                    getline(linhaInsumo, palavra, ',');
                    
                    if(i==0){
                        switch(stoi(palavra)){
                            case VACINA:
                                x = 9;
                                break;
                            case MEDICAMENTO:
                                x = 9;
                                break;
                            case EPI:
                                x = 8;
                                break;
                        }

                    }
                    atributos.push_back(palavra);
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
            file << loc.getNome() << ",";
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
