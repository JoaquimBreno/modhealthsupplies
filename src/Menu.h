#ifndef MENU_H
#define MENU_H

#include <cctype>
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
		void lerArquivoTotal(Controler &ct, StorageManager &st);
		void salvarArquivoTotal(Controler &ct, StorageManager &st);
		int exibeMenuPrincipal(Controler &ct, StorageManager &st);
		int exibeMenu1(Controler &ct, StorageManager &st);

};
#endif