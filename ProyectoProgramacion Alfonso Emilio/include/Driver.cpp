#include "Driver.hpp"

// Inicializa campos a valores por defecto (0 o "")
Driver::Driver()
    : driverId(0), code(""), fullName(""), dob(""), nationality("") {}

// Inicializa todos los miembros con los parámetros recibidos
Driver::Driver(int driverId,
               const string& code,
               const string& fullName,
               const string& dob,
               const string& nationality)
    : driverId(driverId),
      code(code),
      fullName(fullName),
      dob(dob),
      nationality(nationality) {}
