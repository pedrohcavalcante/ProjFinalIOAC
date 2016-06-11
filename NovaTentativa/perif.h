#ifndef _PERIF_H_
#define _PERIF_H_

typedef struct{
	int tipo;
	char dispositivo[50];
	int prioridade;
	int justica;
	bool set_used;
}Perif;

typedef struct no{
	Perif info;
	struct no* prox;
}Aux_Perif;

Aux_Perif* criarLista();
void inserirFinal(Aux_Perif** perifericos, Perif barramento);
void imprimirLista(Aux_Perif** lista);
void imprimirLista(Aux_Perif** lista, bool justica);
void selectionsort_AuxPerif(Aux_Perif **vetor, int tamanho);
void ordena_AuxPerif(Aux_Perif **perif);
void analisar_justica(Aux_Perif **perif);
#endif