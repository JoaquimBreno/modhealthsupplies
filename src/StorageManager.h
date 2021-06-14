#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <fstream>
#include <vector>
#include <sstream>
#include <exception>
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
		void salvarInsumos(Controler &ct);
		void lerInsumos(Controler &ct);

};

#endif