#ifndef CALCULO_H
#define CALCULO_H

#include <iostream>
#include <stdio.h>

template <typename T>
class Calculo {
public:
    Calculo(T a, T b) : a(a), b(b) {};

    T sumar();
    T restar();
    T multiplicar();

private:
    T a;
    T b;
};

template <typename T>
T Calculo<T>::sumar() {
    return a + b;
}

template <typename T>
T Calculo<T>::restar() {
    return a - b;
}

template <typename T>
T Calculo<T>::multiplicar() {
    return a * b;
}

#endif // CALCULO_H
