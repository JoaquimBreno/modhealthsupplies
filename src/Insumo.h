#ifndef INSUMO_H
#define INSUMO_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define VACINA 1
#define MEDICAMENTO 2
#define EPI 3

class Insumo  
{
	protected:
		std::string nome;
		long quantidade;
		double valorUnit;
		std::string dtVencimento;
		std::string nomeFabricante;
		int tipoInsumo;
	
	public:
		
		virtual int getTipoInsumo();
		virtual std::string getNome();
		virtual int getQuantidade();
		virtual double getValorUnit();
		virtual std::string getDtVencimento();
		virtual std::string getNomeFabricante();



		virtual void getDescricao();
		virtual void setQuantidade(int quant);
		virtual void setNome(std::string n);
		virtual void setValorUnit(double valor);
		virtual void setDtVencimento(std::string dt);
		virtual void setNomeFabricante(std::string nomeFabri);
		virtual void setTipoInsumo(int tipo);
		virtual void insereEspecificos();
		virtual void salvaAtributos(std::ofstream &file) = 0;
		virtual void setAtributos(std::vector<std::string> atributos) = 0;
		virtual void setAtributos(std::string nome, long quantidade, double valorUnit, std::string dtVencimento, std::string nomeFabricante, int tipoInsumo);

		Insumo();
		~Insumo();
};
#endif