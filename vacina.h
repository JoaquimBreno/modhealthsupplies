
#ifndef VACINA_H
#define VACINA_H
#include "insumo.h"
#include <iostream>
#include <fstream>
class Vacina  : public Insumo{
    protected:
        std::string tipoVac;
        int quantDoses;
        int intervalo;
    public:
        std::string getTipoVac();
        int getQuantDoses();
        int getIntervalo();

        std::string getDescricao();
        void setTipoVac(std::string tVac);
        void setQuantDoses(int quant);
        void setIntervalo(int intervalo);
        void salvaAtributos(std::ofstream &file);

        Vacina();
        Vacina(Insumo *vac);
        Vacina(std::vector<std::string> atributos);
        ~Vacina();

};
#endif
