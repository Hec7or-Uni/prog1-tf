/****************************************************************************\
 * Curso de Programación 1. Práctica 6 y trabajo obligatorio
 * Autor: Miguel Ángel Latre Abadía
 * Ultima revisión: 8 de diciembre de 2019
 * Resumen: Fichero de interfaz «pedir-nombre-fichero.h» de un módulo que declara
 *          una función denominada «pedirNombreFichero» que facilita la labor de
 *          convertir el nombre de un fichero solicitado al usuario en una ruta de
 *          acceso relativa al directorio de ejecución del proyecto solicitado 
 *          en esta tarea y en la siguiente. 
 * Codificación de caracteres original de este fichero: UTF-8 sin BOM
\****************************************************************************/

#ifndef PEDIR_NOMBRE_FICHERO_H_INCLUDED
#define PEDIR_NOMBRE_FICHERO_H_INCLUDED

const int MAX_LONG_NOMBRE_FICHERO = 200;
const char DIR_DATOS[] = "datos/";
const char DIR_RESULTADOS[] = "resultados/";

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
 * 
 * Ejemplo de utilización: cuando se implemente en el módulo principal la opción 1
 * (cifrado de un texto), se puede invocar a esta función utilizando como
 * argumento para el parámetro «mensaje» la cadena de caracteres
 * "Nombre del fichero a cifrar: " y como argumento para el parámetro «interfijo»,
 * la cadena "-cifrado". Cuando se haya ejecutado la función, si el usuario ha
 * escrito en el teclado "quijote.txt", el valor asignado al argumento 
 * correspondiente al parámetro de salida «rutaOrigen» será
 * "datos/quijote.txt" y, el valor asignado al argumento correspondiente al
 * parámetro de salida «rutaDestino» será "resultados/quijote-cifrado.txt".
 */
void pedirNombreFichero(const char mensaje[], const char interfijo[],
                        char rutaOrigen[], char rutaDestino[]);

#endif // PEDIR_NOMBRE_FICHERO_H_INCLUDED