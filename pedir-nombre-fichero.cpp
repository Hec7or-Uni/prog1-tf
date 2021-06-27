/****************************************************************************\
 * Curso de Programación 1. Práctica 6 y trabajo obligatorio
 * Autor: Héctor Toral Pallás
 * Ultima revisión: 10 de enero de 2020
 * Resumen: Fichero de implementación «pedir-nombre-fichero.cpp» que declara
 *          una función denominada «pedirNombreFichero» que facilita la labor de
 *          convertir el nombre de un fichero solicitado al usuario en una ruta de
 *          acceso relativa al directorio de ejecución del proyecto solicitado 
 *          en esta tarea y en la siguiente.
 * Codificación de caracteres original de este fichero: UTF-8 sin BOM
\****************************************************************************/

#include <iostream>
#include <cstring>
#include "pedir-nombre-fichero.h"

using namespace std;

/*
 * Pre:  «rutaOrigen» y «rutaDestino» tienen una dimensión suficiente como
 *       para albergar una ruta relativa a un fichero cuya denominación
 *       escribirá el usuario. Sus valores están indeterminados al comenzar a
 *       ejecutarse esta función.
 * 
 * Post: Cuando ha terminado de ejecutarse esta función, se ha solicitado al
 *       usuario el nombre de un fichero, utilizando como mensaje para realizar
 *       dicha solicitud la cadena de caracteres «mensaje», que se ha escrito en
 *       la pantalla.
 * 
 *       A continuación, ha leído el nombre del fichero del teclado. (Como este 
 *       consta de un nombre base que no contiene el carácter «.» y una extensión
 *       que comienza con el carácter «.», se ha podido leer con dos instrucciones
 *       distintas, utilizando «.» como delimitador en la primera de ellas.)
 * 
 *       Ha asignado a «rutaOrigen» una ruta de acceso relativa
 *       al fichero cuyo nombre se ha leído de teclado, consistente en la
 *       concatenación de los siguientes elementos:
 *          - la cadena «DIR_DATOS»,
 *          - el nombre base del fichero leído del teclado,
 *          - la extensión del fichero leído del teclado.
 * 
 *       Ha asignado a «rutaDestino» una ruta de acceso a un fichero
 *       consistente en la concatenación de los siguientes elementos:
 *          - la cadena «DIR_RESULTADOS»,
 *          - el nombre base del fichero leído del teclado,
 *          - el interfijo establecido por el valor del parámetro «interfijo»,
 *          - la extensión del fichero leído del teclado.
 */
void pedirNombreFichero(const char mensaje[], const char interfijo[],
                        char rutaOrigen[], char rutaDestino[]){
    cout << mensaje;
    char nombreFichero[MAX_LONG_NOMBRE_FICHERO];
    cin >> nombreFichero;
    
    //SEPARACION DE NOMBRE.
    char ficheroNombre[MAX_LONG_NOMBRE_FICHERO];
    char ficheroExtension[MAX_LONG_NOMBRE_FICHERO];
    
    int DIM_FICHERO = strlen(nombreFichero);
    //NOMBRE.
    int i = 0;
    while (nombreFichero[i] != '.') {
        ficheroNombre[i] = nombreFichero[i];
        i++;
    }
    ficheroNombre[i] = '\0';
    //EXTENSIÓN.
    int o = 0;
    while (o + i < DIM_FICHERO) {
        ficheroExtension[o] = nombreFichero[o+i];
        o++;
    }
    ficheroExtension[i] = '\0';
    
    //rutaOrigen
    strcpy(rutaOrigen, DIR_DATOS);              //  ../../datos/
    strcat(rutaOrigen, ficheroNombre);          //  ../../datos/NOMfichero
    strcat(rutaOrigen, ficheroExtension);       //  ../../datos/NOMfichero.EXTfichero
    
    //rutaDestino
    strcpy(rutaDestino, DIR_RESULTADOS);        //  ../../resultados/
    strcat(rutaDestino, ficheroNombre);         //  ../../resultados/NOMfichero
    strcat(rutaDestino, interfijo);             //  ../../resultados/NOMfichero-cifrado
    strcat(rutaDestino, ficheroExtension);      //  ../../resultados/NOMfichero-cifrado.EXTfichero
}
