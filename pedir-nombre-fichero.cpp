# include <iostream>
# include <cstring>
# include "pedir-nombre-fichero.h"

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
                        char rutaOrigen[], char rutaDestino[]) {
    cout << mensaje;
    
    char nombreFichero[MAX_LONG_NOMBRE_FICHERO];
    cin >> nombreFichero;

    // Inicializar variables para el nombre base y la extensión
    char ficheroNombre[MAX_LONG_NOMBRE_FICHERO] = "";
    char ficheroExtension[MAX_LONG_NOMBRE_FICHERO] = "";

    // Buscar el punto (.) que separa el nombre base de la extensión
    char *punto = strchr(nombreFichero, '.');
    
    if (punto != nullptr) {
        // Copiar el nombre base
        strncpy(ficheroNombre, nombreFichero, punto - nombreFichero);
        ficheroNombre[punto - nombreFichero] = '\0'; // Agregar fin de cadena
        
        // Copiar la extensión incluyendo el punto
        strcpy(ficheroExtension, punto);
    } else {
        // Si no hay punto, todo el nombreFichero es el nombre base
        strcpy(ficheroNombre, nombreFichero);
    }

    // Construir rutaOrigen: DIR_DATOS + nombre base + extensión
    strcpy(rutaOrigen, DIR_DATOS);              //  datos/
    strcat(rutaOrigen, ficheroNombre);          //  datos/NOMfichero
    strcat(rutaOrigen, ficheroExtension);       //  datos/NOMfichero.EXTfichero

    // Construir rutaDestino: DIR_RESULTADOS + nombre base + interfijo + extensión
    strcpy(rutaDestino, DIR_RESULTADOS);        //  resultados/
    strcat(rutaDestino, ficheroNombre);         //  resultados/NOMfichero
    strcat(rutaDestino, interfijo);             //  resultados/NOMfichero-interfijo
    strcat(rutaDestino, ficheroExtension);      //  resultados/NOMfichero-interfijo.EXTfichero
}