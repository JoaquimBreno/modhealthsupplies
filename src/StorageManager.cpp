#include "StorageManager.h"  
#include "Insumo.h"
using namespace std;

StorageManager::StorageManager()
{
	
}
	
void StorageManager::lerInsumos()
{

}

void StorageManager::salvarInsumos(vector<Insumo*> ins)
{
    ofstream file;
    file.open("Estoque.csv", fstream::out);
    
    if(file.is_open())
    {
        for(int i = 0; i < ins.size(); i++){
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
