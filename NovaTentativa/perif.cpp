#include <iostream>
#include <stdlib.h>
#include "perif.h"

Aux_Perif* criarLista(){
	return NULL;
}

void inserirFinal(Aux_Perif** perifericos, Perif barramento){
	Aux_Perif* novo = (Aux_Perif*)new Aux_Perif;
	novo->info = barramento;
	Aux_Perif* aux = *perifericos;
	Aux_Perif* anterior = NULL;
	if (*perifericos == NULL){
		*perifericos = novo;
	}else{
		while(aux != NULL){
			anterior = aux;
			aux = aux->prox;
		}
		anterior->prox = novo;
	}

}
void imprimirLista(Aux_Perif** lista){
	Aux_Perif* aux = *lista;
	//while (aux != NULL && aux->info.set_used == true){
    while (aux != NULL){
		std::cout << "DISPOSITIVO: ";
		std::cout << aux->info.dispositivo << std::endl;
		std::cout << "PRIORIDADE: ";
		std::cout << aux->info.prioridade << std::endl;
        std::cout << "Set_Used: ";
        std::cout << aux->info.set_used << std::endl;
		aux = aux->prox;
	}
}
void imprimirLista(Aux_Perif** lista, bool justica){
	Aux_Perif* aux = *lista;
	while (aux != NULL && aux->info.set_used == true){
    //while (aux != NULL){
		std::cout << "DISPOSITIVO: ";
		std::cout << aux->info.dispositivo << std::endl;
		std::cout << "PRIORIDADE: ";
		std::cout << aux->info.prioridade << std::endl;
        std::cout << "Set_Used: ";
        std::cout << aux->info.set_used << std::endl;
        std::cout << "JUSTICA: ";
        std::cout << aux->info.justica << std::endl;
		aux = aux->prox;
	}
}

void selectionsort_AuxPerif(Aux_Perif **vetor, int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[menor]->info.prioridade > vetor[j]->info.prioridade) menor = j;
        }
        if (menor != i) {
            Aux_Perif *temp = vetor[menor];
            vetor[menor] = vetor[i];
            vetor[i] = temp;
        }
    }
}

void ordena_AuxPerif(Aux_Perif **perif) {
    // 1. Se a lista está vazia, então nem faz nada.
    if (perif == NULL) return;

    // 2. Descobre o tamanho da lista.
    int tamanho = 0;
    Aux_Perif *v;
    for (v = *perif; v != NULL; v = v->prox) {
        tamanho++;
    }

    // 3. Monta um vetor com os elementos da lista.
    Aux_Perif **vetor = (Aux_Perif **) malloc(sizeof(Aux_Perif *) * tamanho);
    int i = 0;
    for (v = *perif; v != NULL; i++) {
        vetor[i] = v;
        v = v->prox;
    }

    // 4. Ordena o vetor.
    selectionsort_AuxPerif(vetor, tamanho);

    // 5. Corrige os ponteiros de acordo com a nova ordenação.
    for (i = 0; i < tamanho - 1; i++) {
        vetor[i]->prox = vetor[i + 1];
    }
    vetor[i]->prox = NULL;

    // 6. Corrige o ponteiro para o início da lista.
    *perif = vetor[0];
    //void imprimirLista(*perif);

    // 7. Deleta o vetor auxiliar.
    free(vetor);
}

/*void analisar_justica(Aux_Perif **perif){
    Aux_Perif *aux = *lista;
    Aux_Perif excesso;
    Perif ident;
    ident = criarLista();
    while (aux != NULL){
        if (aux->info.justica > 5){
            strcpy(ident.dispositivo, aux->info.dispositivo);
            ident.tipo = aux->info.tipo;
            ident.prioridade = aux->info.prioridade;
            ident.justica = aux->info.justica - 5;
            ident.set_used = aux->info.set_used;
            inserirFinal(&excesso, ident);
        }else{
        std::cout << "DISPOSITIVO: ";
		std::cout << aux->info.dispositivo << std::endl;
		std::cout << "PRIORIDADE: ";
		std::cout << aux->info.prioridade << std::endl;
        std::cout << "Set_Used: ";
        std::cout << aux->info.set_used << std::endl;
        }
    }
}*/