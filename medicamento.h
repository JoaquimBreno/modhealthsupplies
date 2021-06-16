#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
#include <iostream>
#include <fstream>
#include "insumo.h"
class Medicamento  : public Insumo
{
    protected:
        std::string dosagem;
        std::string administracao;
        std::string disponibilizacao;
    public:
        std::string getDosagem();
        std::string getAdministracao();
        std::string getDisponibilizacao();
        std::string getDescricao();

        void setDosagem(std::string dosagem);
        void setAdministracao(std::string administracao);
        void setDisponibilizacao(std::string disp);
        void salvaAtributos(std::ofstream &file);

        Medicamento(Insumo *med);
        Medicamento(std::vector<std::string> atributos);
        Medicamento();
        ~Medicamento();

};
#endif
