/****************************************************************************\
 * Curso de Programación 1. Práctica 6 y trabajo obligatorio
 * Autor: Héctor Toral Pallás
 * Ultima revisión: 10 de enero de 2020
 * Resumen: Módulo principal de un programa interactivo dirigido por menú
 *          que permite al usuario cifrar, descifrar y analizar las
 *          probabilidades de descifrado de un fichero de texto.
 * Codificación de caracteres original de este fichero: UTF-8 sin BOM
\****************************************************************************/

#include <iostream>
#include "analisis-cesar.h"
#include "cesar.h"
#include "pedir-nombre-fichero.h"

using namespace std;

//CONSTANTES_GLOBALES
const int FINALIZAR = 0;
const int NUM_OPERACIONES = 4;

/*
 *  Pre:  ---
 *  Post: Ha presentado en pantalla el menú de operaciones disponibles.
 */
void presentarMenu() {
    cout << "MENÚ DE OPERACIONES" << endl;
    cout << "===================" << endl;
    cout << "0 - Finalizar" << endl;
    cout << "1 - Cifrar texto" << endl;
    cout << "2 - Descifrar un texto proporcionando la clave" << endl;
    cout << "3 - Descifrar un texto automáticamente" << endl;
    cout << "4 - Analizar la probabilidad de las claves de un texto cifrado" << endl;
}

/*
 *  Pre:  ---
 *  Post: 1º Presenta en pantalla el menú de operaciones disponibles.
 *        2º Solicita al usuario que escriba el código de una de ellas.
 *        3º Asigna a «operación» la nueva respuesta del usuario.
 */
void pedirOrden(int& operacion) {
    presentarMenu();
    cout << endl;
    cout << "Seleccione una operación [0-" << NUM_OPERACIONES << "]: ";
    cin >> operacion;
    cout << endl;
}

/*
 *  Pre:  ---
 *  Post: Devuelve cifrado el contenido de un fichero.
 */
void ejecutarCifrar(const char fichero_rutaOrigen[], const char fichero_rutaDestino[],
                    int claveDes, int& operacion) {
    cifrar(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
}

/*
 *  Pre:  ---
 *  Post: Devuelve descifrado el contenido de un fichero conociendo la clave de descifrado.
 */
void ejecutarDescifrar(const char fichero_rutaOrigen[], const char fichero_rutaDestino[],
                       int claveDes, int& operacion) {
    descifrar(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
};

/*
 *  Pre:  ---
 *  Post: Devuelve descifrado el contenido de un 
 *        fichero tras analizar la clave que tiene 
 *        mayor probabilidad de descifrarlo.
 */
void ejecutarDescifrarAuto(const char fichero_rutaOrigen[], const char fichero_rutaDestino[],
                           probabilidad caso[], int& operacion) {
    // Modifico el valor de operación para evitar mostrar 
    // los mensajes de validación de cada clave.
    operacion += 1; 
    analisisCesar(fichero_rutaOrigen, fichero_rutaDestino, caso, operacion);
    ordenarAnalisis(caso);
    int claveBF = caso[MAX_NUM_PROBABILIDADES-1].clave;
    // Dejo el valor inicial de operación para mostrar los mensajes de descifrado.
    operacion -= 1;
    descifrar(fichero_rutaOrigen, fichero_rutaDestino, claveBF, operacion);
};

/*
 *  Pre:  ---
 *  Post: Analiza y muestra los resultados de los
 *        desciframientos con todas las claves posibles.
 */
void ejecutarAnalisis(const char fichero_rutaOrigen[], const char fichero_rutaDestino[],
                      probabilidad caso[], int& operacion) {
    analisisCesar(fichero_rutaOrigen, fichero_rutaDestino, caso, operacion);
    ordenarAnalisis(caso);
    menuProbabilidad(caso);
}

/*
 *  Pre:  Requiere del valor de «operación» para seleccionar la orden.
 *  Post: Selecciona la función «ejecutarXXXXXXX» elegida por el usuario.
 */
void ejecutarOrden(int& operacion) {
    int claveDes;
    char fichero_rutaOrigen[MAX_LONG_NOMBRE_FICHERO];
    char fichero_rutaDestino[MAX_LONG_NOMBRE_FICHERO];
    probabilidad caso[MAX_NUM_PROBABILIDADES];
    
    if (operacion == 1) {
        pedirDatos(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
        ejecutarCifrar(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
    }
    else if (operacion == 2) {
        pedirDatos(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
        ejecutarDescifrar(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
    }
    else if (operacion == 3) {
        pedirDatos(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
        ejecutarDescifrarAuto(fichero_rutaOrigen, fichero_rutaDestino, caso, operacion);
    }
    else if (operacion == 4) {
        pedirDatos(fichero_rutaOrigen, fichero_rutaDestino, claveDes, operacion);
        ejecutarAnalisis(fichero_rutaOrigen, fichero_rutaDestino, caso, operacion);
    }
}

/*
 *  Programa que plantea al usuario de manera reiterada un menú con varias opciones.
 *  En cada iteración, lee la respuesta del usuario y presenta los resultados de
 *  ejecutar la opción elegida. Concluye cuando el usuario selecciona la
 *  opción «FINALIZAR».
 */
int main() {
    int operacion;
    pedirOrden(operacion);
    if (operacion != FINALIZAR) {
        if ((operacion < FINALIZAR) || (operacion > NUM_OPERACIONES)) {
            cout << "A ocurrido un error, operación no válida" << endl;
        }
        while (operacion != FINALIZAR) {
            ejecutarOrden(operacion);
            pedirOrden(operacion);
        }
    }
    else {
        return 0;
    }
}