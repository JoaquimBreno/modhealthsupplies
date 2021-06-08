#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Vacina.h"	
#include "Insumo.h"
#include "Epi.h"	
#include "Medicamento.h"	
#include "Controler.h"
#include "StorageManager.h"
#include "Locais.h"

class Menu  
{
	private:

	public:
		Menu();
		~Menu();
		void cadastroDeInsumo(Controler &ct);
		void consultaEstoqueLocal(Controler &ct);
		void consultaEstoqueDescricao(Controler &ct);
		void consultaInsumosTipo(Controler &ct);
		void distribuicao(Controler &ct);
		int exibeMenu1(Controler &ct, StorageManager &st);
		void exibeMenu2();

};
#endif