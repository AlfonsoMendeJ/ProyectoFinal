#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <map>
#include <string>
#include <memory>
#include <iostream>

#include "Circuit.hpp"
#include "Race.hpp"
#include "Driver.hpp"
#include "Team.hpp"
#include "DriverStandings.hpp"
#include "TeamStandings.hpp"
#include "ResultsInfo.hpp"
#include "ResultsInfoDriver.hpp"
#include "ResultsInfoTeam.hpp"
#include "CSVReader.hpp"

using namespace std;

// Encapsula la carga de todos los datos desde ficheros CSV
class DataManager {
public:
    // Carga circuitos y los indexa por su ID
    map<int, Circuit> loadCircuits(const string& filename);

    // Carga carreras, asociando cada una a su Circuit*
    map<int, Race> loadRaces(const string& filename,
                             const map<int, Circuit>& circuits);

    // Carga datos de pilotos
    map<int, Driver> loadDrivers(const string& filename);

    // Carga datos de equipos
    map<int, Team> loadTeams(const string& filename);

    // Carga la clasificación de pilotos por carrera
    map<int, DriverStandings> loadDriverStandings(
        const string& filename,
        const map<int, Race>& races,
        const map<int, Driver>& drivers);

    // Carga la clasificación de equipos por carrera
    map<int, TeamStandings> loadTeamStandings(
        const string& filename,
        const map<int, Race>& races,
        const map<int, Team>& teams);

    // Carga resultados de carrera y crea instancias polimórficas de ResultsInfo
    map<int, unique_ptr<ResultsInfo>> loadResultsInfo(
        const string& filename,
        const map<int, Driver>& drivers,
        const map<int, Team>& teams,
        const map<int, Race>& races);
};

#endif // DATAMANAGER_HPP
