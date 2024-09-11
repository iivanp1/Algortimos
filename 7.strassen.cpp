#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// función para leer una matriz desde un archivo
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

// función para sumar matrices
vector<vector<int>> add_matrix(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B, int split_index, int multiplier = 1) {
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_A[i][j] = matrix_A[i][j] + (multiplier * matrix_B[i][j]);
    return matrix_A;
}

// función para multiplicar matrices usando Strassen
vector<vector<int>> multiply_matrix(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B) {
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2) {
        cout << "\nError: El número de columnas en la matriz A debe ser igual al número de filas en la matriz B\n";
        return {};
    }

    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int>> result_matrix(row_1, result_matrix_row);

    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else {
        int split_index = col_1 / 2;
        vector<int> row_vector(split_index, 0);
        vector<vector<int>> a00(split_index, row_vector), a01(split_index, row_vector),
            a10(split_index, row_vector), a11(split_index, row_vector),
            b00(split_index, row_vector), b01(split_index, row_vector),
            b10(split_index, row_vector), b11(split_index, row_vector);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }

        vector<vector<int>> p = multiply_matrix(a00, add_matrix(b01, b11, split_index, -1));
        vector<vector<int>> q = multiply_matrix(add_matrix(a00, a01, split_index), b11);
        vector<vector<int>> r = multiply_matrix(add_matrix(a10, a11, split_index), b00);
        vector<vector<int>> s = multiply_matrix(a11, add_matrix(b10, b00, split_index, -1));
        vector<vector<int>> t = multiply_matrix(add_matrix(a00, a11, split_index), add_matrix(b00, b11, split_index));
        vector<vector<int>> u = multiply_matrix(add_matrix(a01, a11, split_index, -1), add_matrix(b10, b11, split_index));
        vector<vector<int>> v = multiply_matrix(add_matrix(a00, a10, split_index, -1), add_matrix(b00, b01, split_index));

        vector<vector<int>> result_matrix_00 = add_matrix(add_matrix(add_matrix(t, s, split_index), u, split_index), q, split_index, -1);
        vector<vector<int>> result_matrix_01 = add_matrix(p, q, split_index);
        vector<vector<int>> result_matrix_10 = add_matrix(r, s, split_index);
        vector<vector<int>> result_matrix_11 = add_matrix(add_matrix(add_matrix(t, p, split_index), r, split_index, -1), v, split_index, -1);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
            }
    }
    return result_matrix;
}

// función para medir el tiempo de ejecución de Strassen
long long medir_tiempo_strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    auto start = high_resolution_clock::now();
    vector<vector<int>> resultado = multiply_matrix(A, B);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

int main() {
    // Medir tiempo para matrices cuadradas grandes
    int R1 = 1000, C1 = 1000, R2 = 1000, C2 = 1000;
    vector<vector<int>> mat1_cuadrada(R1, vector<int>(C1));
    vector<vector<int>> mat2_cuadrada(R2, vector<int>(C2));

    leer_matriz("matriz1_grande.txt", mat1_cuadrada, R1, C1);
    leer_matriz("matriz2_grande.txt", mat2_cuadrada, R2, C2);

    long long tiempo_cuadrada = medir_tiempo_strassen(mat1_cuadrada, mat2_cuadrada);
    cout << "Multiplicación de matrices cuadradas de 1000x1000 usando Strassen tardó: " << tiempo_cuadrada << " ms" << endl;

    // Medir tiempo para matrices rectangulares grandes
    R1 = 1000, C1 = 500, R2 = 500, C2 = 1000;
    vector<vector<int>> mat1_rectangular(R1, vector<int>(C1));
    vector<vector<int>> mat2_rectangular(R2, vector<int>(C2));

    leer_matriz("matriz1_rectangular.txt", mat1_rectangular, R1, C1);
    leer_matriz("matriz2_rectangular.txt", mat2_rectangular, R2, C2);

    long long tiempo_rectangular = medir_tiempo_strassen(mat1_rectangular, mat2_rectangular);
    cout << "Multiplicación de matrices rectangulares de 1000x500 y 500x1000 usando Strassen tardó: " << tiempo_rectangular << " ms" << endl;

    return 0;
}
