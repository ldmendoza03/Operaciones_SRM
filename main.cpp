#include "Calculo.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring> // Para manejo de cadenas

// **Función para capturar números de punto flotante o enteros**
template <typename T>
T ingresar(const char* msj) {
    printf("%s", msj);
    char cad[20], c;
    bool puntoDecimal = false; // Controla si ya hay un punto decimal en la cadena
    int i = 0;

    while ((c = getch()) != 13) { // 13 es el código ASCII de Enter
        // Verifica si es un número o un punto decimal
        if (c >= '0' && c <= '9' && i < 19) {
            printf("%c", c);
            cad[i++] = c;
        } else if (c == '.' && !puntoDecimal && i > 0 && std::is_floating_point<T>::value) {
            // Permite un solo punto decimal si es un tipo flotante
            printf("%c", c);
            cad[i++] = c;
            puntoDecimal = true;
        }
    }
    cad[i] = '\0'; // Termina la cadena
    return static_cast<T>(atof(cad)); // Convierte a tipo T (float o int)
}

int main() {
    float a, b;
    printf("Calculadora para numeros mayores a cero\n\n");

    do {
        a = ingresar<float>("Ingrese un numero a: ");
        printf("\n");
        if (a <= 0) {
            printf("El numero ingresado no es valido. Ingrese un numero mayor a cero\n\n");
            continue;
        }

        b = ingresar<float>("Ingrese un numero b: ");
        printf("\n");
        if (b <= 0) {
            printf("El numero ingresado no es valido. Ingrese un numero mayor a cero\n\n");
            continue;
        }
        break; // Rompe el bucle si ambos números son válidos
    } while (true);

    // Crear objeto Calculo y mostrar resultados
    Calculo<float> intCalculo(a, b);
    printf("La suma es: %f\n", intCalculo.sumar());
    printf("La resta es: %f\n", intCalculo.restar());
    printf("La multiplicación es: %f\n", intCalculo.multiplicar());

    return 0;
}
