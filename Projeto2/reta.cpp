#include "reta.h"
#include "figurageometrica.h"
#include "screen.h"
#include <cmath>
#include <iostream>

Reta::Reta(int _xi, int _yi, int _xf, int _yf)
{
    xpi = _xi;
    ypi = _yi;
    xpf = _xf;
    ypf = _yf;
}

void Reta::draw(Screen &t)
{

    float tam;
    float delta_x;
    float delta_y;
    float x=xpi;
    float y=ypi;

    (abs (xpf - xpi) > abs (ypf-ypi))
            ? tam = abs(xpf-xpi)
            : tam = abs(ypf-ypi);

    delta_x = (xpf - xpi)/tam;
    delta_y = (ypf - ypi)/tam;

    int i=1;
    while (i< tam){

        t.setPixel(round(x), round(y));

        x=x+delta_x;
        y = y+delta_y;

        i++;
    }

}
