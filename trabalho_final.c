#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 150
#define D 10

typedef struct{
	int dia;
	int mes;
	int ano;
}tData;

typedef struct{
	char nome[100];
	char cpf[12];
	tData nasc;
	tData adm;
	int dep;
	int cargo;
}tFuncionario;

typedef struct{
	int codigo;
	char nome[100];
}tDepartamento;

//MENUS
int menu();
int menu_funcionario();
int menu_departamento();
//FUNÇOES DE DEPARTAMENTO
void criar_dep();
void altera_nome_dep();
void consultar_dep();
void listar_dep();
void excluir_dep(); 
//FUNÇÕES DE FUNCIONARIO
void cadastrar_funcionario();
void alterar_dados_funcionario();
void transferir_funcionario();
void demitir_funcionario();
void pesquisar_funcionario();
void listar_funcionario();
//OUTRAS FUNÇÕES
int verifica_data();
int eh_bissexto();

int main(){
	
	tFuncionario func[F];
	tDepartamento dep[D];
	int contFunc = 0;
	int contDep = 0;
	int resp;
	int respFun;
	int respDep;
	
	do{
		system("cls");
		resp = menu();
		system("cls");
		
		if(resp==1){//FUNCIONARIO
			do{
				system("cls");
				respFun = menu_funcionario();
				system("cls");
				
				switch(respFun){
				case 1:
					cadastrar_funcionario(func, dep, &contFunc, &contDep);
					break;
				case 2:
					alterar_dados_funcionario(func, &contFunc);
					break;
				case 3:
					transferir_funcionario(func, dep, &contFunc, &contDep);
					break;
				case 4:
					demitir_funcionario(func, &contFunc);
					break;
				case 5:
					pesquisar_funcionario(func, dep, &contFunc, &contDep);
					break;
				case 6:
					listar_funcionario(func, dep, &contFunc, &contDep);
					break;
				}
				
			}while(respFun!=0);
		}

		if(resp==2){//DEPARTAMENTO
			do{
				system("cls");
				respDep = menu_departamento();
				system("cls");
				
				switch(respDep){
					case 1:
						criar_dep(dep, &contDep); 
						break;
					case 2:
						altera_nome_dep(dep, &contDep); 
						break;
					case 3:
						consultar_dep(dep, func, &contDep, &contFunc);
						break;
					case 4:
						listar_dep(dep, func, &contDep, &contFunc);
						break;
					case 5:
						excluir_dep(dep, func, &contDep, &contFunc);
						break;
				}
			}while(respDep!=0);
		}	
	}while(resp!=0);

	printf("\n\n\n\n\n\n\n\n		F I N A L I Z A D O\n\n\n\n\n\n\n");
	
	return 0;
}
/*
OBJETIVO:		Imprimir o menu principal e solicitar que o usuário escolha uma opção do mesmo;
PARAMETROS:		Nao;
RETORNO: 		Retorna "int resp" para a função principal, que armazena a opcao escolhida pelo usuário;
*/
int menu(){
	
	int resp;	
	do{
		resp = -1;
		printf("------------------------------------------------------------\n");
		printf("		   MENU PRINCIPAL\n");
		printf("------------------------------------------------------------\n");
		printf("1. Menu Funcionario\n");
		printf("2. Menu Departamento\n");
		printf("0. Sair\n");
		printf("------------------------------------------------------------\n");
		printf("Escolha uma opcao do menu: ");
		fflush(stdin);
		scanf("%d", &resp);
		
		if(resp!=1 && resp!=2 && resp!=0){
			printf("\nERRO: Opcao invalida!\n\n");
			system("pause");
			system("cls");
		}
		
	}while(resp!=1 && resp!=2 && resp!=0);
	
	return resp;
}
/*
OBJETIVO:	Imprimir o menu funcionario e solicitar que o usuário escolha uma opção do mesmo;
PARAMETROS: Não;
RETORNO:	Retorna "int respFun" para a função principal, que armazena a opcao escolhida pelo usuário;
*/
int menu_funcionario(){
		
	int respFun;
	do{
		respFun = -1;
		printf("------------------------------------------------------------\n");	
		printf("			MENU FUNCIONARIO\n");
		printf("------------------------------------------------------------\n");
		printf("1. Cadastrar funcionario\n");
		printf("2. Alterar dados de um funcionario\n");
		printf("3. Transferir funcionario de departamento\n");
		printf("4. Demitir Funcionario\n");
		printf("5. Pesquisar funcionario\n");
		printf("6. Listar funcionarios\n");
		printf("0. Voltar\n");
		printf("------------------------------------------------------------\n");
		printf("Escolha uma opcao do menu: ");
		fflush(stdin);
		scanf("%d", &respFun);
		
		if(respFun!=1 && respFun!= 2 && respFun!=3 && respFun!=4 && respFun!=5 && respFun!=6 && respFun!=0){
			printf("\nERRO: Opcao invalida!\n\n");
			system("pause");
			system("cls");
		}
		
	}while(respFun!=1 && respFun!= 2 && respFun!=3 && respFun!=4 && respFun!=5 && respFun!=6 && respFun!=7 && respFun!=0);

	return respFun;
}
/*
OBJETIIVO:		Imprimir o menu departamento e solicitar que o usuario escolha uma opção do mesmo;
PARÂMETROS:		Não;
RETORNO:		Retorna "int respDep" para a função principal, que armazena a opção escolhida pelo usuário;	
*/
int menu_departamento(){
	
	int respDep;
	do{
		system("cls");
		respDep = -1;
		printf("------------------------------------------------------------\n");	
		printf("		  MENU DEPARTAMENTO\n");
		printf("------------------------------------------------------------\n");
		printf("1. Criar departamento\n");
		printf("2. Alterar nome de um departamento\n");
		printf("3. Consultar departamento\n");
		printf("4. Listar departamentos\n");
		printf("5. Excluir departamentos\n");
		printf("0. Voltar\n");
		printf("------------------------------------------------------------\n");
		printf("Escolha uma opcao do menu: ");
		fflush(stdin);
		scanf("%d", &respDep);
			
		if(respDep!=1 && respDep!=2 && respDep!=3 && respDep!=4 && respDep!=5 && respDep!=0){
			printf("\nERRO: Opcao invalida!\n\n");
			system("pause");
			system("cls");	
		}
			
	}while(respDep!=1 && respDep!=2 && respDep!=3 && respDep!=4 && respDep!=5 && respDep!=0);
		
	return respDep;
}

/*
OBJETIVO:	Criar novos departamentos e armazená-los no vetor de struct dep[D];
PARAMETROS:	Recebe o vetor de struct "dep[D]" para que um novo departamento e seus dados possam ser armazenados em uma posição desse vetor;
			Recebe por ponteiro a variável  de controle "contDep";
RETORNO: 	Não;
*/
void criar_dep(tDepartamento dep[D], int *contDep){
	
	if(*contDep>=D){
		printf("------------------------------------------------------------\n");
		printf("		CRIAR DEPARTAMENTO\n");
		printf("------------------------------------------------------------\n\n");
		printf("Nossos sistemas informam que ja foram criados %d de %d departamentos\n", *contDep, D);
		printf("portanto, nao ha mais vagas para a criacao de novos departamenos!\n\n");
		printf("------------------------------------------------------------\n");	
		system("pause");
			
	}else{
	
		int resp = - 1;
		tDepartamento aux;
		do{
			do{
				system("cls");
				resp = -1;
				printf("------------------------------------------------------------\n");
				printf("	 	  CRIAR DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Criar departamento\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
				
				if(resp!=1 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
					system("cls");
				}
				
			}while(resp!=1 && resp!=0);
			
			if(resp==1){
				
				if(*contDep==0){ //PRIMEIRO DEPARTAMENTO
				
					system("cls");
					printf("------------------------------------------------------------\n");
					printf("			CRIAR DEPARTAMENTO\n");
					printf("------------------------------------------------------------\n");
					printf("Departamento N* %d\n", *contDep+1);
					printf("------------------------------------------------------------\n");
					printf("Codigo: ");
					scanf("%d", &aux.codigo);
					printf("Nome: ");
					fflush(stdin);
					gets(aux.nome);
					
					int resp2; //CONFIRMACAO DO CADASTRO
					do{
						resp2 = -1;
						system("cls");
						printf("------------------------------------------------------------\n");
						printf("			CRIAR DEPARTAMENTO\n");
						printf("------------------------------------------------------------\n");
						printf("Departamento N* %d\n", *contDep+1);
						printf("Codigo: %d\n", aux.codigo);
						printf("Nome: %s\n", aux.nome);
						printf("------------------------------------------------------------\n");
						printf("Confirmar cadastro? (1-SIM ou 2-NAO): ");
						fflush(stdin);
						scanf("%d", &resp2);
						
						if(resp2!=1 && resp2!=2){
							printf("\nERRO: opcao invalida!\n\n");
							system("pause");
							system("cls");
						}	
					}while(resp2!=1 && resp2!=2);
					
					if(resp2==1){
						dep[*contDep] = aux;
						*contDep = *contDep+1;
						printf("\nCadastro realizado com sucesso!\n\n");
						system("pause");
					}
					if(resp2==2){
						printf("\nCadastro cancelado!\n\n");	
						system("pause");
					}	
							
				}else{ //DEMAIS DEPARTAMENTOS
					
					system("cls");
					printf("------------------------------------------------------------\n");	
					printf("			CRIAR DEPARTAMENTO\n");
					printf("------------------------------------------------------------\n");
					printf("Departamento N* %d\n", *contDep+1);
					printf("------------------------------------------------------------\n");
					printf("Codigo: ");
					fflush(stdin);
					scanf("%d", &aux.codigo);
					
					int i;
					int flag = 0;
					for(i=0; i<*contDep; i++){
						if(aux.codigo==dep[i].codigo){
							flag = 1;
							break;
						}
					}
					
					if(flag==1){
						printf("\nERRO: codigo invalido ou o departamento ja existe!\n\n");
						system("pause");
					}
				
					if(flag==0){
						
						printf("Nome: ");
						fflush(stdin);
						gets(aux.nome);		
						
						int resp2;
			   			do{ // CONFIRMAÇÃO DO CADASTRO
							resp2 = -1;
							system("cls");
							printf("------------------------------------------------------------\n");	
							printf("			CRIAR DEPARTAMENTO\n");
							printf("------------------------------------------------------------\n");
		   	   	   	   		printf("Departamento N* %d\n", *contDep+1);
					  		printf("Codigo: %d\n", aux.codigo);
			   	   	   		printf("Nome: %s\n", aux.nome);
			   	   	   		printf("------------------------------------------------------------\n");
			   	   	   		printf("Confirmar cadastro? (1-SIM ou 2-NAO): ");
			   	   	   		fflush(stdin);
			   	   	   		scanf("%d", &resp2);
			
							if(resp2!=1 && resp2!=2){
								printf("ERRO: opcao invalida!\n\n");
				   	   			system("pause");
				   	   			system("cls");
					  		}
					  	
						}while(resp2!=1 && resp2!=2);
					
						if(resp2==1){
							dep[*contDep] = aux;
							*contDep = *contDep+1;
							printf("\nCadastro realizado com sucesso!\n\n");
							system("pause");
						}
				  		if(resp2==2){
				  			printf("\nCancelado!\n\n");	
				  			system("pause");
					   	}
					}				
				}
			}
			if(*contDep==D){
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("			CRIAR DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n\n");
				printf("Nossos sistemas informam que ja foram criados %d de %d departamentos\n", *contDep, D);
				printf("portanto, nao ha mais vagas para a criacao de novos departamenos!\n\n");
				printf("------------------------------------------------------------\n");	
				system("pause");
				resp = 0;
			}
		}while(resp!=0);
	}	
}
/*
OBJETIVO:	Possibilitar a alteração do nome de um departamento;
PARAMETROS:	Recebe o vetor de sruct "dep[D]" com todos os seus dados, possibilitando a pesquisa de um derpartamento pelo seu código e
			a alteração do nome do mesmo;
RETORNO:	Não;
*/
void altera_nome_dep(tDepartamento dep[D], int *contDep){
	
	if(*contDep==0){
		printf("------------------------------------------------------------\n");	
		printf("	     ALTERAR NOME DE UM DEPARTAMENTO\n");
		printf("------------------------------------------------------------\n\n");
		printf("ERRO: nao existem departamentos cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");
	}else{
		
		int resp;
		do{
			do{
				resp = -1;
				system("cls");
				printf("------------------------------------------------------------\n");	
				printf("	     ALTERAR NOME DE UM DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Buscar por codigo\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
				
				if(resp!=1 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
					system("cls");
				}
				
			}while(resp!=1 && resp!=0);
				
			int i;
			int flag = 0;
			int posicao; 
			if(resp==1){
				
				tDepartamento aux;
				aux.codigo = -1; 
				system("cls");
				printf("------------------------------------------------------------\n");	
				printf("	     ALTERAR NOME DE UM DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");
				printf("Buscar por codigo\n");
				printf("Digite: ");
				fflush(stdin);
			   	scanf("%d", &aux.codigo);
			   	
				for(i=0; i<*contDep; i++){
					if(aux.codigo==dep[i].codigo){
						posicao = i;
						flag = 1;
						break;
					}
				}
				
				if(flag==0){
					printf("\nDepartamento nao encontrado!\n");
					printf("------------------------------------------------------------\n");	
				
				}else{
					printf("\nEncontrado!\n");
					printf("------------------------------------------------------------\n");
					system("pause");
					system("cls");
					
				   	printf("------------------------------------------------------------\n");
					printf("	     ALTERAR NOME DE UM DEPARTAMENTO\n");
					printf("------------------------------------------------------------\n");
					printf("Departamento N* %d\n", posicao+1);
					printf("Codigo: %d\n", dep[posicao].codigo);
					printf("Nome: %s\n", dep[posicao].nome);
					printf("------------------------------------------------------------\n");
					printf("Digite um novo nome: ");
					fflush(stdin);
					gets(aux.nome);
					
					int resp2;
					do{
						resp2 = -1;
						system("cls");
						printf("------------------------------------------------------------\n");	
						printf("	     ALTERAR NOME DE UM DEPARTAMENTO\n");
						printf("------------------------------------------------------------\n");
						printf("Departamento N* %d\n", posicao+1);
						printf("Codig %d\n", aux.codigo);
						printf("Nome: %s\n", aux.nome);
						printf("------------------------------------------------------------\n");
						printf("Confirmar alteracao? (1-SIM ou 2-NAO): ");
						fflush(stdin);
						scanf("%d", &resp2);
						
						if(resp2!=1 && resp2!=2){
							printf("\nERRO: opcao invalida!\n\n");
							system("pause");
						}
						
					}while(resp2!=1 && resp2!=2);
					
					if(resp2==1){
						printf("\nAlteracao realizada com sucesso!\n\n");
						dep[posicao] = aux;
					}else{
						printf("\nCancelado!\n\n");
					}	
				}
				system("pause");
			}
					
		}while(resp!=0);
	}
}
/*
OBJETIVO:	Exibir na tela as informações de um determinado departamento;
PARAMETROS: Recebebe o vetor de struct "dep[D]" com as informações de todos os departamentos, possibilitando a pesquisa de um deles; 
			Recebebe o vetor de struct "func[F]" para que possam ser verificados quantos e quais são os funcionarios lotados em cada
			departamento;
			E recebe por ponteiros as veriáveis de controle "contFunc" e "contDep";
RETORNO:	Não;
*/
void consultar_dep(tDepartamento dep[D], tFuncionario func[F], int *contDep, int *contFunc){
	
	if(*contDep==0){
		printf("------------------------------------------------------------\n");
		printf("		CONSULTAR DEPARTAMENTO\n");
		printf("------------------------------------------------------------\n\n");
		printf("ERRO: nao existem departamentos cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");
		
	}else{
		int resp;
		do{
			do{
				system("cls");
				resp = -1;
				printf("------------------------------------------------------------\n");
				printf("		CONSULTAR DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Buscar por codigo\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
				
				if(resp!=1 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
				}	
			}while(resp!=1 && resp!=0);
			
			int codigoAux;
			int posicao;
			int flag = 0;
			int quant = 0;
			int i;
			if(resp==1){
				
				system("cls");
				codigoAux = dep[*contDep+1].codigo;
				printf("------------------------------------------------------------\n");	
				printf("		CONSULTAR DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");	
				printf("Busca por codigo\n");
				printf("Digite: ");
				scanf("%d", &codigoAux);
				
				for(i=0; i<*contDep; i++){
					if(codigoAux==dep[i].codigo){
						flag = 1;
						posicao = i;
					}
				}
				
				if(flag==0){
					printf("\nDepartamento nao encontrado!\n");
					printf("------------------------------------------------------------\n");
					system("pause");
					
				}else{
					printf("\nEncontrado!\n");
					printf("------------------------------------------------------------\n");	
					system("pause");
					
					/*int quantFun = 0;
					for(i=0; i<*contFunc; i++){
						if(func[i].dep==posicao){
							quantFun++;
						}
					}*/
					for(i=0; i<*contFunc; i++){
						if(func[i].dep==codigoAux){
							quant++;
						}
					}
					
					system("cls");
					printf("------------------------------------------------------------\n");	
					printf("		CONSULTAR DEPARTAMENTO\n");
					printf("------------------------------------------------------------\n");
					printf("Departamento N* %d\n", posicao+1);
					printf("Nome: %s\n", dep[posicao].nome);
					printf("Codigo: %d\n", dep[posicao].codigo);
					printf("Quantidade de funcionarios: %d\n", quant);
					printf("------------------------------------------------------------\n");
					system("pause");
				}
			}
		}while(resp!=0);
	}
}
/*
OBJETIVO:	Listar todos os departamentod cadastradose suas respectivas informações;
PARAMETROS:	Recebe o vetor de struct "dep[D]" para que sejam extraídas e exibidas na tela as informações de todos os departamentos;
			Recebe o vetor de struct "func[F]" para que posssam ser exibidos todos os funcionarios, cada um em seu departamento, na
			lista detalhada;
			Recebe por ponteiro as variiáveis de controle "contDep" e "contFunc";
RETORNO:	Não;
*/
void listar_dep(tDepartamento dep[D], tFuncionario func[F], int *contDep, int *contFunc){

	if(*contDep==0){
		printf("------------------------------------------------------------\n");	
	   	printf("		LISTAR DEPARTAMENTOS\n");
	   	printf("------------------------------------------------------------\n\n");	
	   	printf("ERRO: nao existem departamentos cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
	   	system("pause");
	   	
	}else{
		int resp;
		do{
			do{
				system("cls");
				resp = -1;
				printf("------------------------------------------------------------\n");
				printf("		LISTAR DEPARTAMENTOS\n");
				printf("------------------------------------------------------------\n");
				printf("1. Listar por quantidade de funcionarios\n");
				printf("2. Lista detalhada\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
				
				if(resp!=1 && resp!=2 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
					system("cls");
				}
			}while(resp!=1 && resp!=2 && resp!=0);
			
			if(resp==1){
				
				int i, j;
				int quant;
				int cont = 0;
				system("cls");
				printf("------------------------------------------------------------\n");	
				printf("		LISTAR DEPARTAMENTOS\n");
				printf("------------------------------------------------------------\n");
				for(i=0; i<*contDep; i++){
					quant = 0;
					for(j=0; j<*contFunc; j++){
						if(func[j].dep==dep[i].codigo)
							quant++;
					}
					printf("%d. %s..........%d funcionarios\n", cont+1, dep[i].nome, quant);
					printf("------------------------------------------------------------\n");
					cont++;
				}
				system("pause");
			}
			if(resp==2){
				int i, j, cont;
				system("cls");
				printf("------------------------------------------------------------\n");	
				printf("		LISTAR DEPARTAMENTOS\n");
				printf("------------------------------------------------------------\n");	
				for(i=0; i<*contDep; i++){
					cont = 0;
					if(i>0){
						printf("------------------------------------------------------------\n");
					}
					printf("	[%d] %s\n", dep[i].codigo, dep[i].nome);
					printf("------------------------------------------------------------\n");
					for(j=0; j<*contFunc; j++){	
						if(func[j].dep==dep[i].codigo){
							printf("%d - %s\n", cont+1, func[j].nome);
							cont++;
						}
					}
					printf("\n			*  *  *			\n\n");
				}
				system("pause");
			}
		}while(resp!=0);
	}
}
/*
OBJETIVO:	Remover um depatamento do vetor "dep[D]";
PARAMETROS:	Recebe o vetor de struct dep[D] que possibilita a pesquisa por código de um departamento e exclusão do mesmo;
			Recebe o vetor de struct func[F] a título de verificação da existencia de algum funcionario lotado no departamento
			buscado, caso exista, não permite a exclusão do mesmo;
			E recebe por ponteiro as varoáveis de controle "contFunc" e "contDep";
RETORNO:	Não;
*/
void excluir_dep(tDepartamento dep[D], tFuncionario func[F], int *contDep, int *contFunc){

	if(*contDep==0){
		printf("------------------------------------------------------------\n");	
		printf("		 EXCLUIR DEPARTAMENTO\n");
		printf("------------------------------------------------------------\n\n");
		printf("ERRO: nao existem departamentos cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");	
			
	}else{
		int resp;
		do{
			do{
				system("cls");
				resp = -1;
				
				printf("------------------------------------------------------------\n");
				printf("		 EXCLUIR DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Buscar por codigo\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
				
				if(resp!=1 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
				}
			}while(resp!=1 && resp!=0);
						
			int codigoAux;
			int posicao;
			int flag = 0;
			int i;
			if(resp==1){
				
				codigoAux = -1;
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		 EXCLUIR DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");
				printf("Busca por codigo\n");
				printf("Digite: ");
				scanf("%d", &codigoAux);
				
				for(i=0; i<*contDep; i++){
					if(codigoAux==dep[i].codigo){
						flag = 1;
						posicao = i;
					}
				}
	
				if(flag==0){
					printf("\nERRO: departamento nao encontrado!\n\n");	
					system("pause");
					system("cls");
				
				}else{
					printf("\nEncontrado!\n");
					printf("------------------------------------------------------------\n");	
					system("pause");
					
					int quant = 0;
					for(i=0; i<*contFunc; i++){ //verifica se ha funcionarios no departamento
						if(func[i].dep==dep[posicao].codigo){
							quant++;
						}
					}
					
					if(quant>0){ //entra se existir algum funcionario lotado no departamento NÃO EXCLUI
						system("cls");
						printf("------------------------------------------------------------\n");
						printf("		 EXCLUIR DEPARTAMENTO\n");
						printf("------------------------------------------------------------\n");
						printf("Codigo: %d\n", dep[posicao].codigo);
						printf("Nome: %s\n", dep[posicao].nome);
						printf("Quantidade de funcionarios: %d\n", quant);
						printf("------------------------------------------------------------\n");
						printf("\nERRO: Ha fucionario(s) lotado(s) no departamento, portanto nao\neh possivel excluir!\n\n");
						system("pause");
						
					}else{ //entra se nao existirem funcionarios lotados no departamento EXCLUSÃO POSSÍVEL
						int resp2;
						do{
							system("cls");
							resp2 = -1;
							printf("------------------------------------------------------------\n");
							printf("		 EXCLUIR DEPARTAMENTO\n");
							printf("------------------------------------------------------------\n");
							printf("Codigo: %d\n\n", dep[posicao].codigo);
							printf("Nome: %s\n", dep[posicao].nome);
							printf("Quantidade de funcionarios: %d\n", quant);
							printf("------------------------------------------------------------\n");
							printf("Confirmar exclusao? (1-SIM ou 2-NAO): ");
							fflush(stdin);
							scanf("%d", &resp2);
							
							if(resp2!=1 && resp2!=2){
								printf("\nERRO: opcao invalida!\n\n");
								system("pause");
							}
						}while(resp2!=1 && resp2!=2);
						
						if(resp2==2){
							printf("\nCancelado!\n\n");
							system("pause");
						}else{
							int i;
							*contDep = *contDep-1;
							for(i=0; i<*contDep; i++){
								dep[i] = dep[i+1];
							}
							printf("\nDepartamento excluido com sucesso!\n\n");
							system("pause");
						}
					}
				}
			}
			if(*contDep==0){
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		 EXCLUIR DEPARTAMENTO\n");
				printf("------------------------------------------------------------\n");
				printf("\nVoce excluiu o ultimo departamento!\n\n");
				printf("------------------------------------------------------------\n");
				break;
			}
			
			printf("\n");
		}while(resp!=0);
	}
}

						/*FIM DAS FUNÇÕES DE DEPARTAMENTO*/
//***************************************************************************************************************************************
/*
OBJETIVO:	Cadastrar um funcionario e todos os seus dados em uma posição do vetor de struct func[F]
PARAMETROS:	Recebe o vetor de sruct func[F] com todos os funcionarios e suas respectivas informações. E neste caso, possibilita
   	   	    a inserção de novos funcionarios no vetor;
   	   	    Recebe o vetor de struct dep[D] com todos os departamentos e suas respsctivas informações. Neste caso, ele também é
   	   	    importante para a verificação da existencia ou nao de um determinado departamento, realizado pelo usuário.
RETORNO:	Não;
*/
void cadastrar_funcionario(tFuncionario func[F], tDepartamento dep[D], int *contFunc, int *contDep){
	
	if(*contDep==0 || *contFunc>=F){
		if(*contDep==0){
		   	printf("------------------------------------------------------------\n");
		   	printf("		CADASTRAR FUNCIONARIO\n");
			printf("------------------------------------------------------------\n");
		   	printf("\nERRO: nao existem depatamentos cadastrados!\n\n");
		   	printf("------------------------------------------------------------\n");
		   	system("pause");
		}
		if(*contFunc==F){
			printf("------------------------------------------------------------\n");
		   	printf("		CADASTRAR FUNCIONARIO\n");
			printf("------------------------------------------------------------\n");
		   	printf("\nERRO: existem %d de %d funcionarios empregados nesta empresa.\nNao eh permitido exceder o limite!\n\n", *contFunc, F);
		   	printf("------------------------------------------------------------\n");
		   	system("pause");
		}
		
	}else{
		int resp;
		int resp2;
		
		do{
			if(*contFunc == F){ //verifica todas as vezes se o vetor func[F] já está cheio;
				system("cls");
				printf("------------------------------------------------------------\n");
		   	   	printf("		CADASTRAR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n\n");
				printf("Nossos sistemas informam que ja foram cadastrados %d de %d\nfuncionarios, ", *contFunc, F);
		   	   	printf("por isso, nao ha mais vagas para novos contratos!\n\n");
		   	   	printf("------------------------------------------------------------\n");
		   	   	system("pause");
		   	   	break;
			}
				
			do{
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		CADASTRAR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Novo funcionario\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha a opcao do menu: ");
				fflush(stdin);
				scanf("%d",&resp);
				
				if(resp!=1 && resp!=0){
					printf("\nERRO: resposta invalida!\n\n");
					system("pause");
				}
			}while(resp!=1 && resp!=0);
			
			if(resp==1){
				tFuncionario aux;
				//Nome
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		CADASTRAR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("Funcionario %d\n\n", *contFunc+1);
				printf("------------------------------------------------------------\n");
				printf("Nome: ");
				fflush(stdin);
				gets(aux.nome);
			//******************************************************************************
				//CPF
				int flag;
				do{
					system("cls");
					printf("------------------------------------------------------------\n");
					printf("		CADASTRAR FUNCIONARIO\n");
					printf("------------------------------------------------------------\n");
					printf("Funcionario %d\n\n", *contFunc+1);
					printf("Nome: %s\n", aux.nome);
					printf("------------------------------------------------------------\n");
							
					printf("CPF: ");
					scanf("%s", aux.cpf); 
					fflush(stdin);
					
					int i; 
					flag = 0; 
					for(i=0; i<*contFunc; i++){ //VERIFICA SE CPF JA EXISTE
						if(strcmp(aux.cpf, func[i].cpf)==0){
							flag = 1;
							break;
						}
					}
					
					if(flag == 1){ //FUNCIONARIO JA EXISTENTE
						printf("\nERRO: CPF ja cadastrado!\n\n");
						system("pause");
					}
					
				}while(flag!=0);//se for igual, pede de novo;
			//*******************************************************************************
				// Nascimento
				do{
					aux.nasc.dia = 0;
					aux.nasc.mes = 0;
					aux.nasc.ano = 0;
					flag = 0;
					system("cls");
					printf("------------------------------------------------------------\n");
					printf("		CADASTRAR FUNCIONARIO\n");
					printf("------------------------------------------------------------\n");
					printf("Funcionario %d\n\n", *contFunc+1);
					printf("Nome: %s\n", aux.nome);
					printf("CPF: %s\n", aux.cpf);
					printf("------------------------------------------------------------\n");
					printf("ATENCAO: separar dia, mes e ano por espaco!\n");
					printf("Nascimento: ");
					fflush(stdin);
					scanf("%d%d%d", &aux.nasc.dia, &aux.nasc.mes, &aux.nasc.ano);
					
					flag =  verifica_data(aux.nasc.dia, aux.nasc.mes, aux.nasc.ano);
					
					if(flag==0){
						printf("\nERRO: a data nao existe ou possui formato invalido!\nOBS: atentar aos anos bissextos :)\n\n");
						system("pause");
					}
					
				}while(flag==0);
			//******************************************************************************
				//Admissao
				do{
					aux.adm.dia = 0;
					aux.adm.mes = 0;
					aux.adm.ano = 0;
					flag = 0;
					system("cls");
					printf("------------------------------------------------------------\n");
					printf("		CADASTRAR FUNCIONARIO\n");
					printf("------------------------------------------------------------\n");
					printf("Funcionario %d\n\n", *contFunc+1);
					printf("Nome: %s\n", aux.nome);
					printf("CPF: %s\n", aux.cpf);
					printf("Nascimento: %d/%d/%d\n", aux.nasc.dia, aux.nasc.mes, aux.nasc.ano);
					printf("------------------------------------------------------------\n");
					printf("ATENCAO: separar dia, mes e ano por espaco!\n");
					printf("Adimissao: ");
					fflush(stdin);
					scanf("%d%d%d", &aux.adm.dia, &aux.adm.mes, &aux.adm.ano);
					
					flag =  verifica_data(aux.adm.dia, aux.adm.mes, aux.adm.ano);
					
					if(flag==0){
						printf("\nERRO: a data nao existe ou possui formato invalido!\nOBS: atentar aos anos bissextos :)\n\n");
						system("pause");
					}
					
				}while(flag==0);
			//******************************************************************************
				//Departamento
				do{
					flag = 0;
					system("cls");
					printf("------------------------------------------------------------\n");
					printf("		CADASTRAR FUNCIONARIO\n");
					printf("------------------------------------------------------------\n");
					printf("Funcionario %d\n\n", *contFunc+1);
					printf("Nome: %s\n", aux.nome);
					printf("CPF: %s\n", aux.cpf);
					printf("Nascimento: %d/%d/%d\n", aux.nasc.dia, aux.nasc.mes, aux.nasc.ano);
					printf("Admissao: %d/%d/%d\n", aux.adm.dia, aux.adm.mes, aux.adm.ano);
					printf("------------------------------------------------------------\n");
					printf("Departamento (codigo): ");
					fflush(stdin);
					scanf("%d", &aux.dep);
					
					int i;
					for(i=0; i<*contDep; i++){
						if(aux.dep==dep[i].codigo){
							flag = 1;
							break;
						}
					}
					
					if(flag==0){
						printf("\nERRO: departamento inexistente!\n\n");
						system("pause");
					}
					
				}while(flag==0);
			//******************************************************************************
				//Cargo
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		CADASTRAR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("Funcionario %d\n\n", *contFunc+1);
				printf("Nome: %s\n", aux.nome);
				printf("CPF: %s\n", aux.cpf);
				printf("Nascimento: %d/%d/%d\n", aux.nasc.dia, aux.nasc.mes, aux.nasc.ano);
				printf("Admissao: %d/%d/%d\n", aux.adm.dia, aux.adm.mes, aux.adm.ano);
				printf("Departamento (codigo): %d\n", aux.dep);
				printf("------------------------------------------------------------\n");
				printf("Cargo: ");
				scanf("%d", &aux.cargo);
			//******************************************************************************
				do{
					resp2 = -1;
					system("cls");
					printf("------------------------------------------------------------\n");
					printf("		CADASTRAR FUNCIONARIO\n");
					printf("------------------------------------------------------------\n");
					printf("Funcionario %d\n\n", *contFunc+1);
					printf("Nome: %s\n", aux.nome);
					printf("CPF: %s\n", aux.cpf);
					printf("Nascimento: %d/%d/%d\n", aux.nasc.dia, aux.nasc.mes, aux.nasc.ano);
					printf("Admissao: %d/%d/%d\n", aux.adm.dia, aux.adm.mes, aux.adm.ano);
					printf("Departamento (codigo): %d\n", aux.dep);
					printf("Cargo: %d\n", aux.cargo);
					printf("------------------------------------------------------------\n");
					printf("Confirmar cadastro? (1-SIM ou 2-NAO): ");
					fflush(stdin);
					scanf("%d", &resp2);
						
					if(resp2!=1 && resp2!=2){
						printf("\nERRO: opcao invalida!\n\n");
						system("pause");
						system("cls");
					}	
				}while(resp2!=1 && resp2!=2);
					
					if(resp2==1){
						printf("\nCadastro realizado com sucesso!\n\n");
						func[*contFunc] = aux;
						*contFunc = *contFunc+1;
						system("pause");
					}
					if(resp2==2){
						printf("\nCadastro cancelado!\n\n");
						system("pause");	
					}				
			}
		}while(resp!=0);
	}
}
/*
OBJETIVO:	possibilitar a alteração dos dados de um funcionario, com excessão do seu departamento;
PARÂMETROS:	Recebe o vetor de struct "func" com as informações de todos os funcionarios possiblitando a pesquisa por CPF e a alteração
			dos dados dos elementos do vetor;
			Recebe por ponteiro a variavel de controle do tipo int "contFun";
RETORNO:	Não;
*/
void alterar_dados_funcionario(tFuncionario func[F], int *contFunc){
	
	if(*contFunc==0){
		system("cls");
		printf("------------------------------------------------------------\n");
	   	printf("		ALTERAR DADOS DE UM FUNCIONARIO\n");
		printf("------------------------------------------------------------\n");
		printf("\nERRO: nao existem funcionarios cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");
	}else{
	
		int resp, resp2, resp3;
		tFuncionario aux;
		do{
			do{
				resp = -1;
				system("cls");
			   	printf("------------------------------------------------------------\n");
			   	printf("		ALTERAR DADOS DE UM FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Buscar por CPF\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				scanf("%d", &resp);
				
				if(resp!=1 && resp !=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
				}
				
			}while(resp!=1 && resp!=0);
			
			if(resp==1){	
				system("cls");
				printf("------------------------------------------------------------\n");
			  	printf("		ALTERAR DADOS DE UM FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("Digite: ");
				fflush(stdin);
				gets(aux.cpf);
				
				int flag = 0;
				int i, pos;
				for(i=0; i<*contFunc; i++){
					if(strcmp(aux.cpf, func[i].cpf)==0){
						flag = 1;
						pos = i;
						break;
					}
				}
				
				switch(flag){
					case 1:
						printf("\nEncontrado!\n\n");
						system("pause");
						break;
	                case 0:
	                   	printf("\nFuncionario nao encontrado!\n\n");
	                  	system("pause");
	                  	break;
				}
				
				if(flag==1){
					aux = func[pos];
					int verif = 0;
					do{
						do{
							resp2 = -1;
							system("cls");
						   	printf("------------------------------------------------------------\n");
					  	   	printf("		ALTERAR DADOS DE UM FUNCIONARIO\n");
							printf("------------------------------------------------------------\n");
							printf("Funcionario %d\n", pos+1);
							printf("1. Nome: %s\n", aux.nome);
							printf("2. CPF: %s\n", aux.cpf);
							printf("3. Nascimento: %d/%d/%d\n", aux.nasc.dia, aux.nasc.mes, aux.nasc.ano);
							printf("4. Admissao: %d/%d/%d\n", aux.adm.dia, aux.adm.mes, aux.adm.ano);
							printf("5. Cargo: %d\n", aux.cargo );
							printf("0. Voltar\n");
							printf("------------------------------------------------------------\n");
							printf("Escolha uma opcao do menu: ");
							fflush(stdin);
							scanf("%d", &resp2);
							
							if(resp2!=1 && resp2!=2 && resp2!=3 && resp2!=4 && resp2!= 5 && resp2!=0){
								printf("\nERRO: opcao invalida!\n\n");
								system("pause");
							}
						}while(resp2!=1 && resp2!=2 && resp2!=3 && resp2!=4 && resp2!= 5 && resp2!=0);

						switch(resp2){
							case 1:
								printf("Digite um novo nome: ");
								fflush(stdin);
								gets(aux.nome);
								verif++;
								break;
							case 2:
								printf("Digite um novo CPF: ");
								fflush(stdin);
								fgets(aux.cpf, 12, stdin);
								verif++;
								break;
							case 3:
								printf("Digite uma nova data de nascimento\n(Dia, mes e ano separados por espaco): ");
								scanf("%d%d%d", &aux.nasc.dia, &aux.nasc.mes, &aux.nasc.ano);
								verif++;
								break;
							case 4:
								printf("Digite uma nova data de admissao\n(Dia, mes e ano separados por espaco): ");
								scanf("%d%d%d", &aux.adm.dia, &aux.adm.mes, &aux.adm.ano);
								verif++;
								break;
							case 5: 
								printf("Digite um novo cargo: ");
								scanf("%d", &aux.cargo);
								verif++;
								break;
							case 0:
								if(verif>0){
									printf("Confirmar alteracoes? 1 <SIM> 2 <NAO>: ");
									scanf("%d", &resp3);
									
									if(resp3!=1 && resp3!=2){
										printf("\nERRO: opcao invalida\n\n");
										system("pause");
										resp2 = -1;
									}
									if(resp3==2){
										printf("\nCancelado!\n\n");
										system("pause");
									}
									if(resp3==1){
										func[pos] = aux;
										printf("\nAlteracoes realizadas com sucesso!\n\n");
										system("pause");
									}
								}
						}	
					}while(resp2!=0);
				}
			}
		}while(resp!=0);
	}		
}
/*
OBJETIVO:	Transferir um funcionario de departamento
PARAMETROS: Recebe os vetores de struct "func[F]" e "dep[D]" com todos os departamentos e funcionarios existentes e suas respsctivas informações;
			Recebe por ponteiros as variáveis de controle do tipo inteiras;
RETORNO: 	Não;
*/
void transferir_funcionario(tFuncionario func[F], tDepartamento dep[D], int *contFunc, int *contDep){
	if(*contFunc==0){
		system("cls");
		printf("------------------------------------------------------------\n");
	   	printf("		TRANSFERIR FUNCIONARIO\n");
		printf("------------------------------------------------------------\n");
		printf("\nERRO: nao existem funcionarios cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");
	}else{
		int resp, resp2;
		do{
			do{
				system("cls");
				resp = -1;
		   	   	printf("------------------------------------------------------------\n");
	           	printf("		TRANSFERIR FUNCIONAIRIO\n");
			  	printf("------------------------------------------------------------\n");
		   	   	printf("1. Buscar por CPF\n");
		   	  	printf("0. Voltar\n");
		   	   	printf("------------------------------------------------------------\n");
		   	   	printf("Escolha uma opcao do menu: ");
		   	   	fflush(stdin);
		   	   	scanf("%d", &resp);	
		   	   	
		   	   	if(resp!=1 && resp!=0){
					printf("ERRO: opcao invalida!\n");
					system("pause");	  
			    } 
			    
			}while(resp!=1 && resp!=0);
			
			if(resp==1){
				tFuncionario aux;
				system("cls");
				printf("------------------------------------------------------------\n");
	           	printf("		TRANSFERIR FUNCIONAIRIO\n");
			  	printf("------------------------------------------------------------\n");
				printf("Buscar por CPF\n");
				printf("Digite: ");
			  	fflush(stdin);
			  	gets(aux.cpf);
			  	
			  	int i, posFunc;
			  	int flag = 0;
			  	for(i=0; i<*contFunc; i++){
					if(strcmp(aux.cpf, func[i].cpf)==0){
						flag = 1;
						posFunc = i;
						break;
					}  
			    }
			    
			    switch(flag){
					case 0:
						printf("\nNao encontrado!\n\n");
						system("pause");
						break;
					case 1:
						printf("\nEncontrado!\n\n");
						system("pause");
						break;
				}
				
				if(flag==1){
					aux = func[posFunc];
					system("cls");
					printf("------------------------------------------------------------\n");
	           	   	printf("		TRANSFERIR FUNCIONAIRIO\n");
			  		printf("------------------------------------------------------------\n");
			  		printf("Funcionario %d\n", posFunc+1);
			  		printf("Nome: %s\n", aux.nome);
			  		int posDept;
			  		for(i=0; i<*contDep; i++){
						if(func[posFunc].dep==dep[i].codigo){
							posDept = i;
							break;
						}  
					}
					printf("Departamento: [%d] %s\n", aux.dep, dep[posDept].nome);
					printf("------------------------------------------------------------\n");
					printf("Digite o codigo do novo departamento: ");
					scanf("%d", &aux.dep);
					
					flag = 0;
					int posDep;
					for(i=0; i<*contDep; i++){
						if(aux.dep==dep[i].codigo){
							flag = 1;
							posDep = i;
							break;
						}
					}
					
					if(flag==0){
						printf("\nERRO: o departamento informado nao existe!\n\n");
						system("pause");
						
					}
					if(flag==1){
						do{
							resp2 = -1;
							system("cls");
							printf("------------------------------------------------------------\n");
			           	   	printf("		TRANSFERIR FUNCIONAIRIO\n");
					  		printf("------------------------------------------------------------\n");
					  		printf("Funcionario %d\n", posFunc+1);
					  		printf("Nome: %s\n", aux.nome);
							printf("Departamento: [%d] %s\n", aux.dep, dep[posDep].nome);
							printf("------------------------------------------------------------\n");
							printf("Deseja salvar alteracoes? 1 <SIM> 2 <NAO>: ");
							fflush(stdin);
							scanf("%d", &resp2);
							
							if(resp2!=1 && resp2!=2){
								printf("\nERRO: opcao invalida!\n\n");
								system("pause");
							}
						}while(resp2!= 1 && resp2!=2);
						
						if(resp2==1){
							func[posFunc].dep = aux.dep;
							printf("\nAltecao realizada com sucesso!\n\n");
							system("pause");
						}
						if(resp2==2){
							printf("\nCancelado!\n\n");
							system("pause");
						}
					}
					
				}
			}
			
		}while(resp!=0);
		
	}
}
/*
OBJETIVO:	Excluir um funcionario do vetor de struct "func[F]";
PARAMETROS: Recebe o vetor de struct "func" com as informações de todos os funcionarios possiblitando a pesquisa por CPF;
			Recebe por ponteiro a variavel de controle do tipo int "contFun";
RETORNO:	Não;
*/
void demitir_funcionario(tFuncionario func[F], int *contFunc){
	
	if(*contFunc==0){
		system("cls");
		printf("------------------------------------------------------------\n");
	   	printf("		DEMITIR FUNCIONARIO\n");
		printf("------------------------------------------------------------\n");
		printf("\nERRO: nao existem funcionarios cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");
	}else{
		
		tFuncionario aux;
		int resp;
		do{
			do{
				resp = -1;
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		DEMITIR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Buscar por CPF\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
		
				if(resp!=1 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
				}
				
			}while(resp!=0 && resp!=1);
			
			if(resp==1){
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		DEMITIR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("Buscar por CPF\n");
				printf("Digite: ");
				fflush(stdin);
				gets(aux.cpf);
				
				int i;
				int flag = 0, pos;
				
				for(i=0; i<*contFunc; i++){
					if(strcmp(aux.cpf,func[i].cpf)==0){
						flag = 1;
						pos = i;
						break;
					}
				}
				
				if(flag==0){
					printf("\nFuncionario nao encontrado!\n\n");
					system("pause");
					
				}else{
					printf("\nEncontrado!\n\n");
					system("pause");
					int resp2;
					do{
						system("cls");
						resp2 = -1;
						printf("------------------------------------------------------------\n");
						printf("		DEMITIR FUNCIONARIO\n");
						printf("------------------------------------------------------------\n");	
						printf("Nome: %s\n", func[pos].nome);
						printf("CPF: %s\n", func[pos].cpf);
						printf("Departamento: %d\n", func[pos].dep);
						printf("Cargo: %d\n", func[pos].cargo);
						printf("------------------------------------------------------------\n");
						printf("Confirmar demissao? (1-SIM ou 2-NAO): ");
						fflush(stdin);
						scanf("%d", &resp2);
								
						if(resp2!=1 && resp2!=2){
							printf("\nERRO: opcao invalida!\n\n");
							system("pause");
						}
					}while(resp2!=1 && resp2!=2);
							
					if(resp2==2){
						printf("\nCancelado!\n\n");
						system("pause");
					}else{
						int i;
						*contFunc = *contFunc-1;
						for(i=0; i<*contFunc; i++){
							func[i] = func[i+1];
						}
						printf("\nFuncionario demitido com sucesso!\n\n");
						system("pause");
					}
				
				}
				
		
				
			}
		}while(resp!=0);
	}

}
/*
OBJETIVO: 	Solicitar que o usuário pesquise um funcionario pelo CPF, caso o funcionario exista a função exibirá todos os seus dados tela;
PARAMETROS: Recebe o vetor de struct "func" com as informações de todos os funcionarios possiblitando a pesquisa por CPF;
			Recebe o veror de struc "dep" para que seja exibido o nome do departamento correspondente a pesquisa;
			Recebe por ponteiros as variáveis de controle do tipo int "contFunc" e "contDep";
RETORNO: 	Não;
*/
void pesquisar_funcionario(tFuncionario func[F], tDepartamento dep[D], int *contFunc, int *contDep){
	if(*contFunc==0){
		printf("------------------------------------------------------------\n");
		printf("		PESQUISAR FUNCIONARIO\n");
		printf("------------------------------------------------------------\n");
		printf("\nERRO: nao existem funcionarios cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");
	}else{
		
		int resp;
		do{
			do{
				resp = -1;
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		PESQUISAR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("1. Buscar por CPF\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
				
				if(resp!=1 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
				}
				
			}while(resp!=1 && resp!=0);
			
			tFuncionario aux;;
			if(resp==1){
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		PESQUISAR FUNCIONARIO\n");
				printf("------------------------------------------------------------\n");
				printf("Buscar por CPF\n");
				printf("Digite: ");
				fflush(stdin);
				gets(aux.cpf);
				
				int i;
				int flag = 0, pos = 0;
				for(i=0; i<*contFunc; i++){
					if(strcmp(aux.cpf, func[i].cpf)==0){
						flag = 1;
						pos = i;
						break;
					}
				}
				
				if(flag==0){
					printf("\nFuncionario nao encontrado!\n\n");
					system("pause");
					
				}
				if(flag==1){
					printf("\nEncontrado!\n\n");
					system("pause");
					
					system("cls");
					printf("------------------------------------------------------------\n");
					printf("		PESQUISAR FUNCIONARIO\n");
					printf("------------------------------------------------------------\n");
					printf("Funcionario %d\n", pos+1);
					printf("Nome: %s\n", func[pos].nome);
					printf("CPF: %s\n", func[pos].cpf);
					printf("Nascimento: %d/%d/%d\n", func[pos].nasc.dia, func[pos].nasc.mes, func[pos].nasc.ano);
					printf("Admissao: %d/%d/%d\n", func[pos].adm.dia, func[pos].adm.mes, func[pos].adm.ano);
					int cod = func[pos].dep;
					int posDep;
					for(i=0; i<*contDep; i++){
						if(cod==dep[i].codigo){
							posDep = i;
						}
					}
					printf("Departamento: [%d] %s\n", func[pos].dep, dep[posDep].nome);
					printf("Cargo: %d\n", func[pos].cargo);
					printf("------------------------------------------------------------\n");
					system("pause");
					
				}
		
			}
		}while(resp!=0);
	}
}
/*
OBJETIVO:	Exibir na tela todos os funcionarios e suas respectivas informações;
PARAMETROS:	Recebe o vetore de estruct "func[F]", para que possam sem exibidas as informações de todos os funcionarios;
			Recebe o vetor de struct dep[D] para que o nome do departamento possa ser impresso junto ao seu código e todas as informações de um
			funcionário;
			E recebe por ponteiro as variáveis de controle "contFunc" e "contDep"; 
RETORNO:	Não;
*/
void listar_funcionario(tFuncionario func[F], tDepartamento dep[D], int *contFunc, int *contDep){
	
	if(*contFunc==0){
		printf("------------------------------------------------------------\n");
		printf("		LISTAR FUNCIONARIOS\n");
		printf("------------------------------------------------------------\n");
		printf("\nERRO: nao existem funcionarios cadastrados!\n\n");
		printf("------------------------------------------------------------\n");
		system("pause");
	}else{
		
		int resp;
		int i;
		do{
			do{
				resp = -1;
				system("cls");
			   	printf("------------------------------------------------------------\n");
				printf("		LISTAR FUNCIONARIOS\n");
				printf("------------------------------------------------------------\n");
			   	printf("1. Listar por nome\n");
				printf("2. Lista detalhada\n");
				printf("0. Voltar\n");
				printf("------------------------------------------------------------\n");
				printf("Escolha uma opcao do menu: ");
				fflush(stdin);
				scanf("%d", &resp);
				
				if(resp!=1 && resp!=2 && resp!=0){
					printf("\nERRO: opcao invalida!\n\n");
					system("pause");
				}
				
			}while(resp!=1 && resp!=2 && resp!=0);
			
			if(resp==1){
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		LISTAR FUNCIONARIOS\n");
				printf("------------------------------------------------------------\n");
				for(i=0; i<*contFunc; i++){
					printf("%d - %s\n", i+1, func[i].nome);
					printf("------------------------------------------------------------\n");
				}
				system("pause");
			}
			if(resp==2){
				system("cls");
				printf("------------------------------------------------------------\n");
				printf("		LISTAR FUNCIONARIOS\n");
				printf("------------------------------------------------------------\n");
				int j;
				for(i=0; i<*contFunc; i++){
					printf("Funcionario %d\n\n", i+1);
					printf("Nome: %s\n", func[i].nome);
					printf("CPF: %s\n", func[i].cpf);
					printf("Nascimento: %d/%d/%d\n", func[i].nasc.dia, func[i].nasc.mes, func[i].nasc.ano);
					printf("Admissao: %d/%d/%d\n", func[i].adm.dia, func[i].adm.mes, func[i].adm.ano);
					int cod = func[i].dep;
					int posDep;
					for(j=0; j<*contDep; j++){
						if(cod==dep[j].codigo){
							posDep = j;
							break;;
						}
					}
					printf("Departamento: [%d] %s\n", func[i].dep, dep[posDep].nome);
					printf("Cargo: %d\n", func[i].cargo);
					printf("------------------------------------------------------------\n");
				}
				system("pause");
			}
		}while(resp!=0);
	}
}
/*
OBJETIVO:	Verificar se uma data é valida;
PARAMETROS: Recebe "int dia", "int mes" e "int ano" digitados pelo usuario;
RETORNO:	Retorna um valor inteiro: 1 se a data for válida ou 0 se não for;
*/
int verifica_data(int dia, int mes, int ano){
	
	int flag = 0;
	
	if((ano>=1900 && ano<=2100) && (mes>=1 && mes <=12)){
		if((mes==1) && (dia>=1 && dia<=31)){
			flag = 1;
		}
		if(mes==2){
			if(((eh_bissexto(ano)) == 1) && (dia>=1 && dia<=29)){
				flag = 1;
			}
			if(((eh_bissexto(ano)) == 0) && (dia>=1 && dia<=28)){
				flag=1;
			}
		}
		if((mes==3) && (dia>=1 && dia<=31)){
			flag = 1;
		}
		if((mes==4) && (dia>=1 && dia<=30)){
			flag = 1;
		}
		if((mes==5) && (dia>=1 && dia<=31)){
				flag = 1;
		}
		if((mes==6) && (dia>=1 && dia<=30)){
			flag = 1;
		}
		if((mes==7) && (dia>=1 && dia<=31)){
			flag = 1;
		}
		if((mes==8) && (dia>=1 && dia<=31)){
			flag = 1;
		}
		if((mes==9) && (dia>=1 && dia<=30)){
			flag = 1;
		}
		if((mes==10) && (dia>=1 && dia<=31)){
			flag = 1;
		}
		if((mes==11) && (dia>=1 && dia<=30)){
			flag = 1;
		}
	   	if((mes==12) && (dia>=1 && dia<=31)){
			flag = 1;
		}
	}
			
	return flag;
}
/*
OBJETIVO:	Verificar se um ano é bissexto;
PARAMETROS: Recebe um ano digitado pelo usuário, armazenado na variável "int ano";
RETORNO:	Retorna um valor inteiro: 1 se for bissexto ou 0 se nao for;
*/
int eh_bissexto(int ano){
	int resultado = 0;
	
	if((ano % 4) == 0){
		if((ano % 10) == 0){
			if((ano % 400) == 0){
				resultado = 1;
			}
		}else{
			resultado = 1;
		}
	}
	
	return resultado;
}
