#include "CSVReader.hpp"
#include <algorithm> // std::remove

// Quita todos los caracteres '"' de la cadena
string CSVReader::removeQuotes(const string& input) {
    string result = input;
    result.erase(remove(result.begin(), result.end(), '\"'),
                 result.end());
    return result;
}

// Abre el archivo, lo recorre línea a línea y separa por comas
vector<vector<string>> CSVReader::readCSV(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    string line;

    // Por cada línea en el archivo
    while (getline(file, line)) {
        stringstream lineStream(line);
        string cell;
        vector<string> rowData;

        // Separa la línea en celdas por cada coma
        while (getline(lineStream, cell, ',')) {
            // Limpia posibles comillas y añade a la fila
            rowData.push_back(removeQuotes(cell));
        }

        data.push_back(rowData);
    }

    file.close();
    return data;
}
