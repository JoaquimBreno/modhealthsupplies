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
		
		int getTipoInsumo();
		std::string getNome();
		int getQuantidade();
		double getValorUnit();
		std::string getDtVencimento();
		std::string getNomeFabricante();
		virtual std::string getDescricao();
		virtual void setQuantidade(int quant);
	
		Insumo();
		~Insumo();

};
#endif