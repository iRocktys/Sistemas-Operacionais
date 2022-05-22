#include "scheduler.h"
#include "load_jobs.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void iniciarProcesso(int index);

void round_robin(float quantum){
	//Inicia cada processo
	for(int i = 0; i < queueSize; i++){
		iniciarProcesso(i);
		kill(spid[i], SIGSTOP);
	}
	
	//Comeca processo de indice 0
	kill(spid[alterna], SIGCONT);
	
	while(1){	
		signal(SIGALRM, alternaTarefa);
		alarm(quantum);
		
		while(!receive){
			pause();
		}
		
		receive = 0;		
		
	}
	
}

void fcfs(){	
	for(int i = 0; i < queueSize; i++){
		iniciarProcesso(i);
		//kill(spid[i], SIGSTOP);		
	}
}


void scheduler_init(char* jobs, float quantum){
	int escalonador, aux = 1;
	
	pidx = 0;
	alterna = 0;
	receive = 0;
	
	loadJobs(jobs);

	print_jobsQueue();	
	
	while(aux){
		printf("Escolha Escalonador: [1]-Robin | [2]-FGTS\nOpcao: ");
		scanf("%d", &escalonador);
		
		switch(escalonador){
			case 1:
				round_robin(quantum);
				aux = 0;
				break;
			case 2:
				fcfs();
				aux = 0;
				break;
			default:
				printf("Numero invalido!!\n\n");
				aux = 1;
		}
	}
 
}


void alternaTarefa(int signum){	
	UNUSED(signum);
	
	receive = 1;
	
	kill(spid[alterna], SIGSTOP);
	
	if(alterna < (queueSize-1)){
		alterna++;
	}else{
		alterna=0;
	}
	
	kill(spid[alterna], SIGCONT);

}



