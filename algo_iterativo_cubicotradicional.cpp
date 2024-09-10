#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// funcion para leer una matriz desde un archivo
void leer_matriz(const string& nombre_archivo, vector<vector<int>>& matriz, int filas, int columnas) {
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "no se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(1);
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            archivo >> matriz[i][j];
        }
    }
    archivo.close();
}

// funcion para multiplicar dos matrices
void multiplicar_matrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, vector<vector<int>>& resultado, int R1, int C1, int C2) {
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < C1; k++) {
                resultado[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// funcion para medir el tiempo de ejecucion de la multiplicacion de matrices
long long medir_tiempo_multiplicacion_matrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, vector<vector<int>>& resultado, int R1, int C1, int C2) {
    auto start = high_resolution_clock::now();
    
    multiplicar_matrices(mat1, mat2, resultado, R1, C1, C2);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    
    return duration.count();  // devolvemos el tiempo en milisegundos
}

int main() {
    // definir dimensiones de las matrices
    int R1, C1, R2, C2;

    // medir tiempo para matrices cuadradas de 316x316
    R1 = C1 = 316;
    R2 = C2 = 316;
    vector<vector<int>> mat1_cuadrada(R1, vector<int>(C1));
    vector<vector<int>> mat2_cuadrada(R2, vector<int>(C2));
    vector<vector<int>> resultado_cuadrada(R1, vector<int>(C2));

    leer_matriz("matriz1_cuadrada.txt", mat1_cuadrada, R1, C1);
    leer_matriz("matriz2_cuadrada.txt", mat2_cuadrada, R2, C2);
    
    long long tiempo_cuadrada = medir_tiempo_multiplicacion_matrices(mat1_cuadrada, mat2_cuadrada, resultado_cuadrada, R1, C1, C2);
    cout << "matriz cuadrada de 316x316 tardo: " << tiempo_cuadrada << " ms" << endl;

    // medir tiempo para matrices rectangulares de 500x200 y 200x500
    R1 = 500, C1 = 200;
    R2 = 200, C2 = 500;
    vector<vector<int>> mat1_rectangular(R1, vector<int>(C1));
    vector<vector<int>> mat2_rectangular(R2, vector<int>(C2));
    vector<vector<int>> resultado_rectangular(R1, vector<int>(C2));

    leer_matriz("matriz1_rectangular.txt", mat1_rectangular, R1, C1);
    leer_matriz("matriz2_rectangular.txt", mat2_rectangular, R2, C2);
    
    long long tiempo_rectangular = medir_tiempo_multiplicacion_matrices(mat1_rectangular, mat2_rectangular, resultado_rectangular, R1, C1, C2);
    cout << "matriz rectangular de 500x200 y 200x500 tardo: " << tiempo_rectangular << " ms" << endl;

    return 0;
}
