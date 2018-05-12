#include "circulo.h"

Circulo::Circulo(int _x, int _y, int raio, int fill)
{
    xc = _x;
    yc = _y;
    r = raio;
    p = fill;
}

/**
 * @brief Circulo::draw
 * @param t
   @details Percorre a extensão do círculo
   do centro menos o raio até o centro mais o raio
   nas direções de x e y, verificando se as coordenadas
   fornecidas atendem a equação do círculo (x-a)² + (y-b)² = r².
   Se o circulo for preenchido, a comparação é feita com a desigualdade
   <=. Se nao, os píxels serão alocados por meio do algoritmo
   de Bresenham.**/

void Circulo::draw(Screen &t)
{
    if(p){
        for(int i=(xc-r);i<=(xc+r);i++){
            for(int j=(yc-r);j<=(yc+r);j++){
                if( (i-xc)*(i-xc)+(j-yc)*(j-yc) <= (r*r)){
                    t.setPixel(i,j);
                }
            }
        }
}
    else{
        int x1 = 0;
               int y1 = r;
               int diametro = 1 - r;
               pontosDaCircunferencia(x1,y1,t);
               while(y1 > x1){
                   if(diametro < 0){
                       diametro = diametro + 2*x1 + 3;
                       x1 = x1 + 1;
                   }
                   else{
                       diametro = diametro + 2*(x1-y1) + 5;
                       x1 = x1 + 1;
                       y1 = y1 - 1;
                   }
                   pontosDaCircunferencia(x1,y1,t);
               }
           }
    }
void Circulo::pontosDaCircunferencia(int x1, int y1, Screen &t){
    t.setPixel(xc + x1, yc + y1);
    t.setPixel(xc + y1, yc + x1);
    t.setPixel(xc - y1, yc + x1);
    t.setPixel(xc - x1, yc + y1);
    t.setPixel(xc - x1, yc - y1);
    t.setPixel(xc - y1, yc - x1);
    t.setPixel(xc + y1, yc - x1);
    t.setPixel(xc + x1, yc - y1);
}
