#include "screen.h"
#include <vector>
#include<iostream>
#include<fstream>

Screen::Screen(int nl, int nc)
{
    int nlin = nl;
    int ncol = nc;
    //inicializa a matriz
    mat = vector<vector<char>>(nlin, vector<char>(ncol));
    //atribui a matriz limpa
    for(int i=0;i<nlin;i++){
        for(int j=0;j<ncol;j++){
            mat[i][j]=' ';
        }
    }
}

void Screen::setPixel(int x, int y)
{
    //desenha na posição desejada o que esta no brush
    if(x>0 && y>0 && x<nlin && y<ncol)
        mat[x][y] = brush;
}

void Screen::clear()
{
    //coloca todas as posições da matriz vazias
    for(int i=0;i<nlin;i++){
        for(int j=0;j<ncol;j++){
            mat[i][j]=' ';
        }
    }
}

void Screen::setBrush(char mBrush)
{
    //define o brush
    brush = mBrush;

}

ostream& operator<<(ostream& os, Screen &t)
{
    int nlin, ncol, j;
    //sobrecarga do operador '<<' para imprimir screen
    for(int i=0;i<nlin;i++){
        for(j=0;j<ncol;j++){
            os << t.mat[i][j];
        }
        os<<endl;
    }
    return os;
}
