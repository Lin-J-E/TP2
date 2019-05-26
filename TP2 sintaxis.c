#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct tNodo{
	char Info[5];
	struct tNodo *Siguiente;
}tNodo;


void push(tNodo**, char [5]);
void pop(tNodo**, char [5]);
bool verificaExpresion (char[20], char[6][6][5]);
bool esDelConjuntoPrimero (char);
void acomodarPila (char , tNodo**, char[6][6][5]);
int columnaDeCaracter (char);
int filaSegunDerivacion (char[3]);
//void calcularExpresion (char[]);
void cargarGICaAFP (char[6][6][5]);

int main(){
	char AFP[6][6][5];
	char expresion[20];
	short i = 0;
	cargarGICaAFP (AFP);

	printf("Ingrese expresión aritmética de suma y producto: ");
	scanf("%s", expresion);
	
	verificaExpresion(expresion, AFP);
	

	//;
/*
	if(verificaExpresion (expresion,AFD)){
		calcularExpresion (expresion);
	}
*/

	printf("%s", expresion);
	return 0;
}

void cargarGICaAFP (char p[6][6][5]){
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


bool verificaExpresion (char expresion[20], char AFP[6][6][5]){
	short c = 0;
	tNodo *Pila = NULL;
	
		
	
		
	if (Pila == NULL){
		if (esDelConjuntoPrimero (expresion[c])){
			push(&Pila, "E1");
			printf("%s Lo que hay dentor del puntero\n", Pila->Info);
			acomodarPila (expresion[c], &Pila,AFP);
		}else{
			return false;
		}
	}
	printf("%s Lo que hay dentro del puntero\n", Pila->Info);

	return true;

}


int columnaSegunCaracter (char caracter){
	switch (caracter){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': return 1;
		case '+': return 2;
		case '*': return 3;
		case '(': return 4;
	}		
};

bool esDelConjuntoPrimero (char caracter){
	return (columnaSegunCaracter(caracter) == 1 ||
			columnaSegunCaracter(caracter == 4));
};


int filaSegunDerivacion (char palabra[3]){
	if (palabra[0] == 'E'){
		if (palabra[1] == '1'){
			return 0;
		}else{
			return 1;
		}
	}
	if (palabra[0] == 'T'){
		if (palabra[1] == '1'){
			return 2;
		}else{
			return 3;
		}
	}
	if (palabra[0] == 'F'){
		return 4;
	}
	if (palabra[0] == 'N'){
		return 5;
	}
	
}


void acomodarPila (char caracter , tNodo **Pila, char AFP[6][6][5]){
	int columna = columnaSegunCaracter (caracter);
	char estado[3];
	pop(Pila, estado);
	int fila = filaSegunDerivacion (estado);
	printf("%s\nArriba debería de aparecer E1\n", estado);
	
	if (AFP[fila][columna][2] != '\0'){
		memcpy (estado, &AFP[fila][columna][2], 2);
		printf("%s\nArriba debería de aparecer E2\n", estado);
	}
	push(Pila, estado);
};

