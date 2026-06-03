#include <stdio.h>
#include <stdlib.h>

void findLargestLine(int **matrix, int size, int *result) {  //es la secuencia de 1s mas larga
}



void allocateMatrix(int ***matrix, int size)  //crea una matriz en la memoria
{
    *matrix = malloc(size * sizeof(int *)); // esta linea reserva la memoria de los punteros

    for (int i = 0; i < size; i++) {
        *(*matrix + i) = malloc(size * sizeof(int)); // con este for ya se vuelve existente la matrz 3x3
    }
} 


void fillMatrix(int **matrix, int size) { // esto funciona para llenar   la matriz con 1s o 0s
}

void printMatrix(int **matrix, int size) {  // para  imprimir la matriz
    printf("Matriz (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
    }
}

void freeMatrix(int **matrix, int size) {  //libera la memoria
    for (int i = 0; i < size; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}


int main(void) { // funcion principal que coordina todo
    int size , largestLine;
    int **matrix = NULL;

    printf("El tamaño de la secuencia de 1s mas grande es: %d\n", largestLine);

    return 0;

}


