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

    srand(time(0));  

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo << rand() % 100 << " ";  
        }
        archivo << endl;  
    }
    archivo.close();
}

int main() {
    int filas = 1000;
    int columnas = 1000;
    
    generar_matriz("matriz1_grande.txt", filas, columnas);
    generar_matriz("matriz2_grande.txt", filas, columnas);
    
    return 0;
}
