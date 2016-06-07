#include <iostream>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int tipo;
	char dispositivo[50];
	int prioridade;
}Perif;

typedef struct no{
	Perif info;
	struct no* prox;
}Aux_Perif;

Aux_Perif* criarLista(){
	return NULL;
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

void imprimirLista(Aux_Perif** lista){
	Aux_Perif* aux = *lista;
	while (aux != NULL){
		std::cout << "DISPOSITIVO: ";
		std::cout << aux->info.dispositivo << std::endl;
		std::cout << "PRIORIDADE: ";
		std::cout << aux->info.prioridade << std::endl;
		aux = aux->prox;
	}
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

int main(){
	int solic;
	int cont = 0;
	int aux = 0, prior = 0;
	Aux_Perif* perifericos;
	perifericos = criarLista();
	std::cout << "Entre com o número de solicitações: " << std::endl;
	std::cin >> solic;
	std::cout << "Periféricos:\n1. Impressora\n2. Mouse\n3. Teclado\n4. Scanner\n5. Roteador\n6. Disco Rígido" << std::endl;
	std::cout << "De acordo com os números e Periféricos acima, insira os periféricos que solicitaram execução (bus-request) e sua prioridade" << std::endl;
	while (cont < solic){
		Perif ordem;
		std::cin >> aux >> prior;
		switch (aux){
			case 1:
				//ordem.dispositivo = 'Impressora';
				strcpy(ordem.dispositivo, "Impressora");
				break;
			case 2: 
				strcpy(ordem.dispositivo , "Mouse") ;
				break;
			case 3: 
				strcpy(ordem.dispositivo , "Teclado");
				break;
			case 4:
				strcpy(ordem.dispositivo , "Scanner");
				break;
			case 5:
				strcpy(ordem.dispositivo , "Roteador");
				break;
			case 6: 
				strcpy(ordem.dispositivo , "Disco Rígido");
				break;
			default:
				std::cout << "Error" << std::endl;
				break;
		}
		
		ordem.tipo = aux;
		ordem.prioridade = prior;
		cont++;
		inserirFinal(&perifericos, ordem);
		//delete[] ordem;
		
	}
	std::cout << "Daisy Chaining utilizando método de ordem a chegada ou entrada." << std::endl;
	imprimirLista(&perifericos);
	std::cout << "MÉTODO POR PRIORIDADE: " << std::endl;
	ordena_AuxPerif(&perifericos);
	imprimirLista(&perifericos);
	return 0;
}

	