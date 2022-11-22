#ifndef CORREOS_H
#define CORREOS_H
#include <fstream>
#include <iostream>
#include "Correo.h"
#include "arbol.h"

using namespace std;

class Correos
{
    public:
        Correos();
        ~Correos();
        void eid(int a,int tam,string file);
        void ehora(char a[],int tam, string file);
        void eremitente(int tam, string file);
        void eremitente(char rem[],int tam, string file);
        void edestinatario(int tam, string file);
        void edestinatario(char rem[],int tam, string file);
        void ecc(int tam, string file);
        void ecc(char rem[],int tam, string file);
        void eccciega(int tam, string file);
        void eccciega(char rem[],int tam, string file);
        void easunto(int tam, string file);
        void easunto(char rem[],int tam, string file);
        void econtenido(int tam, string file);
        void econtenido(char cont[],int tam, string file);
        void leer(int tam,string file);
        void leerxremitente(string file);
        void modificar(int tam,string file);
        void busquedaremitente(string file);
        void eliminar(int tam, string file, Arbol *&,Arbol *&);
        void eliminarxremitente(string file, Arbol *&,Arbol *&);
        void exportarcsv(string file);
        void copiacsv(int tam,string file);
        void cargar(string file);
        void eliminarcopiacsv(Arbol *&tree,Arbol *&treeRem);
        void modificarcopiacsv();
        void exportarprop(string file);
        int copiaprop(int tam,int tamesc, string file);
        void modificarprop(string file,int op);
        int leerprop(string file,int tam,int *idretorno,int idbuscar, int *tamesc,int op);
        Correo copiaRam(int t,string file);
        int comparaChar(char a, char b);
        int esMenor(char a[],char b[]);
        void shell(Correo a[], int n);
        void busquedaBinaria(Correo a[],char [], int n);
        bool sonIguales(char a[],char b[]);
        void geneneraindices(Nodo *&);
        int obtenReferencia(string file, int tam);
        int yaExisteIndices();
        void cargaIndices();
        bool indiceActualizado();
        int retornaId(int tam);
        void ObtenRemitente(char aux[], int tam);
        int yaExisteIndicesSec();
        bool indiceSecActualizado();

    protected:

    private:
};

#endif // CORREOS_H
