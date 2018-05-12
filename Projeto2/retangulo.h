#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"

class Retangulo : public FiguraGeometrica
{
    int xs, ys, l, h;
public:
    Retangulo(int xc, int yc, int larg, int alt);
    void draw(Screen &t);
};

#endif // RETANGULO_H
