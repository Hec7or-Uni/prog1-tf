# include <iostream>
# include <cstring>
# include <iomanip>
# include "cesar.h"
# include "analisis-cesar.h"
# include "diccionario.h"

using namespace std;

/*
 *  Pre:  ---
 *  Post: Ha presentado en pantalla el menú con 
 *        las probabilidades de las claves.
 */
void menuProbabilidad(probabilidad caso[]) {
    cout << endl;
    cout << " --------------------------" << endl;
    cout << "  Clave Palabras Porcentaje" << endl;
    cout << " --------------------------" << endl;
    for(int i = 0; i < 26; i++){
        cout << setw(6) << caso[i].clave 
             << setw(9) << caso[i].palabras
             << setw(9) << fixed << setprecision(1) << caso[i].P_Descifrado << " % "<< endl;
    }
    cout << endl;
}

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
                   probabilidad caso[], int& operacion) {
    for(int i = 0; i < 26; i++){
        descifrar(fichero_cifrado, fichero_pwdTest, i, operacion);
        caso[i].clave = i;
        
        int encontradas = 0;
        int noEncontradas = 0;
        contarPalabras(fichero_pwdTest, encontradas, noEncontradas);
        caso[i].palabras = encontradas;
        remove(fichero_pwdTest);
        
        double palabrasTotales = encontradas + noEncontradas;
        caso[i].P_Descifrado = (encontradas / palabrasTotales) * 100;
    }
}

/*
 *  Pre:  ---
 *  Post: Ordena el vector de casos de menor a mayor según el valor
 *        de sus probabilidades de descifrado.
 */
void ordenarAnalisis (probabilidad caso[]) {
    probabilidad aux[MAX_NUM_PROBABILIDADES];
    int min;
    //Algoritmo del Ordenamiento por Selección.
    for(int i = 0; i < MAX_NUM_PROBABILIDADES; i++) {
        min = i;
        for(int j = i + 1; j < MAX_NUM_PROBABILIDADES; j++) {
            if(caso[j].P_Descifrado < caso[min].P_Descifrado) {
                min = j;
            }
        }
        aux[i] = caso[i];
        caso[i] = caso[min];
        caso[min] = aux[i];
    }
}
