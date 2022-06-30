#include <stdio.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char *argv[]){
	clock_t start, end;
	double cpu_time_used;
	int cond=0;
	
	start = clock();
	
	do{
		end = clock();
		cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
		
	}while(cpu_time_used != 5);
	cond=1;
	
	
	printf("Executou durante: %f sec\n", cpu_time_used);
	
	return 0;	

}