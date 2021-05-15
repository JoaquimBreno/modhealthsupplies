#include "Menu.h"  
#include <iostream>
#include "Vacina.h"	
#include "Controler.h"
using namespace std;

Menu::Menu(){
	
}
	
Menu::~Menu(){

}

void Menu::exibeMenu1(){
    Controler ct;
    Vacina vac;
    
    
    ct.cadastraInsumosMS(&vac);
}

void Menu::exibeMenu2(){
}	