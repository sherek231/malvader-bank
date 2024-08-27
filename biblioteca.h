//tela inicial
extern void telainicial();
extern void telafuncionario();
extern void tela_clientec();
extern void tela_clientep();
extern void sair();

//limpar teclado 
extern void limpar_buffer();

//tela de criar as contas 
extern void criar_contas();
extern void conta_funci();
extern void conta_clien();
extern void criar();

//verificando conta 
extern void verificar_conta();
extern void verificar_poupanca();
extern void verificar_corrente();
extern void verificar_cliente();

//consulta dos dados
extern void consultaconta();
extern void consultar_poupanca();
extern void consultar_corrente();
extern void consultar_funcionario();
extern void consultar_cliente();

extern void funcionario();
//tela de funcionario
extern void encerramento();
extern void aberturaconta();
extern void encerramento_poupanca();
extern void encerramento_corrente();
extern void consultadados();
extern void alterar();
extern void cadastrofuncionario();
extern void gerar_relatorios();
extern void menu_cliente();
//tela da abertura de conta 
extern void poupanca();
extern void corrente();

//tela de cliente
extern void saldo();
extern void deposito();
extern void saque();
extern void extrato();
extern void consultar_limite();
extern void saldoc();
extern void depositoc();
extern void saquec();
extern void extratoc();
extern void consultar_limitec();

extern void contas();
//tela de altera 
extern void alterar_poupanca();
extern void alterar_corrente();
extern void alterar_funcionario();
extern void alterar_cliente();

typedef struct{	
	char cep[100];
	char local[100];
	char numcasa[3];
	char bairro[100];
	char city[100];
	char estado[50];	
}Endereco;

typedef struct{	
	char dia[100];
	char mes[100];
	char ano[100];	
}Data;

typedef struct{	
	char numconta[100];
	char agencia[100];
	char cargo[100];
	char nome[32];
	char cpf[12];
	Data nascimento;
	char telefone[100];
	Endereco endereco;
	int senha;	
}Conta;
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
typedef struct{
	char dia_p[3];
	char mes_p[3];
	char ano_p[10];
}Data_p;

typedef struct{	
	char cep_p[100];
	char local_p[100];
	char numcasa_p[3];
	char bairro_p[100];
	char city_p[100];
	char estado_p[50];	
}Endereco_p;

typedef struct{
	char agencia[100];
	char numconta[100];
	char nome[32];
	char cpf[12];
	Data_p nascimento;
	char telefone[100];
	Endereco_p endereco;
	int senha;	
}Poupanca;
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------


typedef struct{
    char dia_v[3];
    char mes_v[3];
    char ano_v[10];
}Data_v;

typedef struct{
    char dia_c[3];
    char mes_c[3];
    char ano_c[10];
}Data_c;

typedef struct{
    char cep_c[100];
    char local_c[100];
    char numcasa_c[3];
    char bairro_c[100];
    char city_c[100];
    char estado_c[50];
}Endereco_c;

typedef struct{
    float limite;
    Data_v vencimento;
    char agencia[100];
    char numconta[100];
    char nome[32];
    char cpf[12];
    Data_c nascimento;
    char telefone[100];
    Endereco_c endereco;
    int senha;
}Corrente;

//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------


typedef struct{	
	char cep[100];
	char local[100];
	char numcasa[3];
	char bairro[100];
	char city[100];
	char estado[50];	
}Endereco_cl;

typedef struct{	
	char dia[100];
	char mes[100];
	char ano[100];	
}Data_cl;

typedef struct{	
	char agencia[100];
	char nome[32];
	float saldo;
	float deposito;
	float saque;
	float extrato;
	float limite;
	char cpf[12];
	Data nascimento;
	char telefone[100];
	Endereco endereco;
	int senha;	
}Conta_cl;
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
typedef struct{
	char dia[5];
	char mes[5];
	char ano[10];
}data_cadastro;

typedef struct{
	char cep[100];
	char local[100];
	char numcasa[3];
	char bairro[100];
	char city[100];
	char estado[50];	
}endereco_cadastro;

typedef struct{
	char numconta[100];
	char agencia[100]; 
	char cargo[100];   
	char nome[32];     
	char cpf[12];      
	data_cadastro nascimento;   
	char telefone[20];
	endereco_cadastro endereco;
	int senha;
}Cadastro;
