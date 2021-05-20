#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <string>
using namespace std;

struct estadisticas{
	int cantidad_humanos;
	int cantidad_zombis;
	int cantidad_vampiros;
	int cantidad_cruces;
	int cantidad_estacas;
	int dosis_agua;
	int cantidad_balas;
	int cantidad_escopetas;
};

struct coordenadas{
	int vanesa_x;
	int vanesa_y;
	int nosferatu_x;
	int nosferatu_y;
	int vampirella_x;
	int vampirella_y;
	int vampiro_x;
	int vampiro_y;
	int zombi_x;
	int zombi_y;
	int humano_x;
	int humano_y;
	int humano_cv_x;
	int humano_cv_y;
	int cruz_x;
	int cruz_y;
	int estaca_x;
	int estaca_y;
	int agua_x;
	int agua_y;
	int escopeta_x;
	int escopeta_y;
	int bala_x;
	int bala_y;
};

//POST: Se muestra por pantalla un ascii art
void mostrar_titulo();

//POST: Se muestra por pantalla 3 opciones
void mostrar_opciones();

//POST: Se inicializaran en cero las coordenadas de cada personaje y objeto
void inicializar_coordenadas(coordenadas &region);

//POST: Se inicializaran en cero los contadores
void inicializar_estadisticas(estadisticas &datos);

//PRE: La estructuras vienen inicializadas
//POST: Se leera el archivo y se actualizaran los datos de las estructuras recibidas por parametro
void leer_archivo(estadisticas &datos, coordenadas &region);

//PRE: Las variables recibidad por parametro NO son negativas
//POST: La funcion devuelve NOROESTE, NORESTE, SUROESTE o SURESTE si las coordenadas cumplen el rango correspondiente
int determinar_region(int coordenada_x, int coordenada_y);

//POST: La funcion devuelve el porcentaje de humanos sobre el total
float porcentaje_humanos(estadisticas &region);

//POST: La funcion devuelve el porcentaje de los zombis
float porcentaje_zombis(estadisticas &region);

//POST: La función devuelve el porcentaje de las escopetas sobre el total
float porcentaje_escopeta(estadisticas &region);

//POST: La funcion devuelve el porcentaje de los vampiros
float porcentaje_vampiros(estadisticas &region);

//POST: La funcion devuelve el porcentaje de agua
float porcentaje_agua(estadisticas &region);

//POST: La funcion devuelve el porcentaje de las cruces
float porcentaje_cruces(estadisticas &region);

//POST: La funcion devuelve el porcentaje de las estacas
float porcentaje_estacas(estadisticas &region);

//POST: La funcion devuelve el porcentaje de las balas
float porcentaje_estacas(estadisticas &region);

//POST: Se mostrara por pantalla el resumen de la cantidad y porcentajes de los elementos
void mostrar_estadisticas(estadisticas &datos);

//POST: La funcion devuelve true si opcion es 1, 2, 3 o 4. False en caso contrario
bool validar_opcion(int &opcion);
//PRE: La variable opcion es un numero positivo
//POST: La funcion devuelve un numero entre 1 y 4 inclusive que representa la region elegida
int pedir_region(int &opcion);

//POST: La funcion devuelve true si el nombre recibido es valido. False en caso contrario
bool validar_nombre(string &nombre_recibido);

//POST: La funcion devuelve un nombre ingresado por el usuario
string pedir_nombre(string &nombre_recibido);

//PRE: Las variables son numeros positivos
//POST: Se muestra por pantalla 'Verdadero' si el personaje u objeto se encuentra en esa region, 'Falso' en caso contrario
void mostrar_respuesta(int &opcion, int retorno);

//PRE: La variable opcion es un numero positivo. La variable nombre recibido es una palabra valida
//POST: Le informa al usuario si su personaje u objeto buscado se encuentra o no en la region
void informar_usuario(int &opcion, string &nombre_recibido, coordenadas &region);

//POST: La funcion devuelve true si la variable eleccion es ESTADISTICAS, BUSCAR ELEMENTO o SALIR. False en caso contrario
bool validar_opciones_inicio(int eleccion);

//PRE: las variables opcion y nombre_recibido son validas
//POST: Se ejecutaran las funciones correspondientes dependiendo de la opcion ingresada por el usuario
void ejecutar_opciones(estadisticas &datos,coordenadas &region, int &opcion, string &nombre_recibido);

#endif /* ARCHIVO_H */
