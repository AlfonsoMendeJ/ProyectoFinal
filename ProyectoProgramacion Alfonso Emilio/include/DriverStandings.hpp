#ifndef DRIVER_STANDINGS_HPP
#define DRIVER_STANDINGS_HPP

#include "Race.hpp"
#include "Driver.hpp"

using namespace std;

/**
 * Representa la posición y puntos de un piloto en una carrera.
 * Contiene datos de referencia a Race y Driver.
 */
class DriverStandings {
private:
    int standingsId;        // ID único de esta entrada de clasificación
    const Race* race;       // Puntero a la carrera correspondiente
    const Driver* driver;   // Puntero al piloto
    int points;             // Puntos obtenidos en la carrera
    int position;           // Posición final en la carrera
    int wins;               // Número de victorias acumuladas

public:
    /**
     * Constructor por defecto: inicializa punteros a nullptr y valores a 0.
     */
    DriverStandings();

    /**
     * Constructor parametrizado.
     *
     * @param standingsId  ID de clasificación
     * @param race         Puntero a la carrera
     * @param driver       Puntero al piloto
     * @param points       Puntos obtenidos
     * @param position     Posición final
     * @param wins         Número de victorias
     */
    DriverStandings(int standingsId,
                    const Race* race,
                    const Driver* driver,
                    int points,
                    int position,
                    int wins);

    // Getters para acceder a los datos (inmutables)
    int getStandingsId() const  { return standingsId; }
    const Race* getRace() const { return race; }
    const Driver* getDriver() const { return driver; }
    int getPoints() const       { return points; }
    int getPosition() const     { return position; }
    int getWins() const         { return wins; }
};

#endif // DRIVER_STANDINGS_HPP
