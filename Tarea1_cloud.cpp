// Tarea1_cloud.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <omp.h>

using namespace std;

const int N = 100;
const int CHUNK = 10; // Ajustado para tamaños razonables en paralelismo
const int MOSTRAR = 10;

void imprimeArreglo(float* d, int size);

int main() {
    cout << "Sumatoria de Arreglos en Paralelo\n";

    float a[N], b[N], c[N];
    std::srand(static_cast<unsigned int>(std::time(0))); 
    // Inicialización de arreglos
    for (int i = 0; i < N; i++) {
        a[i] = rand() % N; // Hacemos los arreglos aleatorios de A y B

        b[i] = rand() % N;
          }

    int pedazos = CHUNK;
    omp_set_num_threads(2);
    // Sumatoria de arreglos en paralelo
#pragma omp parallel for shared(a, b, c, pedazos) schedule(static, pedazos)
    for (int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    // Impresión de resultados
    cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo a:\n";
    imprimeArreglo(a, MOSTRAR);

    cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo b:\n";
    imprimeArreglo(b, MOSTRAR);

    cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo c:\n";
    imprimeArreglo(c, MOSTRAR);

    return 0;
}

void imprimeArreglo(float* d, int size) { // creamos funcion para imprimir los arreglos
    for (int x = 0; x < size; x++) {
        cout << d[x] << " ";
    }
    cout << endl;
}
