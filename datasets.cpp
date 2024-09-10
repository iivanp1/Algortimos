#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  
#include <ctime>      // Para generar numeros aleatorios
using namespace std;

// Funcion para generar un dataset completamente desordenado
vector<int> generar_dataset_desordenado(int tamano) {
    vector<int> vec(tamano);
    for (int i = 0; i < tamano; i++) {
        vec[i] = rand() % 100000;  // Numeros aleatorios entre 0 y 99999
    }
    return vec;
}

// Funcion para generar un dataset semi ordenado, con pocos elementos desordenados
vector<int> generar_dataset_semi_ordenado(int tamano) {
    vector<int> vec(tamano);
    for (int i = 0; i < tamano; i++) {
        vec[i] = i;  // Llenamos el vector con numeros en orden
    }
    // Desordenamos un pequeño porcentaje de los elementos
    random_shuffle(vec.begin(), vec.begin() + tamano / 20);
    return vec;
}

// Funcion para generar un dataset parcialmente ordenado
vector<int> generar_dataset_parcialmente_ordenado(int tamano) {
    vector<int> vec(tamano);
    for (int i = 0; i < tamano; i++) {
        vec[i] = i;  
    }
    // Desordenamos un mayor porcentaje de los elementos 
    random_shuffle(vec.begin(), vec.begin() + tamano / 2);
    return vec;
}

// Funcion para guardar el dataset en un archivo de texto
void guardar_dataset_texto(const vector<int>& vec, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (archivo.is_open()) {
        for (int i = 0; i < vec.size(); i++) {
            archivo << vec[i] << " ";  // Guardar los numeros
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
    }
}

int main() {
    srand(time(0));  // Semilla para los numeros aleatorios
    
    int tamano = 100000;  // Generar un dataset de tamaño 10^5

    // Generamos un dataset desordenado
    vector<int> desordenado = generar_dataset_desordenado(tamano);
    guardar_dataset_texto(desordenado, "dataset_desordenado.txt");
    cout << "Dataset desordenado generado" << endl;

    // Generamos un dataset semi ordenado
    vector<int> semi_ordenado = generar_dataset_semi_ordenado(tamano);
    guardar_dataset_texto(semi_ordenado, "dataset_semi_ordenado.txt");
    cout << "Dataset semi ordenado generado" << endl;

    // Generamos un dataset parcialmente ordenado
    vector<int> parcialmente_ordenado = generar_dataset_parcialmente_ordenado(tamano);
    guardar_dataset_texto(parcialmente_ordenado, "dataset_parcialmente_ordenado.txt");
    cout << "Dataset parcialmente ordenado generado" << endl;

    return 0;
}
