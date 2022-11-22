#ifndef CORREO_H
#define CORREO_H
#include <fstream>
#include <iostream>
using namespace std;

class Correo
{
    public:
        Correo();
        ~Correo();
        char rem[24];

        string getContenido(void){
            return contenido;
        };


        void setContenido(string cont){
            contenido=cont;
        };

        string getContenido2(void){
            return contenido2;
        };

        void setContenido2(string cont){
            contenido2=cont;
        };
        string getCopiaOculta(void){
            return copiaOculta;
        };
        void setCopiaOculta(string co){
            copiaOculta=co;
        };

        int getId(void){
            return id;
        };
        void setId(int id){
            this->id=id;
        };
        string getHora(void){
            return hora;
        };
        void setHora(string h){
            hora = h;
        }
    protected:

    private:
        string hora;
        string contenido;
        string copiaOculta;
        string contenido2;
        int id;
};




#endif // Registro_Hs
