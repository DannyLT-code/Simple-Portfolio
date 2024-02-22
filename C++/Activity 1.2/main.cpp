#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> hacerCambioDP(const vector<int>& denominaciones, int precio, int pagado) {
    int cantidadCambio = pagado - precio;
    vector<int> dp(cantidadCambio + 1, INT_MAX);
    vector<int> resultado(denominaciones.size(), 0);

    dp[0] = 0;

    for (int i = 1; i <= cantidadCambio; i++) {
        for (int j = 0; j < denominaciones.size(); j++) {
            if (denominaciones[j] <= i && dp[i - denominaciones[j]] + 1 < dp[i]) {
                dp[i] = dp[i - denominaciones[j]] + 1;
                resultado[j]++;
            }
        }
    }

    return resultado;
}

vector<int> hacerCambioAvaro(const vector<int>& denominaciones, int precio, int pagado) {
    int cantidadCambio = pagado - precio;
    vector<int> resultado(denominaciones.size(), 0);

    for (int i = 0; i < denominaciones.size(); i++) {
        while (cantidadCambio >= denominaciones[i]) {
            cantidadCambio -= denominaciones[i];
            resultado[i]++;
        }
    }

    return resultado;
}

int main() {
    int N;
    cout << "Por favor, ingrese la cantidad de denominaciones:\n";
    cin >> N;

    vector<int> denominaciones(N);
    cout << "Por favor, ingrese las denominaciones, una en cada linea:" << endl;
    for (int i = 0; i < N; i++)
        cin >> denominaciones[i];

    int P, Q;
    cout << "Por favor, ingrese el precio del producto:\n";
    cin >> P;
    cout << "Por favor, ingrese la cantidad pagada:\n";
    cin >> Q;

    cout << endl;

    vector<int> resultadoDP = hacerCambioDP(denominaciones, P, Q);
    vector<int> resultadoAvaro = hacerCambioAvaro(denominaciones, P, Q);

    // Resultado con programación dinámica
    cout << "Resultado con Programacion Dinamica:" << endl;
    for (int i = 0; i < resultadoDP.size(); i++)
        cout << resultadoDP[i] << endl;

    cout << endl;

    // Resultado con algoritmo avaro
    cout << "Resultado con Algoritmo Avaro:" << endl;
    for (int i = 0; i < resultadoAvaro.size(); i++)
        cout << resultadoAvaro[i] << endl;

    return 0;
}
