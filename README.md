
# Proyecto: Algoritmos de Ordenamiento y Multiplicación de Matrices

Este proyecto implementa varios algoritmos de ordenamiento y multiplicación de matrices. Se incluye la generación de datasets de prueba y la evaluación de los tiempos de ejecución de cada algoritmo. Los resultados experimentales pueden utilizarse para comparar el rendimiento de los algoritmos en diferentes condiciones.

## Requisitos
- Compilador de C++ (g++)
- Sistema operativo Linux/Unix (o Windows con soporte para Bash)

## Compilación y Ejecución

### Generación de Datasets

#### Generar datasets para algoritmos de ordenamiento:
1. Compilar el generador de datasets:
   ```bash
   g++ datasets.cpp -o generar_datasets
   ```
2. Ejecutar el generador de datasets:
   ```bash
   ./generar_datasets
   ```

### Algoritmos de Ordenamiento

#### Insertion Sort
1. Compilar el algoritmo de Insertion Sort:
   ```bash
   g++ 1.InsertionSort.cpp -o insertion_sort
   ```
2. Ejecutar el algoritmo de Insertion Sort:
   ```bash
   ./insertion_sort
   ```

#### Merge Sort
1. Compilar el algoritmo de Merge Sort:
   ```bash
   g++ 2.mergesort.cpp -o merge_sort
   ```
2. Ejecutar el algoritmo de Merge Sort:
   ```bash
   ./merge_sort
   ```

#### Quick Sort
1. Compilar el algoritmo de Quick Sort:
   ```bash
   g++ 3.quicksort.cpp -o quick_sort
   ```
2. Ejecutar el algoritmo de Quick Sort:
   ```bash
   ./quick_sort
   ```

#### std::sort (función estándar)
1. Compilar el algoritmo usando la función estándar:
   ```bash
   g++ 4.funcionsort.cpp -o std_sort
   ```
2. Ejecutar el algoritmo con std::sort:
   ```bash
   ./std_sort
   ```

### Generación de Datasets para Multiplicación de Matrices

#### Generar matrices cuadradas:
1. Compilar el generador de matrices cuadradas:
   ```bash
   g++ datasetmatriz.cpp -o generar_matrices_cuadradas
   ```
2. Ejecutar el generador de matrices cuadradas:
   ```bash
   ./generar_matrices_cuadradas
   ```

#### Generar matrices rectangulares:
1. Compilar el generador de matrices rectangulares:
   ```bash
   g++ datasetmatriz2.cpp -o generar_matrices_rectangulares
   ```
2. Ejecutar el generador de matrices rectangulares:
   ```bash
   ./generar_matrices_rectangulares
   ```

### Algoritmos de Multiplicación de Matrices

#### Algoritmo cúbico tradicional
1. Compilar el algoritmo cúbico tradicional:
   ```bash
   g++ 5.iterativo_cubicotradicional.cpp -o cubico_tradicional
   ```
2. Ejecutar la multiplicación con matrices cuadradas y rectangulares:
   ```bash
   ./cubico_tradicional
   ```

#### Algoritmo cúbico optimizado
1. Compilar el algoritmo cúbico optimizado:
   ```bash
   g++ 6.cubico_optimizado.cpp -o cubico_optimizado
   ```
2. Ejecutar la multiplicación con matrices cuadradas y rectangulares:
   ```bash
   ./cubico_optimizado
   ```

#### Algoritmo de Strassen
1. Compilar el algoritmo de Strassen:
   ```bash
   g++ 7.strassen.cpp -o strassen
   ```
2. Ejecutar la multiplicación con matrices cuadradas y rectangulares:
   ```bash
   ./strassen
   ```

### Explicación:

1. **Algoritmos de Ordenamiento**: Para cada algoritmo de ordenamiento (Insertion Sort, Merge Sort, Quick Sort y `std::sort`), se describe cómo compilar y ejecutar el código.
2. **Algoritmos de Multiplicación de Matrices**: Similar a los algoritmos de ordenamiento, se incluyen los comandos para compilar y ejecutar el algoritmo cúbico tradicional, cúbico optimizado, y Strassen.
