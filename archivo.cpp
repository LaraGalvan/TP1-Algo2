#include "constantes.h"
#include "archivo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void inicializar_coordenadas(coordenadas &region){
	region.vanesa_x = 0;
	region.vanesa_y = 0;
	region.humano_x = 0;
	region.humano_y = 0;
	region.humano_cv_x = 0;
	region.humano_cv_y = 0;
	region.nosferatu_x = 0;
	region.nosferatu_y = 0;
	region.vampirella_x = 0;
	region.vampirella_y = 0;
	region.zombi_x = 0;
	region.zombi_y = 0;
	region.vampiro_x = 0;
	region.vampiro_y = 0;
	region.agua_x = 0;
	region.agua_y = 0;
	region.cruz_x = 0;
	region.cruz_y = 0;
	region.escopeta_x = 0;
	region.escopeta_y = 0;
	region.estaca_x = 0;
	region.estaca_y = 0;
	region.bala_x = 0;
	region.bala_y = 0;
}

void inicializar_estadisticas(estadisticas &datos){
	datos.cantidad_humanos = 0;
	datos.cantidad_zombis = 0;
	datos.cantidad_vampiros = 0;
	datos.cantidad_cruces = 0;
	datos.cantidad_estacas = 0;
	datos.dosis_agua = 0;
	datos.cantidad_balas = 0;
	datos.cantidad_escopetas = 0;
}

void mostrar_titulo(){
	cout << endl;
	cout << "'##::: ##::'#######:::'######::'########:'########:'########:::::'###::::'########:'##::::'##:" << endl;
	cout << " ###:: ##:'##.... ##:'##... ##: ##.....:: ##.....:: ##.... ##:::'## ##:::... ##..:: ##:::: ##:" << endl;
	cout << " ####: ##: ##:::: ##: ##:::..:: ##::::::: ##::::::: ##:::: ##::'##:. ##::::: ##:::: ##:::: ##:" << endl;
	cout << " ## ## ##: ##:::: ##:. ######:: ######::: ######::: ########::'##:::. ##:::: ##:::: ##:::: ##:" << endl;
	cout << " ##. ####: ##:::: ##::..... ##: ##...:::: ##...:::: ##.. ##::: #########:::: ##:::: ##:::: ##:" << endl;
	cout << " ##:. ###: ##:::: ##:'##::: ##: ##::::::: ##::::::: ##::. ##:: ##.... ##:::: ##:::: ##:::: ##:" << endl;
	cout << " ##::. ##:. #######::. ######:: ##::::::: ########: ##:::. ##: ##:::: ##:::: ##::::. #######::" << endl;
	cout << "..::::..:::.......::::......:::..::::::::........::..:::::..::..:::::..:::::..::::::.......:::" << endl;
	cout << endl;
}

void mostrar_opciones(){
	cout << " .   ____ ____ ___ ____ ___  _ ____ ___ _ ____ ____ ____" << endl;
	cout << "´|   |___ [__   |  |__| |  | | [__   |  | |    |__| [__ " << endl;
	cout << "_|_  |___ ___]  |  |  | |__/ | ___]  |  | |___ |  | ___]" << endl;
	cout << " _   ___  _  _ ____ ____ ____ ____  ____ _    ____  _ _  ____ ____ ___ ____" << endl;
	cout << "´_)  |__] |  | [__  |    |__| |__/  |___ |    |___ | V | |___ |  |  |  |  |" << endl;
	cout << "/__  |__] |__| ___] |___ |  | |  |  |___ |___ |___ |   | |___ |  |  |  |__|" << endl;
	cout << "__   ____ ____ _    _ ____ " << endl;
	cout << " _|  [__  |__| |    | |__/ " << endl;
	cout << "__|  ___] |  | |___ | |  | " << endl;
	cout << endl;
}

void leer_archivo(estadisticas &datos, coordenadas &region){

	ifstream archivo;
	archivo.open(ARCHIVO_ESTADO);
	string palabra;

	if (!archivo){
		cout << ERROR_ABRIR_ARCHIVO << endl;
	}

	while(getline(archivo, palabra)){

		stringstream ss(palabra);
		string elemento;
		int cantidad_dosis_agua, cantidad_balas;
		int coordenada_x, coordenada_y;

		getline(ss, elemento, ESPACIO);

		if(elemento == HUMANO){
			(datos.cantidad_humanos)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.humano_x = coordenada_x;
			region.humano_y = coordenada_y;

		}
		else if(elemento == VANESA){
			(datos.cantidad_humanos)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.vanesa_x = coordenada_x;
			region.vanesa_y = coordenada_y;
		}
		else if(elemento == HUMANO_CV){
			(datos.cantidad_humanos)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.humano_cv_x = coordenada_x;
			region.humano_cv_y = coordenada_y;
		}
		else if(elemento == ZOMBI){

			(datos.cantidad_zombis)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.zombi_x = coordenada_x;
			region.zombi_y = coordenada_y;
		}
		else if(elemento == VAMPIRO){
			(datos.cantidad_vampiros)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.vampiro_x = coordenada_x;
			region.vampiro_y = coordenada_y;

		}
		else if(elemento == NOSFERATU){
			(datos.cantidad_vampiros)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.nosferatu_x = coordenada_x;
			region.nosferatu_y = coordenada_y;
		}
		else if(elemento == VAMPIRELLA){
			(datos.cantidad_vampiros)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.vampirella_x = coordenada_x;
			region.vampirella_y = coordenada_y;
		}
		else if(elemento == CRUZ){

			(datos.cantidad_cruces)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.cruz_x = coordenada_x;
			region.cruz_y = coordenada_y;

		}
		else if(elemento == ESCOPETA){

			(datos.cantidad_escopetas)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.escopeta_x = coordenada_x;
			region.escopeta_y = coordenada_y;

		}
		else if(elemento == ESTACA){

			(datos.cantidad_estacas)++;
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.estaca_x = coordenada_x;
			region.estaca_y = coordenada_y;

		}
		else if(elemento == AGUA){
			ss >> cantidad_dosis_agua;
			(datos.dosis_agua) += cantidad_dosis_agua;
			getline(ss, elemento, ESPACIO);
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.agua_x = coordenada_x;
			region.agua_y = coordenada_y;

		}
		else if(elemento == BALA){
			ss >> cantidad_balas;
			(datos.cantidad_balas) += cantidad_balas;
			getline(ss, elemento, ESPACIO);
			getline(ss, elemento, '(');
			ss >> coordenada_x;
			getline(ss, elemento, ',');
			getline(ss, elemento, ESPACIO);
			ss >> coordenada_y;
			region.bala_x = coordenada_x;
			region.bala_y = coordenada_y;
		}
	}
	archivo.close();
}

int determinar_region(int coordenada_x, int coordenada_y){

	int retorno = 0;

	if((coordenada_x >= LIMITE_INICIAL && coordenada_x <= ANCHO_FINAL_NO) && (coordenada_y >= LIMITE_INICIAL && coordenada_y <= ALTO_FINAL_NO)){
		retorno = NOROESTE;
	}
	else if((coordenada_x >= ANCHO_INICIAL_NE && coordenada_x <= ANCHO_FINAL_NE) && (coordenada_y >= LIMITE_INICIAL && coordenada_y <= ALTO_FINAL_NE)){
		retorno = NORESTE;
	}
	else if((coordenada_x >= LIMITE_INICIAL && coordenada_x <= ANCHO_FINAL_SO) && (coordenada_y >= ALTO_INICIAL_SO && coordenada_y <= ALTO_FINAL_SO)){
		retorno = SUROESTE;
	}
	else if((coordenada_x >= ANCHO_INICIAL_SE && coordenada_x <= ANCHO_FINAL_SE) && (coordenada_y >= ALTO_INICIAL_SE && coordenada_y <= ALTO_FINAL_SE)){
		retorno = SURESTE;
	}
	return retorno;
}

float porcentaje_humanos(estadisticas &datos){
	return (((float)datos.cantidad_humanos *100) / (datos.cantidad_humanos + datos.cantidad_zombis + datos.cantidad_vampiros));
}

float porcentaje_zombis(estadisticas &datos){
	return (((float)datos.cantidad_zombis * 100)/(datos.cantidad_humanos+datos.cantidad_zombis+datos.cantidad_vampiros));
}

float porcentaje_escopeta(estadisticas &datos){
	return (((float)datos.cantidad_escopetas*100) / datos.cantidad_balas);
}

float porcentaje_vampiros(estadisticas &datos){
	return (((float)datos.cantidad_vampiros*100) / (datos.cantidad_humanos+datos.cantidad_vampiros+datos.cantidad_zombis));
}

float porcentaje_agua(estadisticas &datos){
	return (((float)datos.dosis_agua*100)/(datos.cantidad_estacas+datos.dosis_agua+datos.cantidad_cruces));
}

float porcentaje_cruces(estadisticas &datos){
	return (((float)datos.cantidad_cruces*100)/(datos.cantidad_cruces+datos.dosis_agua+datos.cantidad_estacas));
}

float porcentaje_estacas(estadisticas &datos){
	return (((float)datos.cantidad_estacas*100)/(datos.cantidad_estacas+datos.dosis_agua+datos.cantidad_escopetas));
}

float porcentaje_balas(estadisticas &datos){
	return (((float)datos.cantidad_balas*100)/datos.cantidad_escopetas);
}

void mostrar_estadisticas(estadisticas &datos){

	float porc_escopeta= porcentaje_escopeta(datos);
	float porc_humanos = porcentaje_humanos(datos);
	float porc_zombis = porcentaje_zombis(datos);
	float porc_vampiros = porcentaje_vampiros(datos);
	float porc_agua = porcentaje_agua(datos);
	float porc_cruces = porcentaje_cruces(datos);
	float porc_estacas = porcentaje_estacas(datos);
	float porc_balas = porcentaje_balas(datos);
	cout << endl;
	cout << RESUMEN_ELEMENTO << setw(19) << RESUMEN_CANTIDAD << setw(19) << RESUMEN_PORCENTAJE << endl;
	cout << "----------------------------------------------" << endl;
	cout << RESUMEN_HUMANOS << setw(16) << datos.cantidad_humanos << setw(19) << porc_humanos << endl;
	cout << RESUMEN_ZOMBIS+ESPACIO << setw(16) << datos.cantidad_zombis << setw(19) << porc_zombis << endl;
	cout << RESUMEN_VAMPIROS << setw(15) << datos.cantidad_vampiros << setw(19) << porc_vampiros << endl;
	cout << RESUMEN_AGUA << setw(12) << datos.dosis_agua << setw(18) << porc_agua << endl;
	cout << RESUMEN_CRUCES+ESPACIO << setw(16) << datos.cantidad_cruces << setw(19) << porc_cruces << endl;
	cout << RESUMEN_ESTACAS+ESPACIO << setw(15) << datos.cantidad_estacas << setw(19) << porc_estacas << endl;
	cout << RESUMEN_ESCOPETAS << setw(14) << datos.cantidad_escopetas << setw(19) << porc_escopeta << endl;
	cout << RESUMEN_BALAS << setw(18) << datos.cantidad_balas << setw(19) << porc_balas << endl;
	cout << endl;
}

bool validar_opcion(int &opcion){
	return ((opcion == NOROESTE) || (opcion == NORESTE) || (opcion == SUROESTE) || (opcion == SURESTE) || (opcion == TERMINAR));
}
int pedir_region(int &opcion){
	cout << endl;
	cout << "------------- BUSQUEDA DE PERSONAJE/OBJETO -------------" << endl;
	cout << endl;
	cout << "\t\t 1) NOROESTE" << endl;
	cout << "\t\t 2) NORESTE" << endl;
	cout << "\t\t 3) SUROESTE" << endl;
	cout << "\t\t 4) SURESTE" << endl;
	cout << endl;
	cout << "Ingrese la region donde buscar | cero(0) para terminar:  ";
	cin >> opcion;
	while(!validar_opcion(opcion)){
		cout << "OPCION INCORRECTA! Por favor ingrese nuevamente: ";
		cin >> opcion;
	}
	return opcion;
}

bool validar_nombre(string &nombre_recibido){
	return ((nombre_recibido == VANESA) || (nombre_recibido == NOSFERATU) || (nombre_recibido == HUMANO) || (nombre_recibido == VAMPIRELLA)
			|| (nombre_recibido == ZOMBI) || (nombre_recibido == VAMPIRO) || (nombre_recibido == HUMANO_CV) || (nombre_recibido == AGUA)
			|| (nombre_recibido == ESCOPETA) || (nombre_recibido == ESTACA) || (nombre_recibido == CRUZ) || (nombre_recibido == BALA));
}

string pedir_nombre(string &nombre_recibido){

	cout << "\nIngrese el nombre de la persona u objeto" << endl;
	cout << "AVISO! Nombre --> 1ra letra en mayuscula || Objeto --> todo en minuscula: ";
	cin >> nombre_recibido;
	while(!validar_nombre(nombre_recibido)){
		cout << "NOMBRE INVALIDO! Ingrese nuevamente: ";
		cin >> nombre_recibido;
	}
	return nombre_recibido;
}

void mostrar_respuesta(int &opcion, int retorno){
	if(opcion == NOROESTE){
		if(retorno == NOROESTE){
			cout << "Verdadero" << endl;
		}
		else{
			cout << "Falso" << endl;
		}
	}
	else if(opcion == NORESTE){
		if(retorno == NORESTE){
			cout << "Verdadero" << endl;
		}
		else{
			cout << "Falso" << endl;
		}
	}else if(opcion == SUROESTE){
		if(retorno == SUROESTE){
			cout << "Verdadero" << endl;
		}
		else{
			cout << "Falso" << endl;
		}
	}
	else if(opcion == SURESTE){
		if(retorno == SURESTE){
			cout << "Verdadero" << endl;
		}
		else{
			cout << "Falso" << endl;
		}
	}
}

void informar_usuario(int &opcion, string &nombre_recibido, coordenadas &region){

	int retorno = 0;
	if(nombre_recibido == VANESA){
		retorno = determinar_region(region.vanesa_x, region.vanesa_y);
	}
	else if(nombre_recibido == NOSFERATU){
		retorno = determinar_region(region.nosferatu_x, region.nosferatu_y);
	}
	else if(nombre_recibido == VAMPIRELLA){
		retorno = determinar_region(region.vampirella_x, region.vampirella_y);
	}
	else if(nombre_recibido == ZOMBI){
		retorno = determinar_region(region.zombi_x, region.zombi_y);
	}
	else if(nombre_recibido == HUMANO){
		retorno = determinar_region(region.humano_x, region.humano_y);
	}
	else if(nombre_recibido == VAMPIRO){
		retorno = determinar_region(region.vampiro_x, region.vampiro_y);
	}
	else if(nombre_recibido == CRUZ){
		retorno = determinar_region(region.cruz_x, region.cruz_y);
	}
	else if(nombre_recibido == ESCOPETA){
		retorno = determinar_region(region.escopeta_x, region.escopeta_y);
	}
	else if(nombre_recibido == ESTACA){
		retorno = determinar_region(region.estaca_x, region.estaca_y);
	}
	else if(nombre_recibido == HUMANO_CV){
		retorno = determinar_region(region.humano_cv_x, region.humano_cv_y);
	}
	else if(nombre_recibido == AGUA){
		retorno = determinar_region(region.agua_x, region.agua_y);
	}
	mostrar_respuesta(opcion, retorno);
}

bool validar_opciones_inicio(int eleccion){
	return ((eleccion == ESTADISTICAS) || (eleccion == BUSCAR_ELEMENTO) || (eleccion == SALIR));
}

void ejecutar_opciones(estadisticas &datos,coordenadas &region, int &opcion, string &nombre_recibido){
	int eleccion;
	int nro_opcion;
	cout << "Elija una de las opciones para comenzar: ";
	cin >> eleccion;
	if(!validar_opciones_inicio(eleccion)){
		cout << "OPCION INCORRECTA! Ingrese nuevamente: ";
		cin >> eleccion;
	}
	if(eleccion == ESTADISTICAS){
		mostrar_estadisticas(datos);
	}
	else if(eleccion == BUSCAR_ELEMENTO){
		nro_opcion = pedir_region(opcion);
		if(nro_opcion != TERMINAR){
			pedir_nombre(nombre_recibido);
			informar_usuario(opcion, nombre_recibido, region);
		}
		else if(nro_opcion == TERMINAR){
			cout << "GRACIAS POR JUGAR <3" << endl;
		}
	}
	else if(eleccion == SALIR){
		cout << "Created by Lara Galvan - TP1 Algo2 Juarez - 1C 2021" << endl;
	}
}
