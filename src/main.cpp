#include <iostream>
#include <string>
#include <stdlib.h>
#include "Menu.h"

int main(void){
    setlocale(LC_ALL, "portuguese-brazilian");
    StorageManager st;
    Controler ct;
    Menu mn;
    while(1){
        int retorno;
        retorno = mn.exibeMenu1(ct, st);
        
        if(retorno == 1){
            return 0;
        }else{
            continue;
        }
    }
}