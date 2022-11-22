#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

#include "Nodo.h"
class Lista
{
    public:
        Lista();
        ~Lista();
        void insertaPos(char [24],);
        void inicializa();
        void inserta(Personaje);
        void insertaf(Personaje);
        void mostrar();
        bool vacia();
        void vaciar();
        int tamano();
        void buscar(string);
        void eliminar(string);
        Personaje prueba(Personaje);
        void guardar();
        void cargar();
        char rem[24];

    private:
        Nodo *h;
};

#endif // LISTA_H
