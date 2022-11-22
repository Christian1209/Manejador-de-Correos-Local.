#ifndef NODO_H
#define NODO_H
#include "NodoSec.h"

class Nodo
{
    public:
        Nodo();
        ~Nodo();
        int dato;
        int peso;
        int referencia;
        Nodo *padre;
        //bool hermano para que si el nodo ya tenia un hijo, el nivel no aumente.
        Nodo *izq;
        Nodo *der;
        char remitente[24];
        NodoSec *ancla;
    private:
};

#endif // NODO_H

