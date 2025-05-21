#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Clase sencilla para leer archivos CSV
class CSVReader {
public:
    // Elimina todas las comillas dobles de una cadena
    static string removeQuotes(const string& input);

    // Lee un CSV línea por línea y devuelve una matriz de celdas
    vector<vector<string>> readCSV(const string& filename);
};

#endif // CSVREADER_HPP
