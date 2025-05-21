#include "ResultsInfoDriver.hpp"

/**
 * Constructor por defecto.
 */
ResultsInfoDriver::ResultsInfoDriver()
    : ResultsInfo(), driver(nullptr)
{}

/**
 * Constructor parametrizado: delega al base y guarda el puntero a driver.
 */
ResultsInfoDriver::ResultsInfoDriver(int resultId,
                                     const Driver* driver,
                                     const Race* race,
                                     int grid,
                                     int position,
                                     int points)
    : ResultsInfo(resultId, race, grid, position, points),
      driver(driver)
{}
