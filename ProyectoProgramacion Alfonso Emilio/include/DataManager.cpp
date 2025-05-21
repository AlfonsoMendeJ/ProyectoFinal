// DataManager.cpp

#include "DataManager.hpp"
#include "ResultsInfoDriver.hpp"
#include "ResultsInfoTeam.hpp"
#include "CSVReader.hpp"

#include <utility>   // std::move
#include <stdexcept> // stoi excepciones

using namespace std;

map<int, Circuit> DataManager::loadCircuits(const string& filename) {
    CSVReader reader;
    auto data = reader.readCSV(filename);
    map<int, Circuit> circuits;

    // Fila 0 = cabeceras
    for (size_t i = 1; i < data.size(); ++i) {
        const auto& row = data[i];
        if (row.size() >= 5) {
            try {
                int id       = stoi(row[0]);
                string name  = row[2];
                string loc   = row[3];
                string country = row[4];
                circuits.emplace(id, Circuit(id, name, loc, country));
            } catch (...) {
                // Ignoramos filas mal formateadas
            }
        }
    }
    return circuits;
}

map<int, Race> DataManager::loadRaces(
    const string& filename,
    const map<int, Circuit>& circuits)
{
    CSVReader reader;
    auto data = reader.readCSV(filename);
    map<int, Race> races;

    for (size_t i = 1; i < data.size(); ++i) {
        const auto& row = data[i];
        if (row.size() >= 6) {
            try {
                int id       = stoi(row[0]);
                int year     = stoi(row[1]);
                int cid      = stoi(row[3]);
                string name  = row[4];
                string date  = row[5];
                const Circuit* cp = circuits.count(cid) ? &circuits.at(cid) : nullptr;
                races.emplace(id, Race(id, year, cp, name, date));
            } catch (...) {
            }
        }
    }
    return races;
}

map<int, Driver> DataManager::loadDrivers(const string& filename) {
    CSVReader reader;
    auto data = reader.readCSV(filename);
    map<int, Driver> drivers;

    for (size_t i = 1; i < data.size(); ++i) {
        const auto& row = data[i];
        if (row.size() >= 8) {
            try {
                int id        = stoi(row[0]);
                string code   = row[3];
                string full   = row[4] + " " + row[5];
                string dob    = row[6];
                string nat    = row[7];
                drivers.emplace(id, Driver(id, code, full, dob, nat));
            } catch (...) {
            }
        }
    }
    return drivers;
}

map<int, Team> DataManager::loadTeams(const string& filename) {
    CSVReader reader;
    auto data = reader.readCSV(filename);
    map<int, Team> teams;

    for (size_t i = 1; i < data.size(); ++i) {
        const auto& row = data[i];
        if (row.size() >= 4) {
            try {
                int id      = stoi(row[0]);
                string name = row[2];
                string nat  = row[3];
                teams.emplace(id, Team(id, name, nat));
            } catch (...) {
            }
        }
    }
    return teams;
}

map<int, DriverStandings> DataManager::loadDriverStandings(
    const string& filename,
    const map<int, Race>& races,
    const map<int, Driver>& drivers)
{
    CSVReader reader;
    auto data = reader.readCSV(filename);
    map<int, DriverStandings> standings;

    for (size_t i = 1; i < data.size(); ++i) {
        const auto& row = data[i];
        if (row.size() >= 7) {
            try {
                int id        = stoi(row[0]);
                int raceId    = stoi(row[1]);
                int driverId  = stoi(row[2]);
                int pts       = stoi(row[3]);
                int pos       = stoi(row[4]);
                int wins      = stoi(row[6]);
                const Race*   rp = races.count(raceId)   ? &races.at(raceId)   : nullptr;
                const Driver* dp = drivers.count(driverId) ? &drivers.at(driverId) : nullptr;
                standings.emplace(id, DriverStandings(id, rp, dp, pts, pos, wins));
            } catch (...) {
            }
        }
    }
    return standings;
}

map<int, TeamStandings> DataManager::loadTeamStandings(
    const string& filename,
    const map<int, Race>& races,
    const map<int, Team>& teams)
{
    CSVReader reader;
    auto data = reader.readCSV(filename);
    map<int, TeamStandings> standings;

    for (size_t i = 1; i < data.size(); ++i) {
        const auto& row = data[i];
        if (row.size() >= 7) {
            try {
                int id         = stoi(row[0]);
                int raceId     = stoi(row[1]);
                int teamId     = stoi(row[2]);
                int pts        = stoi(row[3]);
                int pos        = stoi(row[4]);
                int winsNumber = stoi(row[6]);
                const Race*   rp = races.count(raceId) ? &races.at(raceId) : nullptr;
                const Team*   tp = teams.count(teamId) ? &teams.at(teamId) : nullptr;
                standings.emplace(id, TeamStandings(id, rp, tp, pts, pos, winsNumber));
            } catch (...) {
            }
        }
    }
    return standings;
}

// ÚNICA implementación de loadResultsInfo
map<int, unique_ptr<ResultsInfo>> DataManager::loadResultsInfo(
    const string& filename,
    const map<int, Driver>& drivers,
    const map<int, Team>& teams,
    const map<int, Race>& races)
{
    CSVReader reader;
    auto data = reader.readCSV(filename);
    map<int, unique_ptr<ResultsInfo>> resultsInfo;

    for (size_t i = 1; i < data.size(); ++i) {
        const auto& row = data[i];
        if (row.size() < 10 ||
            row[1] == "\\N" || row[2] == "\\N" || row[3] == "\\N" ||
            row[5] == "\\N" || row[6] == "\\N" || row[9] == "\\N")
        {
            continue;
        }

        try {
            int idResult = stoi(row[0]);
            int idRace   = stoi(row[1]);
            int idDriver = stoi(row[2]);
            int idTeam   = stoi(row[3]);
            int grid     = stoi(row[5]);
            int position = stoi(row[6]);
            int pts      = stoi(row[9]);

            const Race*   rp = races.count(idRace)   ? &races.at(idRace)   : nullptr;
            const Driver* dp = drivers.count(idDriver) ? &drivers.at(idDriver) : nullptr;
            const Team*   tp = teams.count(idTeam)   ? &teams.at(idTeam)   : nullptr;
            if (!rp || !dp || !tp) continue;

            // Creamos siempre ResultsInfoDriver; podrías alternar con Team
            auto ptr = make_unique<ResultsInfoDriver>(
                idResult, dp, rp, grid, position, pts);

            resultsInfo.emplace(idResult, move(ptr));
        } catch (...) {
            // Saltamos filas con conversión fallida
        }
    }
    return resultsInfo;
}
