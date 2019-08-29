//
// Created by Lisandro Diaz  on 2019-08-28.
//

#ifndef SOLUCION_PERIODO_H
#define SOLUCION_PERIODO_H

class Periodo {
public:
    Periodo(int anios, int meses, int dias);

    int anios() const;
    int meses() const;
    int dias() const;

private:
    int _anios;
    int _meses;
    int _dias;
};

#endif //SOLUCION_PERIODO_H