#include "StorageManager.h"  
using namespace std;

StorageManager::StorageManager()
{
	
}
	
void StorageManager::lerInsumosPorLocal(Locais &loc){
    ifstream file;
    file.open("Estoque.csv", fstream::in);
    
    if(file.is_open()){
        bool existeInsumo = false;
        
        while(!file.eof()){
            string aux;
            vector<string> atributos;
            string palavra;
            int x = 9;
            bool verificaLocal = false;

            getline(file, aux);     //Lê linha por linha, colocando em aux
            
            if(aux.size()){ // Verifica se há conteúdo na linha
                istringstream linhaInsumo(aux); //Transforma em uma stream
                
                //Lê a linha do insumo e vai colocando cada palavra em um vector para ser usada como atributo
                //o número x corresponde ao número de atributos de cada insumo 
                for(int i=0; i<x; i++){
                    getline(linhaInsumo, palavra, ',');
                    
                    try{
                        if(i==0 && (stoi(palavra) == loc.getIndex()) ){ // Verifica se a primeira palavra contém o index do local escolhido
                            verificaLocal = true;
                        }
                        if( verificaLocal && i!=0){ // Verifica se a primeira palavra da linha tem o mesmo index do local
                            
                            if(!existeInsumo){
                                loc.deletaTodosInsumos();
                                existeInsumo = true;
                            }

                            if(i==1){
                                switch(stoi(palavra)){

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
                    catch(std::invalid_argument){
                        cout << "Invalid argument" << endl;
                    }
                }
                
                try{
                    Insumo *generico;
                    switch(std::stoi(atributos[0])){ // Verifica a coluna do tipo
                        case VACINA:
                        {
                            generico = new Vacina(atributos);
                            break;
                        }
                        case MEDICAMENTO:
                        {
                            generico = new Medicamento(atributos);
                            break;
                        }
                        case EPI:
                        {
                            generico = new Epi(atributos);
                            break;
                        }
                    }
                    loc.setInsumo(generico);
                }
                catch(std::exception){
                    cout << " Ocorreu um erro " << endl;
                }
            }
        }
        file.close();
    }
    else{
        cout<< "Não foi possivel abrir o arquivo!" << endl;
    }

}

void StorageManager::lerInsumos(Controler &ct)
{
    ifstream file;
    file.open("Estoque.csv", fstream::in);
    
    if(file.is_open()){
        bool existeInsumo = false;
        
        while(!file.eof()){
            string aux;
            vector<string> atributos;
            string palavra;
            int x = 9;
            int local = 0;

            getline(file, aux);//Lê linha por linha, colocando em aux
            
            
            if(aux.size()){ // Verifica se há conteúdo na linha
                istringstream linhaInsumo(aux); //Transforma em uma stream
                
                //Lê a linha do insumo e vai colocando cada palavra em um vector para ser usada como atributo
                //o número x corresponde ao número de atributos de cada insumo 
                for(int i=0; i<x; i++){
                    getline(linhaInsumo, palavra, ',');
                    
                    try{
                        if(i==0){ // Verifica se a primeira palavra contém o index do local escolhido
                            local = stoi(palavra);
                        }
                        if(i!=0){ // Verifica se a primeira palavra da linha tem o mesmo index do local
                            
                            if(!existeInsumo){
                                for( int i = 0; i < 28; i ++){
                                    ct.getLocal(i).deletaTodosInsumos();
                                }
                                existeInsumo = true;
                            }

                            if(i==1){
                                switch(stoi(palavra)){

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
                    catch(std::invalid_argument){
                        cout << "Invalid argument" << endl;
                    }
                }
                
                try{
                    Insumo *generico;
                    switch(std::stoi(atributos[0])){ // Verifica a coluna do tipo
                        case VACINA:
                        {
                            generico = new Vacina(atributos);
                            break;
                        }
                        case MEDICAMENTO:
                        {
                            generico = new Medicamento(atributos);
                            break;
                        }
                        case EPI:
                        {
                            generico = new Epi(atributos);
                            break;
                        }
                    }
                    
                    ct.getLocal(local).setInsumo(generico);
                }
                catch(std::exception){
                    cout << " Ocorreu um erro " << endl;
                }
            }
        }
        file.close();
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
