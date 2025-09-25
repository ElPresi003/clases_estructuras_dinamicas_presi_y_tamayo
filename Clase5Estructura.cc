#include <iostream>
#include <string>

struct Atleta {
    std::string nombre;
    float altura; // ALTURA EN METROS
    float peso;   // PESO EN KILOGRAMOS
    float imc;
};

// Función para solicitar datos de un atleta
Atleta crearAtleta() {
    Atleta aXD;
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, aXD.nombre);
    std::cout << "Ingrese altura (m): ";
    std::cin >> aXD.altura;
    std::cout << "Ingrese peso (kg): ";
    std::cin >> aXD.peso;

    return aXD;
}

// Función para calcular IMC = peso / (altura^2)
void calcularIMC(Atleta* atleta) {
    if (atleta->altura > 0) {
        atleta->imc = atleta->peso / (atleta->altura * atleta->altura);
    } else {
        atleta->imc = 0;
    }
}

int main () {
    // Declarar variable local del struct Atleta
    struct Atleta atleta;

    // Declarar puntero local para struct Atleta
    struct Atleta *ptr_atleta = &atleta;

    // Inicializar el struct
    ptr_atleta->nombre = "Tamayo XD";

    // Sobreescribir con datos ingresados por el usuario
    atleta = crearAtleta();

    // Calcular el IMC del atleta
    calcularIMC(ptr_atleta);

    // Mostrar resultados
    std::cout << "Nombre: " << ptr_atleta->nombre << std::endl;
    std::cout << "Altura: " << ptr_atleta->altura << " m" << std::endl;
    std::cout << "Peso: " << ptr_atleta->peso << " kg" << std::endl;
    std::cout << "IMC: " << ptr_atleta->imc << std::endl;

    return 0;
}
