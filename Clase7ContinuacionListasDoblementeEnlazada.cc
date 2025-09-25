#include <iostream>

struct Datos {
    int numero;
};

struct Nodo {
    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

void InsertarInicio(struct Nodo **lista, int n);
void InsertarFinal(int n);

int main () {
    //Este puntero reserva la memoria en el stat
struct Nodo *lista = nullptr;
InsertarInicio(&lista, 7);
return 0;
}

void InsertarInicio(struct Nodo **lista, int n){
    struct Nodo *NuevoNodo = new Nodo;
    NuevoNodo->datos.numero = n;
    NuevoNodo->siguiente = nullptr;
    NuevoNodo->anterior = nullptr;

    if (*lista  = nullptr) {
        *lista = NuevoNodo;
    }
    else {
        //conexion de nuevo nodo con la lista
        NuevoNodo->siguiente = *lista;
        (*lista)->anterior = NuevoNodo;
        //Asignar el nuevonodo a la cabeza de la lista
        *lista = NuevoNodo;
    }
};

