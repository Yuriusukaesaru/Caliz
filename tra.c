/*REALIZAR UN PROTOTIPO DE UN TRADUCTOR DE INGLES A ESPAÑOL*/

#include <stdio.h>
#include<string.h>
#define N 50


struct traductor
{
	char eng[N];
	char esp[N];
	int lleno;
}trad[N];

void vacio();
void anadir();
void traducir();
void tradu(int op);
int main(){
	int op;
	char key;

	vacio();//FUNCION QUE ESTABLECE LA VARIABLE LLENO A CERO, ES DECIR LIMITA QUE NO SE INTRODUZCAN MAS ELEMENTOS  
				//AL PRINCIPIO DEL PROGRAMA TODOS ESTAN DISPONIBLES PARA LLENAR
	do{

		do{
		printf("BIENVENIDO AL TRADUCTOR INGLES-ESPAÑOL :9 \n");
		printf("ELIGE QUE DESEAS HACER\n");
		printf("\n[1] AÑADIR UNA PALABRA AL DICCIONARIO");
		printf("\n[2] TRADUCIR");
		scanf("%d",&op);
		}while(op<1||op>2);//BUCLE PARA EVITAR QUE SELECCIONEMOS VALORES MENOS DE 1 Y MAYORES QUE 2

		switch(op)//COMPARA EL VALOR DE OP
		{
			case 1: //SI ES 1 SE EJECUTARA LA FUNCION AÑADIR
			  	anadir();
				break;
			case 2:
				traducir();//SI ES 2 SE EJECUTARA LA FUNCION TRADUCIR
				break;
		}
		fflush(stdin);
		getchar();
		printf("\nDESEA HACER OTRA OPERACION? [S][N]: "); //AQUI ME SALTA NO SE POR QUE
		scanf("%c",&key);
	}while(key=='S'||key=='s'); // SE EJECUTARA EL CICLO HASTA QUE EL USUARIO LO QUIERA

	return 0;
}


void vacio() //FUNCION QUE SIRVE COMO IDENTIFICADOR SI EL LUGAR ESTA VACIO O NO
{
	int i;

	for (i = 0; i < N; ++i)//SE EJECUTA HASTA PONER TODOS LOS LLENOS A CERO
							//AL INICIO DEL PROGRAMA ESTAN TODOS LOS DATOS DISPONIBLES
	{						//POR QUE EL CERO ACTUA COMO IDENTIFICADOR 0<-DISPONIBLE 1<-NO DISPONIBLE
		trad[i].lleno=0; 
	}

}


void anadir()
{
		
	int i,aux=0; //AUX ES UNA VARIBLE QUE SIRVE COMO RUTA DE ESCAPE
	
	for (i = 0; i < N && aux==0; i++) //PROGRAMA VA A FUNCIONAR HASTA QUE EL CONTADOR SEA MENOR QUE N Y SOLO SE EJECUTE
	{																				//UNA VEZ GRACIAS A aux
		if(trad[i].lleno==0)//PREGUNTA SI LA VARIABLE LLENO ES CERO ENTONCES ESTA DISPONIBLE PARA LLENAR
		{
			printf("INTRODUCE LA PALABRA EN INGLES: "); //SE PROCEDE A LLENAR CON INFO
			fgets(trad[i].eng,N,stdin);
			getchar();//SE LIMPIA EL BUFFER
						
			printf("\nINTRODUCE LA PALABRA EN ESPAÑOL: ");
			fgets(trad[i].esp,N,stdin);
			getchar();
			
			trad[i].lleno=1;// COMO SE HA LLENADO ESA VARIABLE DE ESTRUCTURA SE PONE 1 
			aux=1; //SE ASIGNA 1 PARA QUE SE CUMPLA LA RUTA DE ESCAPE
		}
	}

}

void traducir()
{

	int op;
	do{
		printf("ELIGE QUE DESEAS HACER\n");
		printf("[1] TRADUCIR DE INGLES-ESPAÑOL");
		printf("[2] TRADUCIR DE ESPAÑOL-INGLES");
		scanf("%d",&op);
	}while(op<1||op>2);//BUCLE PARA EVITAR QUE SELECCIONEMOS VALORES MENOS DE 1 Y MAYORES QUE 2

	switch(op)
	{
		case 1:
			tradu(op);//SE PASA EL PARAMETRO DE OP
			break;
		case 2:
			tradu(op);
			break;
	}

}	

void tradu(int op){
	int i,j,temp=0; //TEMP ES UNA VARIABLE QUE SIRVE COMO RUTA DE ESCAPE 
	char aux[N]; //VECTOR PARA ALMACENAR LA PALABRA QUE SE DESEA BUSCAR

	printf("INTRODUCE LA PALABRA QUE DESEAS BUSCAR: ");
	fgets(aux,N,stdin);
	getchar();


	if(op==1) //SI ELEGISTE TRADUCIR DEL INGLES AL ESPAÑOL
	{
		for (i = 0; i < N && temp==0; i++)
		{
			j=strcmp(aux,trad[i].eng); //AQUI ES IMPORTANTE ACLARAR QUE VA A BUSCAR EN TODAS LAS VARIABLES LA PALABRA
			if(j==0) //QUE BUSCAS GRACIAS AL CONTADOR Y SE COMPARA LA CADENA PARA VER SI ES LA MISMA PALABRA
			{//SI ES LA MISMA LA FUNCION strcmp RETORNA UN CERO QUE SE ALMACENA EN J
				printf("LA TRADUCCION DE %s es %s.",trad[i].eng,trad[i].esp); //SE MUESTRA LA TRADUCCION
				temp=1;   //COMO ES EVIDENTE QUE SE INGRESO LA PALABRA EN INGLES EN ESPAÑOL EN LA MISMA POSICION DEL VECTOR
			}		//PERO EN DIFERENTE VARIABLES SE IMPRIMEN LAS DOS GRACIAS A i
		}
	}
	else //SI NO ELEGISTE TRADUCIR DEL INGLES AL ESPAÑOL ES EVIDENTE QUE BUSCAS TRADUCIR ESPAÑOL AL INGLES
	{
		for (i = 0; i < N && temp==0; i++)
		{
			j=strcmp(aux,trad[i].esp); //LO MISMO, BUSCARA LA PALABRA DENTRO DEL esp
			if(j==0) //SI SON IGUALES SE IMPRIME
			{
				printf("LA TRADUCCION DE %s es %s",trad[i].esp,trad[i].eng);
				temp=1;
			}
		}
	}

}

