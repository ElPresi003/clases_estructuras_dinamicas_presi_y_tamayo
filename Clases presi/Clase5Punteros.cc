#include <iostream>

int main()
{
    // declarar arreglo
    int arreglo_numeros[3] = {2, 100, 1};

    int *ptr = arreglo_numeros;

    // probar sizeof
    std::cout << "Peso de memoria de tipo de dato: "
              << sizeof(int) << " bytes" << std::endl;

    // obtener dir de memoria de un arreglo
    std::cout << "Dir. memoria arreglo_numeros[0]: "
              << arreglo_numeros << " | Valor: " << *(arreglo_numeros) << std::endl;

    std::cout << "Dir. memoria arreglo_numeros[1]: "
              << &arreglo_numeros[1] << " | Valor: " << *(arreglo_numeros + 1) << std::endl;

    std::cout << "Dir. memoria arreglo_numeros[2]: "
              << &arreglo_numeros[2] << " | Valor: " << *(arreglo_numeros + 2) << std::endl;

    // usando puntero
    std::cout << "Dir. memoria arreglo_numeros[2] (ptr + 2): "
              << (ptr + 2) << " | Valor: " << *(ptr + 2) << std::endl;

    return 0;
}
