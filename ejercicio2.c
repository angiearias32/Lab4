#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char *read_pgm(const char *filename, // abre una imagen y sus parametros y reserva memoria  para los pixeles y devolver un puntero
                        int *width,
                        int *height,
                        int *max_val)


{

    FILE *file; // aca se crea una variable que representa el archivo PGM
    char magic[3]; //Guarda las primeras letras del documento
    unsigned char *pixels; //apunta arreglo dinamico

    file = fopen(filename, "r"); //abre para leer

    if (file == NULL) // aqui estamos preguntando si es o no NULL

    {
        return NULL;
    }

    fscanf(file, "%2s", magic); //lee la imagen desde el archivo para verificar si es un archivo PGM

    if (strcmp(magic, "P2") != 0) //comprueba si es PGM

    {
        fclose(file); // cierra el archivo antes de salir
        return NULL;

    }

    fscanf(file, "%d %d", width, height);
    fscanf(file, "%d", max_val);

    pixels = malloc((*width) * (*height) * sizeof(unsigned char)); //width es un puntero pero *width es el valor guardado

    if (pixels == NULL)
    {

        fclose(file);
        return NULL;
    }

    for (int i = 0; i < (*width) * (*height); i++) // recorre una vuelta por cada pixel
    {
        fscanf(file, "%hhu", pixels + i); // esta linea le dice al puntero que vaya al pixel numero i
    }

    fclose(file);
    return pixels;

}


void apply_threshold(unsigned char *pixels,
                     int total,
                     int threshold)

{

}

unsigned char *make_negative(unsigned char *pixels,
                             int total)

{
    return NULL;

}

void write_pgm(const char *filename,
               unsigned char *pixels,
               int width,
               int height,
               int max_val)

{

}

void print_stats(unsigned char *original,
                 unsigned char *thresholed,
                 int total)

{

}

int main(void)
{

    int width, height, max_val, threshold;

    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;

    return 0;
}
