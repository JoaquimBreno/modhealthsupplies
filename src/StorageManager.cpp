#include "StorageManager.h"  
using namespace std;

StorageManager::StorageManager()
{
	
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
            
            try{
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
                        catch(ios_base::failure &fail){
                            cout << "Failure" << endl;
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
            catch(std::exception){
                cout << " Ocorreu um erro " << endl;
            }
        }

        file.close();
    }
    else{
        cout<< "Não foi possivel abrir o arquivo!" << endl;
    }

}

void StorageManager::salvarInsumos(Controler &ct)
{   

    ofstream file;
    file.open("Estoque.csv", fstream::out);
    if(file.is_open()){
        for(int x = 0; x < 28 ; x++){
            if(ct.getLocal(x).getInsumos().size() > 0){
                for(int i = 0; i < ct.getLocal(x).getInsumos().size(); i++){
                    file << ct.getLocal(x).getIndex() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getTipoInsumo() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getNome() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getQuantidade() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getValorUnit() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getDtVencimento() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getNomeFabricante() << ",";
                    
                    ct.getLocal(x).getInsumos()[i]->salvaAtributos(file);
                }
            
            }
        }
    file.close();
    
    }else{
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }
    
}
