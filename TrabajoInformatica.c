// Trabajo: REGISTROS ALMACEN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void stock(Producto [], int );
void nuevo_prod(Producto [], int );
void suministrar(Producto [], int );
void buscar_producto(Producto [], int );
void modificar_precio(Producto [], int );
void pedido(Producto [], int );
void devolucion(Producto [], int );


int main() 
{
	int opcion, cant, i, flag = 1;
	Producto p[cant];
	FILE *g;
		
	g = fopen("Almacen.txt", "r");
		
	if(g == NULL){
		printf("Error al abrir el archivo\n");
		return -1;
	}
		
	
	while(flag{
		fscanf(g, "%d", &cant);
		fflush(stdin);
		
		
		
		for(i=0; i<cant-1; i++){
			fscanf(g, "%s %s %s %s %s %d %f", 
				p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, &p[i].cantidad, &p[i].precio);
			fflush(stdin);
		}
		
		opcion = menu();
		switch(opcion)
		{
			case 1:
				stock(p, cant);
				break;
			case 2:
				nuevo_prod(p, cant);
				break;
			case 3:
				suministrar(p, cant);
				break;
			case 4:
				buscar_producto(p, cant);
				break;
			case 5:
				modificar_precio(p, cant);
				break;
			case 6:
				 pedido(p, cant);
				break;
			case 7:
				 devolucion(p, cant);
				break;
			case 0:
				flag = 0;
		}
	}
	fclose(g);
	
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
	
	do{
		printf("\nOpcion: ");
		scanf("%d", &opcion_menu);
		while(getchar()!='\n');
	}while(opcion_menu>7||opcion_menu<0);

	
	return opcion_menu;
}

void stock(Producto p[], int a){
	int i;
	char vuelta;
	
	for(i = 0; i < a-1; i++){
		printf("%s %s %s %s %s %i %f\n", 
			p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
	}
}

void suministrar(Producto p[], int dim) {
	
	int i, j = 0, cant;
	char cod[5];
	
	FILE *f;
	
	printf("Productos en stock: \n");
	for(i = 0; i < dim-1; i++) {
		printf("%s %s %s %s %s %i\n", p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad);
	}
	
	printf("Introduzca el codigo del producto a suministrar: \n");
	gets(cod);
	
	for (i = 0; i < dim-1; i++) {
		if(strcmp(p[i].codigo, cod) == 0) {
			j = 5;
		}
	}
	
	if (j == 5) {
		printf("Introduzca la cantidad que desea suministrar: \n");
		scanf("%i", &cant);
		
		p[i].cantidad += cant;
		printf("Suministro realizado.\n");
		printf("%s %s %s %s %s %i\n", p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad);
		
		f = fopen("Almacen.txt", "w");
		
		if(f == NULL) {
			printf("Error al abrir el archivo.\n");
			return -2;
		}
		
		fprintf(f, "%i", dim);
		
		for (i = 0; i < dim-1; i++) {
			fprintf(f, "%s %s %s %s %s %i &f\n", p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
		}
		fclose(f);
	}
	else 
	printf("Codigo invalido.");
}

void buscar_producto(Producto p[], int dim){

	int i,j, flag = 1;
	char busqueda[5];
	
	printf("\nIntroduzca el codigo: ");
	gets(busqueda); 
	
	j=0;
	for(i=0;i<dim-1 && flag == 1;i++){
		if(strcmp(busqueda,p[i].codigo)==0){
			j=5;
			flag = 0;
		}
	}
	if(j==5)
		printf("\n%s %s %s %s %s %i %g\n",p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
	
	else
		printf("\nEl codigo introducido no existe. \n");
	
}


void nuevo_producto(Producto p[], int dim){
	
	int i, cont;
	printf("Datos del nuevo producto: ");
	printf("Codigo: ");
	gets(p[dim-1].codigo);
	printf("Genero: ");
	gets(p[dim-1].genero);
	printf("Clase: ");
	gets(p[dim-1].clase);
	printf("Tipo: ");
	gets(p[dim-1].tipo);
	printf("Marca: ");
	gets(p[dim-1].marca);
	cont=dim;
	
	for(i=0;i<dim-1;i++){
		
	}
	
}

void pedido(Producto p[], int dim){
	int i, cant, flag1;
	char cod[5], gen[10], clas[15], tip[10], marc[10];
	float prec;
	
	do{
		printf("Introduzca los datos del pedido\n");
		
		printf("Codigo:\n");
		gets(cod);
		printf("Genero:\n");
		gets(gen);
		printf("Clase:\n");
		gets(clas);
		printf("Tipo:\n");
		gets(tip);
		printf("Marca:\n");
		gets(marc);
		printf("Cantidad:\n");
		scanf("%d", &cant);
		fflush(stdin);
		while(getchar() != '\n');
		
		
		printf("Introduzca 1 si quiere seguir añadiendo algun producto mas o cualquier letra para salir, gracias.\n");
		scanf("%d", &flag1);
		while(getchar() != '\n');
	}while(flag1 == 1);	
}








