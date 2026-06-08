#include <stdio.h>
#include <stdlib.h>

void findLargestLine(int **matrix, int size, int *result)  //es la secuencia de 1s mas larga

{

    int current = 0;
    int max = 0;

    for (int i = 0; i < size; i++) { // manera de recorrer las las filas

        for (int j = 0; j < size; j++) {  // recorre  las columnas de cada fila

            int value = *(*(matrix + i) + j); // este matrix lo mueve a la fila i y luego nos puede dar el puntero al inicio de esa misma  fila
// la j nos mueve por la columna j y obtiene el valor
            if (value == 1) {
                current++;
                if (current > max) {
                    max = current;

                }

            }
            else {
                current = 0;
            }
        }

    }
    *result = max;

}



void allocateMatrix(int ***matrix, int size)  //crea una matriz en la memoria
{
    *matrix = malloc(size * sizeof(int *)); // esta linea reserva la memoria de los punteros

    for (int i = 0; i < size; i++) {
        *(*matrix + i) = malloc(size * sizeof(int)); // con este for ya se vuelve existente la matrz 3x3
    }
}


void fillMatrix(int **matrix, int size) { // esto funciona para llenar   la matriz con 1s o 0s
    for  (int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++) { // en este casi i = filas y j = columnas
            *(*(matrix + i) + j) = rand() % 2; // en esta linea  accedemos al entero, con + i tenemos  la fila, con + j nos  movemos ala columna.
         }
    }
}

void printMatrix(int **matrix, int size) {  // para  imprimir la matriz
    printf("Matriz (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
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

    printf("Ingresar tamaño de matriz: ");
    scanf("%d", &size); //  estas 2 lineas se usan para ingresar en tamaño de la matriz, ya que se ocupa saber el tamaño que el usuario debe ingresar

    allocateMatrix(&matrix, size); // aqui la variable matrix deja de ser NULL

    fillMatrix(matrix, size); // en esta etapa ya debe llenar las posiciones  con el rand, llenar de 1 o 0

    printMatrix(matrix, size); // aqui todavia no se ha hecho la funcion de largestLine entonces se prueba si las demas funciones si estan en fncionamento correcto

    findLargestLine(matrix, size, &largestLine); // en esta funcion lo que se quiere lograr es que a variable sea modificable

    printf("El tamaño de la secuencia de 1s mas grande es: %d\n", largestLine);

    freeMatrix(matrix, size);

    return 0;

}


