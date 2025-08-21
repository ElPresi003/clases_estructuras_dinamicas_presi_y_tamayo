#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

// Declaracion de funciones
std::string generateCoupon(std::string prefijo);
void checkCoupon(std::string identificador_cupon);
bool checkLength(int longitud);
std::vector<std::string> cupones_generados();

int main()
{
    // Pedir y generar varios cupones
    std::vector<std::string> lista_cupones = cupones_generados();

    // Mostrar todos los cupones generados
    std::cout << "\n=== Cupones generados ===" << std::endl;
    for (size_t i = 0; i < lista_cupones.size(); i++)
    {
        std::cout << "Cupon " << i + 1 << ": " << lista_cupones[i] << std::endl;
    }

    return 0;
}

// Generar el cupon con prefijo + numero aleatorio de 3 digitos
std::string generateCoupon(std::string prefijo)
{
    srand(time(0));                            // Inicializar semilla de numeros aleatorios
    int numero_aleatorio = 100 + rand() % 900; // Numero aleatorio entre 100 y 999
    return prefijo + std::to_string(numero_aleatorio);
}

// Verificar si el cupon es premiado
void checkCoupon(std::string identificador_cupon)
{
    int premio;
    int numero = std::stoi(identificador_cupon); // Convertir string a entero

    std::cout << "El numero del cupon es: " << numero << std::endl;

    premio = numero % 2;
    if (premio == 0)
    {
        std::cout << "El boleto esta premiado" << std::endl;
    }
    else
    {
        std::cout << "El cupon no esta premiado" << std::endl;
    }
}

// Validar la longitud del prefijo
bool checkLength(int longitud)
{
    if (longitud != 3)
    {
        std::cout << "Longitud de prefijo invalida, por favor ingresa un prefijo de 3 letras" << std::endl;
        return false; // No es valido
    }
    else
    {
        std::cout << "Prefijo valido, se genera el cupon..." << std::endl;
        return true; // Es valido
    }
}

// Nueva funcion para pedir y generar varios cupones
std::vector<std::string> cupones_generados()
{
    int cantidad;
    std::cout << "Cuantos cupones desea generar?: ";
    std::cin >> cantidad;

    std::vector<std::string> lista_cupones;
    std::string prefijo, cupon;

    for (int i = 0; i < cantidad; i++)
    {
        // Bucle para asegurarse que el prefijo tiene exactamente 3 caracteres
        do
        {
            std::cout << "Ingrese el prefijo del cupon " << i + 1 << " (3 letras): ";
            std::cin >> prefijo;
        } while (!checkLength(prefijo.length()));

        // Generar y guardar cupon
        cupon = generateCoupon(prefijo);
        lista_cupones.push_back(cupon);

        // Mostrar el resultado inmediato
        std::cout << "Su cupon generado es: " << cupon << std::endl;

        // Extraer la parte numerica y verificar premio
        std::string numeros = cupon.substr(prefijo.length());
        checkCoupon(numeros);
        std::cout << "-----------------------------" << std::endl;
    }

    return lista_cupones;
}
