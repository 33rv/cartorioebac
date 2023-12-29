#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //bibiloteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsalvel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema 
{
	//inicio da crição das variáveis/string 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da crição das variáveis/string 
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação dos usuários
	scanf("%s", cpf); //%s refere-se as string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
		
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
	char cpf[40]; 
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: \n"); 
	scanf("%s", cpf);
	printf("\n\n"); 

	FILE *file; 
	file = fopen(cpf, "r");
    
	if(file == NULL)
	{
		printf("não foi possivel abrir o arquivo, não localizado!.\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as infomações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n"); 
	
	}
	
		system("pause"); 

		
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usuario a ser deletado: "); 
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	{
		printf("o usuario nao se encontra no sistema!.\n");
		system("pause"); 
	}
	
	
}

int main()
{
	int opcao=0; //definindo as variaveis 
	int x=1;
	
	for(x=1;x=1;)
    {
    	
    	system("cls"); // responsalvel por limpar a tela 
    	
       setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
       printf("### cartório da EBAC ###\n\n"); //inicio do menu 
       printf("escolha a opção desejada do menu:\n\n");
       printf("\t1 - registrar nomes\n"); 
       printf("\t2 - consutar os nome\n"); 
       printf("\t3 - deletar os nome\n\n");
	   printf("\t4 - sair do sistema\n\n"); 
       printf("opção: "); //final do menu  	
    
    
       scanf("%d", &opcao); //armagenando a escolha do usuario 
    
       system("cls");
       
       
       switch(opcao) // inicio da seleção de menu
       {
       	  case 1:
       	  registro(); //chmada de funções 
    	  break; 
    	  
    	  case 2:
    	  consulta();
    	  break;
    	  
    	  case 3:
     	  deletar();
    	  break;
    	  
    	  case 4:
    	  printf("obrigado por utilizar o sistema!\n");
    	  return 0;
    	  break;
    	 
    	  default:
    	  printf("essa opcao nao esta disponivel!\n");
		  system ("pause");
    	  break;  
	   } //fim da seeção 
	

    }	
}
