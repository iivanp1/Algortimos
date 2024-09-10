# Algoritmos

## Compilación y Ejecución de Algoritmos

### Generación de Datasets de Ordenamiento

Primero, se deben generar los datasets de prueba para los algoritmos de ordenamiento. Estos datasets simulan diferentes casos de ordenamiento como conjuntos completamente desordenados, semi-ordenados y parcialmente ordenados.

```bash
# Compilar el generador de datasets para ordenamiento
g++ datasets.cpp -o generar_datasets

# Generar los datasets de prueba
./generar_datasets
# Compilar el algoritmo de Insertion Sort
g++ InsertionSort.cpp -o insertion_sort

# Ejecutar el algoritmo de Insertion Sort
./insertion_sort
# Compilar el algoritmo de Merge Sort
g++ mergesort.cpp -o merge_sort

# Ejecutar el algoritmo de Merge Sort
./merge_sort
# Compilar el algoritmo de Quick Sort
g++ quicksort.cpp -o quick_sort

# Ejecutar el algoritmo de Quick Sort
./quick_sort
# Compilar el algoritmo usando la función estándar std::sort
g++ funcionsort.cpp -o std_sort

# Ejecutar el algoritmo con std::sort
./std_sort
# Compilar el generador de datasets para matrices
g++ datasetmatriz.cpp -o generar_matrices

# Generar matrices cuadradas de 1000x1000 y matrices rectangulares de 1000x500 y 500x1000
./generar_matrices
# Compilar el algoritmo cúbico tradicional
g++ algo_iterativo_cubicotradicional.cpp -o cubico_tradicional

# Ejecutar la multiplicación con matrices cuadradas y rectangulares
./cubico_tradicional
# Compilar el algoritmo cúbico optimizado
g++ matriztranspuesta.cpp -o cubico_optimizado

# Ejecutar la multiplicación con matrices cuadradas y rectangulares
./cubico_optimizado
# Compilar el algoritmo de Strassen
g++ strassen.cpp -o strassen

# Ejecutar la multiplicación con matrices cuadradas y rectangulares
./strassen
