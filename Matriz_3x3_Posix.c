
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define COORDENADOR 0

int main(int argc , char *argv[]) {

    int size, id, somaprodaprod = 0, i, j, k, tam = 3;

  int a[3][3]={{6,6,6},{7,7,7},{8,8,8}};
  int b[3][3]={{1,1,0},{1,0,1},{1,2,3}};
  int c[3][3];

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

  for(i = id; i < tam; i = i+size) {
   	for(j = 0; j < tam; j++) {
   		 somaprod=0;

   		 for(k = 0; k < tam; k++) {
   			 somaprod = somaprod + a[i][k] * b[k][j];
   		 }
   		 c[i][j] = somaprod;
   	}
  }

    if(id != COORDENADOR){
   	 for(i = id; i < tam; i = i+size)
   		 MPI_Send(&c[i][0], tam, MPI_INT, 0, 10+i, MPI_COMM_WORLD);
    }

  if(id == COORDENADOR){
   	for(j = 1; j < size; j++){
   		 for(i = j; i < tam; i = i+size){
   			 MPI_Recv(&c[i][0], tam, MPI_INT, j, 10+i, MPI_COMM_WORLD, &status);
   		 }
   	 }
  }
  // espera até ter o resultado completo, então imprime a matriz resultado
  MPI_Barrier(MPI_COMM_WORLD);

  if(id == COORDENADOR){
    for(i = 0; i < tam; i++){
   		 for(j = 0; j < tam; j++){
   			 printf("%d\t",c[i][j]);
   		 }
   		 printf("\n");
   	}
  }

    return 0;
}
