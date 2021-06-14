#include <iostream>
#include <string>
#include <stdlib.h>
#include "Menu.h"

int main(void){
    while(1){
        StorageManager st;//objeto criado a partir da classe StorageManager
        Controler ct;//objeto criado a partir da classe Controler
        Menu menu;//objeto criado a partir da classe Menu
        
        if(menu.exibeMenuPrincipal(ct, st) == 0){
            //condição para inicialização do menu, com os devidos parametros 
            return 0;
        }
        else{
            //caso nao feche o menu, ele continua
            continue;
        }
        
    }
}