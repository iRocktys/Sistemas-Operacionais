#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para 3 quadros
typedef struct{
	int pos_1;
	int pos_2;
	int pos_3;
}quadro_3;

typedef struct{
	int time_1;
	int time_2;
	int time_3;
}time_3;

//Struct para 4 quadros
typedef struct{
	int pos_1;
	int pos_2;
	int pos_3;
	int pos_4;
}quadro_4;

typedef struct{
	int time_1;
	int time_2;
	int time_3;
	int time_4;
}time_4;

void opcaoTresQuadros(int *vetor, int tam){
	int pageFault, cont;
	quadro_3 page[tam];
	time_3 time[tam];
	
	//Incrementos iniciais
	//PageFault 1
	pageFault = 0;
	cont=0;
	
	page[pageFault].pos_1 = vetor[cont];
	page[pageFault].pos_2 = -1;
	page[pageFault].pos_3 = -1;
	
	
	time[cont].time_1 = 1;	
	time[cont].time_2 = 0;
	time[cont].time_3 = 0;
	
	//PageFault 2
	pageFault++;
	cont++;
	
	page[pageFault].pos_1 = page[pageFault-1].pos_1;
	page[pageFault].pos_2 = vetor[cont];
	page[pageFault].pos_3 = -1;
	
	time[cont].time_1 = time[cont-1].time_1 + 1;
	time[cont].time_2 = 1;
	time[cont].time_3 = 0;

	//PageFault 3
	pageFault++;
	cont++;
	
	page[pageFault].pos_1 = page[pageFault-1].pos_1;
	page[pageFault].pos_2 = page[pageFault-1].pos_2;
	page[pageFault].pos_3 = vetor[cont];
	
	time[cont].time_1 = time[cont-1].time_1 + 1;
	time[cont].time_2 = time[cont-1].time_2 + 1;
	time[cont].time_3 = 1;

	while(cont < tam){
		//PageFault 4 - talves exista - verificar se numero esta aqui, e substui ou n
		if(page[pageFault].pos_1 == vetor[cont] || page[pageFault].pos_2 == vetor[cont] || page[pageFault].pos_3 == vetor[cont]){
			
			if(page[pageFault].pos_1 == vetor[cont]){
				time[cont].time_1 = 1;
				time[cont].time_2 = time[cont-1].time_2 + 1;
				time[cont].time_3 = time[cont-1].time_3 + 1;

				cont++;
								
			}
			if(page[pageFault].pos_2 == vetor[cont]){

				time[cont].time_1 = time[cont-1].time_1 + 1;
				time[cont].time_2 = 1;
				time[cont].time_3 = time[cont-1].time_3 + 1;

				cont++;
				
			}
			if(page[pageFault].pos_3 == vetor[cont]){
				
				time[cont].time_1 = time[cont-1].time_1 + 1;
				time[cont].time_2 = time[cont-1].time_2 + 1;
				time[cont].time_3 = 1;

				cont++;
				
			}
		}else{
			if(time[cont-1].time_1 > time[cont-1].time_2 && time[cont-1].time_1 > time[cont-1].time_3 ){
				pageFault++;
		
				page[pageFault].pos_1 = vetor[cont]; 
				page[pageFault].pos_2 = page[pageFault-1].pos_2; 
				page[pageFault].pos_3 = page[pageFault-1].pos_3;
				
				time[cont].time_1 = 1;
				time[cont].time_2 = time[cont-1].time_2 + 1;
				time[cont].time_3 = time[cont-1].time_3 + 1;
				cont++;
			
			}else if(time[cont-1].time_2 > time[cont-1].time_1 && time[cont-1].time_2 > time[cont-1].time_3 ){
				pageFault++;
				
				page[pageFault].pos_1 = page[pageFault-1].pos_1;
				page[pageFault].pos_2 = vetor[cont];  
				page[pageFault].pos_3 = page[pageFault-1].pos_3;
				
				time[cont].time_1 = time[cont-1].time_1 + 1;
				time[cont].time_2 = 1;
				time[cont].time_3 = time[cont-1].time_3 + 1;
				cont++;
				
				
			}else if(time[cont-1].time_3 > time[cont-1].time_1 && time[cont-1].time_3 > time[cont-1].time_2 ){
				pageFault++;
				
				page[pageFault].pos_1 = page[pageFault-1].pos_1;
				page[pageFault].pos_2 = page[pageFault-1].pos_2;
				page[pageFault].pos_3 = vetor[cont];  
				
				time[cont].time_1 = time[cont-1].time_1 + 1;
				time[cont].time_2 = time[cont-1].time_2 + 1;
				time[cont].time_3 = 1;
				cont++;
			
			}
		}
	}
	/*
	//Exibe pageFaults criados
	printf("--------------------------------\n");
	printf("---------- 3 QUADROS -----------\n");
	printf("--------------------------------\n");
	
	for(int i = 0; i <= pageFault; i++ ){
		printf("Page-Fault %d: %d %d %d \n", i+1, page[i].pos_1, page[i].pos_2, page[i].pos_3);
	}
	
	
	Caso queira imprimir os TimeStamp
	
	for(int i = 0; i < tam-1; i++){
		printf("TimeStamp %d: %d %d %d \n", i+1, time[i].time_1, time[i].time_2, time[i].time_3);
	}*/

}

void opcaoQuatroQuadros(int *vetor, int tam){
	//Criando as variaveis e struct, tamanho struct poderá ser o maximo de elementos q tem no arquivo
	int pageFault, cont;
	quadro_4 page_4[tam];
	time_4 time_4[tam];
	
	//Incrementos iniciais necessario para inicializacao dos quadros
	//PageFault 1
	pageFault = 0;
	cont=0;
	
	page_4[pageFault].pos_1 = vetor[cont];
	page_4[pageFault].pos_2 = -1;
	page_4[pageFault].pos_3 = -1;
	page_4[pageFault].pos_4 = -1;
	
	time_4[cont].time_1 = 1;	
	time_4[cont].time_2 = 0;
	time_4[cont].time_3 = 0;
	time_4[cont].time_4 = 0;
	
	//PageFault 2
	pageFault++;
	cont++;
	
	page_4[pageFault].pos_1 = page_4[pageFault-1].pos_1;
	page_4[pageFault].pos_2 = vetor[cont];
	page_4[pageFault].pos_3 = -1;
	page_4[pageFault].pos_4 = -1;
	
	time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
	time_4[cont].time_2 = 1;
	time_4[cont].time_3 = 0;
	time_4[cont].time_4 = 0;

	//PageFault 3
	pageFault++;
	cont++;
	
	page_4[pageFault].pos_1 = page_4[pageFault-1].pos_1;
	page_4[pageFault].pos_2 = page_4[pageFault-1].pos_2;
	page_4[pageFault].pos_3 = vetor[cont];
	page_4[pageFault].pos_4 = -1;
	
	time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
	time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
	time_4[cont].time_3 = 1;
	time_4[cont].time_4 = 0;
	
	//PageFault 4
	pageFault++;
	cont++;
	
	page_4[pageFault].pos_1 = page_4[pageFault-1].pos_1;
	page_4[pageFault].pos_2 = page_4[pageFault-1].pos_2;
	page_4[pageFault].pos_3 = page_4[pageFault-1].pos_3;
	page_4[pageFault].pos_4 = vetor[cont];
	
	time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
	time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
	time_4[cont].time_3 = time_4[cont-1].time_3 + 1;
	time_4[cont].time_4 = 1;
	
	//printf("Page-Fault TESTE: %d %d %d %d\n", page[cont].pos_1, page[cont].pos_2, page[cont].pos_3, page[cont].pos_4);

	while(cont < tam){
		//Se possuir pagina a ser inserida ja pertencer aos quadros, somente atualizar o timeStamp
		if(page_4[pageFault].pos_1 == vetor[cont] || page_4[pageFault].pos_2 == vetor[cont] || page_4[pageFault].pos_3 == vetor[cont] || page_4[pageFault].pos_4 == vetor[cont]){
			
			if(page_4[pageFault].pos_1 == vetor[cont]){
				time_4[cont].time_1 = 1;
				time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
				time_4[cont].time_3 = time_4[cont-1].time_3 + 1;
				time_4[cont].time_4 = time_4[cont-1].time_4 + 1;

				cont++;		
			}
			if(page_4[pageFault].pos_2 == vetor[cont]){
				time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
				time_4[cont].time_2 = 1;
				time_4[cont].time_3 = time_4[cont-1].time_3 + 1;
				time_4[cont].time_4 = time_4[cont-1].time_4 + 1;

				cont++;
			}
			if(page_4[pageFault].pos_3 == vetor[cont]){
				time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
				time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
				time_4[cont].time_3 = 1;
				time_4[cont].time_4 = time_4[cont-1].time_4 + 1;

				cont++;
			}
			if(page_4[pageFault].pos_4 == vetor[cont]){
				time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
				time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
				time_4[cont].time_3 = time_4[cont-1].time_3 + 1;
				time_4[cont].time_4 = 1;

				cont++;
			}
		}else{
			if(time_4[cont-1].time_1 > time_4[cont-1].time_2 && time_4[cont-1].time_1 > time_4[cont-1].time_3 && time_4[cont-1].time_1 > time_4[cont-1].time_4){
				pageFault++;
		
				page_4[pageFault].pos_1 = vetor[cont]; 
				page_4[pageFault].pos_2 = page_4[pageFault-1].pos_2; 
				page_4[pageFault].pos_3 = page_4[pageFault-1].pos_3;
				page_4[pageFault].pos_4 = page_4[pageFault-1].pos_4;
				
				time_4[cont].time_1 = 1;
				time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
				time_4[cont].time_3 = time_4[cont-1].time_3 + 1;
				time_4[cont].time_4 = time_4[cont-1].time_4 + 1;
				cont++;
			
			}else if(time_4[cont-1].time_2 > time_4[cont-1].time_1 && time_4[cont-1].time_2 > time_4[cont-1].time_3 && time_4[cont-1].time_2 > time_4[cont-1].time_4){
				pageFault++;
				
				page_4[pageFault].pos_1 = page_4[pageFault-1].pos_1;
				page_4[pageFault].pos_2 = vetor[cont];  
				page_4[pageFault].pos_3 = page_4[pageFault-1].pos_3;
				page_4[pageFault].pos_4 = page_4[pageFault-1].pos_4;
				
				time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
				time_4[cont].time_2 = 1;
				time_4[cont].time_3 = time_4[cont-1].time_3 + 1;
				time_4[cont].time_4 = time_4[cont-1].time_4 + 1;
				cont++;
				
				
			}else if(time_4[cont-1].time_3 > time_4[cont-1].time_1 && time_4[cont-1].time_3 > time_4[cont-1].time_2 && time_4[cont-1].time_3 > time_4[cont-1].time_4){
				pageFault++;
				
				page_4[pageFault].pos_1 = page_4[pageFault-1].pos_1;
				page_4[pageFault].pos_2 = page_4[pageFault-1].pos_2;
				page_4[pageFault].pos_3 = vetor[cont];  
				page_4[pageFault].pos_4 = page_4[pageFault-1].pos_4;
				
				time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
				time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
				time_4[cont].time_3 = 1;
				time_4[cont].time_4 = time_4[cont-1].time_4 + 1;
				cont++;
			
			}else if(time_4[cont-1].time_4 > time_4[cont-1].time_1 && time_4[cont-1].time_4 > time_4[cont-1].time_2 && time_4[cont-1].time_4 > time_4[cont-1].time_3){
				pageFault++;
				
				page_4[pageFault].pos_1 = page_4[pageFault-1].pos_1;
				page_4[pageFault].pos_2 = page_4[pageFault-1].pos_2;
				page_4[pageFault].pos_3 = page_4[pageFault-1].pos_2;
				page_4[pageFault].pos_4 = vetor[cont];
				
				time_4[cont].time_1 = time_4[cont-1].time_1 + 1;
				time_4[cont].time_2 = time_4[cont-1].time_2 + 1;
				time_4[cont].time_3 = time_4[cont-1].time_3 + 1;
				time_4[cont].time_4 = 1;
				cont++;
			
			}
		}
	}
	/*
	//Exibe pageFaults criados
	printf("--------------------------------\n");
	printf("---------- 4 QUADROS -----------\n");
	printf("--------------------------------\n");
	
	for(int i = 0; i <= pageFault; i++ ){
		printf("Page-Fault %d: %d %d %d %d \n", i+1, page_4[i].pos_1, page_4[i].pos_2, page_4[i].pos_3, page_4[i].pos_4);
	}
	
	
	//Caso queira imprimir os TimeStamp
	
	for(int i = 0; i < tam-1; i++){
		printf("TimeStamp %d: %d %d %d %d\n", i+1, time_4[i].time_1, time_4[i].time_2, time_4[i].time_3, time_4[i].time_4);
	}*/

}

int main(int argc, char *argv[]){
	//Abrindo arquivos para leitura
	FILE* Entrada;
	Entrada = fopen("teste.txt", "r+");
	
	//variaveis utilizadas
	int aux, tam=0, *vetor, i=0;
	
	//Verifica a abertura dos arquivos
	if(Entrada == NULL){
		printf("\nError 4:20 - Falha na abertura do arquivo\n");
		system("pause");
	}else{		
		//contagem de paginas
		while(!feof(Entrada)){
			fscanf(Entrada,"%d", &aux);
			tam++;
		}
		//reinicia o arquivo
		rewind(Entrada);
		//aloca o vetor dinamicamente de acordo com a quantidade de pagina
		vetor = malloc(tam * sizeof(int));
		//insere as paginas em cada posicao do vetor
		while(!feof(Entrada)){
			fscanf(Entrada,"%d", &aux);
			vetor[i] = aux; 
			i++;
		}
	}
	//Chamando a funcao para efetuar a paginacao com a quantidade de quadros desejada
	opcaoTresQuadros(vetor, tam);
	opcaoQuatroQuadros(vetor, tam);
	
	printf("Teste pag_1 SUCESSO\n");
	
	//Fechando o arquivo Entrada
	fclose(Entrada);
}