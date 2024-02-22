#include <iostream>
#include <vector>
using namespace std;

void merge(vector<double>& arr, int left, int middle, int right);
void mergeSort(vector<double>& arr, int left, int right);


int main() {
    int N;

    cout << "Numero de valores a ordenar:";
    cin >> N;

    vector<double> values(N);

    cout << "Ingrese " << N << " valores:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    mergeSort(values, 0, N - 1);

    cout << "Merge sort de mayor a menor:" << endl;
    for (int i = 0; i < N; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    return 0;
}

void merge(vector<double>& arr, int left, int middle, int right) {

    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<double> L(n1);
    vector<double> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
