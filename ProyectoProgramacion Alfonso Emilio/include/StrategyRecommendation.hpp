#ifndef STRATEGY_RECOMMENDATION_HPP
#define STRATEGY_RECOMMENDATION_HPP

#include <string>
using namespace std;

/**
 * Ofrece recomendaciones de estrategia de carrera:
 * pit stops, tipo de neumáticos, combustible y setup.
 */
class StrategyRecommendation {
public:
    /**
     * Recomienda número de paradas según clima y longitud.
     */
    string recommendPitStops(const string& weather,
                             int laps,
                             double circuitLength);

    /**
     * Recomienda tipo de neumático según las condiciones.
     */
    string recommendTireType(const string& weather,
                             int laps);

    /**
     * Calcula cantidad de combustible necesaria.
     */
    string recommendFuelStrategy(int laps,
                                 double circuitLength,
                                 const string& weather);

    /**
     * Sugiere setup de coche según tipo de circuito y clima.
     */
    string recommendCarSetup(const string& circuitType,
                             const string& weather);
};

#endif // STRATEGY_RECOMMENDATION_HPP
