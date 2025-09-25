// Hacer un programa que solicite los precios de n cantidad de productos
// almacenados en un arreglo float, los sume y obtenga el promedio

// Utilizar arreglo y los operadores NEW y DELETE
// Solicitar al usuario los datos (Precios)
// Mostrar las direcciones de memoria de cada uno de los precios
// Mostrar el resultado del promedio
// AYUDA SAMUEEEEEL AAAAAAAAA

#include <iostream>

int main()
{
    int n;
    std::cout << "Ingrese la cantidad de productos: ";
    std::cin >> n;

// reservar memoria dinámica para n precios
    float *precios = new float[n];

    // ingresar precios
    for (int i = 0; i < n; i++)
    {
        std::cout << "Ingrese el precio del producto " << (i + 1) << ": ";
        std::cin >> precios[i];
    }

    // mostrar direcciones de memoria y valores
    std::cout << "\n--- Precios ingresados ---\n";
    for (int i = 0; i < n; i++)
    {
        std::cout
            << "Producto " << (i + 1) << " | Precio: " << precios[i] << " | Direccion: " << &precios[i] << std::endl;
    }

    // calcular suma y promedio
    float suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += precios[i];
    }
    float promedio = (n > 0) ? (suma / n) : 0;

    std::cout << "\nSuma total: " << suma << std::endl;
    std::cout << "Promedio: " << promedio << std::endl;

    // liberar memoria
    delete[] precios;

    return 0;
}