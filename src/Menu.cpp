#include "Menu.h"  
#include <vector>
#include <iostream>
#include "Vacina.h"	
#include "Insumo.h"
#include "Epi.h"	
#include "Medicamento.h"	
#include "Controler.h"
#include "StorageManager.h"

using namespace std;

Menu::Menu(){
	
}
	
Menu::~Menu(){

}

void Menu::exibeMenu1(){
    Controler ct;
    Insumo *vac = new Vacina();
    Insumo *med = new Medicamento();
    Insumo *epi = new Epi();
    
    ct.cadastraInsumosMS(vac);
    ct.cadastraInsumosMS(med);
    ct.cadastraInsumosMS(epi);

    ct.distribuiInsumo(ct.getLocal(1), ct.getLocal(0).getInsumos()[0], 500);
    //StorageManager pers;

    //pers.salvarInsumos(ct.getLocal(0).getInsumos());
    


}

void Menu::exibeMenu2(){
}	