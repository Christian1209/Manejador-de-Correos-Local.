#include <iostream>
#include <fstream>
#include "Correos.h"
#include "Correo.h"
#include <time.h>
#define CORREOS_H
#include "arbol.h"

using namespace std;
const std::string currentDateTime(){
     time_t now = time(0);
      struct tm tstruct;
      char buf[21];
      for (int i=0; i<25;i++){
        buf[i]=' ';
      }
      tstruct = *localtime(&now);
      strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); return buf;
}

int main(){
    Correos *uno = new Correos();
    int tam=0;
    int idact=0;
    Arbol *tree = new Arbol;
    Arbol *treeRem = new Arbol();
    int op;
    do{
    cout<<"escoge una opcion:\n1).-Escribir un correo. 2).-Leer correo 5).-Menu copia CSV.";
    cout<<"10).-SALIR"<<endl;
    cin>>op;
        system("cls");
    switch (op){
        case 1:{
            fstream f;
            // Verificar si existe el archivo
            f.open( "pruebaSED.bin", ios::in | ios::out |ios::binary );
            // Si el archivo no existe
            if( !f.is_open())
            {
                f.open("pruebaSED.bin", ios::out);
                if( ! f.good() )
                {
                    cout << "Error al crear el archivo... abortando" << endl;
                    break;
                }
            }
            f.close();
            // Mover el apuntador de escritura al final del archivo para demostrar la
            // persistencia de datos y la capacidad de mover los apuntadores de archivo
            //metodo id
            int tam=0;
            int a=0;
            cout<<"introduce identificador hasta 10 digistos(empieza en 1)"<<endl;
            cin>>a;
            tam=((a-1)*400);
            //a es mi posicion
            string file="pruebaSED.bin";

            uno->eid(a,tam,file);
            f.open("indices.txt", ios::in|ios::out);
            f.seekp(0, ios::beg);
            f<<"DESACTUALIZADO";
            f.close();
            f.open("indicesSecundarios.txt", ios::in|ios::out);
            f.seekp(0, ios::beg);
            f<<"DESACTUALIZADO";
            f.close();
            Nodo *pa = new Nodo();
            //MANDO UN NODO NULL PARA QUE SEA EL PADRE DE LA RAIZ.
            tree->insertar(tree->raiz,pa,a,tam);
            //metodo hora
            cout<<"Mandando hora..."<<endl;
            string prueba=currentDateTime();
            char *c_string_copy = new char[prueba.length() + 1];
            memmove(c_string_copy, prueba.c_str(), prueba.length());
            uno->ehora(c_string_copy,tam,file);
            delete [] c_string_copy;
            //metodo remitente.
            uno->eremitente(tam,file);
            //metodo destinatario
            uno->edestinatario(tam,file);
            //copia carbon
            uno->ecc(tam,file);
            //copia carbon ciega.
            uno->eccciega(tam,file);
            //metodo asunto
            uno->easunto(tam,file);
            //metodo contenido
            uno->econtenido(tam,file);
            //obtengo el remitente para insertarlo en mi arbol de indices secundarios
            char aux[24];
            uno->ObtenRemitente(aux,tam);
            treeRem->insertarRem(aux,treeRem->raiz,pa,tam);
            }
            break;
        case 2:
            {
            int mod =0;
            cout<<"\n1).-Buscar por id. 2).-Buscar por remitente. 3).-Salir";
            cin>>mod;
            switch(mod){
            case 1:
                {
                    int tam=0;
                    do{
                    cout<<"¿Que correo quieres leer, (empieza en 1)?"<<endl;
                    cin>>tam;
                    cin.ignore();
                    }while (tam<=0);
                    tam--;
                    tam=tam*400;
                    string file="pruebaSED.bin";
                    uno->leer(tam,file);
                }
                break;
            case 2:{
                string file="pruebaSED.bin";
                uno->leerxremitente(file);
            }
            break;
            }
            }
            break;
        case 5:{
            int op=0;
            do{
                cout<<"1).-Salir \n2).-Exportar Copia CSV\n3).-Cargar Copia CSV\n4).-Eliminar correo de Copia CSV\n5).-Modificar Correo de copia csv."<<endl;
                cin>>op;
                switch(op){
                case 1:
                    break;
                case 2:{
                    string file="pruebaSED.bin";
                    uno->exportarcsv(file);
                    break;
                }
                case 3:{
                    string file="pruebaSED.bin";
                    uno->cargar(file);
                    break;
                }
                case 4:
                    uno->eliminarcopiacsv(tree,treeRem);
                    break;
                case 5:
                    uno->modificarcopiacsv();
                    break;
                case 6:
                    break;
                }
            }while(op!=1);
        }
        break;
    }
    }while(op!=10);
}
