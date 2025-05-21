#ifndef DRIVINGANALYSIS_HPP
#define DRIVINGANALYSIS_HPP

#include <map>
#include <memory>
#include <string>
#include "Driver.hpp"
#include "Team.hpp"
#include "Race.hpp"
#include "ResultsInfo.hpp"

using namespace std;

// Estructuras para acumular estadísticas
struct DriverStats {
    // …campos con totales, medias, etc.
};
struct TeamStats {
    // …campos con totales, medias, etc.
};

/**
 * Encapsula análisis sobre resultados: top drivers y teams,
 * impresión y guardado de informes.
 */
class DrivingAnalysis {
public:
    /**
     * Calcula estadísticas de los mejores pilotos entre dos años.
     *
     * @param startYear    Año inicial (inclusive)
     * @param endYear      Año final (inclusive)
     * @param drivers      Mapa de pilotos cargados
     * @param resultsInfo  Resultados polimórficos leídos
     * @param races        Mapa de carreras cargadas
     * @return             Mapa driverName → DriverStats
     */
    map<string, DriverStats> calculateTopDrivers(
        int startYear,
        int endYear,
        const map<int, Driver>& drivers,
        const map<int, unique_ptr<ResultsInfo>>& resultsInfo,
        const map<int, Race>& races);

    /**
     * Calcula estadísticas de los mejores equipos entre dos años.
     *
     * @param startYear    Año inicial (inclusive)
     * @param endYear      Año final (inclusive)
     * @param teams        Mapa de equipos cargados
     * @param resultsInfo  Resultados polimórficos leídos
     * @param races        Mapa de carreras cargadas
     * @return             Mapa teamName → TeamStats
     */
    map<string, TeamStats> calculateTopTeams(
        int startYear,
        int endYear,
        const map<int, Team>& teams,
        const map<int, unique_ptr<ResultsInfo>>& resultsInfo,
        const map<int, Race>& races);

    /**
     * Muestra por consola las estadísticas de pilotos.
     */
    void printDriverStats(const map<string, DriverStats>& stats);

    /**
     * Guarda en un CSV las estadísticas de pilotos.
     */
    void saveDriverStatsToFile(const map<string, DriverStats>& stats,
                               const string& filename);

    /**
     * Muestra por consola las estadísticas de equipos.
     */
    void printTeamStats(const map<string, TeamStats>& stats);

    /**
     * Guarda en un CSV las estadísticas de equipos.
     */
    void saveTeamStatsToFile(const map<string, TeamStats>& stats,
                             const string& filename);
};

#endif // DRIVINGANALYSIS_HPP
