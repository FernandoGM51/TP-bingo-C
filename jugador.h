#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#define COLUM 5
#define FIL 3
#define RENGLON "\n\n-------------------------\n\n"

struct JugadorE;

typedef struct JugadorE * Jugador;

/////////////////////////////////////////////////////CARGAR////////////////////////////////////////////////////////////////////////////

//PRE: Requiere un struct Jugador declarada en donde devolver el retorno de la función
//POST: Devuelve un struct Jugador con los datos solicitados por pantalla
Jugador cargarJugador();




/////////////////////////////////////////////////////MOSTRAR///////////////////////////////////////////////////////////////////////////

//PRE: Requiere una estructura Jugador declarada y cargada
//POST: Muestra por pantalla los datos cargados en la estructura Jugador cargada por parámetro
void mostrarJugador(Jugador jug);




///////////////////////////////////////////////////////GETS///////////////////////////////////////////////////////////////////////////

//PRE: Requiere una estructura Jugador declarada y cargada
//POST: Devuelve los datos cargados en la variable "nombre" de la estructura Jugador indicada por parámetro.
char * getNombre(Jugador j);

//PRE: Requiere una estructura Jugador declarada y cargada
//POST: Devuelve los datos cargados en la variable "dni" de la estructura Jugador indicada por parámetro.
int getDni(Jugador j);


////////////////////////////////////////////////////////SETS///////////////////////////////////////////////////////////////////////////

//PRE: Necesita un struct jugador y un arreglo de char
//POST: Setea la variable Nombre del struct ingresado por el arreglo de char ingresado
void setNombre(Jugador j, char nuevoNombre[]);

//PRE: Necesita un struct jugador y un entero
//POST: Setea la variable DNI del struct ingresado por el entero ingresado
void setDni(Jugador j, int nuevoDni);






#endif // JUGADOR_H_INCLUDED