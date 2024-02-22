#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ESTRUCTURAS:
// Estructura para representar un elemento con su peso y valor
struct Item {
    int weight;
    int value;
};
x
// FUNCIONES:
// Funcion para resolver el problema usando enfoque voraz
double Greedy(vector<Item> items, int capacity);
// Funcion de comparación para ordenar los elementos en orden descendente
bool compare(Item a, Item b);


int main() {
    vector<Item> items = {
        {6, 10},
        {5, 8},
        {7, 12},
        {4, 6},
        {3, 6}
    };

    int capacity = 18;
    double maxValue = Greedy(items, capacity);

    cout << "El valor maximo de la mochila es: " << maxValue << endl;

    return 0;
}

double Greedy(vector<Item> items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Si no cabe completo, agregar basado en el espacio disponible
            double remainingCapacity = capacity - currentWeight;
            totalValue += (remainingCapacity / item.weight) * item.value;
            break;
        }
    }

    return totalValue;
}

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}