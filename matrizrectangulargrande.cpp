#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

void generar_matriz(const string& nombre_archivo, int filas, int columnas) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para escritura" << endl;
        return;
    }

    srand(time(0));  // Inicializa la semilla para rand()

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo << rand() % 100 << " ";  // Genera números aleatorios entre 0 y 99
        }
        archivo << endl;  
    }
    archivo.close();
}

int main() {
    int filas1 = 500, columnas1 = 200;  // Dimensiones para la primera matriz
    int filas2 = 200, columnas2 = 500;  // Dimensiones para la segunda matriz 
    
    generar_matriz("matriz1_rectangular_grande.txt", filas1, columnas1);
    generar_matriz("matriz2_rectangular_grande.txt", filas2, columnas2);
    
    return 0;
}
