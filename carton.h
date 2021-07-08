#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#define COLUM 5
#define FIL 3
#define RENGLON "\n\n-------------------------\n\n"

struct CartonE;

typedef struct CartonE * Carton;

////////////////////////////////////////////////CARGAR/////////////////////////////////////////////////////////////////////

//PRE: Necesita un elemento struct Carton
//POST: Carga una struct Carton simple con números aleatorios del 1 al 90
void cargarCartonSinRepetir(Carton car);   

//PRE: Necesita un arreglo de struct Carton y su tamaño en entero
//POST: Carga un array de struct Carton con numeros aleatorios del 1 al 90.
void cargarCartones(Carton car[],int t);        

//PRE: Necesita un arreglo de struct Carton y su tamaño en entero
// Carga un array de struct Carton con los números elegidos por el usuario del 1 al 90.
void cargarCartonesTeclado(Carton car[],int t);   

//PRE: Necesita un elemento struct Carton
// Carga el elemento con los numeros ingresados por el usuario del 1 al 90.
void cargarCartonSinRepetirTeclado(Carton car); 





////////////////////////////////////////////////////INICIAR CARTON/CARTONES///////////////////////////////////////////////////////

//PRE: Necesita un arreglo de struct Carton y su tamaño en entero
//POST: Guarda espacio en memoria con "malloc" y llama a la función setear a 0
void iniciarCartones(Carton car[], int t); 





///////////////////////////////////////////////////MOSTRAR//////////////////////////////////////////////////////////////

//PRE: Necesita un struct Carton simple
//POST: Muestra el contenido de la matriz de una estructura Carton simple
void mostrarCarton(Carton car); 

//PRE: Necesita un arreglo de struct Carton y su tamaño en entero
//POST: Muestra el contenido de la matriz de un array de tipo Carton
void mostrarCartones(Carton car[],int t); 




/////////////////////////////////////////////////////ELEGIR CANT CARTONES//////////////////////////////////////////////////////

//PRE: Requiere tener declarada una variable de tipo entero donde se va a guardar lo que retorne la función
//POST: Retorna la cantidad de cartones que elije el usuario.
int elegirCantCartones(); 




///////////////////////////////////////////////////FUNCIONES AUXILIARES////////////////////////////////////////////////////////

//PRE: Necesita un struct Carton simple y en valor entero lo que se desea buscar dentro de la matriz c
//POST: Devuelve "1" si encuentra el valor buscado o "0" si no lo encontró
int existeEnCarton(Carton car,int busco); 

//PRE: Necesita un struct Carton simple y en valor entero lo que se desea buscar dentro de la matriz c
//POST: Emite un msj al usuario si se encontró esa "bolilla" en el cartón y coloca un "0" en la posición donde se lo encontró
void buscador(Carton car,int busco); 

//PRE: Necesita un arreglo de struct Carton, su tamaño en entero y lo que busco también en entero
//POST: Llama en su interior a la función buscador una cantidad de veces determinada por el parámetro "tam", buscando lo que se coloque en "busco"
void buscador2(Carton car[], int tam, int busco); 

//PRE: Necesita un struct Carton simple
//POST: Llena la matriz de la estructura Carton con valor "0"
void setearACero(Carton car); 




///////////////////////////////////////////////////////FUNCIONES DE JUEGO////////////////////////////////////////////////////////////

//PRE: Necesita dos arrays de tipo struct Carton diferentes y su tamaño en entero.(tienen que tener el mismo tamaño los arrays)
//POST: Función principal. Función que va llamando en su interior a todas las funciones de juego y ejecutando el mismo.
void jugarBingo(Carton jug[], Carton maq[], int tam); 

//PRE: Necesita un array de tipo struct Carton y su tamaño en entero
//POST: Devuelve "5" si la función interior(cantarLinea) tmb retorna 5. Y devuelve 0 si la función interior devuelve otro valor distinto.
int cantarLinea2(Carton c[], int tam); 

//PRE: Necesita un struct Carton simple
//POST: Devuelve 5 si encontró cinco ceros en una linea de la matriz de la struct
int cantarLinea(Carton car); 

//PRE: Necesita un array de tipo struct Carton y su tamaño en entero
//POST: Devuelve "3" si la función interior(cantarColumna) tmb retorna "3". Y devuelve "0" si la función interior devuelve otro valor distinto.
int cantarColumna2(Carton c[], int tam); 

//PRE: Necesita un struct Carton simple
//POST: Devuelve "3" si encontró tres ceros en una columna de la matriz de la struct
int cantarColumna(Carton car); 

//PRE: Necesita un array de tipo struct Carton y su tamaño en entero
//POST: Devuelve "10" si la función interior(cantarBingo) retorna "15". Y devuelve "0" si la función interior devuelve otro valor distinto.
int cantarBingo2(Carton car[],int tam); 

//PRE: Necesita un struct Carton simple
//POST: Devuelve el valor de la cantidad de veces que encontró un "0" en la matriz de la struct Carton
int cantarBingo(Carton car); 





//////////////////////////////////////////////////////FUNCIONES DE LA BOLSA/////////////////////////////////////////////////////////////

//PRE: Necesita un vector de numeros enteros ya declarado, su tamaño en entero y tambien en entero el valor a buscar
//POST: Devuelve la posición de lo buscado. Si no lo encuentra, devuelve "-1"
int busquedaSecuencial(int bol[], int t, int buscar);

//PRE: Necesita un vector de numeros enteros ya declarado y su tamaño en entero
//POST: Coloca el valor "0" en todas las posiciones del vector.
void iniciarBolsaConCero(int bol[], int t);





//////////////////////////////////////////////////////////GETS//////////////////////////////////////////////////////////////////////////////

//PRE: Requiere un array de tipo struct Carton y el indice del elemento que se quiere ver
//POST: Devuelve el cartón solicitado
int getCarton(Carton car[], int UnoDosOTres);



/////////////////////////////////////////////////////////SETS///////////////////////////////////////////////////////////////////////////////

//PRE: Requiere un array de tipo struct Carton y el indice del elemento que se quiere ver
//POST: Modifica, con peticón por teclado, los valores del elemento elegido de la estructura Carton ingresada.
void setCarton(Carton car[], int CeroUnoODos);




#endif // CARTON_H_INCLUDED