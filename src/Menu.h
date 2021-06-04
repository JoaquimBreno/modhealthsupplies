#ifndef MENU_H
#define MENU_H

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
		void cadastroDeInsumo(Controler ct);
		void consultaEstoqueLocal(Controler ct);
		void consultaEstoqueLocal(Controler ct, Locais loc);
		void exibeMenu1(Controler ct);
		void exibeMenu2();

};
#endif