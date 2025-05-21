#ifndef RESULTS_INFO_DRIVER_HPP
#define RESULTS_INFO_DRIVER_HPP

#include "ResultsInfo.hpp"
#include "Driver.hpp"

using namespace std;

/**
 * Subclase de ResultsInfo para resultados de pilotos.
 */
class ResultsInfoDriver : public ResultsInfo {
    const Driver* driver; // Puntero al piloto

public:
    /**
     * Constructor por defecto: llama al base e inicializa driver a nullptr.
     */
    ResultsInfoDriver();

    /**
     * Constructor parametrizado.
     *
     * @param resultId  ID del resultado
     * @param driver    Puntero al piloto
     * @param race      Puntero a la carrera
     * @param grid      Posición en parrilla
     * @param position  Posición final
     * @param points    Puntos obtenidos
     */
    ResultsInfoDriver(int resultId,
                      const Driver* driver,
                      const Race* race,
                      int grid,
                      int position,
                      int points);

    /**
     * Implementación de key(): devuelve el nombre del piloto.
     */
    string key() const override {
        return driver ? driver->getName() : string{};
    }

    const Driver* getDriver() const { return driver; }
};

#endif // RESULTS_INFO_DRIVER_HPP
