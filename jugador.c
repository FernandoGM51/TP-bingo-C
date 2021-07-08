#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "carton.h"
#include "jugador.h"
#define COLUM 5
#define FIL 3
#define RENGLON "\n\n-------------------------\n\n"

struct JugadorE{
	char nombreYapellido[40];
	int dni;
};


/////////////////////////////////////////////////////CARGAR////////////////////////////////////////////////////////////////////////////

Jugador cargarJugador(){
    Jugador j = malloc(sizeof(struct JugadorE));
    char aux[40];
    printf("Ingrese su nombre y apellido:\n");
    fflush(stdin);
    gets(aux);
    fflush(stdin);
    strcpy(getNombre(j),aux);
    printf("Ingrese su DNI:\n");
    scanf("%d",&j->dni);

    return j;
};



/////////////////////////////////////////////////////MOSTRAR//////////////////////////////////////////////////////////////////////////

void mostrarJugador(Jugador j){

    printf("--------Jugador-------\n\n\nNombre y apellido: %s\nDNI: %d",getNombre(j),getDni(j));
}




///////////////////////////////////////////////////////GETS///////////////////////////////////////////////////////////////////////////

char * getNombre(Jugador j){
    return j->nombreYapellido;
}

int getDni(Jugador j){
    return j->dni;
}



////////////////////////////////////////////////////////SETS///////////////////////////////////////////////////////////////////////////

void setNombre(Jugador j, char nuevoNombre[]){
	strcpy(j->nombreYapellido, nuevoNombre);
}

void setDni(Jugador j, int nuevoDni){
	j->dni=nuevoDni;
}

