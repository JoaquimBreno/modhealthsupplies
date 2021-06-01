#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <fstream>
#include "Insumo.h"
#include <vector>

class StorageManager  
{
	private:


	public:
		StorageManager();
		void lerInsumos();
		void salvarInsumos(std::vector<Insumo*> ins);
		

};

#endif