#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "./funciones.h"


void ordenamiento_fichas(articulos_t *articulos){
	char articulo[90];
	int opc, articulo_index, i;	
    for ( opc = 1; opc < CANT_ARTICULOS; opc++)
    {
        for ( i = 0; i < CANT_ARTICULOS-1; i++)
        {
            if(articulos[i].total<articulos[i+1].total){
                strcpy (articulo,articulos[i].descripcion);
                strcpy(articulos[i].descripcion,articulos[i+1].descripcion);
                strcpy(articulos[i+1].descripcion, articulo);

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_1];
                articulos[i].cantidad_sucursal[SUCURSAL_1] = articulos[i+1].cantidad_sucursal[SUCURSAL_1];
                articulos[i+1].cantidad_sucursal[SUCURSAL_1] = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_2];
                articulos[i].cantidad_sucursal[SUCURSAL_2] = articulos[i + 1].cantidad_sucursal[SUCURSAL_2];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_2] = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_3];
                articulos[i].cantidad_sucursal[SUCURSAL_3] = articulos[i + 1].cantidad_sucursal[SUCURSAL_3];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_3] = articulo_index;

                articulo_index = articulos[i].total;
                articulos[i].total = articulos[i + 1].total;
                articulos[i + 1].total = articulo_index;
            }
            
        }
        
    }
	

}

void impresion_fichas(articulos_t *articulos){
    int i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulos[i].descripcion[0]){
        printf("%s\t%d\t%d\t%d\t%d\n", articulos[i].descripcion, articulos[i].cantidad_sucursal[SUCURSAL_1], articulos[i].cantidad_sucursal[SUCURSAL_2], articulos[i].cantidad_sucursal[SUCURSAL_3],articulos[i].total);
        i++;
    }
};

void carga_fichas(articulos_t *articulos){
	char articulo[90];
	int i, articulo_index, sucursal, opc;
    do
    {
	// Ingreso de datos del articulo
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s",articulo);
        i=0;
	// Si el articulo ya tiene descripcion y es igual a la ingresada, no hacer nada.
        while (articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;
        // actualizo el indice
	articulo_index = i;
	// Copio descripcion al array
        strcpy(articulos[i].descripcion, articulo);
	// Printeo estado
        printf("\n%s, Indice: %d\n", articulos[articulo_index].descripcion, articulo_index);
	// Seleccion de sucursal
        printf("Para que sucursal va a realizar la carga? (1,2,3)");
        scanf("%d", &sucursal);
	// Carga de cantidades por sucursal
        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d", &articulos[articulo_index].cantidad_sucursal[sucursal-1]);
	// Actualizacion de cantidad total
	for(i=0;i<3;i++) articulos[articulo_index].total += articulos[articulo_index].cantidad_sucursal[i];        
	
        printf("Desea ingresar otro articulo? 1-Si, 2-No");
        scanf("%d",&opc);
    } while (opc==1);

}
