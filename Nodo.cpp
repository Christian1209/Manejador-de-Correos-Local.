#include "Nodo.h"

Nodo::Nodo()
{
    izq = nullptr;
    der = nullptr;
    padre = nullptr;
    dato = 0;
    peso = 0;
    referencia = 0;
    remitente[1] = 'a';
    ancla = nullptr;
}
