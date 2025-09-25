#include <iostream>

void PasoPorValor (int taza);
void PasoPorPuntero (int *taza);
void PasoPorReferencia (int &incognita); //aqui aun no se da el nombre de la variable

int main()
{

    int taza = 0;

    std::cout << "contenido de la taza " << taza << std::endl;
    PasoPorValor(taza); //100
    std::cout << "contenido de la taza " << taza << std::endl; //0

    PasoPorPuntero(&taza);//100
    std::cout << "contenido de la taza " << taza << std::endl; //0

    PasoPorReferencia(taza); //Aqui se le da la variable taza sola porque ya sse le habia indicado sobre recibir una ingoenita
    std::cout << "contenido de la taza " << taza << std::endl; //200

    PasoPorValor(taza); //300
    std::cout << "contenido de la taza " << taza << std::endl; //200

    return 0;
}

void PasoPorValor (int taza) {
    taza = taza + 100; //Devuelve 100
    std::cout << "Contenido taza " << taza << std::endl;
};

void PasoPorPuntero (int *taza){
    *taza = *taza + 100; //Devuelve 100
    std::cout << "Contenido taza " << *taza << std::endl;
};

void PasoPorReferencia (int &taza) { 
    taza = taza + 100; //Devuelve 100
    std::cout << "Contenido taza " << taza << std::endl;
};

    //int num = 500;

    /* int *ptr = &num;
    // Si un puntero no apunta a nada se le debe indicar que apunte a null ptr
    //int *ptr = nullptr;

    *ptr = 800;
    num = 1000;

    std::cout << "Dir.Memoria " << ptr << " - " << &num << std::endl;
    std::cout << "Dir.Memoria.ptr " << &ptr << std::endl;
    std::cout << "Valor.Num " << *ptr << std::endl; */
