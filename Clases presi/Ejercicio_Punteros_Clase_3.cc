#include <iostream>

// función que intercambia usando los punteros
void CambioPorPuntero(int *a, int *b) {
    int aux = *a; // guarda el valor de lo que apunta a
    *a = *b;      // ahora a vaa toma el valor de b
    *b = aux;     // b toma el valor guardado en la aux
}

// función que imprime los valores
void ImprimirPorPuntero(int *a, int *b) {
    std::cout << "El valor de la variable 1 es: " << *a << std::endl;
    std::cout << "El valor de la variable 2 es: " << *b << std::endl;
}

int main() {
    int variable1 = 5;
    int variable2 = 10;

    std::cout << "Antes del cambio:" << std::endl;
    ImprimirPorPuntero(&variable1, &variable2);

    CambioPorPuntero(&variable1, &variable2);

    std::cout << "Despues del cambio:" << std::endl;
    ImprimirPorPuntero(&variable1, &variable2);

    return 0;
}