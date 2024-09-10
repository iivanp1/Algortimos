#include <bits/stdc++.h>
#include <chrono>  
using namespace std;
using namespace std::chrono;

// Funcion para particionar el vector
int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];  // Selecciona el ultimo elemento como pivote
    int i = (low - 1);  // ind del elemento justo antes del último

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] < pivot) {  
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);  // Ponemos el pivote en su pos
    return (i + 1);
}

// Funcion para quickSort
void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

// Funcion para leer el dataset desde archivo
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

// Funcion para medir el tiempo
void medir_tiempo_quicksort(vector<int>& vec, const string& nombre_algoritmo) {
    auto start = high_resolution_clock::now();
    
    quickSort(vec, 0, vec.size() - 1);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    cout << nombre_algoritmo << " tardo: " << duration.count() << " milisegundos" << endl;

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

    vector<int> vec_copia = desordenado;
    medir_tiempo_quicksort(vec_copia, "Quicksort - dataset desordenado");

    vec_copia = semi_ordenado;
    medir_tiempo_quicksort(vec_copia, "Quicksort - dataset semi ordenado");

    vec_copia = parcialmente_ordenado;
    medir_tiempo_quicksort(vec_copia, "Quicksort - dataset parcialmente ordenado");

    return 0;
}
