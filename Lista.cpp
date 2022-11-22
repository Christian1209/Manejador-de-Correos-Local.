#include "Lista.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;
#include "Nodo.h"
int Lista::tamano(){
int cont=0;
Nodo *aux=h;
while(aux){
    cont++;
    aux=aux->sig;
}
cout<<cont<<endl;
return cont;
}
void Lista::inicializa(){
    h=nullptr;

}
void Lista::inserta (Personaje a){
    Nodo *tmp=new Nodo();
    tmp->dato=a;
    if (vacia()){
        h=tmp;
    }
    else {
        tmp->sig=h;
        h->ant=tmp;
        h=tmp;
    }
}
void Lista::mostrar(){
    Nodo *aux=h;
    if (aux){
        while(aux){
            cout<<"[Nombre: "<<aux->dato.getNombre()<<" Nivel: "<<aux->dato.getNivel()<<" Id: "<<aux->dato.getId()<<"]";
            aux=aux->sig;
        }
    }
    else{
        cout<<"lista vacia"<<endl;
    }
}
void Lista::insertaf (Personaje d){
    Nodo *tmp = new Nodo();
    tmp->dato=d;

    Nodo *aux=h;
    if(aux==nullptr){
        h=tmp;
    }
    else{
            while(aux->sig){
                    aux=aux->sig;
            }
            aux->sig=tmp;
            tmp->ant=aux;
        }
    }
void Lista::insertaPos(Personaje dato, int pos){
    if (pos>=1 && pos-1<tamano()){
        Nodo *tmp=new Nodo();
        tmp->dato=dato;
        Nodo *aux=h,*auxRet;

        int i=0;
        while(i<pos-1 && aux){
            aux=aux->sig;
            i++;
        }
        if(aux==h){
            tmp->sig=h;
            h->ant=tmp;
            h=tmp;
        }
        else{
            aux->ant->sig=tmp;
            tmp->ant=aux->ant;
            tmp->sig=aux;
            aux->ant=tmp;
            }
        }
    else{
        cout<<"pos no valida"<<endl;
    }
    }
bool Lista::vacia(){
       if (h==nullptr){
        return true;
        }
    else{
        return false;
        }
}
Nodo* Lista::primero(){
    if (vacia()){
        cout<<"lista vacia"<<endl;
        return nullptr;
    }
    else{
        Nodo *prim= new Nodo();
        prim=h;
        cout<<"\nEl primer elemento de la lista es el personaje : "<<prim->dato.getNombre()<<endl;
        return prim;
    }
}
Nodo* Lista::ultimo(){
    Nodo *tmp = new Nodo();
    Nodo *aux=h;
    if (vacia()){
        cout<<"lista vacia"<<endl;
        return nullptr;
    }
    else{
    while(aux->sig){
        aux=aux->sig;
        }
    cout<<"el ultimo elemento de la lista es el personaje: "<<aux->dato.getNombre()<<endl;
    return aux;
        }
    }
void Lista::buscar(string d){
    int b=0;
    int i=0;
    Nodo *aux=h;
    if(vacia()){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(aux){
            if(d==aux->dato.getNombre()){
                b=1;
                i=i+1;
                cout<<"\ntu Personaje:"<<aux->dato.getNombre()<<" ha sido encontrado en la posicion: "<<i<<endl;
                return;

            }
            aux=aux->sig;
            i=i+1;
        }
    }
    if (b==0){
        cout<<"Personaje no encontrado"<<endl;
    }
}
void Lista::eliminar(string d){
    Nodo *aux=h;
    Nodo *auxR=nullptr;
    bool band=true;
    if (aux){//elementos de la lista
        while(aux and band){
            if(aux->dato.getNombre()!=d){
                auxR=aux;
                aux=aux->sig;
            }
            else{
             band=false;
             }
        }
        if (aux==nullptr){
            cout<<"Personaje no encontrado"<<endl;
        }
        else if(aux==h){
            h->sig->ant=nullptr;
            h=h->sig;
            cout<<"Personaje eliminado"<<endl;
            delete aux;
        }
        else{
            aux->ant->sig=aux->sig;
            aux->sig->ant=aux->ant;
            cout<<"Personaje eliminado"<<endl;
            delete aux;
        }
    }
    else
        cout<<"Lista vacia"<<endl;
}
Nodo* Lista::anterior(string d){
    Nodo *aux=h;
    Nodo *auxR=nullptr;
    bool band=true;
    if(aux){
        while(aux and band){
            if(aux->dato.getNombre()!=d){
                aux=aux->sig;
            }
            else{
                band=false;
            }
        }
        if(aux->ant==nullptr){
            cout<<"primera posicion, no hay anterior"<<endl;
            return nullptr;
        }
        else if(aux==nullptr){
            cout<<"dato no encontrado"<<endl;
            return nullptr;
        }
        else
            cout<<"dato encontrado, se devuelve la posicion de: "<<aux->ant->dato.getNombre()<<endl;
            return aux->ant;
    }
    return nullptr;
}
Nodo* Lista::siguiente(string d){
    int b=0;
    Nodo *aux=h;
    if(vacia()){
        cout<<"Lista vacia"<<endl;
    }
    else{
        while(aux){
            if(aux->dato.getNombre()==d and aux->sig==nullptr){
                cout<<"\nTu numero es el ultimo, no hay siguiente"<<endl;
                return nullptr;
            }
            else if(d==aux->dato.getNombre()){
                b=1;
                cout<<"\ntu numero ha sido encontrado, se devuelve la posicion de :"<<aux->sig->dato.getNombre()<<endl;
                return aux->sig;
            }
            else{
                aux=aux->sig;
            }
        }
    }
    if (b==0){
        cout<<"Personaje no encontrado"<<endl;
        return nullptr;
    }
}
void Lista::vaciar(){
    Nodo *aux=h;
    if(vacia()){
        cout<<"lista vacia!"<<endl;
    }
    else if(h->sig==nullptr){
            cout<<"lista de un elemento vaciada..."<<endl;
            h=nullptr;
    }
    else{
            cout<<"Vaciando Lista de varios elementos..."<<endl;
        while(h){
            aux=h;
            h=h->sig;
            aux=nullptr;
        }
    }
}
void Lista::guardar(){
    //el constructor de ofstream abre el archivo
    ofstream archivoClientesSalida( "file01.txt", ios::out );
    // sale del programa si no puede crear el archivo
    if ( !archivoClientesSalida ) // operador ! sobrecargado
    {
    cerr << "No se pudo abrir el archivo" << endl;
    exit( EXIT_FAILURE );
    } // fin de if
    Nodo *aux=h;
    if (aux){
        while(aux){
            cout<<"[Nombre: "<<aux->dato.getNombre()<<" Nivel: "<<aux->dato.getNivel()<<" Id: "<<aux->dato.getId()<<"]";
            archivoClientesSalida << aux->dato.getId() << "|" << aux->dato.getNombre() << "|" << aux->dato.getNivel() << "*";
            aux=aux->sig;
        }
    }
    else{
        cout<<"lista vacia"<<endl;
    }
}
void Lista::cargar(){
  int i,j;
  string d;
  ifstream is("file01.txt", ifstream::binary);
  if (is) {
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    char * buffer = new char [length];
    char * registro=new char;
    char * campo=new char;

    char *tokenPtr;
    char *tokenCampo;



    cout << "Reading " << length << " characters... ";
    // read data as a block:
    is.read (buffer,length);

    stringstream ss(buffer);

    vector<string> tokens;
    vector<string> tokensC;

    string tmpStr;
    string tmpStrC;

    if (is)
    {
      cout<< "all characters read successfully."<<endl;
      //cout<<buffer<<endl;
      i=0;
      d=(string)buffer;
      int p=0;


      while(getline(ss,tmpStr,'*'))
      {
          tokens.push_back(tmpStr);
      }


         for(int i = 0; i < tokens.size()-1; i++)
         {
            stringstream cm(tokens[i]);
            Personaje p1("a",1,1);
                   while(getline(cm,tmpStrC,'|'))
                  {
                      tokensC.push_back(tmpStrC);
                      p++;

                  }
                     //for(int i = 0; i < tokensC.size(); i++) {
                          //cout << tokensC[i] << "";
                    //}
                    //cout<<"limite del for"<<endl;
           // cout << tokens[i]<<endl;
           cout<<p;
           p1.setId(atoi(tokensC[p-3].c_str()));
           p1.setNombre(tokensC[p-2]);
           p1.setNivel(atoi(tokensC[p-1].c_str()));
           inserta(p1);
         }
    }
    else{
      cout << "error: only " << is.gcount() << " could be read";

    is.close();

    // ...buffer contains the entire file...

    delete[] buffer;
  }
}
}

Lista::Lista()
{
    h=nullptr;
    //ctor
}

Lista::~Lista()
{
    //dtor
}
