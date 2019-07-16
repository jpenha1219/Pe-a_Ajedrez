#include <stdlib.h>
#include <stdio.h>
#include "chess.h"
#include <string.h>




int cont_filas(char** c1)
{
	int cont = 0;
	while(c1[cont] != 0)
	{
		cont++;

	}
	return cont;
}

int cont_col(char* c1)
{
	int cont = 0;
	while(c1[cont] != 0)
	{
		cont++;

	}
	return cont;
}
//crea una imagen que representa un negativo de la imagen original
char** reverse(char** c1)
{
	
	
	int filas = cont_filas(c1);
	char** rev = (char**) malloc((filas+1)*sizeof(char*));
	
	for(int i=0; i<filas;i++)
	{
		int col = cont_col(c1[i]);
		rev[i] = (char*) malloc(col*sizeof(char));
	}
	for( int i =0; c1[i]!=0;i++){
		for( int j = 0; c1[i][j]!=0;j++){
			switch(c1[i][j])
			{
				case '_':
					rev[i][j] = '=';
					break;
					
				case '=':
					rev[i][j] = '_';
					break;
					
				case '.':
					rev[i][j] = '@';
					break;
					
				case '@':
					rev[i][j] = '.';
					break;
				
				default:
					rev[i][j] = c1[i][j];
					break;
			}

		}

	}
	
	return rev;
}

char** repeatH(char** c1, int n)
{
	int filas = cont_filas(c1);
	char** rev = (char**) malloc((filas+1)*sizeof(char*));
	
	for(int i=0; i<filas;i++)
	{
		int col = cont_col(c1[i]);
		rev[i] = (char*) malloc(n*col*sizeof(char));
	}
	
	int i=0;
	int j=0;
	for( int i =0; c1[i]!=0;i++){
		for( int j = 0; c1[i][j]!=0;j++){
			for(int k=0;k<n;k++)
			{
				rev[i][j+k*cont_col(c1[i])]=c1[i][j];
			}	
		}
	}
	return rev;
}

char** repeatV(char** c1, int n)
{
	int filFig=cont_filas(c1);
	int filas=filFig*n;
	int columnas=cont_col(c1[0]);

	char** resp=(char**)malloc(sizeof(char*)*(filas+1));
	
	for(int i=0;i<filas;++i){
		resp[i]=(char*)malloc(sizeof(char)*(columnas+1));
	}
	for(int i=0;i<filas;++i){
		for(int j=0;j<columnas;++j){

			resp[i][j]=c1[i%filFig][j];
		}
		resp[i][columnas]=0;
	}
	resp[filas]=0;

	return resp;
}
char** rotateR(char** c1){
	int filas=cont_filas(c1);
	int col=cont_col(c1[1]);
	//Creacion de puntero doble cuadrado
	char** rpta = (char**)malloc(sizeof (char *)* filas);
	//designacion de cada fila
	for (int i = 0; i < filas; i++)
		rpta[i] = (char*)malloc(sizeof(char) * col);
	//Poniendo cada posicion en la nueva ubicacion
	for(int i = 0; i < 58; i++){
		for(int j = 0; j < 58; j++){
			rpta[i][j] = c1[57-j][i];
		}
	}
	return rpta;
}
char** rotateL(char** c1){
	int filas=cont_filas(c1);
	int col=cont_col(c1[1]);

	//Creacion de puntero doble cuadrado
	char** rpta = (char**)malloc(sizeof (char *)* filas);

	//designacion memoria de cada fila
	for (int i = 0; i < 58; i++)
		rpta[i] = (char*)malloc(sizeof(char) * col);

	//Poniendo cada posicion en la nueva ubicacion
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < col; j++){
			rpta[i][j] = c1[j][57-i];
		}
	}
	return rpta;
}




char** flipH(char** c1)
{
	int filas = cont_filas(c1);
	int col = cont_col(c1[0]);
	
	char** rev = (char**) malloc((filas+1)*sizeof(char*));
	for(int i=0; i<filas;i++)
		rev[i] = (char*) malloc(col*sizeof(char));
	
	for(int i=0;i<filas;i++)
	{
		for(int j=0;j<col;j++)
		{
			rev[i][j]=c1[filas-i-1][j];
		}
	}
	
	return rev;
}

char** flipV(char** c1)
{
	int filas = cont_filas(c1);
	int col = cont_col(c1[0]);
	
	char** rev = (char**) malloc((filas+1)*sizeof(char*));
	for(int i=0; i<filas;i++)
		rev[i] = (char*) malloc(col*sizeof(char));
	
	for(int i=0;i<filas;i++)
	{
		for(int j=0;j<col;j++)
		{
			rev[i][j]=c1[i][col-j-1];
		}
	}
	
	return rev;
}


char** superImpose(char** c1,char** c2){
	int filas = cont_filas(c1);
	int col = cont_col(c1[0]);
	//filas
	for(int i=0;i<filas;i++){
		char* aux = *(c1+i);
		char* aux2 = *(c2+i);
		char* aux3 = (char*) malloc(sizeof(char)*col);
		//columnas
		for(int j=0;j<col;j++){
			aux3[j] = *(aux+j);
		}
		//columnas
		for(int k=0;k<col;k++){
			if(aux3[k]==' '){
				aux3[k] = *(aux2+k);
			}		
		}
		c1[i]=aux3;
	}
	return c1;
}

char** up(char** c1, char** c2)
{
	int filas1 = cont_filas(c1);
	int filas2 = cont_filas(c2);
	
	char** rev = (char**) malloc((filas1+filas2+1)*sizeof(char*));
	for(int i=0;i<filas1;i++)
		rev[i] = (char*) malloc(cont_col(c1[i])*sizeof(char));
	for(int i=filas1;i<filas1+filas2;i++)
		rev[i] = (char*) malloc(cont_col(c2[i-filas1])*sizeof(char));
				
	for(int i=0;i<filas1;i++)
	{
		for(int j=0;j<cont_col(c1[i]);j++)
		{
			rev[i][j] = c1[i][j];
		}
	}
	for(int i=filas1;i<filas1+filas2;i++)
	{
		for(int j=0;j<cont_col(c2[i-filas1]);j++)
		{
			rev[i][j] = c2[i-filas1][j];
		}
	}
	
	return rev;
}

char** join(char** c1, char** c2){

	int col1,col2,filas;
	col1=cont_col(c1[0]);
	col2=cont_col(c2[0]);
	filas=cont_filas(c1);

	char** rsp;
	int AllCol = col1+col2;
	rsp=(char**)malloc(sizeof(char*)*(filas+1));

	for(int i=0;i<filas;i++){
		rsp[i]=(char*)malloc(sizeof(char)*(AllCol+1));
	}

	for(int i=0;i<filas;i++){
		for(int j=0;j<AllCol;j++){
			rsp[i][j]=c1[i][j];
			if(j>=col1){
				rsp[i][j]=c2[i][j-col1];
			}
		}
		rsp[i][AllCol]=0;
	}
	rsp[filas]=0;

	return rsp;
} 
void imprimir(char** fichas)
{
	int i=0;
	int j=0;
	int j2=0;

	while(fichas[i]!=0)
	{
		while(fichas[i][j]!=0)
		{
			printf("%c",fichas[i][j]);
			j++;
		}
		i++;
		j2 = j;
		j=0;
	}
	
}
