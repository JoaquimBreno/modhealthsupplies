#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <fstream>
#include <vector>
#include <sstream>
#include <exception>
#include "controler.h"
#include "insumo.h"
#include "vacina.h"
#include "medicamento.h"
#include "epi.h"
#include "locais.h"

class storagemanager
{
public:
    storagemanager();
    int salvarInsumos(Controler &ct);
    int lerInsumos(Controler &ct);
};

#endif // STORAGEMANAGER_H
