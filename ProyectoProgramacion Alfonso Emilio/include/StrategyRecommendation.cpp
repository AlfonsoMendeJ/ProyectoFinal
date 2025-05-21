#include "StrategyRecommendation.hpp"

/**
 * Basado en laps y clima, estima paradas.
 */
string StrategyRecommendation::recommendPitStops(
    const string& weather, int laps, double circuitLength)
{
    if (weather == "rainy") {
        return to_string(laps / 20 + 1)
             + " pit stops are recommended due to wet conditions.";
    } else {
        return to_string(laps / 30 + 1)
             + " pit stops are recommended.";
    }
}

/**
 * Elige neumático según clima.
 */
string StrategyRecommendation::recommendTireType(
    const string& weather, int laps)
{
    if (weather == "rainy") {
        return "Wet tires are recommended.";
    } else if (weather == "hot") {
        return "Soft tires are recommended for better grip.";
    } else {
        return "Hard tires are recommended for durability.";
    }
}

/**
 * Estima combustible necesario en kg.
 */
string StrategyRecommendation::recommendFuelStrategy(
    int laps, double circuitLength, const string& weather)
{
    double fuelPerLap = 2.4; // kg/vuelta estimado
    double fuelNeeded = laps * fuelPerLap;
    return "Estimated fuel needed: "
         + to_string(fuelNeeded) + " kg.";
}

/**
 * Sugiere configuración de aerodinámica según circuito y clima.
 */
string StrategyRecommendation::recommendCarSetup(
    const string& circuitType, const string& weather)
{
    if (circuitType == "highDownforce" && weather == "rainy") {
        return "Increase downforce and use full wets.";
    } else if (circuitType == "highSpeed") {
        return "Decrease downforce for better top speed.";
    } else {
        return "Standard setup recommended.";
    }
}
