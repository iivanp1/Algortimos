#include <bits/stdc++.h>
#include <chrono>  
using namespace std;
using namespace std::chrono;

// funcion para combinar dos subarreglos 
void merge(vector<int>& arr, int izq, int medio, int der)
{
    int tamano_izq = medio - izq + 1;
    int tamano_der = der - medio;

    // crear vectores temporales
    vector<int> izquierda(tamano_izq), derecha(tamano_der);

    // copiar datos a los vectores temporales
    for (int i = 0; i < tamano_izq; i++)
        izquierda[i] = arr[izq + i];
    for (int j = 0; j < tamano_der; j++)
        derecha[j] = arr[medio + 1 + j];

    int i = 0, j = 0;
    int k = izq;

    // combinar los vectores
    while (i < tamano_izq && j < tamano_der) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        }
        else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    // copiar los elementos restantes de izquierda
    while (i < tamano_izq) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    // copiar los elementos restantes de derecha
    while (j < tamano_der) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}

// funcion merge_sort para ordenar el arreglo
// izq es el indice de la izquierda y der el indice de la derecha
void merge_sort(vector<int>& arr, int izq, int der)
{
    if (izq >= der)
        return;

    int medio = izq + (der - izq) / 2;
    merge_sort(arr, izq, medio);
    merge_sort(arr, medio + 1, der);
    merge(arr, izq, medio, der);
}

// funcion para imprimir el vector
void imprimir_vector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
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

// Funcion para medir el tiempo de ejecucion de Merge Sort
void medir_tiempo_merge_sort(vector<int>& vec, const string& nombre_algoritmo) {
    auto start = high_resolution_clock::now();
    
    merge_sort(vec, 0, vec.size() - 1);
    
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

    // Medir tiempo de Merge Sort para cada dataset
    vector<int> vec_copia = desordenado;
    medir_tiempo_merge_sort(vec_copia, "Merge Sort - dataset desordenado");

    vec_copia = semi_ordenado;
    medir_tiempo_merge_sort(vec_copia, "Merge Sort - dataset semi ordenado");

    vec_copia = parcialmente_ordenado;
    medir_tiempo_merge_sort(vec_copia, "Merge Sort - dataset parcialmente ordenado");

    return 0;
}
