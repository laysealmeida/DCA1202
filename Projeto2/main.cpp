#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>


#include "screen.h"
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"

using namespace std;

int main()
{
      vector <FiguraGeometrica*> figuras;
      vector <FiguraGeometrica*>::iterator it;

      ifstream entrada;
      ofstream saida;
      string comando;
      int x, y, largura, altura,xi,yi,r;
      char b;
      bool fillmode;

entrada.open("C:\Users\almei\OneDrive\Desktop\Projeto2\entrada.txt");

if(entrada.is_open()){
       cout << "Arquivo aberto com sucesso\n";
   }
   else{
       cout << "Falha na abertura do arquivo\n";
   }

   entrada.close();

   saida.open("C:\Users\almei\OneDrive\Desktop\Projeto2\saida.txt");

   saida.close();

}

