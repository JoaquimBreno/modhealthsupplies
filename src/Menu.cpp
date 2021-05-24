#include "Menu.h"  
#include <vector>
#include <iostream>
#include "Vacina.h"	
#include "Insumo.h"
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
    
    //ct.cadastraInsumosMS(vac);
    //ct.cadastraInsumosMS(med);
    ct.cadastraInsumosMS(epi);

   int tipo;
    
    //cin >> tipo;
    //cin.ignore(); 
    
    //vector<Insumo*> teste;
    //teste = ct.consultaInsumoPorTipo(ct.getLocal(0), tipo);

    //for( int i = 0 ; i < teste.size(); i++){
    //    teste[i]->getDescricao();
    //}
    ct.delecaoDeInsumo(ct.getLocal(0));
    ct.consultaInsumos(ct.getLocal(0));

}

void Menu::exibeMenu2(){
}	