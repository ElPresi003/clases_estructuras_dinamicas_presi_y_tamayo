#include <iostream>
#include <string.h>
#include <string>

int main()
{
    int numero_de_album = 0;
    bool continuar;
    std::string nombre_album;
    do
    {   numero_de_album = +1;
        std::cout << "Prueba" << std::endl;
        std::cin >> nombre_album;
        std::cout <<"Deseas agregar otra cancion? 1 para si 0 para no." << std::endl;
        std::cin >> continuar;
    }

    while (continuar = !true);

    return 0;
}