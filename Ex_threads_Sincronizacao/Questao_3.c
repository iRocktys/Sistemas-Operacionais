#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{                      //*****************

int id;                                        //Struct para configurar os argmentos das threads
int length;

} thread_arg, ptr_thread_arg; //****************

pthread_t threads[2];   //Declaração threads
sem_t sem;
int aux = 0;

void *thread_func(void *arg){

	ptr_thread_arg  targ = (ptr_thread_arg) arg;
	int i;

	for(i = targ->id; i < targ->length; i +=2){
		if(targ->id == 0){

			sem_wait(&sem);
			if(aux == 0){
					printf("Thread par  %d - valor %d\n", (int)pthread_self(),i);
					aux = 1;
		}else
			i-= 2;
			sem_post(&sem);
			sched_yield();
	}else{

			sem_wait(&sem);

			if(aux == 1){
				printf("Thread impar  %d - valor %d\n", (int)pthread_self(),i);
				aux = 0;
		}else
			i-=2;
			sem_post(&sem);
			sched_yield();
		}
	}//for
}

int main(){

	thread_arg arguments[2];
	int i;
	sem_init(&sem,0,1);


	for(i = 0; i < 2; i++){
		arguments[i].id = i;
		arguments[i].length = 10; //Confugurando os parâmetros das threads

		pthread_create(&(threads[i]), NULL, thread_func, &(arguments[i])); // Criando as threads
	}
		for(i = 0; i<2;i++)
		 pthread_join(threads[i], NULL); //Inserir as threads na fila de pronto

	return 0;
}
