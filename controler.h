#ifndef CONTROLER_H
#define CONTROLER_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
class storagemanager;
#include "locais.h"
#include "insumo.h"
#include "vacina.h"
#include "medicamento.h"
#include "epi.h"

class Controler
{
    private:
    Locais locais[28];

    public:
        void cadastraInsumosMS(Insumo *insFilho);
        std::vector<std::string> consultaInsumos(Locais &loc);
        std::vector<std::string> consultaInsumosDescricaoLocal(Locais &loc);
        std::vector<std::string> consultaInsumosDescricao();
        std::vector<Insumo*> consultaInsumoPorTipo(Locais loc, int tipoInsumo);
        void delecaoDeInsumo(Locais &loc);
        void distribuiInsumo(Locais &dest, Insumo *insumo, long quantidade);

        Locais & getLocal(int index);
        Locais *getLocais();

        Controler();
        ~Controler();

};
#endif
