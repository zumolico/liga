#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variaveis globais
int i=0,j=0;
char sair='s';
int numero_equipas, numero_jogadores;

typedef struct data1{
		int dia;
		int mes;
		int ano;
	}DATA;
	
typedef struct jogador1{
	char nome[50];
	int numero;
	char posicao[5];
	DATA data;
	
}JOGADOR;
typedef struct datat1{
		int dia;
		int mes;
		int ano;
	}DATAT;
typedef struct treinador1{
		int numero;
		char nomet[50];
		DATAT datat;
	}TREINADOR;
typedef struct equipa1{
	
	char nome[50];
	char sigla[50];
	int pontos;
	int ano;
	
	TREINADOR treinador;
	JOGADOR jogador[20];
}EQUIPA;

EQUIPA equipa[20];

//funcoes
void inserir();
void inserir_equipa();
void carregar();
void print();
void print_equipa();
void descarregar();


int main()
{
	inserir();
	descarregar();
	carregar();
	print();
	
	
	return 0;
	
}

void carregar(){
	
	FILE *fequipas;
	fequipas = fopen("equipas.txt","a+");
	if(fequipas == NULL){
		printf("Erro ao abrir o ficheiro!");
		exit(1);
	}
	i=0;
	while(fscanf(fequipas,"%s %s %d %d",equipa[i].nome,equipa[i].sigla,&equipa[i].pontos,equipa[i].ano) != EOF)
	{
		i++;
	}
	fclose(fequipas);
	numero_equipas=i;
	
	FILE *fjogadores;
	fjogadores = fopen("jogadores.txt","a+");
	if(fjogadores == NULL){
		printf("Erro ao abrir o ficheiro!");
		exit(1);
	}
	i=0;
	j=0;
	while(i!=numero_equipas)
	{
		int j=0;
		while(j!=20 && equipa[i].jogador[j].numero != EOF){
			fscanf(fjogadores,"%d %s %s %d %d %d",equipa[i].jogador[j].numero,equipa[i].jogador[j].nome,equipa[i].jogador[j].posicao,equipa[i].jogador[j].data.dia,equipa[i].jogador[j].data.mes,equipa[i].jogador[j].data.ano);
			j++;
		}
		i++;
	}
	numero_jogadores=j;
	fclose(fjogadores);
	
	FILE *ftreinador;
	ftreinador = fopen("treinador.txt","a+");
	if(ftreinador == NULL){
		printf("Erro ao abrir o ficheiro!");
		exit(1);
	}
	i=0;
	while(i != numero_equipas);
	{
		fprintf(ftreinador,"%d\t%d %d %d\t%s\n",equipa[i].treinador.numero,&equipa[i].treinador.datat.dia,equipa[i].treinador.datat.mes,equipa[i].treinador.datat.ano,equipa[i].treinador.nomet);
		i++;
	}
	fclose(ftreinador);
	printf("\n%i\t\t%i",numero_equipas,numero_jogadores);
}

void inserir(){
	
	inserir_equipa();
}

void inserir_equipa(){
	
	i=0;
	do{
	printf("Insira o nome da equipa\n");
	scanf("%s",equipa[i].nome);
	printf("Insira a sigla\n");
	scanf(" %s",equipa[i].sigla);
	printf("Insira o ano em que foi fundada\n");
	scanf("%d",&equipa[i].ano);
	printf("Insira os pontos\n");
	scanf("%d",&equipa[i].pontos);
	printf("Deseja continuar a introduzir?\n('n' ou 'N') para sair ('s' ou 'S') para continuar): ");
	scanf(" %c",&sair);
	i++;
	numero_equipas=i;
	}while(sair!='N' && sair!='n');
}

void print(){
	
	print_equipa();
}

void print_equipa(){
	
	for(i=0;i<numero_equipas;i++){
		printf("%s\t\t%s\t\t%d\t\t%d",equipa[i].nome,equipa[i].sigla,equipa[i].ano,equipa[i].pontos);
	}
}

void descarregar(){
	
	FILE *fequipas;
	fequipas = fopen("equipas.txt","w");
	for(i=1;i<=numero_equipas;i++){
	fprintf(fequipas, "%s\t%s\t%d\t%d\n", equipa[i].nome,equipa[i].sigla,equipa[i].ano,equipa[i].pontos);
	}
	fclose(fequipas);
	
	FILE *fjogadores;
	fjogadores = fopen("jogadores.txt","w");
	
	for(i=0;i<=numero_equipas;i++){
		for(j=0;j<=numero_jogadores;j++){
			fprintf(fjogadores,"%d %s %s %d %d %d",equipa[i].jogador[j].numero,equipa[i].jogador[j].nome,equipa[i].jogador[j].posicao,equipa[i].jogador[j].data.dia,equipa[i].jogador[j].data.mes,equipa[i].jogador[j].data.ano);
		}
	}
	fclose(fjogadores);
	
	FILE *ftreinador;
	ftreinador = fopen("treinador.txt","w");
	
	for(i=0;i<=numero_equipas;i++){
		fprintf(ftreinador,"%d\t%d %d %d\t%s\n",equipa[i].treinador.numero,equipa[i].treinador.datat.dia,equipa[i].treinador.datat.mes,equipa[i].treinador.datat.ano,equipa[i].treinador.nomet);
	}
	fclose(ftreinador);
}
