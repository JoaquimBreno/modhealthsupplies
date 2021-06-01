#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <fstream>
#include "Insumo.h"
#include <vector>

class StorageManager  
{
	private:


	public:
		void lerInsumos();
		void salvarInsumos(vector<Insumo*> ins);
		StorageManager();
		~StorageManager();

};
#endif