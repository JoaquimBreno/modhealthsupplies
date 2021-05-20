#include "Menu.h"  
#include <iostream>
#include "Vacina.h"	
#include "Epi.h"	
#include "Medicamento.h"	
#include "Controler.h"
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
    ct.consultaInsumosDescricao(ct.getLocal(0)); 
    //ct.consultaInsumos(ct.getLocal(0));
}

void Menu::exibeMenu2(){
}	