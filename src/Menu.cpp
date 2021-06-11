#include "Menu.h"  

using namespace std;

Menu::Menu(){
	
}
	
Menu::~Menu(){

}

int Menu::exibeMenuPrincipal(Controler &ct, StorageManager &st){
    while(1){ 
        int opcao;
        cout << " GERENCIADOR DE INSUMOS MS " << endl;
        cout << "-----------------------------------" << endl;
        cout << " Escolha uma opcao de menu: " << endl;
        cout << "-----------------------------------" << endl;
        cout << "1 -> Menu Principal" << endl;
        cout << "0 -> Sair" << endl;
        
        cin >> opcao;
        cin.ignore();
        system("CLS");
        
            switch (opcao){
                case 1:
                    st.lerInsumos(ct);
                    while(1){
                        if(exibeMenu1(ct, st)==1){
                            continue;
                            st.salvarInsumos(ct);
                        }
                        else{
                            break;
                        }
                    }
                    break;
                case 0:
                    return 0;
            }
            return 1;
    }
    
}

int Menu::exibeMenu1(Controler &ct, StorageManager &st){
    int opcao;
    cout << "1 -> Cadastrar insumo" << endl;
    cout << "2 -> Consulta insumos" << endl;
    cout << "3 -> Consulta a descricao dos Insumos" << endl;
    cout << "4 -> Consulta insumos por tipo" << endl;
    cout << "5 -> Distribuir insumos" << endl;
    cout << "6 -> Salvar todos os locais" << endl;
    cout << "0 -> Sair" << endl;
    
    cin >> opcao;
    cin.ignore();
    system("CLS");
    
    switch (opcao){
        case 1:
            cadastroDeInsumo(ct);
            break;
        case 2:
            consultaEstoqueLocal(ct);
            break;
        case 3:
            consultaEstoqueDescricao(ct);
            break;
        case 4:
            consultaInsumosTipo(ct);
            break;
        case 5:
            distribuicao(ct);
            break;
        case 6:
            salvarArquivoTotal(ct,st);
            break;
        case 0:
            return 0;
    }
    return 1;
}

void Menu::cadastroDeInsumo(Controler &ct){
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


    system("CLS");

    cout << "Qual o tipo de insumo? " << endl << endl;
    
    cout << "1 -> VACINA" << endl;
    cout << "2 -> MEDICAMENTO" << endl;
    cout << "3 -> EPI" << endl;

    cin >> tipoInsumo;
    cin.ignore();

    system("CLS");

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
            cout << "Digite o intervalo de doses(numero de dias): " << endl;
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

void Menu::consultaEstoqueLocal(Controler &ct){

    while(1){
        try{
            system("CLS");

            int local;

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
            

            cin >> local;
            if(local < 0  || local > 27){
                throw "Local nao encontrado";
            }
            cin.ignore();
            system("CLS");
            
            ct.consultaInsumos(ct.getLocal(local));
        }
        catch(char const* erro){
            cout << erro << endl;
        }

        char resposta;

        cout << "Queres continuar a consultar? s/n" << endl;
        cin >> resposta;
        cin.ignore();
        
        if(resposta == 's' || resposta == 'S'){
            continue;
        }else if(resposta == 'n' || resposta == 'N'){
            break;
        }     
    } 
    
}

void Menu::consultaEstoqueDescricao(Controler &ct){

    while(1){
        try{
            system("CLS");

            int local;

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
            

            cin >> local;
            if(local < 0  || local > 27){
                throw "Local nao encontrado";
            }
            cin.ignore();
            system("CLS");
            
            ct.consultaInsumosDescricao(ct.getLocal(local));
        }
        catch(char const* erro){
            cout << erro << endl;
        }

        char resposta;

        cout << "Queres continuar a consultar? s/n" << endl;
        cin >> resposta;
        cin.ignore();
        
        if(resposta == 's' || resposta == 'S'){
            continue;
        }else if(resposta == 'n' || resposta == 'N'){
            break;
        }     
    } 
    
}

void Menu::consultaInsumosTipo(Controler &ct){

    vector<Insumo*> insumos;
    
    while(1){
        try{
            system("CLS");

            int local;
            int tipo;

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
            

            cin >> local;
            cin.ignore();
            system("CLS");
            if(local < 0  || local > 27){
                throw "Local nao encontrado";
            }

            system("CLS");
            
            cout << "Digite o tipo do insumo desejado: " << endl;
            cout << "[1] -> Vacina" << endl;
            cout << "[2] -> Medicamento" << endl;
            cout << "[3] -> Epi" << endl;
            
            cin >> tipo;
            cin.ignore();
            if( tipo < 1 || tipo > 3){
                throw "Tipo nao encontrado";
            }
            
            vector<Insumo*> insumos;    
            insumos = ct.consultaInsumoPorTipo(ct.getLocal(local), tipo);

            if(insumos.size() == 0){
                cout << "Nao ha insumos do tipo pesquisado nesse local" << endl;
            }
            for(Insumo* ins : insumos){
                ins->getDescricao();
            }

        }
        catch(char const* erro){
            cout << erro << endl;
        }

        char resposta;

        cout << "Queres continuar a consultar? s/n" << endl;
        cin >> resposta;
        cin.ignore();
        
        if(resposta == 's' || resposta == 'S'){
            continue;
        }else if(resposta == 'n' || resposta == 'N'){
            break;
        }     
    }  
}

void Menu::distribuicao(Controler &ct){
    while(1){
        string nomeInsumo;
        int quantidade;
        int destino;
        if(ct.getLocal(0).getInsumos().size() <= 0){
            cout << "Nao ha insumos no estoque MS" << endl;
            return;
        }
        
        cout << "Digite o nome do insumo que deseja mandar: " << endl;
        getline(cin, nomeInsumo);
        
        cout << endl << "Escolha o local de destino: " << endl;
        cout << "-----------------------------------" << endl;
        cout << "[0] - Ministerio da Saude" << endl << "[1] - Acre" << endl << "[2] - Alagoas" << endl <<
                "[3] - Amapa" << endl << "[4] - Amazonas" << endl << "[5] - Bahia" << endl << "[6] - Ceara" << endl <<
                "[7] - Distrito Federal" << endl <<"[8] - Espirito Santo" << endl << "[9] - Goias" << endl << "[10] - Maranhao" << endl << 
                "[11] - Mato Grosso" << endl << "[12] - Mato Grosso do Sul" << endl << "[13] - Minas Gerais" << endl << 
                "[14] - Para" << endl << "[15] - Paraiba" << endl << "[16] - Parana" << endl << "[17] - Pernambuco" << endl <<
                "[18] - Piaui" << endl << "[19] - Rio de Janeiro" << endl<< "[20] - Rio Grande do Norte" << endl <<
                "[21] - Rio Grande do Sul" << endl << "[22] - Rondonia" << endl << "[23] - Roraima" << endl <<
                "[24] - Santa Catarina" << endl << "[25] - Sao Paulo" << endl << "[26] - Sergipe" << endl <<"[27] - Tocantins" << endl; 
        cin >> destino;
        cin.ignore();
        
        system("CLS");
        cout << "Digite a quantidade que deseja mandar: " << endl;
        cin >> quantidade;
        cin.ignore();

        for(Insumo* ins : ct.getLocal(0).getInsumos()){
            cout << ins->getNome() << endl;
            if(ins->getNome() == nomeInsumo){
                ct.distribuiInsumo(ct.getLocal(destino), ins, quantidade);
            }
        }
        char resposta;
        system("CLS");

        cout << "Queres continuar a distribuir? s/n" << endl;
        cin >> resposta;
        cin.ignore();
        
        if(resposta == 's' || resposta == 'S'){
            continue;
        }else if(resposta == 'n' || resposta == 'N'){
            break;
        }  
    }
}

void Menu::lerArquivoLocal(Controler &ct, StorageManager &st){
    int localIndex;
    cout << "Escolha o local que deseja ler do arquivo" << endl << endl;
    cout << "[0] - Ministerio da Saude" << endl << "[1] - Acre" << endl << "[2] - Alagoas" << endl <<
                "[3] - Amapa" << endl << "[4] - Amazonas" << endl << "[5] - Bahia" << endl << "[6] - Ceara" << endl <<
                "[7] - Distrito Federal" << endl <<"[8] - Espirito Santo" << endl << "[9] - Goias" << endl << "[10] - Maranhao" << endl << 
                "[11] - Mato Grosso" << endl << "[12] - Mato Grosso do Sul" << endl << "[13] - Minas Gerais" << endl << 
                "[14] - Para" << endl << "[15] - Paraiba" << endl << "[16] - Parana" << endl << "[17] - Pernambuco" << endl <<
                "[18] - Piaui" << endl << "[19] - Rio de Janeiro" << endl<< "[20] - Rio Grande do Norte" << endl <<
                "[21] - Rio Grande do Sul" << endl << "[22] - Rondonia" << endl << "[23] - Roraima" << endl <<
                "[24] - Santa Catarina" << endl << "[25] - Sao Paulo" << endl << "[26] - Sergipe" << endl <<"[27] - Tocantins" << endl; 
    cin >> localIndex;
    cin.ignore();
    system("CLS");
    
    st.lerInsumosPorLocal(ct.getLocal(localIndex)); 
    cout << " Funcao executada " << endl;
}


void Menu::lerArquivoTotal(Controler &ct, StorageManager &st){
    st.lerInsumos(ct);
    cout << " Funcao executada " << endl;
}

void Menu::salvarArquivoTotal(Controler &ct, StorageManager &st){
    try{
        st.salvarInsumos(ct);
    }
    catch(std::exception){
        cout << " Ocorreu um inesperado " << endl;
    }
    cout << " Funcao executada " << endl;
}

