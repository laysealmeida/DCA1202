#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"

class Circulo : public FiguraGeometrica
{
    int xc, yc, r, p;
    //p = preenchido ou contorno (p=0 -> contorno, p=1 ->preenchido)
public:
    Circulo(int _x, int _y, int raio, int fill);
    void draw(Screen &t);

    void pontosDaCircunferencia(int x1, int y1, Screen &t);
};

#endif // CIRCULO_H
