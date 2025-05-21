#ifndef RESULTSPREDICTOR_HPP
#define RESULTSPREDICTOR_HPP

#include <map>
#include <memory>
#include <string>
#include "Driver.hpp"
#include "Team.hpp"
#include "Race.hpp"
#include "DriverStandings.hpp"
#include "TeamStandings.hpp"
#include "ResultsInfo.hpp"

using namespace std;

/**
 * Encapsula las funciones de predicción de resultados
 * tanto para pilotos como para equipos.
 */
class ResultsPredictor {
public:
    /**
     * Calcula y muestra el impacto de la posición de salida
     * (grid) sobre los puntos obtenidos.
     *
     * @param resultsInfo  Resultados cargados (polimórficos)
     */
    void calculateStartPositionImpact(
        const map<int, unique_ptr<ResultsInfo>>& resultsInfo);

    /**
     * Predicción general de resultados de pilotos,
     * sin filtrar por circuito.
     *
     * @param drivers    Mapa de pilotos
     * @param standings  Clasificaciones de pilotos
     * @param races      Mapa de carreras
     */
    void predictResults(
        const map<int, Driver>& drivers,
        const map<int, DriverStandings>& standings,
        const map<int, Race>& races);

    /**
     * Predicción de resultados de pilotos para un circuito específico.
     *
     * @param drivers      Mapa de pilotos
     * @param standings    Clasificaciones de pilotos
     * @param races        Mapa de carreras
     * @param circuitName  Nombre del circuito
     */
    void predictResults(
        const map<int, Driver>& drivers,
        const map<int, DriverStandings>& standings,
        const map<int, Race>& races,
        const string& circuitName);

    /**
     * Predicción general de resultados de equipos,
     * sin filtrar por circuito.
     *
     * @param teams     Mapa de equipos
     * @param standings Clasificaciones de equipos
     * @param races     Mapa de carreras
     */
    void predictTeamResults(
        const map<int, Team>& teams,
        const map<int, TeamStandings>& standings,
        const map<int, Race>& races);

    /**
     * Predicción de resultados de equipos para un circuito específico.
     *
     * @param teams        Mapa de equipos
     * @param standings    Clasificaciones de equipos
     * @param races        Mapa de carreras
     * @param circuitName  Nombre del circuito
     */
    void predictTeamResults(
        const map<int, Team>& teams,
        const map<int, TeamStandings>& standings,
        const map<int, Race>& races,
        const string& circuitName);
};

#endif // RESULTSPREDICTOR_HPP
