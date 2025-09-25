#include <iostream>

// Estructura de datos
struct Datos
{
    int num;
};

// Nodo de la lista
struct Nodo
{
    Datos datos;
    Nodo *siguiente;
};

// Lista global
Nodo *lista = nullptr;

// Declaración de funciones
void InsertarInicio(int n);
void InsertarFinal(int n);
void imprimir();
void EliminarInicio();
void EliminarFinal();

int main()
{
    InsertarInicio(100);
    InsertarInicio(300);
    InsertarInicio(500);
    InsertarFinal(1000);
    EliminarInicio();
    imprimir(); // 500, 300, 100, 1000
    return 0;
}

// Inserta un nodo al inicio
void InsertarInicio(int n)
{
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.num = n;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
}

// Inserta un nodo al final
void InsertarFinal(int n)
{
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.num = n;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr)
    {
        // Si la lista está vacía, el nuevo nodo es la cabeza
        lista = nuevoNodo;
    }
    else
    {
        // Recorremos hasta el último nodo
        Nodo *temporal = lista;
        while (temporal->siguiente != nullptr)
        {
            temporal = temporal->siguiente;
        }
        // Enlazamos el último nodo con el nuevo
        temporal->siguiente = nuevoNodo;
    }
}

// Imprimir la lista
void imprimir()
{
    Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            std::cout << "Valor: " << temporal->datos.num
                      << " Direccion nodo: " << temporal
                      << " Dir siguiente: " << temporal->siguiente
                      << std::endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        std::cout << "La lista está vacía\n";
    }
}

void EliminarInicio()
{
    if (lista != nullptr)
    {
        Nodo *temporal = lista;   // Guardo el primer nodo
        lista = lista->siguiente; // Muevo la cabeza al siguiente nodo
        delete temporal;          // Libero memoria del nodo eliminado
    }
    else
    {
        std::cout << "La lista está vacía" << std::endl;
    }
}

void EliminarFinal() {
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    if (lista != nullptr) {
        //Se va realizando iteraciones hasta llegar al ultimo nodo que apunte a nullptr
        while (temporal->siguiente != nullptr) {
            temporal2 = temporal;
            temporal = temporal->siguiente;
        }
    }
};