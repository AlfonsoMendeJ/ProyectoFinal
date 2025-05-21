#ifndef RACE_HPP
#define RACE_HPP

#include "Circuit.hpp"
#include <string>

using namespace std;

/**
 * Representa una carrera en el calendario.
 */
class Race {
public:
    int raceId;             // Identificador único de la carrera
    int year;               // Año en que se celebra
    const Circuit* circuit; // Puntero al circuito donde tiene lugar
    string name;            // Nombre de la carrera
    string date;            // Fecha de la carrera (por ejemplo, "2025-05-17")

    /**
     * Constructor por defecto: inicializa valores a 0 o nullptr,
     * cadenas vacías.
     */
    Race();

    /**
     * Constructor parametrizado.
     *
     * @param raceId   ID de la carrera
     * @param year     Año de la carrera
     * @param circuit  Puntero al objeto Circuit correspondiente
     * @param name     Nombre de la carrera
     * @param date     Fecha (string) de la carrera
     */
    Race(int raceId,
         int year,
         const Circuit* circuit,
         const string& name,
         const string& date);
};

#endif // RACE_HPP
