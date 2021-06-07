#include "Menu.h"  


using namespace std;

Menu::Menu(){
	
}
	
Menu::~Menu(){

}

void Menu::exibeMenu1(Controler ct){
    int opcao;

    cout << "1 -> Cadastrar insumo" << endl;
    cout << "2 -> Consulta insumos" << endl;
    cout << "3 -> Consulta a descricao dos Insumos" << endl;
    cout << "4 -> Consulta insumos por tipo" << endl;
    cout << "5 -> Distribuir insumos" << endl;
    cout << "0 -> Sair" << endl;
    
    switch (opcao)
    {
        case 1:
            cadastroDeInsumo(ct);
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
    

}

void Menu::exibeMenu2(){
    
    Controler ct;
    Insumo *vac = new Vacina();
    Insumo *med = new Medicamento();
    Insumo *epi = new Epi();
    
    ct.cadastraInsumosMS(vac);
    ct.cadastraInsumosMS(med);
    ct.cadastraInsumosMS(epi);

    ct.distribuiInsumo(ct.getLocal(1), ct.getLocal(0).getInsumos()[2], 500);
    ct.consultaInsumos(ct.getLocal(0));

}	

void Menu::cadastroDeInsumo(Controler ct)
{
    char resposta;
    Insumo *insumo;
    
    //atributos gerais:
    std::string nome;
    long quantidade;
    double valorUnit;
    std::string dtVencimento;
    std::string nomeFabricante;
    int tipoInsumo;
    
    //atributos medicamento:
    std::string dosagem;
    std::string administracao;
    std::string disponibilizacao;
    
    //atributos Vacina:
    std::string tipoVac;
	int quantDoses;
	int intervalo;	
    
    //atributos EPI:
    std::string tipo;
	std::string descricao;


    system("clear");

    cout << "Qual o tipo de insumo? " << endl << endl;
    
    cout << "1 -> VACINA" << endl;
    cout << "2 -> MEDICAMENTO" << endl;
    cout << "3 -> EPI" << endl;

    cin >> tipoInsumo;
    cin.ignore();

    system("clear");

    cout << "Digite o nome do insumo:" << endl;
    getline(cin, nome);
    cout << "Digite a quantidade desse insumo:" << endl;
    cin >> quantidade;
    cin.ignore();
    cout << "Digite o valor unitario desse insumo:" << endl;
    cin >> valorUnit;
    cin.ignore();
    cout << "Digite a data de vencimento desse insumo:" << endl;
    getline(cin, dtVencimento);
    cout << "Digite o nome do fabricante desse insumo:" << endl;
    getline(cin, nomeFabricante);
   

    switch(tipoInsumo){

        case VACINA:
            insumo = new Vacina();
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipoInsumo);

            cout << "Digite o tipo da vacina: " << endl;
            getline(cin, tipoVac);
            cout << "Digite a quantidade de doses: " << endl;
		    cin >> quantDoses;
            cin.ignore();
            cout << "Digite o intervalo de doses: " << endl;
            cin >> intervalo;
            cin.ignore();	

            ((Vacina*)insumo)->setTipoVac(tipoVac);
            ((Vacina*)insumo)->setQuantDoses(quantDoses);
            ((Vacina*)insumo)->setIntervalo(intervalo);
            
            break;
        case MEDICAMENTO:
            insumo = new Medicamento();
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipoInsumo);

            cout << "Digite a dosagem do medicamento: " << endl;
            getline(cin, dosagem);
            cout << "Digite o metodo de administracao do medicamento: " << endl;
            getline(cin, administracao);
            cout << "Digite a disponibilizacao do medicamento: " << endl;
            getline(cin, disponibilizacao);
            
            ((Medicamento*)insumo)->setDosagem(dosagem);
            ((Medicamento*)insumo)->setAdministracao(administracao);
            ((Medicamento*)insumo)->setDisponibilizacao(disponibilizacao);
            
            break;
        case EPI:
            insumo = new Epi();
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipoInsumo);
            
            cout << "Digite o tipo da EPI?" << endl;
            getline(cin, tipo);
            cout << "Digite a descricao da EPI?" << endl;
            getline(cin, descricao);
            
            ((Epi*)insumo)->setTipo(tipo);
            ((Epi*)insumo)->setAtDescricao(descricao);

            break;
    
    }

    cout << "Tem certeza que deseja cadastrar esse insumo? s/n" << endl;
    cin >> resposta;
    cin.ignore();
    
    if(resposta == 's' || resposta == 'S'){
        ct.cadastraInsumosMS(insumo);
    }else if(resposta == 'n' || resposta == 'N'){
        cout << "Cadastramento cancelado.";
        return;
    }

}

void Menu::consultaEstoqueLocal(Controler ct, Locais loc)
{
    system("clear");

    cout << "Digite o local que deseja consultar" << endl;
    cout << "-----------------------------------" << endl;
    cout << "[0] - Ministerio da Saude" << endl << "[1] - Acre" << endl << "[2] - Alagoas" << endl <<
            "[3] - Amapa" << endl << "[4] - Amazonas" << endl << "[5] - Bahia" << endl << "[6] - Ceara" << endl <<
            "[7] - Distrito Federal" << endl <<"[8] - Espirito Santo" << endl << "[9] - Goias" << endl << "[10] - Maranhao" << endl << 
            "[11] - Mato Grosso" << endl << "[12] - Mato Grosso do Sul" << endl << "[13] - Minas Gerais" << endl << 
            "[14] - Para" << endl << "[15] - Paraiba" << endl << "[16] - Parana" << endl << "[17] - Pernambuco" << endl <<
            "[18] - Piaui" << endl << "[19] - Rio de Janeiro" << endl<< "[20] - Rio Grande do Norte" << endl <<
            "[21] - Rio Grande do Sul" << endl << "[22] - Rondonia" << endl << "[23] - Roraima" << endl <<
            "[24] - Santa Catarina" << endl << "[25] - Sao Paulo" << endl << "[26] - Sergipe" << endl <<"[27] - Tocantins" << endl; 
    

    
}