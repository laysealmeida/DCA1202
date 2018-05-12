#include "retangulo.h"
#include "figurageometrica.h"
#include "screen.h"
Retangulo::Retangulo(int xc, int yc, int larg, int alt)
{
    xs = xc;
    ys = yc;
    l = larg;
    h = alt;
}

void Retangulo::draw(Screen &t)
{
    t.setPixel(xs,ys);
    for(int i=xs;i<=xs+l;i++){
        t.setPixel(i,ys);
    }
    for(int i=xs;i<=ys+h;i++){
        t.setPixel(xs,i);
    }

    for(int i=xs;i<=ys+h;i++){
        t.setPixel(xs+l,i);
    }
    for(int i=xs;i<=xs+l;i++){
        t.setPixel(i,ys+h);
    }

}
