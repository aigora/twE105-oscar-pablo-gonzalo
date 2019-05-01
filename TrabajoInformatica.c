// Trabajo: REGISTROS ALMACEN

# include <stdio.h>

typedef struct {
	char codigo[5];
	char genero [10];
	char clase [15];
	char tipo[10];
	char marca[10];
	float precio;
	int cantidad;
};producto

int menu(void);
void stock(Producto p[], int a);
void buscar_producto(Producto p[], int dim);
void nuevo_prod(Producto p[], int dim);
void suministrar(Producto p[], int dim);
void modificar_precio(Producto p[], int dim);
void pedido(Producto p[], int dim);
void devolucion(Producto p[], int dim);

int opcion_menu(int n);
int main() 
{
	int opcion;
	
	printf("Indique la operacion que quiere realizar:\n");
	printf(" 1 - Ver stock\n");
	printf(" 2 - Registrar nuevo producto\n");
	printf(" 3 - Suministrar stock\n");
	printf(" 4 - Buscador de productos\n");
	printf(" 5 - Variar precio de un producto\n");
	printf(" 6 - Facturar pedido\n");
	printf(" 7 - Devolucion producto\n");
	printf(" 0 - Salir\n");
	printf("\nOpcion: ");
	scanf("%d", &opcion);
	while(getchar()!='\n');
	
	while(opcion>7||opcion<0){
		
		printf("opcion no valida, vuelva a introducir la opcion: ");
		scanf("%d", &opcion);
	}
		

	switch(opcion)
	{
		case 1:
			printf("VER STOK---------");
			break;
		case 2:
			printf("NUEVO PRODUCTO----------");
			break;
		case 3:
			printf("SUMINISTRAR STOK------------");
			break;
		case 4:
			printf("BUSCAR PRODUCTO------------");
			break;
		case 5:
			printf("VARIAR PRECIO----------");
			break;
		case 6:
			printf("FACTURAR PEDIDO----------");
			break;
		case 7:
			printf("DEVOLUCION PRODUCTO----------");
			break;
		case 0:
			printf("SALIENDO...");
			return 0;
	}
	
}

int opcion_menu(int n) {
	int i;
}
