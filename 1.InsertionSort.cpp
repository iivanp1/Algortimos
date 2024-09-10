#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>  // Para medir tiempos 
using namespace std;
using namespace std::chrono;

// Funcion para ordenar el arreglo usando Insertion Sort
void insertionsort(int arr[], int tamano)
{
    for (int i = 1; i < tamano; ++i) {
        int clave = arr[i];  // Guardamos el valor del elemento actual
        int j = i - 1;

        // Movemos los elementos que son mayores que clave un lugar adelante
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];  // Mover el elemento un lugar adelante
            j = j - 1;  // Continuar comparando hacia atras
        }
        arr[j + 1] = clave;  // Se inserta la clave en su posicion correcta
    }
}

// Funcion para leer el dataset 
vector<int> leer_dataset(const string& nombre_archivo) {
    vector<int> vec;
    ifstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        int numero;
        while (archivo >> numero) {
            vec.push_back(numero);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
    }
    return vec;
}

// Funcion para medir el tiempo de ejecucion de Insertion Sort
void medir_tiempo_insertionsort(vector<int>& vec, const string& nombre_algoritmo) {
    int tamano = vec.size();
    int* arr = &vec[0];  // Convertir vector a arreglo

    auto start = high_resolution_clock::now();
    
    insertionsort(arr, tamano);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << nombre_algoritmo << " tardo: " << duration.count() << " milisegundos" << endl;

    // Imprimir el vector ordenado
    cout << "Valores ordenados (" << nombre_algoritmo << "): ";
    for (const auto& valor : vec) {
        cout << valor << " ";
    }
    cout << endl;
}

int main()
{
    // Leer los datasets
    vector<int> desordenado = leer_dataset("dataset_desordenado.txt");
    vector<int> semi_ordenado = leer_dataset("dataset_semi_ordenado.txt");
    vector<int> parcialmente_ordenado = leer_dataset("dataset_parcialmente_ordenado.txt");

    // Medir tiempo de Insertion Sort para cada dataset
    vector<int> vec_copia = desordenado;
    medir_tiempo_insertionsort(vec_copia, "Insertion Sort - dataset desordenado");

    vec_copia = semi_ordenado;
    medir_tiempo_insertionsort(vec_copia, "Insertion Sort - dataset semi ordenado");

    vec_copia = parcialmente_ordenado;
    medir_tiempo_insertionsort(vec_copia, "Insertion Sort - dataset parcialmente ordenado");

    return 0;
}
