#include "Race.hpp"

/**
 * Inicializa raceId y year a 0, circuit a nullptr,
 * name y date a cadenas vacías.
 */
Race::Race()
    : raceId(0),
      year(0),
      circuit(nullptr),
      name(""),
      date("")
{}

/**
 * Inicializa todos los campos con los valores recibidos.
 */
Race::Race(int raceId,
           int year,
           const Circuit* circuit,
           const string& name,
           const string& date)
    : raceId(raceId),
      year(year),
      circuit(circuit),
      name(name),
      date(date)
{}
