#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <fstream>
#include "Insumo.h"
#include <vector>
#include "Locais.h"
#include <sstream>

class StorageManager  
{
	private:


	public:
		StorageManager();
		void lerInsumos(Locais &loc);
		void salvarInsumos(std::vector<Insumo*> ins, Locais loc);
		

};

#endif