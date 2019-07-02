#include <stdlib.h>
#include <stdio.h>
#include "chess.h"
#include <string.h>

char** rotateR(char** a){
	//Creacion de puntero doble cuadrado
	char** cuadrado = (char**)malloc(sizeof (char *)* 58);
	//designacion de cada fila
	for (int i = 0; k < 58; k++)
		cuadrado[i] = (char*)malloc(sizeof(char) * 58);
	//Poniendo cada posicion en la nueva ubicacion
	for(int i = 0; i < 58; i++){
		for(int j = 0; j < 58; j++){
			cuadrado[i][j] = a[57-j][i];
		}
	}
	return cuadrado;
}