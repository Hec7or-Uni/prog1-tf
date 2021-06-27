/****************************************************************************\
 * Curso de Programación 1. Práctica 6 y trabajo obligatorio
 * Autor: Héctor Toral Pallás
 * Ultima revisión: 10 de enero de 2020
 * Resumen: Fichero de interfaz «analisis-cesar.h» de un módulo que declara
 *          una función denominada «analisisCesar» que facilita la labor de
 *          calcular la probabilidad de descifrar el contenido de un fichero
 *          solicitado al usuario.
 * Codificación de caracteres original de este fichero: UTF-8 sin BOM
\****************************************************************************/

#ifndef ANALISIS_CESAR_H_INCLUDED
#define ANALISIS_CESAR_H_INCLUDED

const int MAX_NUM_PROBABILIDADES = 26;

struct probabilidad {
    int clave;
    int palabras;
    double  P_Descifrado;
};

/*
 *  Pre:  ---
 *  Post: Ha presentado en pantalla el menú con 
 *        las probabilidades de las claves.
 */
void menuProbabilidad(probabilidad caso[]);

/*
 *  Pre:  ---
 *  Post: Calcula la posibilidad de descifrar el fichero con cada una de las claves posibles.
 *        1º Cifra con clave[i] un fichero [fichero_pwdTest](fichero temporal).
 *            -Guarda la clave[i] en caso[i].clave.
 *        2º Cuenta el número de palabras que comparten [fichero_pwdTest] y [diccionario].
 *            -Guarda el número de palabras encontradas en caso[i].palabras.
 *            -Borra el fichero temporal una vez guardada la clave y el número de palabras.
 *        3º Se calcula la probabilidad de descifrar el fichero [fichero_cifrado] con la clave[i].
 *            -Guarda la probabilidad en caso[i].P_Descifrado.
 */
void analisisCesar(const char fichero_cifrado[], const char fichero_pwdTest[],
                   probabilidad caso[], int& operacion);

/*
 *  Pre:  ---
 *  Post: Ordena el vector de casos de menor a mayor según el valor
 *        de sus probabilidades de descifrado.
 */
void ordenarAnalisis (probabilidad caso[]);

#endif // ANALISIS_CESAR_H_INCLUDED