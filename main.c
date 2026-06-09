#include <stdio.h>
#include "./funciones.h"


int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};
    printf("Bienvendio al final de Info 1\n\n");
    /*CARGA de las fichas*/
	carga_fichas(articulos);
    /* Impresion de fichas cargadas*/
	impresion_fichas(articulos);
    /* Ordenamiento */
	ordenamiento_fichas(articulos);
    printf("\n\n###################################");
    printf("\n##############ORDENADO################");
    printf("\n################################### \n");
    // impresion fichas
	impresion_fichas(articulos);
    return 0;
}

