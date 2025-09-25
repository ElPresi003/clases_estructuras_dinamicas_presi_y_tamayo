#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <string>

struct InformacionCupon
{
    int cant_cupones;
    std::string nombre_persona;
    std::vector<std::string> cupones_generados_vector;
    std::vector<std::pair<std::string, std::string>> cupon_premio;
};

// Function declarations
std::string GenerarCupon(std::string prefijo);
std::string SolicitarDatos();
std::string VerificarCupon(std::string cupon);
InformacionCupon SolicitarDatosGenerales();

int main()
{
    srand(time(0)); // Inicializar semilla para números aleatorios

    // Vector para almacenar múltiples structs de cupones (si quieres usarlo para varios usuarios)
    std::vector<InformacionCupon> InfoCupones;

    // Solicitar datos generales de un usuario
    InformacionCupon cupon = SolicitarDatosGenerales();

    // Guardar el struct en el vector
    InfoCupones.push_back(cupon);

    // Mostrar todos los cupones y su premio
    for (auto c : cupon.cupon_premio)
    {
        std::cout << "Cupón generado: " << c.first << " | Premio: " << c.second << "\n";
    }

    return 0;
}

// Función para generar un cupón con prefijo + número aleatorio
std::string GenerarCupon(std::string prefijo)
{
    int random = 100 + rand() % 900; // números entre 100 y 999
    return prefijo + std::to_string(random);
}

// Función para solicitar prefijo de 3 letras
std::string SolicitarDatos()
{
    std::string prefijo;
    do
    {
        std::cout << "Ingrese las letras del cupón (3 letras): ";
        std::cin >> prefijo;
        if (prefijo.length() != 3)
        {
            std::cout << "Error. Debes ingresar solo 3 letras.\n";
        }
    } while (prefijo.length() != 3);
    return prefijo;
}

// Función para verificar si el cupón tiene premio
std::string VerificarCupon(std::string cupon)
{
    std::string mensaje;
    std::string num_extraido = cupon.substr(3); // tomar desde el 4to caracter hasta el final
    int conversion = std::stoi(num_extraido);
    if (conversion % 2 == 0)
    {
        mensaje = "tiene premio";
    }
    else
    {
        mensaje = "no tiene premio";
    }
    return mensaje;
}

// Función para solicitar datos generales y generar los cupones
InformacionCupon SolicitarDatosGenerales()
{
    InformacionCupon cupon;

    std::cout << "Por favor ingrese su nombre: ";
    std::cin >> cupon.nombre_persona;

    std::cout << "Ingrese cantidad de cupones a generar: ";
    std::cin >> cupon.cant_cupones;

    for (int i = 0; i < cupon.cant_cupones; i++)
    {
        std::string prefijo = SolicitarDatos();
        std::string cupon_generado = GenerarCupon(prefijo);
        std::string premio = VerificarCupon(cupon_generado);

        cupon.cupones_generados_vector.push_back(cupon_generado);
        cupon.cupon_premio.push_back(std::make_pair(cupon_generado, premio));
    }

    return cupon;
}
