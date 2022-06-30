#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{                      //***********************************************

int id;                                        //Struct para configurar os argmentos das threads
int length;

} thread_arg, *ptr_thread_arg; //***********************************************

pthread_t threads[2];   //Declaração threads
int flag[2];
int turn;


void *thread_func(void *arg){
	ptr_thread_arg  targ = (ptr_thread_arg) arg;
	int i;

	for(i = targ->id; i < targ->length; i +=2){
		if(targ->id == 0){
			flag[1] = 1;

		       	while (flag[0] == 1 && turn == 1);

			printf("Thread par  %d - valor %d\n", (int)pthread_self(),i);

			flag[1] = 0;
			turn = 1;


			sched_yield();
		}else{
			flag[0] = 1;

		       	while (flag[1] == 1 && turn == 0);

			printf("Thread impar  %d - valor %d\n", (int)pthread_self(),i);

			flag[0] = 0;
			turn = 0;

			sched_yield();
		}
	}
}

int main(){
	thread_arg arguments[2];
	int i;

       	flag[0] = 0;
       	flag[1] = 1;
      	turn = 1;

	for(i = 0; i < 2; i++){
		//Confugurando os parâmetros das threads
		arguments[i].id = i;
		arguments[i].length = 10;

		// Criando as threads
		pthread_create(&(threads[i]), NULL, thread_func, &(arguments[i]));

	}

	for(i = 0; i < 2; i++){
		//Inserir as threads na fila de pronto
		pthread_join(threads[i], NULL);
	}

	return 0;
}
