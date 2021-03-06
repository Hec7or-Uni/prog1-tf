# pragma once

# include "pedir-nombre-fichero.h"

/*
 *  Pre:  ---
 *  Post: Pide los datos necesarios para las siguientes funciones.
 */
void pedirDatos(char fichero_rutaOrigen[], char fichero_rutaDestino[],
                int& claveDes, int& operacion);

/*
 *  Pre:  La función requerirá de la ruta relativa de un fichero para cifrarlo
 *        y otra distinta donde se guardara su copia cifrada, además necesitará
 *        una clave de cifrado y el código de operación dado por el usuario. 
 *  Post: Cifrará el fichero de texto deseado por el usuario con una clave de
 *        cifrado «claveDes» para cifrar el fichero y con una clave «-claveDes»
 *        para descifrarlo. En caso de error mostrará unos mensajes de error si no es
 *        capaz de abrir los ficheros y otros de confirmación de cifrado o descifrado.
 *        
 */
void cifrar(const char fichero_rutaOrigen[], const char fichero_rutaDestino[],
            int& claveDes, int& operacion);

/*
 *  Pre:  La función requerirá de la ruta relativa de un fichero para descifrarlo
 *        y otra distinta donde se guardara su copia descifrada, además necesitará
 *        una clave de descifrado y el código de operación dado por el usuario. 
 *  Post: Descifra el contenido de un fichero mediante una clave de descifrado.
 *        Se apoya en la función «cifrar» de la parte superior para su funcionamiento.
 */
void descifrar(const char fichero_rutaOrigen[], const char fichero_rutaDestino[],
               int& claveDes, int& operacion);

/*
 *  Pre:  necesita los datos <caracter> y <claveDes>
 *  Post: Cambia el valor de la letra a cifrar claveDes
 *        posiciones en el código ASCII para cifrar el fichero.
 */
void cambiarLetras(char& caracter, int& claveDes);
