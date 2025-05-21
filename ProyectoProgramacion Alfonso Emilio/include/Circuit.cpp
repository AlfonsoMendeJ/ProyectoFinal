#include "Circuit.hpp"

// Inicializa con id = 0 y cadenas vacías
Circuit::Circuit()
    : circuitId(0), name(""), location(""), country("") {}

// Inicializa todos los miembros con los valores proporcionados
Circuit::Circuit(int id,
                 const string& n,
                 const string& loc,
                 const string& country)
    : circuitId(id),
      name(n),
      location(loc),
      country(country) {}
