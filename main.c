#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carton.h"
#include "jugador.h"


int main()
{


    srand(time(NULL));

	
	int cantCartones;
	int iniciarJuego=1;

	Jugador j1;
	//modificacion

	//---------------------NUEVO MENU Sabado 31/10----------------------------------------------


   while(iniciarJuego==1){

	printf("�����BIENVENIDOS AL BINGO!!!!!\n\n");
	printf("Presione 'ENTER' para continuar\n");
	getchar();
	system("cls");

	printf("Ingreso de datos\n");
	j1=cargarJugador();
	getchar();
	system("cls");
	printf("Bien! Ahora elija la cantidad de cartones(La maquina jugara con la misma cantidad que usted)\n");

	cantCartones=elegirCantCartones();
	//Una vez que elijo la cantidad de cartones, creo los cartones
	Carton cartonJugador[cantCartones];
	Carton cartonMaquina[cantCartones];

	//system("cls");
	//inicio los cartones en 0
            iniciarCartones(cartonJugador,cantCartones);
			iniciarCartones(cartonMaquina,cantCartones);

			//CARGO LOS CARTONES
			int opcion;
			do{
                printf("\n1- Carga manual. 2- Carga aleatoria\n\n");
                scanf("%d",&opcion);
			}
			while(opcion<1 || opcion>2);
			//una vez que lee la opcion, entra al switch,y dependiendo la opcion que eligio el Jugador, se cargan los cartones.
            switch(opcion){
                case 1:
                    cargarCartonesTeclado(cartonJugador,cantCartones);
                    cargarCartones(cartonMaquina,cantCartones);
                break;

                case 2:
                    cargarCartones(cartonJugador,cantCartones);
                    cargarCartones(cartonMaquina,cantCartones);
            }
            //se muestran los cartones
            printf("\nJUGADOR:\n");
            mostrarCartones(cartonJugador,cantCartones);
            printf("\nMAQUINA:\n");
            mostrarCartones(cartonMaquina,cantCartones);

            //arranca el juego, que finaliza cuando algun carton se llena y canta BINGO
            printf("\nPRESIONA 'ENTER' PARA EMPEZAR EL JUEGO\n\n");
            getch();
            system("cls");
            jugarBingo(cartonJugador,cartonMaquina,cantCartones);

            //mensajes y puntajes finales
            printf("\n\nTERMINO EL JUEGO\n\nGracias por participar!\n\n");
            printf("\n\n1-Nuevo juego || 2-Salir\n\n");
            scanf("%d",&iniciarJuego);

   }

    return 0;
}

