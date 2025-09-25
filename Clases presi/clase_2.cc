#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

// Structure to hold all coupon-related information for one person
struct InformacionCupon
{
    int cant_cupones;           // Amount of coupons to generate
    std::string nombre_persona; // Name of the person
    std::vector<std::pair<std::string, bool>> cupon_premio;
    // Each element stores (coupon, isWinner)
};

// Function declarations
std::string generateCoupon(std::string prefijo);
bool isWinner(std::string identificador_cupon);
bool checkLength(int longitud);

int main()
{
    // Create the structure to store the information
    InformacionCupon info;

    // Ask for the name of the person
    std::cout << "Enter your name: ";
    std::cin >> info.nombre_persona;

    // Ask for the amount of coupons to generate
    std::cout << "How many coupons do you want to generate?: ";
    std::cin >> info.cant_cupones;

    // Loop to generate all coupons and store them inside the struct
    for (int i = 0; i < info.cant_cupones; i++)
    {
        std::string prefijo;

        // Ask for a prefix of exactly 3 characters
        do
        {
            std::cout << "Enter the prefix for coupon " << i + 1 << " (3 letters): ";
            std::cin >> prefijo;
        } while (!checkLength(prefijo.length()));

        // Generate coupon with prefix + random number
        std::string cupon = generateCoupon(prefijo);

        // Extract the numeric part to check if it is a winner
        std::string numeros = cupon.substr(prefijo.length());
        bool ganador = isWinner(numeros);

        // Store both coupon and result in the vector of the struct
        info.cupon_premio.push_back({cupon, ganador});

        // Show immediate result
        std::cout << "Your generated coupon is: " << cupon << std::endl;
        std::cout << "Result: " << (ganador ? "WINNER!" : "Not a winner") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    // Show all coupons stored in the struct
    std::cout << "\n=== Coupons of " << info.nombre_persona << " ===" << std::endl;
    int contador = 1;
    for (auto &par : info.cupon_premio)
    {
        std::cout << "Coupon " << contador << ": " << par.first
                  << " | Winner: " << (par.second ? "YES" : "NO") << std::endl;
        contador++;
    }

    return 0;
}

// Function that generates a coupon with prefix + random 3-digit number
std::string generateCoupon(std::string prefijo)
{
    srand(time(0));                            // Initialize random seed
    int numero_aleatorio = 100 + rand() % 900; // Random number between 100 and 999
    return prefijo + std::to_string(numero_aleatorio);
}

// Function that checks if the coupon is a winning one
bool isWinner(std::string identificador_cupon)
{
    int numero = std::stoi(identificador_cupon); // Convert string to integer
    return (numero % 2 == 0);                    // Winner if even
}

// Function to check if the prefix has exactly 3 characters
bool checkLength(int longitud)
{
    if (longitud != 3)
    {
        std::cout << "Invalid prefix length, please enter a prefix of 3 letters" << std::endl;
        return false; // Not valid
    }
    else
    {
        std::cout << "Valid prefix, generating coupon..." << std::endl;
        return true; // Valid
    }
}
