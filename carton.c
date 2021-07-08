#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COLUM 5
#define FIL 3
#define RENGLON "\n\n-------------------------\n\n"
#include "carton.h"



struct CartonE{
	int c[FIL][COLUM];
};

////////////////////////////////////////////////////////CARGAR///////////////////////////////////////////////////

void cargarCartonSinRepetir(Carton car){
	int f,c,num;
	for(f=0;f<FIL;f++){
		for(c=0;c<COLUM;c++){
			num=1+rand()%90;
			while((existeEnCarton(car,num))==1){
				num=1+rand()%90;
			}
			car->c[f][c]=num;
		}
	}
}

void cargarCartones(Carton car[],int t){
	int i;
	for(i=0;i<t;i++){
		cargarCartonSinRepetir(car[i]);
	}
}

void cargarCartonesTeclado(Carton car[],int t){
    int i;
	for(i=0;i<t;i++){
		cargarCartonSinRepetirTeclado(car[i]);
	}
}

void cargarCartonSinRepetirTeclado(Carton car){
	int f,c,num;
    for(f=0;f<FIL;f++){
		for(c=0;c<COLUM;c++){
			printf("Ingrese el valor para la fila: %d columna: %d\n",f,c);
			scanf("%d",&num);
			while(num<1 || num>90){
				printf("Numero erroneo. Ingrese un numero entre 1 y 90: \n");
				scanf("%d",&num);
			}
			while((existeEnCarton(car,num))==1){
                    printf("Numero repetido. Ingrese un numero entre 1 y 90: \n");
                    scanf("%d",&num);
            }
            car->c[f][c] = num;
		}
	}
}





//////////////////////////////////////////////////INICIAR CARTON/CARTONES/////////////////////////////////////////////

void iniciarCartones(Carton car[], int t){
	int i;
	for(i=0;i<t;i++){
		car[i]=malloc(sizeof(struct CartonE));
		setearACero(car[i]);
	}
}





///////////////////////////////////////////////////////MOSTRAR//////////////////////////////////////////////////////////

void mostrarCarton(Carton car){
	int f,c;
	for(f=0;f<FIL;f++){
		for(c=0;c<COLUM;c++){

			if (car->c[f][c]<10){
                printf(" %d  |",car->c[f][c]);
            }
            if (car->c[f][c]>=10){
                printf(" %d |",car->c[f][c]);
            }
		}
		printf("\n");
	}
}

void mostrarCartones(Carton car[],int t){
	int i;
	for(i=0;i<t;i++){
		printf("--------carton %d--------\n",i+1);
		mostrarCarton(car[i]);
		printf(RENGLON);
	}
}




///////////////////////////////////////////////////ELEGIR CANT CARTONES/////////////////////////////////////////////////

int elegirCantCartones(){
	int cant=0;
	while(cant<1 || cant>3){

	printf("Ingrese la cantidad de cartones con los que jugara (maximo 3):\n");
	scanf("%d",&cant);

	}

	return cant;
}




///////////////////////////////////////////////////FUNCIONES AUXILIARES////////////////////////////////////////////////

int existeEnCarton(Carton car,int busco){
	int f,c,i;
	int pos=0;

	for(f=0;f<FIL;f++){
		for(c=0;c<COLUM;c++){
			if(car->c[f][c]==busco){
				pos=1;
			}
		}
	}
	return pos;
}

void buscador(Carton car,int busco){
	int f,c;

	for(f=0;f<FIL;f++){
		for(c=0;c<COLUM;c++){
			if(car->c[f][c]==busco){
				car->c[f][c]=0;
				printf("Se encontro la bolilla en un carton!!\n");
			}
		}
	}
}

void buscador2(Carton car[], int tam, int busco){
	int i;
	for(i=0;i<tam;i++){
		buscador(car[i],busco);
	}
}

void setearACero(Carton car){
	int f,c;
    for(f=0;f<FIL;f++){
        for(c=0;c<COLUM;c++){
            car->c[f][c]=0;
        }
    }
}



///////////////////////////////////////////////////FUNCIONES DE JUEGO////////////////////////////////////////////////////

void jugarBingo(Carton jug[], Carton maq[], int tam){

	int i,busqueda,aux;
	int cont = 0;
	int num[90];
	int puntosJug=0; ////
	int puntosMaq=0; ///
	int contLinea=0;
	int contColum=0;
	int contBingo=0;
	while(contBingo==0){

        iniciarBolsaConCero(num,90);
        for(i=0;i<90;i++){
            do{
            aux = 1+rand()%90;
            //me fijo sino se repite
            busqueda = busquedaSecuencial(num,90,aux);

            }
            //tirar numeros hasta que no se repita
            while(busqueda!=-1);
            //si da distinto de -1,quiere decir que no se repite. Entonces lo guardo
            num[i]=aux;
            //le sumo uno a contador,para saber la cantidad de numeros que van saliendo
            cont++;

            printf("\n\nNumero de bolillero: (%d)\n",num[i]);
            printf("\nJugador: ");
            buscador2(jug,tam,num[i]);
            printf("\nMaquina: ");
            buscador2(maq,tam,num[i]);   //hasta acá lo que haria es poner 0 si encuentra el numero que salió
            printf("\n-------------------------------Jugador---------------------------------\n\n");
            mostrarCartones(jug,tam);

            if((cantarLinea2(jug,tam))==5 && contLinea==0){
                printf("\nLINEAAA!!!!!!");
                puntosJug+=20;
                contLinea=1;
            }

            if((cantarColumna2(jug,tam))==3 && contColum==0){
                printf("\nCOLUMNA!!!!!!");
                puntosJug+=10;
                contColum=1;
            }

            if((cantarBingo2(jug,tam)==10) && contBingo==0){
                printf("\nBINGOOOOOOOOOOOOOO!!!!!!!!");
                puntosJug+=70;
                contBingo=1;
                if(contBingo == 1){
                    system("cls");
                    printf(RENGLON"\nFelicidades, Has Ganado el BINGO!!\n\n");
                    mostrarCartones(jug,tam);
                    printf("Presiona 'ENTER' para ver como quedo el carton de la maquina:\n\n");
                    getch();
                    mostrarCartones(maq,tam);
                    getch();
                    system("cls");
                    break;
                }

            }



            printf("\n-------------------------------Maquina---------------------------------\n\n");
            mostrarCartones(maq,tam);

            if((cantarLinea2(maq,tam))==5 && contLinea==0){
                printf("\nLINEAAA!!!!!");
                puntosMaq+=20;
                contLinea=1;
            }

            if((cantarColumna2(maq,tam))==3 && contColum==0){
                printf("\nCOLUMNA!!!!!!");
                puntosMaq+=10;
                contColum=1;
            }


            if((cantarBingo2(maq,tam)==10) && contBingo==0){
                printf("\nBINGOOOOOOOOOOOOOO!!!!!!!!");
                puntosMaq+=70;
                contBingo=1;
                if(contBingo == 1){
                    system("cls");
                    printf(RENGLON"\nHas perdido el BINGO, Vuelve a intentarlo!!\n\n");
                    mostrarCartones(maq,tam);
                    printf("Presiona 'ENTER' para ver como quedo tu carton:\n\n");
                    getch();
                    mostrarCartones(jug,tam);
                    getch();
                    system("cls");
                    break;
                }
            }

            getch();
            system("cls");


        }//cierre for


	}//cierre while


	printf("CANT NUMEROS: %d\n\n ",cont);
	//Multiplicaciones segun la cantidad de numeros que salieron
	if(cont<30){
        puntosJug= puntosJug * 2;
        puntosMaq= puntosMaq * 2;
	}
	if(cont>=30 && cont<50){

        puntosJug= puntosJug * 1.7;
        puntosMaq= puntosMaq * 1.7;
	}
	if(cont>=50 && cont<70){

        puntosJug= puntosJug * 1.5;
        puntosMaq= puntosMaq * 1.5;
	}
	//funcion que guarda el archivo------------------------------------
    if(contBingo == 1){

        FILE *puntero=fopen("Puntuaciones.txt","a");
        fprintf(puntero,"---------PUNTUACIONES TOTALES---------\n\nJugador:\n%d\nMaquina:\n%d\n\n",puntosJug,puntosMaq);
        fclose(puntero);
    }
}//cierre funcion

int cantarLinea2(Carton c[], int tam){
	int puntos=0;
	int i;
	for(i=0;i<tam;i++){
		if((cantarLinea(c[i]))==5){
			puntos=5;
			break;
		}
	}

	return puntos;
}

int cantarLinea(Carton car){
    int cont=0;
    int f,c;

	for(f=0;f<FIL;f++){
    	for(c=0;c<COLUM;c++){
        	if(car->c[f][c]==0){
            	cont = cont+1;
            }
        }
        if(cont==5){

            break;
        }
        else{
            cont = 0;
        }
    }

	return cont;
}

int cantarColumna2(Carton c[], int tam){
	int puntos=0;
	int i;
	for(i=0;i<tam;i++){
		if((cantarColumna(c[i]))==3){
			puntos=3;
			break;
		}
	}

	return puntos;
}

int cantarColumna(Carton car){
    int cont=0;
	int c,f;

	for(c=0;c<COLUM;c++){
    	for(f=0;f<FIL;f++){
        	if(car->c[f][c]==0){
            	cont = cont+1;
            }
		}
        if(cont==3){

            break;
        }
        else{
            cont = 0;
        }
    }

    return cont;
}

int cantarBingo2(Carton car[],int tam){
	int i;
	int puntos=0;
	for(i=0;i<tam;i++){
		if((cantarBingo(car[i]))==15){
			puntos=10;
			break;
		}
	}

	return puntos;
}

int cantarBingo(Carton car){
	int cont=0;
    int f,c;
    for(f=0;f<FIL;f++){
    	for(c=0;c<COLUM;c++){
        	if(car->c[f][c]==0){
            	cont = cont+1;
            }
        }

    }


	return cont;
}




//////////////////////////////////////////////////////FUNCIONES DE LA BOLSA/////////////////////////////////////////////////////////////

int busquedaSecuencial(int bol[], int t, int buscar){

    int pos = -1;
    int i;

    for (i=0; i<t; i++){
    	if ( bol[i]==buscar){ //Lo encontre
                pos = i;
        }
    }

    return pos;
}

void iniciarBolsaConCero(int bol[], int t){
	int i;
    for(i=0;i<t;i++){
        bol[i] = 0;

    }
}




//////////////////////////////////////////////////////////GETS//////////////////////////////////////////////////////////////////////////////

int getCarton(Carton car[], int CeroUnoODos){
	return car[CeroUnoODos]->c;
}



/////////////////////////////////////////////////////////SETS///////////////////////////////////////////////////////////////////////////////

void setCarton(Carton car[], int CeroUnoODos){
	printf("\nVuelva a ingresar los valores del carton elegido:\n");
	cargarCartonSinRepetirTeclado(car[CeroUnoODos]);
}
