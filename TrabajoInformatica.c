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
}Producto;

int menu(void);
void stock(Producto p[], int a);
void buscar_producto(Producto p[], int dim);
void nuevo_prod(Producto p[], int dim);
void suministrar(Producto p[], int dim);
void modificar_precio(Producto p[], int dim);
void pedido(Producto p[], int dim);
void devolucion(Producto p[], int dim);


int main() 
{
	int opcion, cant;
		
	opcion = menu();
	switch(opcion)
	{
		case 1:
			stock(Producto p[], int cant);
			break;
		case 2:
			buscar_producto(Producto p[], int cant);
			break;
		case 3:
			nuevo_prod(Producto p[], int cant);
			break;
		case 4:
			suministrar(Producto p[], int cant);
			break;
		case 5:
			modificar_precio(Producto p[], int cant);
			break;
		case 6:
			 pedido(Producto p[], int cant);
			break;
		case 7:
			 devolucion(Producto p[], int cant);
			break;
		case 0:
			return 0;
	}
	
}

int menu(void) {
	int opcion_menu;
	
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
	scanf("%d", &opcion_menu);
	while(getchar()!='\n');
	
	while(opcion_menu>7||opcion_menu<0){
		
		printf("Opcion no valida, vuelva a introducir la opcion: ");
		scanf("%d", &opcion_menu);
	}
	return opcion_menu;
}
