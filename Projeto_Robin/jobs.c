#include <unistd.h>
#include "jobs.h"



void print_jobsQueue(){
	printf("\n\nProcessos na Fila:\n");
	for(int ind = 0; ind < queueSize; ind++){
		printf("Processo %d: %s\n", ind+1, fila[ind]);
	}
	printf("\n");

}


void iniciarProcesso(int index){

	pid_t pid;	

	pid = fork();

	if(pid == 0){
		execlp(fila[index], argumentos[index],(char *)NULL);
		kill(pid, SIGSTOP); 
		

	}else{
		//printf("spid [%d] = %d \n",pidx, spid[pidx]);
		spid[pidx] = pid;
		pidx++;	

	}
	
	
}
