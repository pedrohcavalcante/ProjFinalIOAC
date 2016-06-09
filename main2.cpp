#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "perifericos.h"

int main(){
	int solic;
	int cont = 0;
	int aux = 0, prior = 0;
	Aux_Perif* perifericos;
	perifericos = criarLista();
	std::cout << "Entre com o número de solicitações: " << std::endl;
	std::cin >> solic;
	std::cout << "Periféricos:\n1. Impressora\n2. Mouse\n3. Teclado\n4. Scanner\n5. Roteador\n6. Disco Rígido" << std::endl;
	// TESTE DE CRIAÇÃO PARA SET TRUE
	for (int i = 1; i <= 6; ){
		Perif ordem_teste;
		switch (i){
			case 1:
				//ordem.dispositivo = 'Impressora';
				strcpy(ordem_teste.dispositivo, "Impressora");
				
				break;
			case 2: 
				strcpy(ordem_teste.dispositivo , "Mouse") ;
				break;
			case 3: 
				strcpy(ordem_teste.dispositivo , "Teclado");
				break;
			case 4:
				strcpy(ordem_teste.dispositivo , "Scanner");
				break;
			case 5:
				strcpy(ordem_teste.dispositivo , "Roteador");
				break;
			case 6: 
				strcpy(ordem_teste.dispositivo , "Disco Rígido");
				break;
			default:
				std::cout << "Error" << std::endl;
				break;
		}
		ordem_teste.tipo = i;
		i++;
		//ordem_teste.prioridade = prior;
		inserirFinal(&perifericos, ordem_teste);
	}

	std::cout << "De acordo com os números e Periféricos acima, insira os periféricos que solicitaram execução (bus-request) e sua prioridade" << std::endl;
	while (cont < solic){
		//Perif ordem;
		std::cin >> aux >> prior;
		switch (aux){
			case 1:
				//ordem.dispositivo = 'Impressora';
				//strcpy(ordem.dispositivo, "Impressora");
				percorre_true(&perifericos, 1, prior);
				break;
			case 2: 
				//strcpy(ordem.dispositivo , "Mouse") ;
				percorre_true(&perifericos, 2, prior);
				break;
			case 3: 
				//strcpy(ordem.dispositivo , "Teclado");
				percorre_true(&perifericos, 3, prior);
				break;
			case 4:
				percorre_true(&perifericos, 4, prior);
				//strcpy(ordem.dispositivo , "Scanner");
				break;
			case 5:
				percorre_true(&perifericos, 5, prior);
				//strcpy(ordem.dispositivo , "Roteador");
				break;
			case 6: 
				percorre_true(&perifericos, 6, prior);
				//strcpy(ordem.dispositivo , "Disco Rígido");
				break;
			default:
				std::cout << "Error" << std::endl;
				break;
		}
		
		//ordem_teste.prioridade = prior;
		cont++;
		//inserirFinal(&perifericos, ordem);
		//delete[] ordem;
		
	}
	std::cout << "Daisy Chaining utilizando método de ordem a chegada ou entrada." << std::endl;
	imprimirLista(&perifericos);
	std::cout << "MÉTODO POR PRIORIDADE: " << std::endl;
	ordena_AuxPerif(&perifericos);
	imprimirLista(&perifericos);
	return 0;
}

	