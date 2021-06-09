#include <iostream>
#include <string>
#include <stdlib.h>
#include "Menu.h"

int main(void){
    while(1){
        StorageManager st;
        Controler ct;
        Menu menu;
        
        if(menu.exibeMenuPrincipal(ct, st) == 0){
            return 0;
        }
        else{
            continue;
        }
        
    }
}