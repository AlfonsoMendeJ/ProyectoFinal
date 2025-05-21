#include "ResultsInfoTeam.hpp"

/**
 * Constructor por defecto.
 */
ResultsInfoTeam::ResultsInfoTeam()
    : ResultsInfo(), team(nullptr)
{}

/**
 * Constructor parametrizado: delega al base y guarda el puntero a team.
 */
ResultsInfoTeam::ResultsInfoTeam(int resultId,
                                 const Team* team,
                                 const Race* race,
                                 int grid,
                                 int position,
                                 int points)
    : ResultsInfo(resultId, race, grid, position, points),
      team(team)
{}
