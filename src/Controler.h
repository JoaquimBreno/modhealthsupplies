#ifndef CONTROLER_H
#define CONTROLER_H
#include <vector>
#include "Locais.h"
#include "Insumo.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "EPI.h"

class Controler  
{
	private:
	Locais locais[28];
		
	public:
		void cadastraInsumosMS(Insumo *insFilho);
		void consultaInsumos(Locais loc);
		void consultaInsumosDescricao(Locais loc);

		std::vector<Insumo*> consultaInsumoPorTipo(Locais loc, int tipoInsumo); //Verificar o tipo ( array, vector ou list )
		void distribuiInsumo(Locais &dest, Insumo *insumo, long quantidade);
		void delecaoDeInsumo(Locais &loc);
		Locais & getLocal(int index);
		
		Controler();
		~Controler();

};
#endif