#include <iostream>
#include <fstream>
#include <string>
#include <mpi.h>

using namespace std;

// funcion que lee una linea del archivo como string y separa los datos por comas en un arreglo de strings
string* readLine(ifstream& file, int& size) {
    string line;
    getline(file, line);
    size = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
            size++;
        }
    }
    size++;
    string* data = new string[size];
    int index = 0;
    int start = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
            data[index] = line.substr(start, i - start);
            start = i + 1;
            index++;
        }
    }
    data[index] = line.substr(start, line.length() - start);
    return data;
}

// Funcion que agregue arreglos de strings a un arreglo de arreglos de strings
void addToArray(string**& array, string* data, int& size) {
    string** temp = new string * [size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    temp[size] = data;
    if (size > 0) {
        delete[] array;
    }
    size++;
    array = temp;
}

// Funcion para agregar elementos de un arreglo a una fila de una matriz de strings
void addRow(string**& array, string* data, int& size) {
    string** temp = new string * [size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    temp[size] = data;
    if (size > 0) {
        delete[] array;
    }
    size++;
    array = temp;
}

// Funcion para contar el numero de veces que se repiten los valores de un arreglo de strings en otro arreglo de strings
int* countVectorizer(string* data, string* data2, int size, int size2) {
    int* vector = new int[size];
    for (int i = 0; i < size; i++) {
        vector[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size2; j++) {
            if (data[i] == data2[j]) {
                vector[i]++;
            }
        }
    }
    return vector;
}

// Function to append ints to an array of ints
void appendToArray(int*& array, int data, int& size) {
    int* temp = new int[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    temp[size] = data;
    if (size > 0) {
        delete[] array;
    }
    size++;
    array = temp;
}

// function to concatenate two string arrays
string* concatenateArrays(string* array1, string* array2, int size1, int size2) {
    string* array = new string[size1 + size2];
    for (int i = 0; i < size1; i++) {
        array[i] = array1[i];
    }
    for (int i = 0; i < size2; i++) {
        array[i + size1] = array2[i];
    }
    return array;
}

// funcion para borrar todos los duplicados en un array de strings
string* deleteDuplicates(string* array, int& size) {
    string* temp = new string[size];
    int index = 0;
    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < index; j++) {
            if (array[i] == temp[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[index] = array[i];
            index++;
        }
    }
    string* newArray = new string[index];
    for (int i = 0; i < index; i++) {
        newArray[i] = temp[i];
    }
    delete[] temp;
    size = index;
    return newArray;
}

// Funcion para ordenar por orden alfabetico un arreglo de strings
void sortArray(string*& array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Funcion para hacer cast a un arreglo de ints a un arreglo de strings
string* intToString(int* array, int size) {
    string* newArray = new string[size];
    for (int i = 0; i < size; i++) {
        newArray[i] = to_string(array[i]);
    }
    return newArray;
}

// Función para pasar de una matriz con filas y columnas a un archivo csv
void matrixToCSV(string** matrix, int rows, int columns, string filename) {
    ofstream file;
    file.open(filename);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            file << matrix[i][j];
            if (j < columns - 1) {
                file << ",";
            }
        }
        file << endl;
    }
    file.close();
}

int main(int argc, char** argv)
{

    int num_processes = 0;
    int process_id = 0; 
    int name_length = 0;
    char host_name[MPI_MAX_PROCESSOR_NAME];

    int size_array;
    int rows = 0;
    int n = 6;
    int size = 0;
    int size_aux = 0;
    int n_aux = 0;
    int* size_array_data = new int[n];
    string* array_of_words;
    string** array;
    string** matrix = new string * [n];
    string path = "C://Users//javi2//Documents//ComputoParalelo//C++//mpi//Libros//";
    string path_to_save = "C://Users//javi2//Documents//ComputoParalelo//C++//mpi//Resultados//";
    string files[n] = {"dickens_a_christmas_carol.txt","dickens_a_tale_of_two_cities.txt","dickens_oliver_twist.txt","shakespeare_hamlet.txt","shakespeare_romeo_juliet.txt","shakespeare_the_merchant_of_venice.txt"};
    


    MPI_Init(&argc, &argv); //inicializa una parte paralela y asignale ¿4?
    //Aqui empiza lo paralelo
    //es donde van las tasks
    MPI_Comm_size(MPI_COMM_WORLD, &num_processes); //MPI_COMM_WORLD is the communicator 
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    MPI_Get_processor_name(host_name, &name_length);

    
    ifstream myfile (path + files[process_id]);
    string* data = readLine(myfile, size_array);
    myfile.close();
    cout << "Archivo: " << files[process_id] << endl;
    cout << "Size: " << size_array << endl;

    // MPI_Gather(&size_array, 1, MPI_INT);
    // MPI_Gather(&size_array_data, n, MPI_INT);
    // MPI_Gather(&array, n, MPI_INT);
    
    appendToArray(size_array_data, size_array, n_aux);
    addToArray(array, data, size_aux);
    array_of_words = concatenateArrays(array_of_words, data, size, size_array);
    size += size_array;

    MPI_Finalize();
    


    array_of_words = deleteDuplicates(array_of_words, size);
    sortArray(array_of_words, size);
    cout << "Size of array of words: " << size << endl;
    addRow(matrix, array_of_words, rows);


    MPI_Init(&argc, &argv); //inicializa una parte paralela y asignale ¿4?
    //Aqui empiza lo paralelo
    //es donde van las tasks
    MPI_Comm_size(MPI_COMM_WORLD, &num_processes); //MPI_COMM_WORLD is the communicator 
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    MPI_Get_processor_name(host_name, &name_length);

    int* vector = countVectorizer(array_of_words, array[process_id], size, size_array_data[process_id]);
    addRow(matrix, intToString(vector,size), rows);
    MPI_Finalize();

    // print the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 15; j < 25; j++) {
            if(i == 0){
                cout << matrix[i][j] << "  ";
            }
            else{
                cout << matrix[i][j] << "    ";
            }
        }
        cout << endl;
    }

    matrixToCSV(matrix, rows, size, path_to_save + "results.csv");
}