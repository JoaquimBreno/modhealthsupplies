#include "Menu.h" 

using namespace std;

Menu::Menu(){
	
}
	
Menu::~Menu(){

}

int Menu::exibeMenuPrincipal(Controler &ct, StorageManager &st){
    while(1){ 
        char opcao;

        //inicialização da intefarce de interação com o usuário
        cout << " GERENCIADOR DE INSUMOS MS " << endl;
        cout << "-----------------------------------" << endl;
        cout << " Escolha uma opcao de menu: " << endl;
        cout << "-----------------------------------" << endl;
        cout << "1 -> Menu Principal" << endl;
        cout << "0 -> Sair" << endl;
        
        cin >> opcao;
        cin.ignore();
        fflush(stdin);//limpar buffer do teclado 

        system("CLS");//limpa o terminal
        
        //switch para selecionar a opção desejada 
        switch (opcao){
            case '1':
                lerArquivoTotal(ct,st);
                while(1){
                    if(exibeMenu1(ct, st)==1){
                        salvarArquivoTotal(ct,st);  //Se sair do Menu 1 salva todas as alterações de maneira obrigatória
                        continue;
                    }
                    else{
                        break;
                    }
                }
                break;

            case '0':
            //vai sair do programa 
                return 0;
            default:
            //tratamento de erro, caso o usuário digite uma opção invalida 
                cout << endl << "Opcao invalida, digite uma opcao valida!" << endl << endl;
                break;
        }
        return 1;
    }
    
}

int Menu::exibeMenu1(Controler &ct, StorageManager &st){
    char opcao;
    //tela de interação com o usuario, relacionada ao menu 1
    cout << "1 -> Cadastrar insumo" << endl;
    cout << "2 -> Consulta insumos" << endl;
    cout << "3 -> Consulta a descricao dos Insumos" << endl;
    cout << "4 -> Consulta insumos por tipo" << endl;
    cout << "5 -> Distribuir insumos" << endl;
    cout << "6 -> Salvar todos os locais" << endl;
    cout << "0 -> Sair" << endl;
    
    cin >> opcao;
    cin.ignore();
    fflush(stdin);
    system("CLS");
    //switch para a seleção de determinada função, escolhida pelo usuario 
    switch (opcao){
        case '1':
            cadastroDeInsumo(ct);
            break;
        case '2':
            consultaEstoqueLocal(ct);
            break;
        case '3':
            consultaEstoqueDescricao(ct);
            break;
        case '4':
            consultaInsumosTipo(ct);
            break;
        case '5':
            distribuicao(ct);
            break;
        case '6':
            salvarArquivoTotal(ct,st);
            break;
        case '0':
            return 0;
        default: //tratamento de erro 
            cout << endl << "Opcao invalida, digite uma opcao valida!" << endl << endl;
            break;
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
    //tela de interação do usuário, relacionada ao cadastro de insumo
    cout << "Qual o tipo de insumo? " << endl;
    
    cout << "1 -> VACINA" << endl;
    cout << "2 -> MEDICAMENTO" << endl;
    cout << "3 -> EPI" << endl;

    cin >> tipoInsumo;
    cin.ignore();

    system("CLS");

    //Tratamento de erros
    if(tipoInsumo != 1 && tipoInsumo != 2 && tipoInsumo != 3){
        cout << endl << "Tipo de insumo nao valido!" << endl << endl;
        return;
    }

    //Interação fixa, independente do tipo de insumo escolhido
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
   
    //Switch para os tipos de insumo
    switch(tipoInsumo){

        case VACINA:
            insumo = new Vacina();//insumo recebe tipo vacina, podemos acessar os parametros de vacina
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipoInsumo);
            //interação dos parametros fixos de vacina 
            cout << "Digite o tipo da vacina: " << endl;
            getline(cin, tipoVac);
            cout << "Digite a quantidade de doses: " << endl;
		    cin >> quantDoses;
            cin.ignore();
            cout << "Digite o intervalo de doses(numero de dias): " << endl;
            cin >> intervalo;
            cin.ignore();	
            //conversão do tipo insumo para o tipo vacina, usando casting
            ((Vacina*)insumo)->setTipoVac(tipoVac);
            ((Vacina*)insumo)->setQuantDoses(quantDoses);
            ((Vacina*)insumo)->setIntervalo(intervalo);
            
            break;

        case MEDICAMENTO:
            insumo = new Medicamento();//insumo recebe tipo vacina, podemos acessar os parametros de vacina
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipoInsumo);
            //interação dos parametros fixos de medicamentos 
            cout << "Digite a dosagem do medicamento: " << endl;
            getline(cin, dosagem);
            cout << "Digite o metodo de administracao do medicamento: " << endl;
            getline(cin, administracao);
            cout << "Digite a disponibilizacao do medicamento: " << endl;
            getline(cin, disponibilizacao);
            //conversão do tipo insumo para o tipo Medicamentos, usando casting
            ((Medicamento*)insumo)->setDosagem(dosagem);
            ((Medicamento*)insumo)->setAdministracao(administracao);
            ((Medicamento*)insumo)->setDisponibilizacao(disponibilizacao);
            
            break;
        case EPI:
            insumo = new Epi();//insumo recebe tipo vacina, podemos acessar os parametros de EPI
            insumo->setAtributos(nome, quantidade, valorUnit, dtVencimento, nomeFabricante, tipoInsumo);
            //interação dos parametros fixos de EPI
            cout << "Digite o tipo da EPI?" << endl;
            getline(cin, tipo);
            cout << "Digite a descricao da EPI?" << endl;
            getline(cin, descricao);
            //conversão do tipo insumo para o tipo EPI, usando casting    
            ((Epi*)insumo)->setTipo(tipo);
            ((Epi*)insumo)->setAtDescricao(descricao);

            break;
    
    }

    //confimação de cadastro
    cout << "Tem certeza que deseja cadastrar esse insumo? s/n" << endl;
    cin >> resposta;
    cin.ignore();
    //condição para cadastro
    if(resposta == 's' || resposta == 'S'){
        ct.cadastraInsumosMS(insumo);
    }else if(resposta == 'n' || resposta == 'N'){
        system("CLS");
        cout << "Cadastramento cancelado." << endl << endl;
        return;
    }

}

void Menu::consultaEstoqueLocal(Controler &ct){

    while(1){
        try{
            system("CLS");

            string s;
            int indexLocal;
            //exibição dos locais, para a interação com o usuário 
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
        
            
            cin >> s;
            //tratamento de erro 
            //transformação de string para inteiro 
            char *end;
            long i = strtol( s.c_str(), &end, 10 );
            if ( *end == '\0' )
            {
                indexLocal = stoi(s); //o index do local vai receber o inteiro "s" convertido 
                if(indexLocal < 0  || indexLocal > 27){
                    throw "Local nao encontrado";
                }
            }
            else
            {
                cout << "Digite um local valido" << endl;
                return;
            }
            system("CLS");
            //consultaro os insumos de acordo com o local passado como index
            ct.consultaInsumos(ct.getLocal(indexLocal));
        }

        catch(char const* erro){
            cout << erro << endl;
        }

        char resposta;
        //confirmação de consulta 
        cout << "Queres continuar a consultar? s/n" << endl;
        cin >> resposta;
        cin.ignore();
        //condição de confirmação 
        if(resposta == 's' || resposta == 'S'){
            continue;
        }else if(resposta == 'n' || resposta == 'N'){
            system("CLS");
            break;
        }     
    } 
    
}

void Menu::consultaEstoqueDescricao(Controler &ct){

    while(1){
       try{
            system("CLS");

            string s;   //string que recebe a entrada do usuário
            int indexLocal;

            //Interface de interação
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
        
            
            cin >> s;
            
            //(Tratamento de erros)
            //Condições que verificam se o usuário digitou apenas números
            char *end;
            long i = strtol( s.c_str(), &end, 10 );
            if ( *end == '\0' )
            {
                //Se digitou apenas números, transforma em inteiro e verifica se é um local valido
                indexLocal = stoi(s);
                if(indexLocal < 0  || indexLocal > 27){
                    throw "Local nao encontrado";
                }
            }
            else
            {
                cout << "Digite um local válido" << endl;
                return;
            }
            system("CLS");
            
            ct.consultaInsumosDescricao(ct.getLocal(indexLocal)); //Chama a função de consulta
        }
        catch(char const* erro){
            cout << erro << endl;
        }

        char resposta;

        //Verifica se o usuário deseja continuar a consultar
        cout << "Queres continuar a consultar? s/n" << endl;
        cin >> resposta;
        cin.ignore();
        
        if(resposta == 's' || resposta == 'S'){
            continue;
        }else if(resposta == 'n' || resposta == 'N'){
            system("CLS");
            break;
        }     
    } 
    
}

void Menu::consultaInsumosTipo(Controler &ct){

    vector<Insumo*> insumos;
    
    while(1){
        try{
            system("CLS");
            
            string s;       //string que recebe a entrada do usuário
            int local;
            int tipo;
            
            //Interface de interação
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
            

            cin >> s;
            
            //(Tratamento de erros)
            //Condições que verificam se o usuário digitou apenas números
            char *end;
            long i = strtol( s.c_str(), &end, 10 );
            if ( *end == '\0' )
            {
                //Se digitou apenas números, transforma em inteiro e verifica se é um local valido
                local = stoi(s);
                if(local < 0  || local > 27){
                    throw "Local nao encontrado";
                }
            }
            else
            {
                cout << "Digite um local valido" << endl;
                return;
            }

            system("CLS");
            //interaçao para saber o tipo de insumo desjado para consulta 
            cout << "Digite o tipo do insumo desejado: " << endl;
            cout << "[1] -> Vacina" << endl;
            cout << "[2] -> Medicamento" << endl;
            cout << "[3] -> Epi" << endl;
            
            cin >> tipo;
            cin.ignore();
            //tratamento de erro 
            if( tipo < 1 || tipo > 3){
                throw "Tipo nao encontrado";
            }
            
            vector<Insumo*> insumos;    
            insumos = ct.consultaInsumoPorTipo(ct.getLocal(local), tipo);
            //condição que verifica se o tamanho do insumo é igual a 0
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
        //tratamento de erro
        cout << "Queres continuar a consultar? s/n" << endl;
        cin >> resposta;
        cin.ignore();
        
        if(resposta == 's' || resposta == 'S'){
            continue;
        }else if(resposta == 'n' || resposta == 'N'){
            system("CLS");
            break;
        }     
    }  
}

void Menu::distribuicao(Controler &ct){
    while(1){
        try{
            string s; 
            string nomeInsumo;
            int quantidade;
            int destino;

            //condição para saber se há ou não insumos em enstoque para distribuir 

            if(ct.getLocal(0).getInsumos().size() <= 0){
                cout << "Nao ha insumos no estoque MS" << endl;
                return;
            }
            
            //interação com o usuários 
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
            cin >> s;
            
            //(Tratamento de erros)
            //Condições que verificam se o usuário digitou apenas números
            char *end;
            long i = strtol( s.c_str(), &end, 10 );
            if ( *end == '\0' )
            {
                //Se digitou apenas números, transforma em inteiro e verifica se é um destino valido
                destino = stoi(s);
                if(destino < 0  || destino > 27){
                    system("CLS");
                    throw "Local nao encontrado";
                }
            }
            else
            {
                cout << "Digite um local valido" << endl;
                return;
            }
        
            cout << "Digite a quantidade que deseja mandar: " << endl;
            cin  >> quantidade;
            cin.ignore();
            //for para distribuição os insumos 
            for(Insumo* ins : ct.getLocal(0).getInsumos()){
                if(ins->getNome() == nomeInsumo){
                    ct.distribuiInsumo(ct.getLocal(destino), ins, quantidade);
                }
            }
        }
        catch(char const* erro){
            cout << erro << endl;
        }
        char resposta;

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

//função para ler todos os arquivos 
void Menu::lerArquivoTotal(Controler &ct, StorageManager &st){
    st.lerInsumos(ct);
    
}

//função para salvar todos os arquivos 
void Menu::salvarArquivoTotal(Controler &ct, StorageManager &st){
    try{
        st.salvarInsumos(ct);
    }
    catch(std::exception){
        cout << " Ocorreu um inesperado " << endl;
    }
    cout << " Funcao executada " << endl;
}

