#ifndef INSUMO_H
#define INSUMO_H
#include <iostream>
#include <string>

#define VACINA 1
#define MEDICAMENTO 2
#define EPI 3

class Insumo  
{
	protected:
		std::string nome;
		int quantidade;
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
	
		Insumo();
		~Insumo();
};
#endif