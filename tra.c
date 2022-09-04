/*REALIZAR UN PROTOTIPO DE UN TRADUCTOR DE INGLES A ESPAÑOL*/

#include <stdio.h>
#include <string.h>

#define MAX_LETRAS 50
#define MAX_PALABRAS 50

void anadir_palabra();
void menu_traducir();
void traducir_palabra( int _Modo );

struct {
	char ing[MAX_LETRAS];
	char esp[MAX_LETRAS];
} palabra[MAX_PALABRAS];

int registradas = 0;

int main()
{
	short opcion;
	char key;
	
	do {
		do {
			printf("\nBIENVENIDO AL TRADUCTOR INGLES-ESPAÑOL :9 \n");
			printf("ELIGE QUE DESEAS HACER\n");
			printf("\n[1] AÑADIR UNA PALABRA AL DICCIONARIO");
			printf("\n[2] TRADUCIR\n\n");
			scanf( "%hd", &opcion );
			getchar();

		} while ( opcion < 1 || 2 < opcion );

		switch ( opcion ) {
			case 1: //añadir
				if ( registradas <  MAX_PALABRAS ) // si hay cupo
					anadir_palabra();
				break;
			case 2:
				menu_traducir();
				break;
		}

		printf( "\nDESEA HACER OTRA OPERACION? [S][N]: ");
		scanf( "%c", &key );

	} while( key == 'S' || key == 's' );

	return 0;
}

void anadir_palabra()
{
	/* Ya se sabe cuantas palabras se han registrado
	 * si hay 5 palabras, la ultima quedo en la 4,
	 * asi que escribir en el indice 5 es seguro.
	 * Al final incrementamos el conteo de palabras */

	printf("\nINTRODUCE LA PALABRA EN INGLES: ");
	fgets( palabra[registradas].ing, MAX_LETRAS, stdin);
	printf("\nINTRODUCE LA PALABRA EN ESPAÑOL: ");
	fgets( palabra[registradas].esp, MAX_LETRAS,stdin);
	++registradas;
}

void menu_traducir()
{
	short opcion;

	do {
		printf("\nELIGE QUE DESEAS HACER");
		printf("\n[1] TRADUCIR DE INGLES-ESPAÑOL");
		printf("\n[2] TRADUCIR DE ESPAÑOL-INGLES\n\n");
		scanf( "%hd",&opcion );
		getchar();
	} while( opcion < 1 || 2 < opcion );
	
	traducir_palabra( opcion );
}	

void traducir_palabra( int _Modo )
{
	char palabra_ingresada[MAX_LETRAS];

	printf( "\nINTRODUCE LA PALABRA QUE DESEAS BUSCAR: ");
	fgets( palabra_ingresada, MAX_LETRAS, stdin );

	int i = 0;
	/* Aqui empleamos el operador ternario ?: . si _Modo
	 * es 1, vanos a comparar la palabra ingresada con
	 * la version en ingles, de lo contrario, con la "otra".
	 * El ciclo se rompera si strcmp nos devuelce 0 (false)
	 * o si el contador llego al numero de registradas */
	while ( i < registradas &&
				strcmp( palabra_ingresada,
					_Modo == 1 ? palabra[i].ing : palabra[i].esp ) )
		++i;
	
	/* Si el contador igualo las registradas, significa
	 * que supero el limite y no la encontro. por lo tanto
	 * verificamos que sea menor (la busqueda tuvo exito).
	 * Este metodo esta patentado por tu servidor jeje*/
	if ( i < registradas )
		printf("\nLA TRADUCCION DE %s es %s",
			_Modo == 1 ? palabra[i].ing : palabra[i].esp,
			_Modo == 1 ? palabra[i].esp : palabra[i].ing );

}


