#include "StorageManager.h"  
using namespace std;

StorageManager::StorageManager()
{
	
}

void StorageManager::lerInsumos(Controler &ct)
{
    ifstream file;
    file.open("Estoque.csv", fstream::in); //abrir arquivo csv para leitura
    
    if(file.is_open()){
        bool existeInsumo = false;
        
        while(!file.eof()){
            //estrutura de repetição para ser verdade enquanto o arquivo nao chegar ao fim 
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
                            if(i==0){ // Transforma a primeira palavra no index do local 
                                local = stoi(palavra);
                            }
                            if(i!=0){ 
                                
                                if(!existeInsumo){
                                    //condição para deletar todos os insumos de todos os locais
                                    for( int i = 0; i < 28; i ++){
                                        ct.getLocal(i).deletaTodosInsumos();
                                    }
                                    existeInsumo = true;
                                }
                                //Esse switch muda o numero de iterações de acordo com a quantidade de atributos
                                //referentes ao tipo de insumo daquela linha
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
                            //forma um vector contendo o conteudo da linha    
                            atributos.push_back(palavra);
                            }
                        }
                        catch(std::invalid_argument){   //Pega o erro derivado da função stoi()
                            cout << "Invalid argument" << endl;
                        }
                    }
                    
                    try{
                        Insumo *generico;
                        //Esse switch inicializa o ponteiro "generico" com o tipo de insumo dependendo linha
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
                        
                        //Cadastra o insumo da linha no local da linha
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
    file.open("Estoque.csv", fstream::out); //abre o arquirvo para a escrita 
    if(file.is_open()){
        for(int x = 0; x < 28 ; x++){ //percorre os locais um por um
            if(ct.getLocal(x).getInsumos().size() > 0){ //Se o vector de insumos do local tiver algum insumo faça:
                //Percorre o vector de insumos escrevendo cada insumo no arquivo
                for(int i = 0; i < ct.getLocal(x).getInsumos().size(); i++){
                    file << ct.getLocal(x).getIndex() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getTipoInsumo() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getNome() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getQuantidade() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getValorUnit() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getDtVencimento() << ",";
                    file << ct.getLocal(x).getInsumos()[i]->getNomeFabricante() << ",";
                    
                    //Parte personalizada dos atributos de acordo com o tipo de insumo
                    ct.getLocal(x).getInsumos()[i]->salvaAtributos(file);
                }
            
            }
        }
    file.close();
    
    
    }else{
        cout << "Nao foi possivel abrir o arquivo!" << endl;
    }
    
}
