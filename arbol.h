#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"

class Arbol
{
    public:
        Arbol();
        void insertar(Nodo *&,Nodo *&,int,int);
        void mostrar(Nodo *,int);
        void inorden(Nodo *);
        void preorden(Nodo *);
        void postorden(Nodo *);
        void buscar(int e);
        void rotacionder(Nodo *);
        void rotacionizq(Nodo *);
        bool vacio(Nodo *root);
        int buscar(Nodo *root, int e);
        void generaindices();
        void cargaArbol();
        void actualizaIndices(Nodo *root);
        void inordenEscribe(Nodo *root);
        void eliminar(Nodo *&actual,Nodo *&papa,int e);
        void insertarRem(char a[]);
        int esMenor(char a[],char b[]);
        void insertarRem(char e[],Nodo *&actual,Nodo *&papa,int refe);
        bool sonIguales(char a[],char b[]);
        int comparaChar(char a, char b);
        void inordenRem(Nodo *actual);
        void cargaArbolRem();
        void generaindicesRem();
        void inordenMostrar(Nodo *actual);
        void eliminaRem(Nodo *root,char e[],int refe);
        void busquedaRem(Nodo *root,char e[]);
        void inordenRemAux(Nodo *actual);
        void actualizaIndicesSec(Nodo *actual);

        Nodo *raiz;
    private:
};

#endif // ARBOL_H
