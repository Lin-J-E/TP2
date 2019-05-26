#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct tNodo{
	char Info[5];
	struct tNodo *Siguiente;
}tNodo;


void push(tNodo**, char [5]);
void pop(tNodo**, char [5]);
//bool verificaExpresion (char[]);
//void calcularExpresion (char[]);
void cargarGICaAFD (char[6][6][5]);

int main(){
	char AFD[6][6][5];
	char expresion[20];

	cargarGICaAFD (AFD);

	printf("Ingrese expresión aritmética de suma y producto: ");
	scanf("%s", expresion);

	
/*
	if(verificaExpresion (expresion,AFD)){
		calcularExpresion (expresion);
	}
*/

	printf("%s", expresion);
	return 0;
}

void cargarGICaAFD (char p[6][6][5]){
	//	T.T.	             {0,1,2,...,9}	                +	                    *	                    (	                L
	strcpy(p[0][0],"E1"); strcpy(p[0][1],"T1E2"); p[0][2][0] ='\0';       p[0][3][0] ='\0';       strcpy(p[0][4],"T1E2"); p[0][5][0] ='\0';
	strcpy(p[1][0],"E2"); p[1][1][0] ='\0';   	  strcpy(p[1][2],"T1E2"); p[1][3][0] ='\0';       p[1][4][0] ='\0';       strcpy(p[1][5],"e");
	strcpy(p[2][0],"T1"); strcpy(p[2][1],"F1T2"); p[2][2][0] ='\0';       p[2][3][0] ='\0';       strcpy(p[2][4],"F1T2"); p[2][5][0] ='\0';
	strcpy(p[3][0],"T2"); p[3][1][0] ='\0';       p[3][2][0] ='\0';       strcpy(p[3][3],"F1T2"); p[3][4][0] ='\0';       strcpy(p[3][5],"e");
	strcpy(p[4][0],"F1"); strcpy(p[4][1],"N");    p[4][2][0] ='\0';       p[4][3][0] ='\0';       strcpy(p[4][4],"E1)");  p[4][5][0] ='\0';
	strcpy(p[5][0],"N");  strcpy(p[5][1],"e");    p[5][2][0] ='\0';       p[5][3][0] ='\0';       p[5][4][0] ='\0';       p[5][5][0] ='\0';
}

void push (tNodo* *Pila, char valor[5]){
	tNodo* nuevoNodo = malloc(sizeof(tNodo));
	strcpy(nuevoNodo->Info, valor);
	nuevoNodo->Siguiente = (*Pila);
	(*Pila) = nuevoNodo;
}

void pop (tNodo* *Pila, char valor[5]){
	tNodo* nodoAuxiliar = (*Pila);
	strcpy(valor, nodoAuxiliar->Info);
	(*Pila) = nodoAuxiliar->Siguiente;
	free (nodoAuxiliar);
}

/*
bool verificaExpresion (char expresion[], char[6],[6],[5]){

}
*/
