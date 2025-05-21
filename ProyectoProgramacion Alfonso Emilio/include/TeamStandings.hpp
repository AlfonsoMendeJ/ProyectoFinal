#ifndef TEAM_STANDINGS_HPP
#define TEAM_STANDINGS_HPP

#include "Team.hpp"
#include "Race.hpp"

/**
 * Representa la clasificación de un equipo en una carrera.
 */
class TeamStandings {
public:
    int teamStandingsId;    // ID único de esta entrada
    const Race* race;       // Puntero a la carrera
    const Team* team;       // Puntero al equipo
    int points;             // Puntos obtenidos
    int position;           // Posición final
    int winsNumber;         // Número de victorias

    /**
     * Constructor por defecto: inicializa a nullptr y 0.
     */
    TeamStandings();

    /**
     * Constructor parametrizado.
     *
     * @param teamStandingsId  ID de la clasificación
     * @param race             Puntero a la carrera
     * @param team             Puntero al equipo
     * @param points           Puntos obtenidos
     * @param position         Posición final
     * @param winsNumber       Número de victorias
     */
    TeamStandings(int teamStandingsId,
                  const Race* race,
                  const Team* team,
                  int points,
                  int position,
                  int winsNumber);
};

#endif // TEAM_STANDINGS_HPP
