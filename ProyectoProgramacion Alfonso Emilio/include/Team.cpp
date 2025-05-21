#include "Team.hpp"

// Inicializa miembros a valores por defecto
Team::Team()
    : teamId(0), name(""), nationality("") {}

// Inicializa según parámetros recibidos
Team::Team(int teamId,
           const string& name,
           const string& nationality)
    : teamId(teamId),
      name(name),
      nationality(nationality) {}
