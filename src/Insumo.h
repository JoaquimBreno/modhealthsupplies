#ifndef INSUMO_H
#define INSUMO_H

#include <string>

#define VACINA 1
#define MEDICAMENTO 2
#define EPI 3

class Insumo  
{
	protected:
		std::string nome;
		int quantidade;
		float valorUnitario;
		std::string dtVencimento;
		std::string nomeFabricante;
		int tipoInsumo;
	
	public:
		
		int getTipoInsumo();
		std::string getNome();
		int getQuantidade();
		float valorUnitario();
		std::string getDtVencimento();
		std::string getNomeFabricante();
	
		Insumo();
		~Insumo();

};
#endif