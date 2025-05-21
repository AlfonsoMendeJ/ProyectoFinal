#include "ResultsInfo.hpp"

/**
 * Constructor por defecto: inicializa todas las propiedades a
 * valores “vacíos” (0 o nullptr).
 */
ResultsInfo::ResultsInfo()
    : resultId(0),
      race(nullptr),
      grid(0),
      position(0),
      points(0)
{}

/**
 * Constructor parametrizado.
 */
ResultsInfo::ResultsInfo(int resultId,
                         const Race* race,
                         int grid,
                         int position,
                         int points)
    : resultId(resultId),
      race(race),
      grid(grid),
      position(position),
      points(points)
{}
