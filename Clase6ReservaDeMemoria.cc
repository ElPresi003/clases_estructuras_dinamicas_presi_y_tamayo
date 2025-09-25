#include <iostream>

int main() {
    // reservar memoria dinámica
    int* ptr = new int;    

    // asignar un valor al entero dinámico
    *ptr = 123;  
    std::cout << "Direccion de memoria asignada: " << ptr << std::endl;
    std::cout << "Valor en esa direccion: " << *ptr << std::endl;

    // liberar memoria
    delete ptr;       

    // marcar el puntero como vacío (evitar puntero colgante)
    ptr = nullptr;    

    // verificar
    if (ptr == nullptr) {
        std::cout << "Puntero vacio (sin memoria asignada)" << std::endl;
    }

    return 0;
}
