#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "perifericos.h"


int main(){
	int solic;
	int cont = 0;
	int justica = 0;
	int aux = 0, prior = 0;
	Aux_Perif* perifericos;
	Aux_Perif* perif_just;
	perifericos = criarLista();
	perif_just = criarLista();
	std::cout << "Entre com o número de solicitações: " << std::endl;
	std::cin >> solic;
	std::cout << "Periféricos:\n1. Impressora\n2. Mouse\n3. Teclado\n4. Scanner\n5. Roteador\n6. Disco Rígido" << std::endl;
	std::cout << "De acordo com os números e Periféricos acima, insira a ordem de entrada das solicitações, sua prioridade e o tempo de justiça" << std::endl;
	while (cont < solic){
		Perif ordem;
		Perif justica_vet;
		std::cin >> aux >> prior >> justica;
		switch (aux){
			case 1:
				//ordem.dispositivo = 'Impressora';
				strcpy(ordem.dispositivo, "Impressora");
				strcpy(justica_vet.dispositivo, "Impressora");
				break;
			case 2: 
				strcpy(ordem.dispositivo , "Mouse") ;
				strcpy(justica_vet.dispositivo, "Mouse");
				break;
			case 3: 
				strcpy(ordem.dispositivo , "Teclado");
				strcpy(justica_vet.dispositivo, "Teclado");
				break;
			case 4:
				strcpy(ordem.dispositivo , "Scanner");
				strcpy(justica_vet.dispositivo, "Scanner");
				break;
			case 5:
				strcpy(ordem.dispositivo , "Roteador");
				strcpy(justica_vet.dispositivo, "Roteador");
				break;
			case 6: 
				strcpy(ordem.dispositivo , "Disco Rígido");
				strcpy(justica_vet.dispositivo, "Disco Rigido");
				break;
			default:
				std::cout << "Error" << std::endl;
				break;
		}
		
		ordem.tipo = aux;
		justica_vet.tipo = aux;

		ordem.prioridade = prior;
		justica_vet.prioridade = prior;

		justica_vet.set_used = true;
		ordem.set_used = true;

		ordem.justica = justica;
		justica_vet.justica = justica;

		cont++;
		inserirFinal(&perifericos, ordem);
		inserirFinal(&perif_just, justica_vet);
		//delete[] ordem;
		
	}
	std::cout << "Daisy Chaining utilizando método de ordem a chegada ou entrada." << std::endl;
	imprimirLista(&perifericos);
	std::cout << "MÉTODO POR JUSTIÇA" << std::endl;
	imprimirLista_Justica(&perif_just);
	std::cout << "MÉTODO POR PRIORIDADE: " << std::endl;
	ordena_AuxPerif(&perifericos);
	imprimirLista(&perifericos);
	return 0;
}

	