#ifndef RESULTS_INFO_TEAM_HPP
#define RESULTS_INFO_TEAM_HPP

#include "ResultsInfo.hpp"
#include "Team.hpp"

using namespace std;

/**
 * Subclase de ResultsInfo para resultados de equipos.
 */
class ResultsInfoTeam : public ResultsInfo {
    const Team* team; // Puntero al equipo

public:
    /**
     * Constructor por defecto: llama al base e inicializa team a nullptr.
     */
    ResultsInfoTeam();

    /**
     * Constructor parametrizado.
     *
     * @param resultId  ID del resultado
     * @param team      Puntero al equipo
     * @param race      Puntero a la carrera
     * @param grid      Posición en parrilla
     * @param position  Posición final
     * @param points    Puntos obtenidos
     */
    ResultsInfoTeam(int resultId,
                    const Team* team,
                    const Race* race,
                    int grid,
                    int position,
                    int points);

    /**
     * Implementación de key(): devuelve el nombre del equipo.
     */
    string key() const override {
        return team ? team->getName() : string{};
    }

    const Team* getTeam() const { return team; }
};

#endif // RESULTS_INFO_TEAM_HPP
