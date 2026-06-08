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


void apply_threshold(unsigned char *pixels, // aqui convertimos la imagen en blanco y negro
                     int total,
                     int threshold)

{

    for (int i = 0; i < total;  i++)
    {

        if (*(pixels + i) >= threshold)
        {

            *(pixels + i) = 255;
        }
        else
        {
            *(pixels + i) = 0;
        }

    }

}

unsigned char *make_negative(unsigned char *pixels,
                             int total)
// esta funcion toma la imagen y la convierte en una nueva pero con los  colores invertidos
{

    unsigned char *negative;

    negative = malloc(total * sizeof(unsigned char)); //reserva la memoria para guardar imagen

    if (negative == NULL) // verifica si el malloc fallo
    {

    return NULL;
    }

    for (int i = 0; i < total; i++)
    {
        *(negative + i) = 255 - *(pixels + i); // recorre todos los pixeles y calcla el negativo

    }

    return negative; // devuelve la imagen negativa
}

void write_pgm(const char *filename,
               unsigned char *pixels,
               int width,
               int height,
               int max_val) // abre un archivo, escribe, recorre todos los pixeles usando *(pixels + i)
{

    FILE *file;

    file  = fopen(filename, "w");

    if (file == NULL)
    {
        return;
    }

    fprintf(file, "P2\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", max_val);

    for (int i = 0; i < width * height; i++)
    {
        fprintf(file, "%d ", *(pixels + i));
        if ((i + 1) % width  == 0)
        {
            fprintf(file, "\n");
        }
    }

    fclose(file);

}

void print_stats(unsigned char *original,
                 unsigned char *thresholed,
                 int total)

{

    int blancos = 0;
    int negros = 0;
    int suma = 0;

    for (int i = 0; i < total; i++)

    {
        suma += *(original + i);
        if (*(thresholed + i) == 255)
        {
            blancos++;
        }

        else
        {
            negros++;

        }
    }

    printf("Pixeles blancos: %d\n", blancos);
    printf("Pixeles negros: %d\n", negros);
    printf("Promedio de imagen original: %.2f\n",
            (float)suma / total);

}

int main(void)
{

    int width, height, max_val, threshold;

    unsigned char *pixels = NULL;
    unsigned char *negative = NULL;
    unsigned char *original = NULL;

    pixels = read_pgm("input.pgm", // carga la imagen commleta en la memoria
                      &width, // direccion de memoria de la variable
                      &height,
                      &max_val);

    original = read_pgm("input.pgm",
                        &width,
                        &height,
                        &max_val);

    if (pixels == NULL) // aqui preguntamos si la lectura  fallo
    {
        printf("Error al leer imagen\n");
        return 1;
    }

    printf("Ingrese el valor del umbral: "); // en est parte los pixeles pasan a 0 o a 255
    scanf("%d", &threshold);


    apply_threshold(pixels,
                    width * height,
                    threshold); // convierte la imagen en blanco y negro
    negative = make_negative(pixels,
                             width * height); // gener la imagen en negativo y guarda en  la direccion de negativo
    write_pgm("output_threshold.pgm",
              pixels,
              width,
              height,
              max_val);

    write_pgm("output_negative.pgm",
              negative,
              width,
              height,
              max_val);

    print_stats(original,
                pixels,
                width * height);

    free(original);
    free(pixels);
    free(negative);
    return 0;
}
