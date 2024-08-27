#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "biblioteca.h"
void sair(){
}
void voltar(){
	
}


void relatorios(){
}



void telainicial(){
	
	system("cls");
	style();
	
	int op;
	
	printf("\t\t\t\t\t\t\t\t\t\t\t\t 1- FUNCIONNARIO \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t 2- CLIENTE\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t 3- SAIR \n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t\t 4- CRIAR CONTAS \n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t\tdigite uma opcao:");
		scanf("%i", &op);
		
			limpar_buffer();
		
		switch (op){
			case 1:
				verificar_conta();
				break;
				
			case 2:
				verificar_cliente();
				break;
				
			case 3:
				sair();
				break;
				
			case 4:
				criar_contas();
		}				
}

void criar_contas(){
	system("cls");
	int opc;
	
	printf("\n 1- Conta Funcionario\n");
	printf("\n 2- Conta Cliente\n ");
		printf("\n\ndigite uma opcao:");
		scanf("%i", &opc);
		
	limpar_buffer();
		
	switch (opc){
		case 1:
			conta_funci();
			break;
		case 2:
			conta_clien();
			break;
		
	}
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
	

void conta_funci(){
	system("cls");
	
	Conta funcionario;
	printf("Digite o numero da conta: ");
		fgets(funcionario.numconta, sizeof(funcionario.numconta), stdin);
		
	printf(" Digite sua agencia: ");
		fgets(funcionario.agencia, sizeof(funcionario.agencia), stdin);
		fflush(stdin);
		
	printf(" Digite a seu cargo: ");
		fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
		fflush(stdin);
		
	printf(" Digite o seu nome: ");
		fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
		fflush(stdin);
		
	printf(" Digite o seu CPF:");
		fgets(funcionario.cpf, sizeof(funcionario.cpf), stdin);
		fflush(stdin);
		
	printf("\n Digite a sua data de nascimento- \n\n");
		printf(" Dia: ");
			fgets(funcionario.nascimento.dia, sizeof(funcionario.nascimento.dia),stdin);
			fflush(stdin);
			
		printf(" Mes: ");
			fgets(funcionario.nascimento.mes, sizeof(funcionario.nascimento.mes), stdin);
			fflush(stdin);
			
		printf(" Ano: ");
			fgets(funcionario.nascimento.ano, sizeof(funcionario.nascimento.ano), stdin);
			fflush(stdin);
			
	printf(" Digite o numero de telefone: ");
		fgets(funcionario.telefone, sizeof(funcionario.telefone), stdin);
		fflush(stdin);
		
	printf(" \nEndereco- \n\n");
		printf(" CEP:");
			fgets(funcionario.endereco.cep, sizeof(funcionario.endereco.cep), stdin);
			fflush(stdin);
			
		printf(" Local:");
			fgets(funcionario.endereco.local, sizeof(funcionario.endereco.local), stdin);
			fflush(stdin);
			
		printf(" Numero da casa: ");
			fgets(funcionario.endereco.numcasa, sizeof(funcionario.endereco.numcasa), stdin);
			fflush(stdin);
			
		printf(" Bairro: ");
			fgets(funcionario.endereco.bairro, sizeof(funcionario.endereco.bairro), stdin);
			fflush(stdin);
			
		printf(" Cidade: ");
			fgets(funcionario.endereco.city, sizeof(funcionario.endereco.city), stdin);
			fflush(stdin);
			
		printf(" estado: ");
			fgets(funcionario.endereco.estado, sizeof(funcionario.endereco.estado), stdin);
			fflush(stdin);
			
			printf("\n Digite uma senha \n");
				scanf("%i", &funcionario.senha);
				limpar_buffer();
				
				FILE*arquivo;
				arquivo = fopen("funcionario.bin", "ab");
				
				fwrite(&funcionario, sizeof(Conta), 1, arquivo);
				fclose(arquivo);
					telainicial();
				
	}

void verificar_conta(){
	system("cls");
	style2();
          int contan;
          char cpf[12];
          int conta_senha;
          
    printf("\t\t\t\t\t\t\t Digite o numero da sua conta:  ");
    scanf("%d", &contan);
		limpar_buffer();
		
    printf("\t\t\t\t\t\t\t Digite o seu CPF:  ");
    scanf("%s", cpf);
		limpar_buffer();
		
    printf("\t\t\t\t\t\t\t Digite a sua senha: ");
    scanf("%d", &conta_senha);
    limpar_buffer();
 
    FILE *arquivo = fopen("funcionario.bin", "rb");
    if (arquivo == NULL) {
        printf("\t\t\t\tERRO, ARQUIVO NAO EXISTE\n");
        telainicial();
        return;
    }
    
Conta conta;

fseek(arquivo,(contan-1)* sizeof(Conta), SEEK_SET);

if (fread(&conta, sizeof(Conta), 1, arquivo) !=1){
	if(feof(arquivo)){
		printf("ERRO, CONTA NAO ENCONTRADA");
				style3();
			system("pause");
			telainicial();
	}else{
		printf("ERRO AO LER A CONTA");
					system("pause");
			telainicial();
	}
		
}
	if(conta_senha == conta.senha){
		printf("\n\n\n\n\n\t\t\t\t\t\t\t\tSENHA CORRETA\n");
		style3();
			system("pause");
		telafuncionario();
	}
	else{
		printf("\nSENHA INCORRETA\n");
			system("pause");
			telainicial();
	}
	
}


void telafuncionario(){
	system("cls");
	
	int op;
	
	printf("\n 1- ABERTURA DE CONTA \n");
	printf("\n 2- ENCERRAMENTO DE CONTA \n");
	printf("\n 3- CONSULTA DADOS \n");
	printf("\n 4- ALTERA DADOS \n");
	printf("\n 5- CADASTRO DE FUNCIONARIO \n");

	printf("\n 6- SAIDA \n");
		printf("\n\nDIGITE UMA OPCAO:");
		scanf("%i", &op);
		
			limpar_buffer();
		
		switch (op){
			case 1:
				aberturaconta();
			
				break;
				
			case 2:
				encerramento();
				break;
			
			case 3:
				consultadados();
				break;
				
			case 4:
				alterar();
				break;
				
			case 5:
				cadastrofuncionario();
				break;
				
			case 6:
				telainicial();
				break;
		}
}

void aberturaconta(){
	
	system("cls");
	int op;
	
		printf("\n 1- CONTA POUPANCA - CP \n");
	printf("\n 2- CONTA CORRENTE - CC \n");
	printf("\n 3- Voltar  \n");
		printf("\n\ndigite uma opcao:");
		scanf("%d", &op);
		
	limpar_buffer();
		
		switch (op){
			case 1:
				poupanca();
				break;
				
			case 2:
				corrente();
				break;
				
			case 3:
				telafuncionario();
				break;
		}	
}

void poupanca(){
		system("cls");
	
	Poupanca poupanca;
	
	printf(" Digite sua agencia: ");
		fgets(poupanca.agencia, sizeof(poupanca.agencia), stdin);
		fflush(stdin);
		
	printf(" Digite o numero da conta: ");
		fgets(poupanca.numconta, sizeof(poupanca.numconta), stdin);
		fflush(stdin);
		
	printf(" Digite o seu nome: ");
		fgets(poupanca.nome, sizeof(poupanca.nome), stdin);
		fflush(stdin);
		
	printf(" Digite o seu CPF:");
		fgets(poupanca.cpf, sizeof(poupanca.cpf), stdin);
		fflush(stdin);
		
	printf("\nDigite a sua data de nascimento-\n\n");
		printf(" Dia: ");
			fgets(poupanca.nascimento.dia_p, sizeof(poupanca.nascimento.dia_p),stdin);
			fflush(stdin);
			
		printf(" Mes: ");
			fgets(poupanca.nascimento.mes_p, sizeof(poupanca.nascimento.mes_p), stdin);
			fflush(stdin);
			
		printf(" Ano: ");
			fgets(poupanca.nascimento.ano_p, sizeof(poupanca.nascimento.ano_p), stdin);
			fflush(stdin);
			
	printf(" Digite o numero de telefone: ");
		fgets(poupanca.telefone, sizeof(poupanca.telefone), stdin);
		fflush(stdin);
		
	printf("\n Endereco-\n\n");
		printf(" CEP:");
			fgets(poupanca.endereco.cep_p, sizeof(poupanca.endereco.cep_p), stdin);
			fflush(stdin);
			
		printf(" Local:");
			fgets(poupanca.endereco.local_p, sizeof(poupanca.endereco.local_p), stdin);
			fflush(stdin);
			
		printf(" Numero da casa: ");
			fgets(poupanca.endereco.numcasa_p, sizeof(poupanca.endereco.numcasa_p), stdin);
			fflush(stdin);
			
		printf(" Bairro: ");
			fgets(poupanca.endereco.bairro_p, sizeof(poupanca.endereco.bairro_p), stdin);
			fflush(stdin);
			
		printf(" Cidade: ");
			fgets(poupanca.endereco.city_p, sizeof(poupanca.endereco.city_p), stdin);
			fflush(stdin);
			
		printf(" estado: ");
			fgets(poupanca.endereco.estado_p, sizeof(poupanca.endereco.estado_p), stdin);
			fflush(stdin);
			
			printf("\n Digite uma senha \n");
				scanf("%i", &poupanca.senha);
				limpar_buffer();
				
					FILE*arquivo;
				arquivo = fopen("poupanca.bin", "ab");
				
				fwrite(&poupanca, sizeof(Conta), 1, arquivo);
				fclose(arquivo);
				
				aberturaconta();
	}

void verificar_poupanca(){
	system("cls");
	
          int contan;
          char cpf[12];
          int poupanca_senha;
          
    printf("\t\t\t\t\t\t\t Digite o numero da sua conta:  ");
    scanf("%d", &contan);
		limpar_buffer();
		
    printf("\t\t\t\t\t\t\t Digite o seu CPF:  ");
    scanf("%s", cpf);
		limpar_buffer();
		
    printf("\t\t\t\t\t\t\t Digite a sua senha: ");
    scanf("%d", &poupanca_senha);
    limpar_buffer();
 
    FILE *arquivo = fopen("poupanca.bin", "rb");
    if (arquivo == NULL) {
        printf("\t\t\t\tERRO, ARQUIVO NAO EXISTE\n");
        return;
    }
    
Poupanca poupanca;

fseek(arquivo,(contan-1)* sizeof(Poupanca), SEEK_SET);

if (fread(&poupanca, sizeof(Poupanca), 1, arquivo) !=1){
	if(feof(arquivo)){
		printf("ERRO, CONTA NAO ENCONTRADA");
				style3();
			system("pause");
			telainicial();
	}else{
		printf("ERRO AO LER A CONTA");
					system("pause");
			telainicial();
	}
		
}
	if(poupanca_senha == poupanca.senha){
		printf("\n\n\n\n\n\t\t\t\t\t\t\t\tSENHA CORRETA\n");

			system("pause");
		tela_clientep();
	}
	else{
		printf("\nSENHA INCORRETA\n");
			system("pause");
			telainicial();
	}
	
}



void corrente(){
	system("cls");
		Corrente corrente;
	
	printf(" Digite sua agencia: ");
		fgets(corrente.agencia, sizeof(corrente.agencia), stdin);
		fflush(stdin);
		
	printf(" Digite o numero da conta: ");
		fgets(corrente.numconta, sizeof(corrente.numconta), stdin);
		fflush(stdin);
		
		printf(" Digite o limite da conta: ");
		scanf("%i", &corrente.limite);
				limpar_buffer();
		
		printf("\n Digite a data de vencimento:\n\n ");
		printf(" Dia: ");
			fgets(corrente.vencimento.dia_v, sizeof(corrente.vencimento.dia_v),stdin);
			fflush(stdin);
			
		printf(" Mes: ");
			fgets(corrente.vencimento.mes_v, sizeof(corrente.vencimento.mes_v), stdin);
			fflush(stdin);
			
		printf(" Ano: ");
			fgets(corrente.vencimento.ano_v, sizeof(corrente.vencimento.ano_v), stdin);
			fflush(stdin);
		
	printf(" Digite o seu nome: ");
		fgets(corrente.nome, sizeof(corrente.nome), stdin);
		fflush(stdin);
		
	printf(" Digite o seu CPF:");
		fgets(corrente.cpf, sizeof(corrente.cpf), stdin);
		fflush(stdin);
		
	printf("\n Digite a sua data de nascimento:\n\n");
		printf(" Dia: ");
			fgets(corrente.nascimento.dia_c, sizeof(corrente.nascimento.dia_c),stdin);
			fflush(stdin);
			
		printf(" Mes: ");
			fgets(corrente.nascimento.mes_c, sizeof(corrente.nascimento.mes_c), stdin);
			fflush(stdin);
			
		printf(" Ano: ");
			fgets(corrente.nascimento.ano_c, sizeof(corrente.nascimento.ano_c), stdin);
			fflush(stdin);
			
	printf(" Digite o numero de telefone: ");
		fgets(corrente.telefone, sizeof(corrente.telefone), stdin);
		fflush(stdin);
		
	printf(" Endereco \n\n");
		printf(" CEP:");
			fgets(corrente.endereco.cep_c, sizeof(corrente.endereco.cep_c), stdin);
			fflush(stdin);
			
		printf(" Local:");
			fgets(corrente.endereco.local_c, sizeof(corrente.endereco.local_c), stdin);
			fflush(stdin);
			
		printf(" Numero da casa: ");
			fgets(corrente.endereco.numcasa_c, sizeof(corrente.endereco.numcasa_c), stdin);
			fflush(stdin);
			
		printf(" Bairro: ");
			fgets(corrente.endereco.bairro_c, sizeof(corrente.endereco.bairro_c), stdin);
			fflush(stdin);
			
		printf(" Cidade: ");
			fgets(corrente.endereco.city_c, sizeof(corrente.endereco.city_c), stdin);
			fflush(stdin);
			
		printf(" estado: ");
			fgets(corrente.endereco.estado_c, sizeof(corrente.endereco.estado_c), stdin);
			fflush(stdin);
			
			printf("\n Digite uma senha \n");
				scanf("%i", &corrente.senha);
				limpar_buffer();
				
					FILE*arquivo;
				arquivo = fopen("corrente.bin", "ab");
				
				fwrite(&corrente, sizeof(Conta), 1, arquivo);
				fclose(arquivo);
				
				aberturaconta();
	}
	
	void verificar_corrente(){
		system("cls");
	style2();
          int contan;
          char cpf[12];
          int corrente_senha;
          
    printf("\t\t\t\t\t\t\t Digite o numero da sua conta:  ");
    scanf("%d", &contan);
		limpar_buffer();
		
    printf("\t\t\t\t\t\t\t Digite o seu CPF:  ");
    scanf("%s", cpf);
		limpar_buffer();
		
    printf("\t\t\t\t\t\t\t Digite a sua senha: ");
    scanf("%d", &corrente_senha);
    limpar_buffer();
 
    FILE *arquivo = fopen("poupanca.bin", "rb");
    if (arquivo == NULL) {
        printf("\t\t\t\tERRO, ARQUIVO NAO EXISTE\n");
        return;
    }
    
Corrente corrente;

fseek(arquivo,(contan-1)* sizeof(Corrente), SEEK_SET);

if (fread(&corrente, sizeof(Corrente), 1, arquivo) !=1){
	if(feof(arquivo)){
		printf("ERRO, CONTA NAO ENCONTRADA");
				style3();
			system("pause");
			telainicial();
	}else{
		printf("ERRO AO LER A CONTA");
					system("pause");
			telainicial();
	}
		
}
	if(corrente_senha == corrente.senha){
		printf("\n\n\n\n\n\t\t\t\t\t\t\t\tSENHA CORRETA\n");
		style3();
			system("pause");
			tela_clientec();
	}
	else{
		printf("\nSENHA INCORRETA\n");
			system("pause");
			telainicial();
	}
	
}

	
	void encerramento(){
		system("cls");
		int op;
		
		printf("\n1- POUPANCA");
		printf("\n2- CORRENTE");
		printf("\n 3- VERIFICAR CONTE POUPANCA");
		printf("\n 4- VERIFICAR CONTA CORRENTE");
		printf("\nndigite uma opcao:");
			scanf("%i", &op);
			
			switch(op){
				
				case 1:
					encerramento_poupanca();
					break;
				case 2:
					encerramento_corrente();
					break;
					
				case 3:
					verificar_poupanca();
					break;
				
				case 4:
					verificar_corrente();
					break;	
			}
	}
	
	void encerramento_poupanca(){
		system("cls");
	int numconta;
	
	Poupanca poupanca;
	
	printf("\n DIGITE O NUMERO DA CONTA:");
		scanf("%i", &numconta);
		
		FILE *arquivo;
		arquivo = fopen("poupanca.bin", "r+b");
		fseek(arquivo, (numconta - 1)* sizeof(Poupanca), SEEK_SET);
		fread(&poupanca, sizeof(Poupanca), 1, arquivo);
			
			strcpy(poupanca.agencia, "");
			strcpy(poupanca.cpf, "");
			strcpy(poupanca.endereco.bairro_p, "");
			strcpy(poupanca.endereco.cep_p, "");
			strcpy(poupanca.endereco.city_p, "");
			strcpy(poupanca.endereco.estado_p, "");
			strcpy(poupanca.endereco.local_p, "");
			strcpy(poupanca.endereco.numcasa_p, "");
			strcpy(poupanca.nascimento.ano_p, "");
			strcpy(poupanca.nascimento.dia_p, "");
 			strcpy(poupanca.nascimento.mes_p, "");
 			strcpy(poupanca.nome, "");
 			strcpy(poupanca.numconta, "");
 			poupanca.senha = 0;
 			strcpy(poupanca.telefone, "");
 			
 		fseek(arquivo, (numconta - 1)* sizeof(Poupanca), SEEK_SET);

		fwrite(&poupanca, sizeof(Poupanca), 1, arquivo);
		
			fseek(arquivo, (numconta - 1)* sizeof(Poupanca), SEEK_SET);
			fread(&poupanca, sizeof(Poupanca), 1, arquivo);
			
			if(poupanca.senha == 0){
				printf("\nENCERRAMENTO COM SUCESSO!!!!!!");
					system("pause");
					telafuncionario();
			}else{
				printf("ERRO!!!!!!!!");
					system("pause");
					telainicial();
			}
		
}

	void encerramento_corrente(){
			system("cls");
	int numconta;
	
	Corrente corrente;
	
	printf("\n DIGITE O NUMERO DA CONTA:");
		scanf("%i", &numconta);
		
		FILE *arquivo;
		arquivo = fopen("corrente.bin", "r+b");
		fseek(arquivo, (numconta - 1)* sizeof(Corrente), SEEK_SET);
		fread(&corrente, sizeof(Corrente), 1, arquivo);
			
			strcpy(corrente.agencia, "");
			strcpy(corrente.cpf, "");
			strcpy(corrente.endereco.bairro_c, "");
			strcpy(corrente.endereco.cep_c, "");
			strcpy(corrente.endereco.city_c, "");
			strcpy(corrente.endereco.estado_c, "");
			strcpy(corrente.endereco.local_c, "");
			strcpy(corrente.endereco.numcasa_c, "");
			corrente.limite = 0;
			strcpy(corrente.vencimento.dia_v, "");
			strcpy(corrente.vencimento.mes_v, "");
			strcpy(corrente.vencimento.ano_v, "");
			strcpy(corrente.nascimento.dia_c, "");
 			strcpy(corrente.nascimento.mes_c, "");
 			strcpy(corrente.nascimento.ano_c, "");
 			strcpy(corrente.nome, "");
 			strcpy(corrente.numconta, "");
 			corrente.senha = 0;
 			strcpy(corrente.telefone, "");
 			
 			
 			
 		fseek(arquivo, (numconta - 1)* sizeof(Corrente), SEEK_SET);

		fwrite(&corrente, sizeof(Corrente), 1, arquivo);
		
			fseek(arquivo, (numconta - 1)* sizeof(Corrente), SEEK_SET);
			fread(&corrente, sizeof(Corrente), 1, arquivo);
			
			if(corrente.senha == 0){
				printf("\nENCERRAMENTO COM SUCESSO!!!!!!");
					system("pause");
					telafuncionario();
			
			}else{
				printf("ERRO!!!!!!!!");
					system("pause");
					telainicial();
			}
			
}

	
	void consultadados(){
		system("cls");
		
		int op;
		
		printf("\n1- COSULTAR CONTA");
		printf("\n2- CONSULTAR FUNCIONARIO");
		printf("\n3- CONSULTAR CLIENTE");
		printf("\n4- VOLTAR");
		printf("\n\ndigite uma opcao:");
			scanf("%i", &op);
			
		limpar_buffer();

		switch(op){
			case 1:
				consultaconta();
				break;
			
			case 2:
				consultar_funcionario();
				break;
				
			case 3:
				consultar_cliente();
				break;
			
			case 4:
				telafuncionario();
				break;
		}	
	}
	
	void consultaconta(){
		system("cls");
		int op;
		
		printf("\n1- POUPANCA");
		printf("\n2- CORRENTE");
		printf("\n3- VOLTAR");
		printf("\n\ndigite uma opcao:");
			scanf("%i", &op);
			
			limpar_buffer();
			
			switch(op){
				
				case 1:
					consultar_poupanca();
					break;
					
				case 2:
					consultar_corrente();
					break;
					
				case 3:
					consultadados();
			}
	}
	
	void consultar_poupanca(){
		system("cls");
		
	int nconta;
	
	printf("\n\t\t\t\t\t\t\t\t\t\tDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);
		
	FILE *arquivo = fopen("poupanca.bin", "rb");
	fseek(arquivo,(nconta - 1) *sizeof(Poupanca), SEEK_SET);
	
	Poupanca poupanca;
	fread(&poupanca, sizeof(Poupanca), 1, arquivo);
	

	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO DA AGENCIA E: %s", poupanca.agencia);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CPF: %s", poupanca.cpf);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NOME:%s", poupanca.nome);
	printf("\n\t\t\t\t\t\t\t\t\t\t-DIA/NASCIMENTO: %s", poupanca.nascimento.dia_p);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-MES/NASCIMENTO :%s", poupanca.nascimento.mes_p);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-ANO/NASCIMENTO: %s", poupanca.nascimento.ano_p);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-TELEFONE: %s", poupanca.telefone);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CEP: %s", poupanca.endereco.cep_p);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CIDADE: %s", poupanca.endereco.city_p);
	printf("\n\t\t\t\t\t\t\t\t\t\t-ESTADO: %s", poupanca.endereco.estado_p);
	printf("\n\t\t\t\t\t\t\t\t\t\t-LOCAL: %s", poupanca.endereco.local_p);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %s", poupanca.endereco.numcasa_p);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-SENHA: %i \n", poupanca.senha);
 		system("pause");
		 consultadados();
}
void consultar_corrente(){
	system("cls");
		
	int nconta;
	
	printf("\n\t\t\t\t\t\t\t\t\t\tDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);
		
	FILE *arquivo = fopen("corrente.bin", "rb");
	fseek(arquivo,(nconta - 1) *sizeof(Corrente), SEEK_SET);
	
	Corrente corrente;
	fread(&corrente, sizeof(Corrente), 1, arquivo);
	
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO DA AGENCIA E: %s", &corrente.agencia);
	printf("\n-CPF: %s", corrente.cpf);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NOME:%s", corrente.nome);
	printf("\n\t\t\t\t\t\t\t\t\t\t-DIA: %s", corrente.nascimento.dia_c);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-MES :%s", corrente.nascimento.mes_c);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-ANO: %s", corrente.nascimento.ano_c);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-TELEFONE: %s", corrente.telefone);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CEP: %s", corrente.endereco.bairro_c);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CIDADE: %s", corrente.endereco.cep_c);
	printf("\n\t\t\t\t\t\t\t\t\t\t-ESTADO: %s", corrente.endereco.city_c);
	printf("\n\t\t\t\t\t\t\t\t\t\t-LOCAL: %s", corrente.endereco.estado_c);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %s", corrente.endereco.local_c);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %d", corrente.endereco.numcasa_c);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %.2f", corrente.limite);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %s", corrente.vencimento.dia_v);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %s", corrente.vencimento.mes_v);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %s", corrente.vencimento.ano_v);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-SENHA: %i \n", corrente.senha);
 		system("pause");
		 consultadados();
}	

void consultar_funcionario(){
system("cls");
		
	int nconta;
	
	printf("\n\t\t\t\t\t\t\t\t\t\tDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);
		
	FILE *arquivo = fopen("funcionario.bin", "rb");
	fseek(arquivo,(nconta - 1) *sizeof(Conta), SEEK_SET);
	
	Conta funcionario;
	
	fread(&funcionario, sizeof(Conta), 1, arquivo);
	
	
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t-NUMERO DA AGENCIA E: %s", funcionario.agencia);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CPF: %s", funcionario.cpf);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NOME:%s", funcionario.nome);
	printf("\n\t\t\t\t\t\t\t\t\t\t-DIA: %s", funcionario.nascimento.dia);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-MES :%s", funcionario.nascimento.mes);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-ANO: %s", funcionario.nascimento.ano);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-TELEFONE: %s", funcionario.telefone);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CEP: %s", funcionario.endereco.cep);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CIDADE: %s", funcionario.endereco.city);
	printf("\n\t\t\t\t\t\t\t\t\t\t-ESTADO: %s", funcionario.endereco.estado);
	printf("\n\t\t\t\t\t\t\t\t\t\t-LOCAL: %s", funcionario.endereco.local);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %s", funcionario.endereco.numcasa);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-SENHA %i \n", funcionario.senha);
 	system("pause");
 	consultadados();
}

void consultar_cliente(){
	system("cls");
		
	int nconta;
	
	printf("\nDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);
		
	FILE *arquivo = fopen("cliente.bin", "rb");
	fseek(arquivo,(nconta - 1) *sizeof(Conta_cl), SEEK_SET);
	
	Conta_cl cliente;
	
	fread(&cliente, sizeof(Conta_cl), 1, arquivo);
	
	
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO DA AGENCIA E: %s", cliente.agencia);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CPF: %s", cliente.cpf);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NOME:%s", cliente.nome);
	printf("\n\t\t\t\t\t\t\t\t\t\t-DIA: %s", cliente.nascimento.dia);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-MES :%s", cliente.nascimento.mes);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-ANO: %s", cliente.nascimento.ano);
 	printf("\\t\t\t\t\t\t\t\t\t\t-TELEFONE: %s", cliente.telefone);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CEP: %s", cliente.endereco.cep);
	printf("\n\t\t\t\t\t\t\t\t\t\t-CIDADE: %s", cliente.endereco.city);
	printf("\n\t\t\t\t\t\t\t\t\t\t-ESTADO: %s", cliente.endereco.estado);
	printf("\n\t\t\t\t\t\t\t\t\t\t-LOCAL: %s", cliente.endereco.local);
	printf("\n\t\t\t\t\t\t\t\t\t\t-NUMERO: %s", cliente.endereco.numcasa);
 	printf("\n\t\t\t\t\t\t\t\t\t\t-SENHA %i \n", cliente.senha);
 	system("pause");
	consultadados();
}

void alterar(){
	system("cls");
	int op; 
	
	printf("\n1- ALTERAR CONTA");
	printf("\n2- ALTERAR FUNCIONARIO");
	printf("\n3- ALTERAR CLIENTE ");
	printf("\n4- SAIR");
	printf("\n DIGITE UM NUMERO:");
		scanf("%i", &op);
		limpar_buffer();
		
		switch(op){
			
			case 1:
				contas();
				break;
			
			case 2:
				alterar_funcionario();
				break;
			
			case 3:
				alterar_cliente();
				break;
				
			case 4:
				telafuncionario();
		}
}

void contas(){
	system("cls");
	int op;
	
	printf("\n 1- POUPANCA");
	printf("\n 2- CORRENTE");
	printf("\n\n DIGITE UM NUMERO:");
		scanf("%i", &op);	
		limpar_buffer();
		
		switch(op){
			
			case 1:
				alterar_poupanca();
				break;
			case 2:
				alterar_corrente();
				break;
		}

}

void alterar_poupanca(){
	system("cls");
	int nconta;
	
	printf("\n\t\t\t\t\t\t\t\t\t\tDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);  
			limpar_buffer();

		FILE *arquivo = fopen("poupanca.bin", "r+b");
	
	Poupanca poupanca;
	
	fread(&corrente, sizeof(Corrente), 1, arquivo);
	
	printf("Digite o novo agencia:");
		fgets(poupanca.agencia, sizeof(poupanca.agencia), stdin);
	poupanca.agencia[strcspn(poupanca.agencia, "\n")] = '\0';
	
	printf("Digite o novo dia de nascimento:");
		fgets(poupanca.nascimento.dia_p, sizeof(poupanca.nascimento.dia_p), stdin);
	poupanca.nascimento.dia_p[strcspn(poupanca.nascimento.dia_p, "\n")] = '\0';
	
	printf("Digite o novo mes do nascimento:");
		fgets(poupanca.nascimento.mes_p, sizeof(poupanca.nascimento.mes_p), stdin);
	poupanca.nascimento.mes_p[strcspn(poupanca.nascimento.mes_p, "\n")] = '\0';
	
	printf("Digite o novo ano do nascimento:");
		fgets(poupanca.nascimento.ano_p, sizeof(poupanca.nascimento.ano_p), stdin);
	poupanca.nascimento.ano_p[strcspn(poupanca.nascimento.ano_p, "\n")] = '\0';
	
	printf("Digite o novo CPF:");
		fgets(poupanca.cpf, sizeof(poupanca.cpf), stdin);
	poupanca.cpf[strcspn(poupanca.cpf, "\n") -1] = '\0';
	
	printf("Digite o novo telefone:");
		fgets(poupanca.telefone, sizeof(poupanca.telefone), stdin);
	poupanca.telefone[strcspn(poupanca.telefone, "\n")] = '\0';
	
	printf("Digite o novo bairro:");
		fgets(poupanca.endereco.bairro_p, sizeof(poupanca.endereco.bairro_p), stdin);
	poupanca.endereco.bairro_p[strcspn(poupanca.endereco.bairro_p, "\n")] = '\0';
	
	printf("Digite o novo cep:");
		fgets(poupanca.endereco.cep_p, sizeof(poupanca.endereco.cep_p), stdin);
	poupanca.endereco.cep_p[strcspn(poupanca.endereco.cep_p, "\n")] = '\0';
	
		printf("Digite a nova cidade:");
		fgets(poupanca.endereco.city_p, sizeof(poupanca.endereco.city_p), stdin);
	poupanca.endereco.city_p[strcspn(poupanca.endereco.city_p, "\n")] = '\0';
	
	printf("Digite o seu novo estado:");
		fgets(poupanca.endereco.estado_p, sizeof(poupanca.endereco.estado_p), stdin);
	poupanca.endereco.estado_p[strcspn(poupanca.endereco.estado_p, "\n")] = '\0';
	
	printf("Digite a nova localizacao:");
		fgets(poupanca.endereco.local_p, sizeof(poupanca.endereco.local_p), stdin);
	poupanca.endereco.local_p[strcspn(poupanca.endereco.local_p, "\n")] = '\0';
	
	printf("Digite o novo numero da casa:");
		fgets(poupanca.endereco.numcasa_p, sizeof(poupanca.endereco.numcasa_p), stdin);
	poupanca.endereco.numcasa_p[strcspn(poupanca.endereco.numcasa_p, "\n")] = '\0';
	
	printf("Digite sua nova senha: ");
		scanf("%i", &poupanca.senha);
		limpar_buffer();
		
		fseek(arquivo, -sizeof(Corrente), SEEK_CUR);
	fwrite(&corrente, sizeof(Corrente), 1, arquivo);
	fclose(arquivo);
	
	alterar();
		
	}

void alterar_corrente(){
	system("cls");
	int nconta;
	
	printf("\n\t\t\t\t\t\t\t\t\t\tDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);  
			limpar_buffer();

		FILE *arquivo = fopen("corrente.bin", "r+b");
		
	Corrente corrente;
	
	fread(&corrente, sizeof(Corrente), 1, arquivo);
	
	printf("Digite o novo agencia:");
		fgets(corrente.agencia, sizeof(corrente.agencia), stdin);
	fflush(stdin);
	corrente.agencia[strcspn(corrente.agencia, "\n")] = '\0';
	
	printf("Digite seu novo limite:");
		scanf("%f", &corrente.limite);
	limpar_buffer();
	
	printf("Digite o novo dia de vencimento da conta:");
		fgets(corrente.vencimento.dia_v, sizeof(corrente.vencimento.dia_v), stdin);
		fflush(stdin);
	corrente.vencimento.dia_v[strcspn(corrente.vencimento.dia_v, "\n")] = '\0';
	
	printf("Digite o novo mes de vencimento da conta:");
		fgets(corrente.vencimento.mes_v, sizeof(corrente.vencimento.mes_v), stdin);
	     fflush(stdin);
	corrente.vencimento.mes_v[strcspn(corrente.vencimento.mes_v, "\n")] = '\0';
	
	printf("Digite o novo ano de vencimento da Cconta:");
		fgets(corrente.vencimento.ano_v, sizeof(corrente.vencimento.ano_v), stdin);
			fflush(stdin);
	corrente.vencimento.ano_v[strcspn(corrente.vencimento.ano_v, "\n")] = '\0';
	
	printf("Digite o novo dia de nascimento:");
		fgets(corrente.nascimento.dia_c, sizeof(corrente.nascimento.dia_c), stdin);
			fflush(stdin);
	corrente.nascimento.dia_c[strcspn(corrente.nascimento.dia_c, "\n")] = '\0';
	
	printf("Digite o novo mes do nascimento:");
		fgets(corrente.nascimento.mes_c, sizeof(corrente.nascimento.mes_c), stdin);
		fflush(stdin);
	corrente.nascimento.mes_c[strcspn(corrente.nascimento.mes_c, "\n")] = '\0';
	
	printf("Digite o novo ano do nascimento:");
		fgets(corrente.nascimento.ano_c, sizeof(corrente.nascimento.ano_c), stdin);
		fflush(stdin);
	corrente.nascimento.ano_c[strcspn(corrente.nascimento.ano_c, "\n")] = '\0';
	
	printf("Digite o novo CPF:");
		fgets(corrente.cpf, sizeof(corrente.cpf), stdin);
		fflush(stdin);
	corrente.cpf[strcspn(corrente.cpf, "\n")] = '\0';
	
	printf("Digite o novo telefone:");
		fgets(corrente.telefone, sizeof(corrente.telefone), stdin);
		fflush(stdin);
	corrente.telefone[strcspn(corrente.telefone, "\n")] = '\0';
	
	printf("Digite o novo bairro:");
		fgets(corrente.endereco.bairro_c, sizeof(corrente.endereco.bairro_c), stdin);
		fflush(stdin);
	corrente.endereco.bairro_c[strcspn(corrente.endereco.bairro_c, "\n")] = '\0';
	
	printf("Digite o novo cep:");
		fgets(corrente.endereco.cep_c, sizeof(corrente.endereco.cep_c), stdin);
		fflush(stdin);
	corrente.endereco.cep_c[strcspn(corrente.endereco.cep_c, "\n")] = '\0';
	
		printf("Digite a nova cidade:");
		fgets(corrente.endereco.city_c, sizeof(corrente.endereco.city_c), stdin);
		fflush(stdin);
	corrente.endereco.city_c[strcspn(corrente.endereco.city_c, "\n")] = '\0';
	
	printf("Digite o novo estado:");
		fgets(corrente.endereco.estado_c, sizeof(corrente.endereco.estado_c), stdin);
		fflush(stdin);
	corrente.endereco.estado_c[strcspn(corrente.endereco.estado_c, "\n")] = '\0';
	
	printf("Digite a nova localizacao:");
		fgets(corrente.endereco.local_c, sizeof(corrente.endereco.local_c), stdin);
		fflush(stdin);
	corrente.endereco.local_c[strcspn(corrente.endereco.local_c, "\n")] = '\0';
	
	printf("Digite o novo numero da casa:");
		fgets(corrente.endereco.numcasa_c, sizeof(corrente.endereco.numcasa_c), stdin);
		fflush(stdin);
	corrente.endereco.numcasa_c[strcspn(corrente.endereco.numcasa_c, "\n")] = '\0';
	
	printf("Digite sua nova senha: ");
		scanf("%i", &corrente.senha);
		limpar_buffer();
		
		fseek(arquivo, -sizeof(Corrente), SEEK_CUR);
	fwrite(&corrente, sizeof(Corrente), 1, arquivo);
	fclose(arquivo);
	
	alterar();
}


void alterar_funcionario(){
     system("cls");
      int nconta;
	
	printf("\n\t\t\t\t\t\t\t\t\t\tDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);  
			limpar_buffer();

		FILE *arquivo = fopen("funcionario.bin", "r+b");
		
	Conta funcionario;
	
	fread(&funcionario, sizeof(Conta), 1, arquivo);
	
	printf("Digite o novo agencia:");
		fgets(funcionario.agencia, sizeof(funcionario.agencia), stdin);
		 fflush(stdin);
	funcionario.agencia[strcspn(funcionario.agencia, "\n")] = '\0';
	
	printf("Digite o novo telefone:");
		fgets(funcionario.telefone, sizeof(funcionario.telefone), stdin);
		fflush(stdin);
	funcionario.telefone[strcspn(funcionario.telefone, "\n")] = '\0';
	
	printf("Digite o novo bairro:");
		fgets(funcionario.endereco.bairro, sizeof(funcionario.endereco.bairro), stdin);
		fflush(stdin);
	funcionario.endereco.bairro[strcspn(funcionario.endereco.bairro, "\n")] = '\0';
	
	printf("Digite o novo cep:");
		fgets(funcionario.endereco.cep, sizeof(funcionario.endereco.cep), stdin);
		fflush(stdin);
	funcionario.endereco.cep[strcspn(funcionario.endereco.cep, "\n")] = '\0';
	
		printf("Digite a nova cidade:");
		fgets(funcionario.endereco.city, sizeof(funcionario.endereco.city), stdin);
		fflush(stdin);
	funcionario.endereco.city[strcspn(funcionario.endereco.city, "\n")] = '\0';
	
	printf("Digite a novo estado:");
		fgets(funcionario.endereco.estado, sizeof(funcionario.endereco.estado), stdin);
		fflush(stdin);
	funcionario.endereco.estado[strcspn(funcionario.endereco.estado, "\n")] = '\0';
	
	printf("Digite a nova localizacao:");
		fgets(funcionario.endereco.local, sizeof(funcionario.endereco.local), stdin);
		fflush(stdin);
	funcionario.endereco.local[strcspn(funcionario.endereco.local, "\n")] = '\0';
	
	printf("Digite o novo numero da casa:");
		fgets(funcionario.endereco.numcasa, sizeof(funcionario.endereco.numcasa), stdin);
		fflush(stdin);
	funcionario.endereco.numcasa[strcspn(funcionario.endereco.numcasa, "\n")] = '\0';
	
	printf("Digite sua nova senha: ");
		scanf("%i", &funcionario.senha);
		
		fseek(arquivo, -sizeof(Conta), SEEK_CUR);
	fwrite(&funcionario, sizeof(Conta), 1, arquivo);
	fclose(arquivo);
	
	telafuncionario();
}

void alterar_cliente(){
	system("cls");
      int nconta;
	
	printf("\n\t\t\t\t\t\t\t\t\t\tDIGITE O NUMERO DA SUA CONTA:");
		scanf("%i", &nconta);  
			limpar_buffer();

		FILE *arquivo = fopen("cliente.bin", "r+b");
		
	Conta_cl cliente;
	
	fread(&cliente, sizeof(Conta_cl), 1, arquivo);
	
	printf("Digite o novo agencia:");
		fgets(cliente.agencia, sizeof(cliente.agencia), stdin);
		 fflush(stdin);
	cliente.agencia[strcspn(cliente.agencia, "\n")] = '\0';
	
	printf("Digite o novo telefone:");
		fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
		fflush(stdin);
	cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';
	
	printf("Digite o novo bairro:");
		fgets(cliente.endereco.bairro, sizeof(cliente.endereco.bairro), stdin);
		fflush(stdin);
	cliente.endereco.bairro[strcspn(cliente.endereco.bairro, "\n")] = '\0';
	
	printf("Digite o novo cep:");
		fgets(cliente.endereco.cep, sizeof(cliente.endereco.cep), stdin);
		fflush(stdin);
	cliente.endereco.cep[strcspn(cliente.endereco.cep, "\n")] = '\0';
	
		printf("Digite a nova cidade:");
		fgets(cliente.endereco.city, sizeof(cliente.endereco.city), stdin);
		fflush(stdin);
	cliente.endereco.city[strcspn(cliente.endereco.city, "\n")] = '\0';
	
	printf("Digite a novo estado:");
		fgets(cliente.endereco.estado, sizeof(cliente.endereco.estado), stdin);
		fflush(stdin);
	cliente.endereco.estado[strcspn(cliente.endereco.estado, "\n")] = '\0';
	
	printf("Digite a nova localizacao:");
		fgets(cliente.endereco.local, sizeof(cliente.endereco.local), stdin);
		fflush(stdin);
	cliente.endereco.local[strcspn(cliente.endereco.local, "\n")] = '\0';
	
	printf("Digite o novo numero da casa:");
		fgets(cliente.endereco.numcasa, sizeof(cliente.endereco.numcasa), stdin);
		fflush(stdin);
	cliente.endereco.numcasa[strcspn(cliente.endereco.numcasa, "\n")] = '\0';
	
	printf("Digite sua nova senha: ");
		scanf("%i", &cliente.senha);
		
		fseek(arquivo, -sizeof(Conta_cl), SEEK_CUR);
	fwrite(&cliente, sizeof(Conta_cl), 1, arquivo);
	fclose(arquivo);
	
	telafuncionario();
}




void cadastrofuncionario(){
	system("cls");
	
	Cadastro funcionario;
	
	printf("numero da conta funcionario");
		fgets(funcionario.numconta, sizeof(funcionario.numconta), stdin);
		
	printf(" Codigo funcionario: ");
		fgets(funcionario.agencia, sizeof(funcionario.agencia), stdin);
		fflush(stdin);
		
	printf("cargo do funcionario: ");
		fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
		fflush(stdin);
		
	printf(" nome do funcionario: ");
		fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
		fflush(stdin);
		
	printf(" CPF do funcionario:");
		fgets(funcionario.cpf, sizeof(funcionario.cpf), stdin);
		fflush(stdin);
		
	printf("\n data de nascimento do funcionario- \n\n");
		printf(" Dia: ");
			fgets(funcionario.nascimento.dia, sizeof(funcionario.nascimento.dia),stdin);
			fflush(stdin);
			
		printf(" Mes: ");
			fgets(funcionario.nascimento.mes, sizeof(funcionario.nascimento.mes), stdin);
			fflush(stdin);
			
		printf(" Ano: ");
			fgets(funcionario.nascimento.ano, sizeof(funcionario.nascimento.ano), stdin);
			fflush(stdin);
			
	printf("  telefone do funcionario: ");
		fgets(funcionario.telefone, sizeof(funcionario.telefone), stdin);
		fflush(stdin);
		
	printf(" \nEndereco do funcionario- \n\n");
		printf(" CEP:");
			fgets(funcionario.endereco.cep, sizeof(funcionario.endereco.cep), stdin);
			fflush(stdin);
			
		printf(" Local:");
			fgets(funcionario.endereco.local, sizeof(funcionario.endereco.local), stdin);
			fflush(stdin);
			
		printf(" Numero da casa: ");
			fgets(funcionario.endereco.numcasa, sizeof(funcionario.endereco.numcasa), stdin);
			fflush(stdin);
			
		printf(" Bairro: ");
			fgets(funcionario.endereco.bairro, sizeof(funcionario.endereco.bairro), stdin);
			fflush(stdin);
			
		printf(" Cidade: ");
			fgets(funcionario.endereco.city, sizeof(funcionario.endereco.city), stdin);
			fflush(stdin);
			
		printf(" estado: ");
			fgets(funcionario.endereco.estado, sizeof(funcionario.endereco.estado), stdin);
			fflush(stdin);
			
			printf("\nsenha do funcionario\n");
				scanf("%i", &funcionario.senha);
				limpar_buffer();
				
				FILE*arquivo;
				arquivo = fopen("funcionario.bin", "ab");
				
				fwrite(&funcionario, sizeof(Conta), 1, arquivo);
				fclose(arquivo);
					telainicial();
}


void conta_clien(){
	system("cls");
	
	Conta_cl cliente;
	
	printf(" Digite sua agencia: ");
		fgets(cliente.agencia, sizeof(cliente.agencia), stdin);
		fflush(stdin);
		
			
	printf(" Digite o seu nome: ");
		fgets(cliente.nome, sizeof(cliente.nome), stdin);
		fflush(stdin);
		
	printf(" Digite o seu CPF:");
		fgets(cliente.cpf, sizeof(cliente.cpf), stdin);
		fflush(stdin);
		
	printf("\n Digite a sua data de nascimento- \n\n");
		printf(" Dia: ");
			fgets(cliente.nascimento.dia, sizeof(cliente.nascimento.dia),stdin);
			fflush(stdin);
			
		printf(" Mes: ");
			fgets(cliente.nascimento.mes, sizeof(cliente.nascimento.mes), stdin);
			fflush(stdin);
			
		printf(" Ano: ");
			fgets(cliente.nascimento.ano, sizeof(cliente.nascimento.ano), stdin);
			fflush(stdin);
			
	printf(" Digite o numero de telefone: ");
		fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
		fflush(stdin);
		
	printf(" \nEndereco- \n\n");
		printf(" CEP:");
			fgets(cliente.endereco.cep, sizeof(cliente.endereco.cep), stdin);
			fflush(stdin);
			
		printf(" Local:");
			fgets(cliente.endereco.local, sizeof(cliente.endereco.local), stdin);
			fflush(stdin);
			
		printf(" Numero da casa: ");
			fgets(cliente.endereco.numcasa, sizeof(cliente.endereco.numcasa), stdin);
			fflush(stdin);
			
		printf(" Bairro: ");
			fgets(cliente.endereco.bairro, sizeof(cliente.endereco.bairro), stdin);
			fflush(stdin);
			
		printf(" Cidade: ");
			fgets(cliente.endereco.city, sizeof(cliente.endereco.city), stdin);
			fflush(stdin);
			
		printf(" estado: ");
			fgets(cliente.endereco.estado, sizeof(cliente.endereco.estado), stdin);
			fflush(stdin);
			
			printf("\n Digite uma senha \n");
				scanf("%i", &cliente.senha);
				limpar_buffer();
				
				FILE*arquivo;
				arquivo = fopen("cliente.bin", "ab");
				
				fwrite(&cliente, sizeof(Conta_cl), 1, arquivo);
				fclose(arquivo);
					telainicial();
				
	}




void verificar_cliente(){
	system("cls");
	
          int contan;
          char cpf[12];
          int cliente_senha;
          
    printf("\n Digite o número da sua conta: \n ");
    scanf("%d", &contan);
		limpar_buffer();
		
    printf("\n Digite o seu CPF:\n  ");
    scanf("%s", cpf);
		limpar_buffer();
		
    printf("\n Digite a sua senha:\n  ");
    scanf("%d", &cliente_senha);
    limpar_buffer();

    FILE *arquivo = fopen("cliente.bin", "rb");
    if (arquivo == NULL) {
        printf("ERRO, ARQUIVO NÃO EXISTE\n");
        	fclose(arquivo);
        return;
    }
    
Conta_cl cliente;

fseek(arquivo,(contan-1)* sizeof(Conta_cl), SEEK_SET);

if (fread(&cliente, sizeof(Conta_cl), 1, arquivo) !=1){
	if(feof(arquivo)){
		printf("ERRO, CONTA NAO ENCONTRADA");
				system("pause");
			telainicial();
	}else{
		printf("ERRO AO LER A CONTA");
					system("pause");
			telainicial();
	}
	
}
	if(cliente_senha == cliente.senha){
		printf("\nSENHA CORRETA\n");
			system("pause");
		menu_cliente();
	}
	else{
		printf("\nSENHA INCORRETA\n");
			system("pause");
			telainicial();
	}
	
}


void tela_clientep(){
	system("cls");
	
	int op;
	
	printf("\n 1- SALDO \n");
	printf("\n 2- DEPOSITO \n");
	printf("\n 3- SAQUE \n");
	printf("\n 4- EXTRATO \n");
	printf("\n 5- CONSULTA LIMITE \n");
	printf("\n 6- SAIR \n");

		printf("\n\ndigite uma opcao:");
		scanf("%i", &op);
		
			limpar_buffer();
		
		switch (op){
			case 1:
				saldo();
			
				break;
				
			case 2:
				deposito();
				break;
				
			case 3:
				saque();
				break;
				
			case 4:
				extrato();
				break;
				
			case 5:
				consultar_limite();
				break;
				
			case 6:
				telainicial();
				break;
		}
}

void menu_cliente(){
	system("cls");
	int op;
	
	printf("\n\t\t\t\t\t\t\t\t 1- POUPANCA");
	printf("\n\t\t\t\t\t\t\t\t 2- CORRENTE");
		printf("\n\t\t\t\t\t\t\t\t 3- SAIR");
	printf("\n\t\t\t\t\t\t\t\t Digite uma opcao:");

		scanf("%i", &op);
		limpar_buffer();
		
		switch(op){
			
			case 1:
				verificar_poupanca();
				break;
				
			case 2:
				verificar_corrente();
				break;
				
			case 3:
				telainicial();
				break;
		}
}

void saldo(){
	system("cls");
	FILE *arquivo = fopen("extratos.csv", "a");
	float quant;
			

	printf("Quando de saldo vc deseja ter:");
		scanf("%f", &quant);
		
			limpar_buffer();
		fprintf(arquivo,"você tem R$%.2f de saldo \n", quant);
		fclose(arquivo);
		
		tela_clientep();
}

void deposito(){
	system("cls");
	FILE *arquivo = fopen("extratos.csv", "a");

	float depo;
	
	printf("Quanto vc deseja depositar:");
	scanf("%.2f", &depo);
		limpar_buffer();
		fprintf(arquivo,"você tem R$%.2f de deposito \n", depo);
		fclose(arquivo);
		
		tela_clientep();

}

void saque(){
	system("cls");
		FILE *arquivo = fopen("extratos.csv", "a");

	float money;
	
	printf("quanto vc quer sacar:");
		scanf("%f", &money);
			limpar_buffer();
		
		
		fprintf(arquivo, "você sacou R$%f \n", money);
		fclose(arquivo);
		
	tela_clientep();
	
}
void extrato(){
	system("extratos.csv");
}
void consultar_limite(){
	system("cls");
		FILE *arquivo = fopen("extratos.csv", "a");
	float lim;
	
	printf("quanto de limite vc deseja:\n");
	scanf("%f", &lim);
		limpar_buffer();

	
		fprintf(arquivo, " tem um limite de R$%f \n", lim);
		fclose(arquivo);
		
	tela_clientep();
} 

void tela_clientec(){
		system("cls");
	
	int op;
	
	printf("\n 1- SALDO \n");
	printf("\n 2- DEPOSITO \n");
	printf("\n 3- SAQUE \n");
	printf("\n 4- EXTRATO \n");
	printf("\n 5- CONSULTA LIMITE \n");
	printf("\n 6- SAIR \n");

		printf("\n\ndigite uma opcao:");
		scanf("%i", &op);
		
			limpar_buffer();
		
		switch (op){
			case 1:
				saldoc();
			
				break;
				
			case 2:
				depositoc();
				break;
				
			case 3:
				saquec();
				break;
				
			case 4:
				extratoc();
				break;
				
			case 5:
				consultar_limitec();
				break;
				
			case 6:
				telainicial();
				break;
		}
}

void saldoc(){
		system("cls");
		
FILE *arquivo = fopen("extratosc.csv", "a");
	float quant;
	
	printf("Quando de saldo vc deseja ter:");
		scanf("%f", quant);
		limpar_buffer();
		
		
		fprintf(arquivo,"você tem R$%.2f de saldo\n", quant);
		fclose(arquivo);
		
		tela_clientec();
}

void depositoc(){
	system("cls");
	FILE *arquivo = fopen("extratosc.csv", "a");

	float depo;
	
	printf("Quanto vc deseja depositar:");
	scanf("%f", &depo);
		
		limpar_buffer();
		
		fprintf(arquivo,"você tem R$%.2f de deposito \n", depo);
		fclose(arquivo);
		
		tela_clientec();
}


void saquec(){
	system("cls");
		FILE *arquivo = fopen("extratosc.csv", "a");

	float money;
	
	printf("quanto vc quer sacar:");
		scanf("%f", &money);
		
			limpar_buffer();
		
		fprintf(arquivo, "você sacou R$%.2f \n", money);
		fclose(arquivo);
		
	tela_clientec();
}

void extratoc(){
	
	system("extratosc.csv");
	
}	

void consultar_limitec(){
	system("cls");
	float lim;
	
	printf("quanto de limite vc deseja:");
	scanf("%f", &lim);
		limpar_buffer();

		FILE *arquivo = fopen("extratosc.csv", "a");
		fprintf(arquivo, " tem um limite de R$%f \n", lim);
		fclose(arquivo);
		
	tela_clientec();
}
