#include <iostream>   // Para cin, cout, cerr
#include <map>        // Para std::map
#include <memory>     // Para std::unique_ptr
#include <stdexcept>  // Para std::invalid_argument

// Incluimos los headers de nuestro dominio (carpeta include/)
#include "include/Circuit.hpp"
#include "include/Race.hpp"
#include "include/Driver.hpp"
#include "include/Team.hpp"
#include "include/DriverStandings.hpp"
#include "include/TeamStandings.hpp"
#include "include/ResultsInfo.hpp"
#include "include/DataManager.hpp"
#include "include/ResultsPredictor.hpp"
#include "include/DrivingAnalysis.hpp"
#include "include/StrategyRecommendation.hpp"

using namespace std;

int main() {
    // Objetos principales para orquestar la lógica
    DataManager dataManager;               // Carga datos desde CSV
    ResultsPredictor predictor;            // Predice resultados
    DrivingAnalysis analysis;              // Analiza estadísticas
    StrategyRecommendation strategy;       // Recomienda estrategia de carrera

    // Rutas a los archivos CSV que contienen los datos
    const string circuitsFilename        = "Database/circuits.csv";
    const string racesFilename           = "Database/races.csv";
    const string driverFilename          = "Database/drivers.csv";
    const string driverStandingsFilename = "Database/driver_standings.csv";
    const string teamFilename            = "Database/constructors.csv";
    const string teamStandingsFilename   = "Database/constructor_standings.csv";
    const string resultsInfoFilename     = "Database/results.csv";

    // Cargamos todos los datos en colecciones indexadas por ID
    map<int, Circuit> circuits =
        dataManager.loadCircuits(circuitsFilename);

    map<int, Race> races =
        dataManager.loadRaces(racesFilename, circuits);

    map<int, Driver> drivers =
        dataManager.loadDrivers(driverFilename);

    map<int, Team> teams =
        dataManager.loadTeams(teamFilename);

    map<int, DriverStandings> standings =
        dataManager.loadDriverStandings(
            driverStandingsFilename, races, drivers);

    map<int, TeamStandings> teamStandings =
        dataManager.loadTeamStandings(
            teamStandingsFilename, races, teams);

    // Cargamos los resultados en punteros polimórficos
    map<int, unique_ptr<ResultsInfo>> resultsInfo =
        dataManager.loadResultsInfo(
            resultsInfoFilename, drivers, teams, races);

    // Bucle principal del menú de usuario
    while (true) {
        // Mostramos las opciones disponibles
        cout << "\n--- Main Menu ---\n";
        cout << "1. Driver Results Prediction\n";
        cout << "2. Team Results Prediction\n";
        cout << "3. Predict Importance of Start Position\n";
        cout << "4. Top 5 Drivers Analysis\n";
        cout << "5. Generate Report of Top 5 Drivers\n";
        cout << "6. Top 5 Teams Analysis\n";
        cout << "7. Generate Report of Top 5 Teams\n";
        cout << "8. Pit Stop and Tire Strategy Recommendation\n";
        cout << "9. Fuel Strategy Recommendation\n";
        cout << "10. Car Setup Recommendation\n";
        cout << "11. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore();  // Limpiamos el '\n' del buffer

        switch (choice) {
            case 1: { // Predicción de resultados de pilotos
                cout << "1. General Prediction\n";
                cout << "2. Prediction by Circuit\n";
                cout << "Choose an option for the prediction: ";
                int subChoice;
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 1) {
                    // Llamada a la versión genérica
                    predictor.predictResults(drivers, standings, races);
                }
                else if (subChoice == 2) {
                    // Llamada por circuito con control de entrada
                    string circuitName;
                    cout << "Enter Circuit Name: ";
                    getline(cin, circuitName);
                    try {
                        if (circuitName.empty())
                            throw invalid_argument(
                                "El nombre de circuito no puede estar vacío.");
                        predictor.predictResults(
                            drivers, standings, races, circuitName);
                    }
                    catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << "\n";
                    }
                }
                else {
                    cout << "Invalid option. Please try again.\n";
                }
                break;
            }

            case 2: { // Predicción de resultados de equipos
                cout << "1. General Prediction\n";
                cout << "2. Prediction by Circuit\n";
                cout << "Choose an option for the prediction: ";
                int subChoice;
                cin >> subChoice;
                cin.ignore();

                if (subChoice == 1) {
                    predictor.predictTeamResults(
                        teams, teamStandings, races);
                }
                else if (subChoice == 2) {
                    string circuitName;
                    cout << "Enter Circuit Name: ";
                    getline(cin, circuitName);
                    try {
                        if (circuitName.empty())
                            throw invalid_argument(
                                "El nombre de circuito no puede estar vacío.");
                        predictor.predictTeamResults(
                            teams, teamStandings, races, circuitName);
                    }
                    catch (const invalid_argument& e) {
                        cerr << "Error: " << e.what() << "\n";
                    }
                }
                else {
                    cout << "Invalid option. Please try again.\n";
                }
                break;
            }

            case 3:
                // Impacto de la posición de salida
                predictor.calculateStartPositionImpact(resultsInfo);
                break;

            case 4: { // Análisis Top 5 pilotos
                int startYear, endYear;
                cout << "Enter start year: ";
                cin >> startYear;
                cout << "Enter end year: ";
                cin >> endYear;
                auto topDrivers = analysis.calculateTopDrivers(
                    startYear, endYear, drivers, resultsInfo, races);
                analysis.printDriverStats(topDrivers);
                break;
            }

            case 5: { // Generar informe Top 5 pilotos
                string filename;
                int startYear, endYear;
                cout << "Enter filename to save report: ";
                getline(cin, filename);
                cout << "Enter start year: ";
                cin >> startYear;
                cout << "Enter end year: ";
                cin >> endYear;
                auto topDrivers = analysis.calculateTopDrivers(
                    startYear, endYear, drivers, resultsInfo, races);
                analysis.saveDriverStatsToFile(topDrivers, filename);
                cout << "Report saved to '" << filename << "'\n";
                break;
            }

            case 6: { // Análisis Top 5 equipos
                int startYear, endYear;
                cout << "Enter start year: ";
                cin >> startYear;
                cout << "Enter end year: ";
                cin >> endYear;
                auto topTeams = analysis.calculateTopTeams(
                    startYear, endYear, teams, resultsInfo, races);
                analysis.printTeamStats(topTeams);
                break;
            }

            case 7: { // Generar informe Top 5 equipos
                string filename;
                int startYear, endYear;
                cout << "Enter filename to save report: ";
                getline(cin, filename);
                cout << "Enter start year: ";
                cin >> startYear;
                cout << "Enter end year: ";
                cin >> endYear;
                auto topTeams = analysis.calculateTopTeams(
                    startYear, endYear, teams, resultsInfo, races);
                analysis.saveTeamStatsToFile(topTeams, filename);
                cout << "Report saved to '" << filename << "'\n";
                break;
            }

            case 8: { // Recomendaciones de pit stops y neumáticos
                string weather;
                int laps;
                double circuitLength;
                cout << "Enter weather conditions (rainy, hot, etc.): ";
                getline(cin, weather);
                cout << "Enter number of laps: ";
                cin >> laps;
                cout << "Enter circuit length in km: ";
                cin >> circuitLength;
                cin.ignore();
                cout << strategy.recommendPitStops(
                    weather, laps, circuitLength) << endl;
                cout << strategy.recommendTireType(weather, laps) << endl;
                break;
            }

            case 9: { // Recomendación de estrategia de combustible
                string weather;
                int laps;
                double circuitLength;
                cout << "Enter weather conditions (rainy, hot, etc.): ";
                getline(cin, weather);
                cout << "Enter number of laps: ";
                cin >> laps;
                cout << "Enter circuit length in km: ";
                cin >> circuitLength;
                cin.ignore();
                cout << strategy.recommendFuelStrategy(
                    laps, circuitLength, weather) << endl;
                break;
            }

            case 10: { // Recomendación de setup de coche
                string circuitType, weather;
                cout << "Enter circuit type (highDownforce, highSpeed, etc.): ";
                getline(cin, circuitType);
                cout << "Enter weather conditions (rainy, hot, etc.): ";
                getline(cin, weather);
                cout << strategy.recommendCarSetup(
                    circuitType, weather) << endl;
                break;
            }

            case 11:
                cout << "Exiting program...\n";
                return 0;  // Salimos

            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}
