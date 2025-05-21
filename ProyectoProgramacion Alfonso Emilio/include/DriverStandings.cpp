#include "DriverStandings.hpp"

// Inicializa todo a 0 o nullptr
DriverStandings::DriverStandings()
    : standingsId(0),
      race(nullptr),
      driver(nullptr),
      points(0),
      position(0),
      wins(0)
{}

// Inicializa todos los miembros con los parámetros recibidos
DriverStandings::DriverStandings(int standingsId,
                                 const Race* race,
                                 const Driver* driver,
                                 int points,
                                 int position,
                                 int wins)
    : standingsId(standingsId),
      race(race),
      driver(driver),
      points(points),
      position(position),
      wins(wins)
{}
