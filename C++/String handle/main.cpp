#include <iostream>
#include <vector>
using namespace std;

// Función para construir el arreglo de prefijos (LPS)
vector<int> construirLPS(string subcadena) {
    int m = subcadena.length();
    vector<int> lps(m, 0); // Inicializamos el arreglo LPS con 0's
    int len = 0; // Longitud del prefijo actual

    for (int i = 1; i < m; ) {
        if (subcadena[i] == subcadena[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Función para encontrar todas las ocurrencias de la subcadena en la cadena principal usando KMP
vector<int> encontrarOcurrenciasKMP(string cadena, string subcadena) {
    vector<int> ocurrencias;
    int n = cadena.length();
    int m = subcadena.length();
    vector<int> lps = construirLPS(subcadena);

    int i = 0; // Índice para la cadena principal
    int j = 0; // Índice para la subcadena

    while (i < n) {
        if (subcadena[j] == cadena[i]) {
            i++;
            j++;
        }

        if (j == m) { // Encontramos una ocurrencia
            ocurrencias.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && subcadena[j] != cadena[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return ocurrencias;
}

int main() {
    string cadenaPrincipal = "ababcababcabc";
    string subcadena = "abc";

    vector<int> ocurrencias = encontrarOcurrenciasKMP(cadenaPrincipal, subcadena);

    if (ocurrencias.empty()) {
        cout << "No se encontraron ocurrencias." << endl;
    } else {
        cout << "Ocurrencias encontradas en las posiciones: ";
        for (int i = 0; i < ocurrencias.size(); i++) {
            cout << ocurrencias[i];
            if (i < ocurrencias.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
