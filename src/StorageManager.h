#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <fstream>
#include <vector>
#include <sstream>
#include "Controler.h"
#include "Insumo.h"
#include "Vacina.h"
#include "Medicamento.h"
#include "Epi.h"
#include "Locais.h"


class StorageManager  
{
	private:


	public:
		StorageManager();
		void lerInsumosPorLocal(Locais &loc);
		void salvarInsumos(std::vector<Insumo*> ins, Locais loc);
		void lerInsumos(Controler &ct);

};

#endif