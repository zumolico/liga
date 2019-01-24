#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100

//variaveis globais
int opcao; 
int i=0;
char sair='n';

//structs
typedef struct equipa
{
	char nome[DIM];
	char sigla[4];
	int ano[8];
	int pontos;

	struct treinador
	{
		int numero;
		char nome[DIM];
		int data[11];	
	};
	JOGADOR jogador1[20];

}EQUIPA;
typedef struct jogador
	{
		char nome[DIM];
		int numero;
		char posicao[4];
		char nacional[DIM];

		struct nascimento
		{
			int dia;
		int mes;
		int ano;
	};
}JOGADOR;

EQUIPA equipa1[20];

equipa11[0].treinador.nome;
equipa[0].jogador[0].numero;
EQUIPA treinador1[1];

//funcoes

void inserir();
void inserir_jogador();
void inserir_treinador();
void inserir_equipa();
void editar();
void apagar();
void listar();
void listar_jogadores();
void listar_equipas();
void listar_treinadores();
void apagar_jogador();

int main()
{
	printf("Escolha uma opcao: \n\n1. Inserir\n2. Editar\n3. Apagar\n4. Listar\n5. Sair---> ");
	scanf("%i", &opcao);
	
	switch(opcao)
	{
		case 1: inserir();break;
		case 2: editar();break;
		case 3: apagar();break;
		case 4: listar();break;
		case 5: exit(1);break;
		default: printf("Opcao Invalida!\a"); 
	}
	return 0;
}
 void inserir()
{
	printf("Escolha uma opcao: \n\n1. Inserir jogador\n2. Inserir treinador\n3. Inserir equipa\n--> ");
	scanf("%i",&opcao);
	switch(opcao)
	{
		case 1: inserir_jogador();break;
		case 2: inserir_treinador();break;
		case 3: inserir_equipa();break;
		case 4: main();break;
		default: printf("Opcao invalida!");
	}
}
void inserir_equipa()
{
	FILE *equipa;
	equipa = fopen("equipa.txt", "a+");
	if(equipa == NULL)
	{
		printf("Erro ao abrir ficheiro\n");
		exit(1);
	}
	do
	{
		printf("Insira o nome da equipa\n");
		scanf("%s", &equipa1[i].nome[i]);
		printf("Insira a sigla\n");
		scanf("%s", equipa1[i].sigla);
		//printf("Insira o ano em que foi fundada\n");
		//scanf("%d/%d/%d",jogador[i].ano)
		printf("Insira os pontos\n");
		scanf("%d", &equipa1[i].pontos);
		printf("Deseja continuar a introduzir ?(S para sair)\n");
		scanf(" %c",&sair);
		fprintf(equipa, "%s\t%s\t%d\n", equipa1[i].nome, equipa1[i].sigla, equipa1[i].pontos);
		i++;
	} while (sair!='S' && sair != 's');
	fclose(equipa);
	main();
}
void inserir_treinador()
{
	FILE *treinador;
	treinador = fopen("treinador.txt", "a+");
	if(treinador == NULL)
	{
		printf("Erro ao abrir ficheiro\n");
		exit(1);
	}
	do
	{
		printf("Insira o nome do treinador\n");
		scanf("%s", treinador1[i].nome);
		//printf("Insira a data de nascimento\n");
		//scanf("%d", treinador[i].data);
		printf("Insira a equipa que treina\n");
		scanf("%s",treinador1[i].equipa);
		printf("Insira o numero de inscrcao\n");
		scanf("%d", &treinador1[i].numero);
		printf("Deseja continuar a introduzir ?(S para sair)\n");
		scanf(" %c", &sair);
		fprintf(treinador, "%s\t%s\t%d\n", treinador1[i].nome, treinador1[i].equipa, treinador1[i].numero);
		i++;
	} while (sair!='S' && sair != 's');
	fclose(treinador);
	main();
}
void inserir_jogador()
{
	FILE *jogador;
	jogador = fopen("jogador.txt", "a+");
	if(jogador == NULL)
	{
		printf("Erro ao abrir ficheiro\n");
		exit(1);
	}
	do
	{
		printf("Insira o nome do jogador\n");
		scanf("%s", jogador1[i].nome);
		//printf("Insira a data de nascimento\n");
		//scanf("%d", jogador[i].data);
		printf("Insira a equipa em joga\n");
		scanf("%s", jogador1[i].equipa);
		printf("Insira o numero de inscrcao\n");
		scanf("%d", &jogador1[i].numero);
		printf("Insira a posicao que joga\n");
		scanf("%s", jogador1[i].posicao);
		printf("Insira a nacionalidade\n");
		scanf("%s", jogador1[i].nacional);
		printf("Deseja continuar a introduzir ?(S para sair)\n");
		scanf(" %c", &sair);
		fprintf(jogador, "%s\t%s\t%d\t%s\t%s\n", jogador1[i].nome, jogador1[i].equipa, jogador1[i].numero, jogador1[i].posicao, jogador1[i].nacional);
		i++;
	} while (sair!='S' && sair != 's');
	fclose(jogador);
	main();
}
void listar()
{
	printf("Escolha uma opcao\n\n1. Listar jogadores\n2. Listar Equipas\n3. Listar Treinadores\n4. Voltar Atras\n---> ");
	scanf("%i", &opcao);
	switch(opcao)
	{
		case 1: listar_jogadores();break;
		case 2: listar_equipas();break;
		case 3: listar_treinadores();break;
		case 4: main();break;
		default: printf("Opcao Invalida!\a");
	}
}
void listar_jogadores()
{
	FILE *jogador; 
	jogador = fopen("jogador.txt", "a+");
	int i=0;
	
	while(fscanf(jogador,"%s %s %i %s %s",jogador1[i].nome,jogador1[i].equipa,&jogador1[i].numero,jogador1[i].posicao,jogador1[i].nacional) != EOF)
	{
		printf("%s %s %i %s %s\n",jogador1[i].nome,jogador1[i].equipa,jogador1[i].numero,jogador1[i].posicao,jogador1[i].nacional);
		i++;
	}
	fclose(jogador);
}
void editar(){}
void apagar()
{
	apagar_jogador();
}
void listar_equipas(){}
void listar_treinadores(){}
void apagar_jogador()
{
	char pesquisa_jogador[50];
	int i=0;
	FILE *jogador;
	jogador = fopen("jogador.txt", "a+");
	
	while(fscanf(jogador,"%s %s %i %s %s",jogador1[i].nome,jogador1[i].equipa,&jogador1[i].numero,jogador1[i].posicao,jogador1[i].nacional) != EOF)
	{
		i++;
	}
	fclose(jogador);

	printf("Que jogador quer apagar: ");
	for (int m = 0; m <= i; m++)
	{
		printf("%s\n",jogador1[m].nome);
	}
	scanf("%s",pesquisa_jogador);
	for (int j = 0; j <= i; j++)
	{
		
		if(strcmp(pesquisa_jogador,jogador1[j].nome)==0)
		{
			for (int k = j; k <= i; k++)
			{
				strcpy(jogador1[k].nome,jogador1[k+1].nome);
			}
		}
		jogador = fopen("jogador.txt","w");
	 	for (int l = 0; l <(i-1); l++)
	 	{
	 		fprintf(jogador, "%s\t%s\t%d\t%s\t%s\n", jogador1[j].nome, jogador1[j].equipa, jogador1[j].numero, jogador1[j].posicao, jogador1[j].nacional);
	 	}
	 	fclose(jogador);
	}	
}





















