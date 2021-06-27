# include <iostream>
# include <fstream>
# include "pedir-nombre-fichero.h"
# include "cesar.h"
# include "analisis-cesar.h"

using namespace std;

/*
 *  Pre:  ---
 *  Post: Pide los datos necesarios para las siguientes funciones.
 */
void pedirDatos(char fichero_rutaOrigen[], char fichero_rutaDestino[],
                int& claveDes, int& operacion) {
    if (operacion == 1) {
        char mensaje[] = "Nombre del fichero a cifrar: ";
        char interfijo[] = "-cifrado";
        pedirNombreFichero(mensaje, interfijo, fichero_rutaOrigen, fichero_rutaDestino);
        cout << "Clave de desplazamiento: ";
        cin >> claveDes;
    }
    else if (operacion == 2) {
        char mensaje[] = "Nombre del fichero a descifrar: ";
        char interfijo[] = "-descifrado";
        pedirNombreFichero(mensaje, interfijo, fichero_rutaOrigen, fichero_rutaDestino);
        cout << "Clave de desplazamiento: ";
        cin >> claveDes; 
    }
    else if ((operacion == 4) || (operacion == 3)) {
        char mensaje[] = "Nombre del fichero a descifrar: ";
        char interfijo[] = "-descifrado";
        pedirNombreFichero(mensaje, interfijo, fichero_rutaOrigen, fichero_rutaDestino);
    }
}

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
            int& claveDes, int& operacion) {
    ifstream D;
    ofstream R;
    D.open(fichero_rutaOrigen);                                     // ../../datos/fichero/
    R.open(fichero_rutaDestino);                                    // ../../resultados/fichero/
    
    if ((D.is_open()) && (R.is_open())) {
        char caracter;                                              // Dato a ser cifrado.
        D.get(caracter);
        while (!D.eof()) {
            if (isalpha(caracter)) {                                // ¿caracter?(caracter) = true
                cambiarLetras(caracter, claveDes);
                R.put(caracter);
                D.get(caracter);
            }
            else {                                                  // ¿caracter?(caracter) = false
                R.put(caracter);
                D.get(caracter);
            }
        }
        if (operacion == 1) {
            cout << "El contenido del fichero " << "\"" << fichero_rutaOrigen << "\"" 
                 << " ha sido cifrado con clave " << claveDes << endl;
            cout << "y almacenado en " << "\"" << fichero_rutaDestino << "\"." 
                 << "" << endl <<endl;
        }
        else if ((operacion == 2) || (operacion == 3)) {
            cout << "El contenido del fichero " << "\"" << fichero_rutaOrigen << "\"" 
                 << " ha sido descifrado" << endl;
            cout << "utilizando la clave " << - claveDes << " y almacenado en " << "\"" 
                 << fichero_rutaDestino << "\"." << "" << endl << endl;
        }
    }
    else {
        cerr << "No se ha podido acceder al fichero " << "\"" << fichero_rutaOrigen 
             << "\"." << "" << endl;
        cerr << "No ha podido crearse el fichero " << "\"" << fichero_rutaDestino 
             << "\"." << "" << endl << endl;
    }
    D.close();
    R.close();
}

/*
 *  Pre:  La función requerirá de la ruta relativa de un fichero para descifrarlo
 *        y otra distinta donde se guardara su copia descifrada, además necesitará
 *        una clave de descifrado y el código de operación dado por el usuario. 
 *  Post: Descifra el contenido de un fichero mediante una clave de descifrado.
 *        Se apoya en la función «cifrar» de la parte superior para su funcionamiento.
 */
void descifrar(const char fichero_rutaOrigen[], const char fichero_rutaDestino[],
               int& claveDes, int& operacion) {
    int claveDes_Descifrar = - claveDes;
    cifrar(fichero_rutaOrigen, fichero_rutaDestino, claveDes_Descifrar, operacion);
}

/*
 *  Pre:  necesita los datos <caracter> y <claveDes>
 *  Post: Cambia el valor de la letra a cifrar claveDes
 *        posiciones en el código ASCII para cifrar el fichero.
 */
void cambiarLetras(char& caracter, int& claveDes) {
    if (isupper(caracter)) {
        caracter += claveDes;
        if (caracter > 'Z') {
            caracter -= 26;
        }
        if (caracter < 'A') {
            caracter += 26;
        }
    }
    else {
        caracter += claveDes;
        if (caracter > 'z') {
            caracter -= 26;
        }
        if (caracter < 'a') {
            caracter += 26;
        }
    }
}
