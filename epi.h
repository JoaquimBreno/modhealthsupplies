#ifndef EPI_H
#define EPI_H
#include <fstream>
#include <iostream>
#include "insumo.h"

class Epi : public Insumo
{
    protected:
    std::string tipo;
    std::string descricao;

    public:
        std::string getTipo();
        std::string getAtDescricao();

        std::string getDescricao();
        void setTipo(std::string tipo);
        void setAtDescricao(std::string desc);
        void salvaAtributos(std::ofstream &file);

        Epi();
        Epi(std::vector<std::string> atributos);
        Epi(Insumo *epi);
        ~Epi();


};
#endif
