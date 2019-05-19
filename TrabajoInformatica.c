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
void nuevo_producto(Producto [], int );
void suministrar(Producto [], int );
void buscar_producto(Producto [], int );
void modificar_precio(Producto [], int );
void pedido(Producto [], int );
void devolucion(Producto [], int );


int main() 
{
	int opcion, cant, i, flag = 1;
		
	
	while(flag){
		FILE *g;
			
		g = fopen("Almacen.txt", "r");
			
		if(g == NULL){
			printf("Error al abrir el archivo\n");
			return -1;
		}
		
		fscanf(g, "%i", &cant);
		fflush(stdin);
		Producto p[cant];	
		
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
				nuevo_producto(p, cant);
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
		system("cls");
	}
	return 0;	
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
	
	for(i = 0; i < a-1; i++){
		printf("%s %s %s %s %s %i %f\n", 
			p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
	}
	
	printf("\nPulse intro para volver al menu\n");
	while(getchar() != '\n');
}

void nuevo_producto(Producto p[], int dim){
	FILE *h;
	int i, cont, flag = 1;
	
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
	
	for(i=0;i<dim-1 && flag==1;i++){
		if(strcmp(p[i].codigo,p[dim-1].codigo)==0 && strcmp(p[i].marca,p[dim-1].marca)==0){
			cont=0;
			flag = 0;
		}
	}
	if(cont==dim){
		printf("Se ha anadido un nuevo producto\n");
		printf("Cantidad: ");
		scanf("%i",&p[dim-1].cantidad);
		while(getchar()!='\n');
		
		printf("Precio: ");
		scanf("%f",&p[dim-1].precio);
		while(getchar()!='\n');
		
		dim++;
		h=fopen("Almacen.txt","w");
		
		if(h==NULL)
			printf("Error al abrir el archivo\n");
		
		fprintf(h,"%i\n",dim);
		for(i=0;i<dim-1;i++){
			fprintf(h,"%s %s %s %s %s %i %f\n",p[i].codigo,p[i].genero,p[i].clase,p[i].tipo,p[i].marca,p[i].cantidad,p[i].precio);
		}
		fclose(h);
		printf("Se ha anadido exitosamente:\n");
		printf("%s %s %s %s %s %i %f",p[dim-2].codigo,p[dim-2].genero,p[dim-2].clase,p[dim-2].tipo,p[dim-2].marca,p[dim-2].cantidad,p[dim-2].precio);
	}
	else
		printf("\nProducto ya existente\n");
	
	printf("\nPulsa intro para volver al menu\n");
	while(getchar() != '\n');	
}

void suministrar(Producto p[], int dim) {
	
	int i, j = 0, cant, flag=1;
	char cod[5];
	FILE *f;
	
	printf("Productos en stock: \n");
	for(i = 0; i < dim-1; i++) {
		printf("%s %s %s %s %s %i\n", p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad);
	}
	
	printf("Introduzca el codigo del producto a suministrar: \n");
	gets(cod);
	
	for (i = 0; i < dim-1 && flag == 1; i++) {
		if(strcmp(p[i].codigo, cod) == 0) {
			j = 5;
			flag = 0;
		}
	}
	
	if (j == 5) {
		printf("Introduzca la cantidad que desea suministrar: \n");
		scanf("%i", &cant);
		while(getchar() != '\n');
		p[i-1].cantidad += cant;
		printf("Suministro realizado.\n");
		printf("%s %s %s %s %s %i\n", p[i-1].codigo, p[i-1].genero, p[i-1].clase, p[i-1].tipo, p[i-1].marca, p[i-1].cantidad);
		
		f = fopen("Almacen.txt", "w");
		
		if(f == NULL) {
			printf("Error al abrir el archivo.\n");
	
		}
		
		fprintf(f, "%i\n", dim);
		
		for (i = 0; i < dim-1; i++) {
			fprintf(f, "%s %s %s %s %s %i %f\n", p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
		}
		fclose(f);
	}
	else 
		printf("Codigo invalido.");
	
	printf("\nPulse intro para volver al menu\n");
	while(getchar() != '\n');
}

void buscar_producto(Producto p[], int dim){

	int i,j=0, flag = 1;
	char busqueda[5];
	
	printf("\nIntroduzca el codigo: ");
	gets(busqueda); 
	
	for(i=0;i<dim-1 && flag == 1;i++){
		if(strcmp(busqueda,p[i].codigo)==0){
			j=5;
			flag = 0;
		}
	}
	if(j==5)
		printf("\n%s %s %s %s %s %i %f\n",p[i-1].codigo, p[i-1].genero, p[i-1].clase, p[i-1].tipo, p[i-1].marca, p[i-1].cantidad, p[i-1].precio);
			
	else
		printf("\nEl codigo introducido no existe. \n");
	
	printf("\nPulse intro para volver al menu\n");
	while(getchar() != '\n');
}

void modificar_precio(Producto p[], int dim){
	
	int i, j = 0,flag = 1;
	float  incre;
	FILE *f;
	char cod[5];
	printf("Codigo del producto al que le quiere cambiar el precio:");
	gets(cod);
	
	for (i = 0; i < dim-1 && flag == 1; i++) {
		if (strcmp(p[i].codigo, cod) == 0) {
			j = 1;
			flag = 0;
		}
	}
	
	if (j == 1) {
		printf("Introduzca la cantidad que desea aumentar o disminuir el precio: \n");
		printf("(Para rebajar el precio ponga signo negativo)\n");
		
		scanf("%f", &incre);
		
		p[i].precio += incre;
		
		printf("Precio modificado: \n");
		printf("%s %f", p[i].codigo, p[i].precio);
		f = fopen("Almacen.txt", "w");
		
		if(f == NULL)
			printf("Error al abrir el archivo\n");
		
		fprintf(f, "%i\n", dim);
		
		for (i = 0; i < dim-1; i++) {
			fprintf(f, "%s %s %s %s %s %i %f\n", p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
		}
		fclose(f);
	}
	
	else 
		printf("Codigo invalido: \n");
	
	printf("\nPulse intro para volver al menu principal.\n");
	while(getchar() != '\n');
}

void pedido(Producto p[], int dim){
	int i, cant=0, flag1, j, flag = 1, lista1[30],lista2[30], x, cont=0;
	char cod[5], gen[10], clas[15], tip[10], marc[10];
	float prec=0;
	FILE *f;
	
	for(j=0; j<30; j++){
		lista1[j] = 0;
	}
	
	for(j=0; j<30; j++){
		lista2[j] = 0;
	}
	
	printf("Lista de productos del stock:\n");
	for(i = 0; i < dim-1; i++){
		printf("%s %s %s %s %s %i %f\n", 
			p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
	}
	
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
		x=0;
		
		for(i=0; i<dim-1 && flag ==1 ; i++){
			if(strcmp(cod, p[i].codigo)==0 && strcmp(gen, p[i].genero)==0 && strcmp(clas, p[i].clase)==0 && strcmp(tip, p[i].tipo)==0 && strcmp(marc, p[i].marca)==0){
				x = 5;
				flag = 0;
			}
		}
			if(x==5){
			if(cant <= p[i].cantidad){
				printf("Tu pedido se ha realizado correctamente\n");
				cont++;
				p[i].cantidad -= cant;
				prec += cant*p[i].precio;
				lista1[cont] = i+1;
				lista2[cont] = cant;
				
				f = fopen("Almacen.txt", "w");
				
				if(f == NULL)
					printf("Error al abrir el archivo");
				
				fprintf(f, "%i\n", dim);
				
				for(i=0; i<dim-1; i++){
					fprintf(f, "%s %s %s %s %s %i %f\n", 
						p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
				}
				
				fclose(f);
				
				printf("Pedido actual:\n");
				
				for(j=0; j<30; j++){
					if(lista1[j] != 0){
						if(lista2[j] != 0){
							printf("%s %s %s %s %s %f x %d\n", 
								p[lista1[x]-1].codigo, p[lista1[x]-1].genero, p[lista1[x]-1].clase, p[lista1[x]-1].tipo, p[lista1[x]-1].marca, p[lista1[x]-1].precio, lista2[x]);
						}	
					}
				}
				printf("Coste de tu pedido: %f\n", prec);
			}
			else
				printf("Se nos han agotado las unidades de ese producto\n");
		}
		else
			printf("El producto seleccionado no esta en nuestro stock\n");
			
		printf("Introduzca 1 si quiere seguir añadiendo algun producto mas o cualquier letra para salir, gracias.\n");
		scanf("%d", &flag1);
		while(getchar() != '\n');
	}while(flag1 == 1);	
	
	printf("\nPulse intro para volver al menu\n");
	while(getchar() != '\n');
}


void devolucion(Producto p[],int dim){
	
	char scod[5];
	int i, v, addDev, fechaCC[3],fechaAA[3], flag=1;
	char n;
	FILE *f;
	
	printf("Lista de productos en stock: \n");
	for(i=0;i<dim-1;i++){
		printf("%6s %10s %11s %11s %10s %5i\n",p[i].codigo,p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad);
	}
	
	printf("\nCodigo del producto desea devolver: ");
	gets(scod);
	
	v=0;
	for(i=0;i<dim-1 && flag==1;i++){
		if(strcmp(p[i].codigo,scod)==0){
			v=5;
			flag=0;
		}
	}
	
	if(v==0){
		printf("Introduzca la cantidad a devolver de producto codigo %s: ",scod);
		scanf("%i", &addDev);
		while(getchar()!='\n');
		
		p[i].cantidad=p[i].cantidad+addDev;
		
		printf("Se han devuelto %i producto(s) al stock\n",addDev);
		printf("%s %s %s %s %s %i %f\n",p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
		f=fopen("Almacen.txt", "w");
		
		if(f==NULL)
			printf("Error al abrir el archivo\n");
		
		fprintf(f,"%i\n",dim);
		
		for(i=0;i<dim-1;i++){
			fprintf(f,"%s %s %s %s %s %i %f\n",p[i].codigo, p[i].genero, p[i].clase, p[i].tipo, p[i].marca, p[i].cantidad, p[i].precio);
		}
		fclose(f);
	}
	else
		printf("\nCodigo incluido");
		
	printf("\nPulsa intro para volver al menu\n");
	while(getchar() != '\n');		
}






