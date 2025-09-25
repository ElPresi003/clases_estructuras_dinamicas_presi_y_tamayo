#include <iostream>

int main()
{
    int arreglo[] = {10, 20, 30, 40, 50};
    int tamanio = sizeof(arreglo) / sizeof(arreglo[0]);
    int suma = 0;

    std::cout << "Usando indices" << std::endl;
    for (int i = 0; i < tamanio; i++)
    {
        std::cout << "Valor " << arreglo[i]
                  << " : Direccion " << &arreglo[i] << std::endl;
        suma += arreglo[i];
    }

    std::cout << "Suma total: " << suma << std::endl
              << std::endl;

    return 0;
}
