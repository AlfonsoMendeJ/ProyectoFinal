#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <string>

using namespace std;

// Representa un circuito de competición
class Circuit {
public:
    int circuitId;    // Identificador único del circuito
    string name;      // Nombre del circuito
    string location;  // Ciudad o región donde se ubica
    string country;   // País del circuito

    // Constructor por defecto: inicializa todo a valores “vacíos”
    Circuit();

    // Constructor parametrizado: asigna campo por campo
    Circuit(int id,
            const string& n,
            const string& loc,
            const string& country);
};

#endif // CIRCUIT_HPP
