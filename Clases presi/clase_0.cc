#include <iostream>

int SumarDatos(int x, int y);

int main()
{
int x, y, total;
    // Invocar a la funcion de suma
    SumarDatos(5, 10);
    return 0;
}
// Definicion de la funcion
int SumarDatos(int x, int y) {
    return x + y;
}