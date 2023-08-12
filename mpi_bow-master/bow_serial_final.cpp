#include <map>
#include <string>
#include <iostream>
#include <omp.h>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;
/**
 * Counts all the words on each text file and stores them on a dictionary.
 * 
 * @param file_name The name of the text file
 * @param dict Dictionary containing all the words on the corpus
 * @returns A dictionary with all the word frequencies.
*/
//Cuenta las palabras de cada obra y las guarda en un diccionario, recibe el diccionario de palabras y el nombre del archivo
map<string, int> read_count_words(string file_name,map<string, int> dict){
    vector<int> count;
    std::ifstream file;
    file.open(file_name);
    while (!file.eof()){
        string word;
        getline(file,word,',');
        dict[word]+=1;
        for(int i = 0; i<50;i++){
            count.push_back(i);
        }
    }
    file.close();
    return dict;
}

/**
 * Reads a text file with all the words on the corpus into a dictionary.
 * 
 * @param file_name The name of the dictionary text file
 * @returns A dictionary with keys initialized as all the words on the corpus
 */
map<string, int> read_dictionary(string file_name){
    map<string, int> dict;
    std::ifstream file;
    file.open(file_name);
    while (!file.eof()){
        string word;
        getline(file,word,',');
        dict.insert({word,0});
    }
    file.close();
    return dict;
}

/**
 * Gets an array with all the words on the corpus.
 * 
 * @param `words` A dictionary containing the words on the corpus
 * @return A `string` array containing all the strings on the `words` dictionary
 */
string* get_word_list(map<string, int> words){
    int index = 0;
    string* palabras = new string[words.size()];
    for (auto iterator = words.begin(); iterator != words.end(); ++iterator) {
        palabras[index] = iterator->first;
        index++;
    }
    return palabras;
}

/**
 * Stores the BOW matrix on a `.csv` file.
 * 
 * @param words A string array containing the words on the dictionary
 * @param file_name The name of the resulting `csv` file.
 * @param bow The BOW dictionary
 * @param num_lecturas The number of texts on the corpus
 * @param num_palabras size of the `words` array
 */
void save_csv_list(string* words,string file_name,map<string, int>* bow,int num_lecturas,int num_palabras){
    fstream fout;
    fout.open(file_name, ios::out);
    for (int i = 0; i< num_palabras; i++){
        fout << words[i] << ",";
    }
    fout << "\n";
    for (int i = 0; i < num_lecturas; i++){
        for (int j = 0; j < num_palabras; j++){
            fout << bow[i][words[j]] << ",";
        }
        fout << "\n";
    }
}

int main (int argc, char *argv[]) {
    const int num_lecturas = 6;
    //Nombres de los archivos a leer
    string libros[num_lecturas] = {"shakespeare_the_merchant_of_venice.txt", 
                                   "shakespeare_romeo_juliet.txt", 
                                   "shakespeare_hamlet.txt", 
                                   "dickens_a_christmas_carol.txt", 
                                   "dickens_oliver_twist.txt",
                                   "dickens_a_tale_of_two_cities.txt"};
    //Lista de diccionarios para almacenar resultados
    map<string, int>* bow = new map<string, int>[num_lecturas];

    //Lectura del diccionario de palabras 
    map<string, int> words = read_dictionary("diccionario.txt");

    const int num_palabras =  words.size();

    string* lista_palabras = new string[num_palabras];

    //Lista de palabras 
    string* palabras = get_word_list(words);

    auto start = high_resolution_clock::now();

    //Llenado de matriz con diccionarios
    for (int i = 0; i < num_lecturas; i++){
        map<string, int> text = read_count_words(libros[i],words);
        bow[i] = text;
    }

    //Finalizar conteo del tiempo
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(end - start);

    cout <<float(duration.count())/1000<<'\n';

    //Guardar csv
    save_csv_list(palabras,"serial_bow.csv",bow,num_lecturas,num_palabras);

    return 0;
}