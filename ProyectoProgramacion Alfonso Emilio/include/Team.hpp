#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
using namespace std;

/**
 * Representa un equipo constructor.
 */
class Team {
public:
    int teamId;         // Identificador único del equipo
    string name;        // Nombre del equipo
    string nationality; // Nacionalidad del equipo

    /**
     * Constructor por defecto: inicializa a 0 y cadenas vacías.
     */
    Team();

    /**
     * Constructor parametrizado.
     *
     * @param teamId      ID del equipo
     * @param name        Nombre del equipo
     * @param nationality Nacionalidad
     */
    Team(int teamId,
         const string& name,
         const string& nationality);

    /**
     * Devuelve el nombre, usado por ResultsInfoTeam.
     */
    const string& getName() const { return name; }
};

#endif // TEAM_HPP
