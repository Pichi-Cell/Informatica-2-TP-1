#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define TOTAL 3

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3]; // sucursal 1 2 3    
    int total;
}articulos_t;

void carga_fichas(articulos_t *articulos );
void impresion_fichas(articulos_t *articulos);
void ordenamiento_fichas(articulos_t *articulos);


