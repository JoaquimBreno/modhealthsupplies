#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <fstream>
#include <vector>
#include <sstream>
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
		void lerInsumos(Locais &loc);
		void salvarInsumos(std::vector<Insumo*> ins, Locais loc);
		

};

#endif