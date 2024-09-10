#include <iostream>
#include <vector>
#include <algorithm>  // std::sort
#include <fstream>    // Para leer archivos
#include <chrono>     // Para medir tiempo de ej

using namespace std;
using namespace std::chrono;

// Funcion para leer el dataset desde archivo
vector<int> leer_dataset(const string& nombre_archivo) {
    vector<int> vec;
    ifstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        int numero;
        while (archivo >> numero) {
            vec.push_back(numero);  // Se leen los numeros y se guardan
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
    }
    return vec;
}

// Funcion para medir el tiempo de ejecucion de std::sort
void medir_tiempo_sort(vector<int>& vec, const string& nombre_algoritmo) {
    auto start = high_resolution_clock::now();
    
    // Llamamos a std::sort para ordenar el vector
    std::sort(vec.begin(), vec.end());
    
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

int main() {
    // Leer los datasets
    vector<int> desordenado = leer_dataset("dataset_desordenado.txt");
    if (desordenado.empty()) {
        cout << "Error al leer el dataset desordenado" << endl;
        return 1;
    }

    vector<int> semi_ordenado = leer_dataset("dataset_semi_ordenado.txt");
    if (semi_ordenado.empty()) {
        cout << "Error al leer el dataset semi ordenado" << endl;
        return 1;
    }

    vector<int> parcialmente_ordenado = leer_dataset("dataset_parcialmente_ordenado.txt");
    if (parcialmente_ordenado.empty()) {
        cout << "Error al leer el dataset parcialmente ordenado" << endl;
        return 1;
    }

    // Medir tiempo de std::sort para cada dataset
    vector<int> vec_copia = desordenado;
    medir_tiempo_sort(vec_copia, "std::sort - dataset desordenado");

    vec_copia = semi_ordenado;
    medir_tiempo_sort(vec_copia, "std::sort - dataset semi ordenado");

    vec_copia = parcialmente_ordenado;
    medir_tiempo_sort(vec_copia, "std::sort - dataset parcialmente ordenado");

    return 0;
}
