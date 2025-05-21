#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <string>
using namespace std;

/**
 * Representa un piloto de la competición.
 */
class Driver {
public:
    int driverId;       // Identificador único del piloto
    string code;        // Código de piloto (p. ej. abreviatura)
    string fullName;    // Nombre completo
    string dob;         // Fecha de nacimiento en formato string
    string nationality; // Nacionalidad

    /**
     * Constructor por defecto: inicializa campos numéricos a 0 y strings vacíos.
     */
    Driver();

    /**
     * Constructor parametrizado: inicializa todos los miembros con los valores dados.
     *
     * @param driverId     Identificador del piloto
     * @param code         Código del piloto
     * @param fullName     Nombre completo
     * @param dob          Fecha de nacimiento
     * @param nationality  Nacionalidad
     */
    Driver(int driverId,
           const string& code,
           const string& fullName,
           const string& dob,
           const string& nationality);

    /**
     * Devuelve el nombre completo.
     * Utilizado por ResultsInfoDriver para mostrar la clave.
     */
    const string& getName() const { return fullName; }
};

#endif // DRIVER_HPP
