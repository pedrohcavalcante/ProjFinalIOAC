#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "perif.h"

//using namespace std;

int main(){
    int cont;
	int prior, time_exec;
	Aux_Perif *barramentos;
	barramentos = criarLista();
	Perif insert_impressora;
	Perif insert_mouse;
	Perif insert_teclado;
	Perif insert_scanner;
	Perif insert_roteador;
	Perif insert_harddisk;
	Perif insert_usb;
		strcpy(insert_impressora.dispositivo, "Impressora");
		strcpy(insert_mouse.dispositivo, "Mouse");
		strcpy(insert_teclado.dispositivo, "Teclado");		
		strcpy(insert_scanner.dispositivo, "Scanner");		
		strcpy(insert_roteador.dispositivo, "Roteador");
		strcpy(insert_harddisk.dispositivo, "Disco Rígido");
		strcpy(insert_usb.dispositivo, "USB");
  	std::cout << "Entre com o número dos periféricos a serem utilizados: " << std::endl;
    std::cout << "1. Impressora\n2. Mouse\n3. Teclado\n4. Scanner\n5. Roteador\n6. Disco Rígido\n7. USB" << std::endl;
	std::cout << "Pressione ctrl + d para finalizar" << std::endl;
    while (std::cin >> cont){
		//Perif ordem;
		switch (cont){
			case 1:
				//strcpy(ordem.dispositivo, "Impressora");
				std::cout << "Defina agora a prioridade de " << insert_impressora.dispositivo << std::endl;
				std::cin >> prior;
				std::cout << "Defina o tempo de execução de " << insert_impressora.dispositivo << std::endl;
				std::cin >> time_exec;
				//setData(&barramentos, 1, prior, time_exec);
				insert_impressora.tipo  = 1;
				insert_impressora.prioridade = prior;
				insert_impressora.justica = time_exec;
				insert_impressora.set_used = true;
				inserirFinal(&barramentos, insert_impressora);
				break;
			case 2: 
				//strcpy(ordem.dispositivo , "Mouse") ;
				std::cout << "Defina agora a prioridade de " << insert_mouse.dispositivo << std::endl;
				std::cin >> prior;
				std::cout << "Defina o tempo de execução de " << insert_mouse.dispositivo << std::endl;
				std::cin >> time_exec;
				//setData(&barramentos, 2, prior, time_exec);
				insert_mouse.tipo  = 2;
				insert_mouse.prioridade = prior;
				insert_mouse.justica = time_exec;
				insert_mouse.set_used = true;
				inserirFinal(&barramentos, insert_mouse);
		
				break;
			case 3: 
				//strcpy(ordem.dispositivo , "Teclado");
				std::cout << "Defina agora a prioridade de " << insert_teclado.dispositivo << std::endl;
				std::cin >> prior;
				std::cout << "Defina o tempo de execução de " << insert_teclado.dispositivo << std::endl;
				std::cin >> time_exec;
				//setData(&barramentos, 3, prior, time_exec);
				insert_teclado.tipo  = 3;
				insert_teclado.prioridade = prior;
				insert_teclado.justica = time_exec;
				insert_teclado.set_used = true;
				inserirFinal(&barramentos, insert_teclado);				
				break;
			case 4:
				//strcpy(ordem.dispositivo , "Scanner");
				std::cout << "Defina agora a prioridade de " << insert_scanner.dispositivo << std::endl;
				std::cin >> prior;
				std::cout << "Defina o tempo de execução de " << insert_scanner.dispositivo << std::endl;
				std::cin >> time_exec;
				//setData(&barramentos, 4, prior, time_exec);
				insert_teclado.tipo  = 4;
				insert_scanner.prioridade = prior;
				insert_scanner.justica = time_exec;
				insert_scanner.set_used = true;
				inserirFinal(&barramentos, insert_scanner);
				break;
			case 5:
				//strcpy(ordem.dispositivo , "Roteador");
				std::cout << "Defina agora a prioridade de " << insert_roteador.dispositivo << std::endl;
				std::cin >> prior;
				std::cout << "Defina o tempo de execução de " << insert_roteador.dispositivo << std::endl;
				std::cin >> time_exec;
				//setData(&barramentos, 5, prior, time_exec);
				insert_roteador.tipo  = 5;
				insert_roteador.prioridade = prior;
				insert_roteador.justica = time_exec;
				insert_roteador.set_used = true;
				inserirFinal(&barramentos, insert_roteador);
				break;
			case 6: 
				//strcpy(ordem.dispositivo , "Disco Rígido");
				std::cout << "Defina agora a prioridade de " << insert_harddisk.dispositivo << std::endl;
				std::cin >> prior;
				std::cout << "Defina o tempo de execução de " << insert_harddisk.dispositivo << std::endl;
				std::cin >> time_exec;
				//setData(&barramentos, 6, prior, time_exec);
				insert_harddisk.tipo  = 6;
				insert_harddisk.prioridade = prior;
				insert_harddisk.justica = time_exec;
				insert_harddisk.set_used = true;
				inserirFinal(&barramentos, insert_harddisk);
				break;
			case 7:
				//strcpy(ordem.dispositivo, "USB");
				std::cout << "Defina agora a prioridade de " << insert_usb.dispositivo << std::endl;
				std::cin >> prior;
				std::cout << "Defina o tempo de execução de " << insert_usb.dispositivo << std::endl;
				std::cin >> time_exec;
				//setData(&barramentos, 7, prior, time_exec);
				insert_usb.tipo  = 7;
				insert_usb.prioridade = prior;
				insert_usb.justica = time_exec;
				insert_usb.set_used = true;
				inserirFinal(&barramentos, insert_usb);
				break;
			default:
				std::cout << "Error" << std::endl;
				break;
		}
		/*
		ordem.tipo = cont;
		ordem.set_used = true;
		std::cout << "Defina agora a prioridade de " << ordem.dispositivo << std::endl;
		std::cin >> ordem.prioridade;
		std::cout << "Defina o tempo de execução de " << ordem.dispositivo << std::endl;
		std::cin >> ordem.justica;
		inserirFinal(&barramentos, ordem);
		*/
		std::cout << "Entre com o número do periférico a ser utilizado ou ctrl + d para finalizar" << std::endl;
		
    }
		std::cout << "DAISY CHAINING" << std::endl;
		imprimirLista(&barramentos);	
		std::cout << "PRIORIDADE" << std::endl;
		ordena_AuxPerif(&barramentos);
		imprimirLista(&barramentos);
		std::cout << "JUSTICA" << std::endl;
		imprimirLista(&barramentos, true);
		Aux_Perif *excesso_time;
		excesso_time = criarLista();
		while (barramentos != NULL){
			if (barramentos->info.justica > 5){
				Perif insert_device_extra;
				strcpy(insert_device_extra.dispositivo, barramentos->info.dispositivo);
				insert_device_extra.tipo =  barramentos->info.tipo;
				insert_device_extra.prioridade =  barramentos->info.prioridade;
				insert_device_extra.justica =  barramentos->info.justica - 5;
				insert_device_extra.set_used = barramentos->info.set_used;
				inserirFinal(&excesso_time, insert_device_extra);
				
			}
			barramentos = barramentos->prox;
		}
		std::cout << "Repetindo dispositivos que tiveram tempo de execução inicial superior ao tempo de justiça inicialmente" << 
		" implementado" << std::endl;
		imprimirLista(&excesso_time, true);
}