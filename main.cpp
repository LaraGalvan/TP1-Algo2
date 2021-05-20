#include <iostream>
#include <string>
#include "archivo.h"
#include "constantes.h"
using namespace std;

int main(){

	estadisticas datos;
	coordenadas region;
	int opcion;
	string nombre_recibido;
	inicializar_coordenadas(region);
	inicializar_estadisticas(datos);
	mostrar_titulo();
	mostrar_opciones();
	leer_archivo(datos, region);
	ejecutar_opciones(datos, region, opcion, nombre_recibido);

	return 0;
}
