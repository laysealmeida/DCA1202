#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"

class Reta : public FiguraGeometrica
{
    int xpi, ypi, xpf, ypf;
public:
    Reta(int _xi, int _yi, int _xf, int _yf);
    void draw(Screen &t);
};

#endif // RETA_H
