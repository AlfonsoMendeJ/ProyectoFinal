#ifndef RESULTS_INFO_HPP
#define RESULTS_INFO_HPP

#include <string>
#include "Race.hpp"

using namespace std;

/**
 * Clase base abstracta para información de resultados.
 * Se derivan versiones específicas para driver y team.
 */
class ResultsInfo {
protected:
    int resultId;        // ID único del resultado
    const Race* race;    // Puntero a la carrera
    int grid;            // Posición en parrilla de salida
    int position;        // Posición final de llegada
    int points;          // Puntos obtenidos

public:
    /**
     * Constructor por defecto: inicializa valores a 0 o nullptr.
     */
    ResultsInfo();

    /**
     * Constructor parametrizado.
     *
     * @param resultId  ID de este resultado
     * @param race      Puntero a la carrera
     * @param grid      Posición en parrilla
     * @param position  Posición final
     * @param points    Puntos ganados
     */
    ResultsInfo(int resultId,
                const Race* race,
                int grid,
                int position,
                int points);

    virtual ~ResultsInfo() = default;

    /**
     * Método puro (virtual) que obliga a las subclases
     * a devolver una “clave” (driver o team).
     */
    virtual string key() const = 0;

    // Getters comunes
    int getResultId()   const { return resultId; }
    const Race* getRace() const { return race; }
    int getGrid()       const { return grid; }
    int getPosition()   const { return position; }
    int getPoints()     const { return points; }
};

#endif // RESULTS_INFO_HPP
