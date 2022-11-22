#include "Arbol.h"
#include "Nodo.h"
#include <iostream>
#include "Correos.h"
using namespace std;

void Arbol::rotacionder(Nodo *actual){
        Nodo *b = new Nodo();
        b=actual->izq;
    if((b->peso)==-1){
        //Se hace rotación simple hacia derecha
        //cout<<"Rotación simple derecha"<<endl;
        //necesitamos saber si el nodo que vamos a mover tiene un nodo padre.
        if(actual->padre->padre!=nullptr){
                //cout<<actual->dato<<endl;
                //ahora necesitamos saber si es hijo por la parte derecha o izquierda
            if((actual->padre->dato)>(actual->dato)){
                //aqui, el padre es mayor por lo tanto es hijo izquierdo
                b->padre=actual->padre;
                actual->padre->izq=b;
            }
            else{
                //aqui, padre es menor por lo tanto es hijo por derecha.
                b->padre=actual->padre;
                actual->padre->der=b;
            }
        }
        else{
               //si el nodo no tiene pade, es raiz y hay qeu moverla.
            b->padre=actual->padre;
            raiz=b;
        }
        if(b->der!=nullptr){
               //si B osea el hijo del nodo que va a rotar, tiene hijo derecho hay que pasarlo a la parte izquierda del nodo a rotar.
            //cout<<"b si tenia algo en su parte derecha.";
            b->der->padre=actual;
            actual->izq=b->der;
            actual->peso=0;
        }
        else{
            actual->izq=nullptr;
        //si no, el nodo a rotar es nulo.
            actual->peso=1;
        }
        b->der=actual;
        //Equilibrio de pesos.
        b->peso=0;
    }
    else if(b->peso=1){
        //Se hace rotacion doble a derecha.s
        Nodo *c = new Nodo();
        c=b->der;
        if(c->der==nullptr){
            cout<<"LLEGUE!"<<endl;
            actual->izq=c;
            c->izq=b;
            b->izq=nullptr;
            b->der=nullptr;
            b->peso=0;
            c->peso=-1;
            actual->peso=-2;
            b->padre=c;
            c->padre=actual;

            rotacionder(actual);
        }
        else{
            //cout<<"C si tiene hijo!!!"<<endl;
            actual->izq=c;
            c->padre=actual;
            c->izq=b;
            b->padre=c;
            b->der=nullptr;
            c->peso=-1;
            b->peso=-1;
            actual->peso=-2;
            rotacionder(actual);
        }
        //cout<<"rotacion doble a derecha"<<endl;
    }

}

void Arbol::rotacionizq(Nodo *actual){
        Nodo *b = new Nodo();
        b=actual->der;
    if((b->peso)==(1)){
        //Se hace rotación simple hacia izq
        //cout<<"Rotación simple hacia izq"<<endl;
        //necesitamos saber si el nodo que vamos a mover tiene un nodo padre.
        if(actual->padre->padre!=nullptr){
                //cout<<"Entre aqui!";
                //cout<<actual->dato<<endl;
                //ahora necesitamos saber si es hijo por la parte derecha o izquierda
            if((actual->padre->dato)>(actual->dato)){
                //aqui, el padre es mayor por lo tanto es hijo izquierdo
                //cout<<"aqui";
                b->padre=actual->padre;
                actual->padre->izq=b;
            }
            else{
                //aqui, padre es menor por lo tanto es hijo por derecha.
                b->padre=actual->padre;
                actual->padre->der=b;
            }
        }
        else{
               //si el nodo no tiene pade, es raiz y hay qeu moverla.
            b->padre=actual->padre;
            raiz=b;
        }
        if(b->izq!=nullptr){
               //si B osea el hijo del nodo que va a rotar, tiene hijo izquierdo hay que pasarlo a la parte izquierda del nodo a rotar.
            //cout<<"b si tenia algo en su parte izquierda.";
            b->izq->padre=actual;
            actual->der=b->izq;
            //si habia algo, queda con peso 0.
            actual->peso=0;
        }
        else{
            actual->der=nullptr;
            actual->peso=-1;
        //si no, el nodo a rotar es nulo.
        }
        b->izq=actual;
        //Equilibrio de pesos.
        b->peso=0;
        }
    else if((b->peso)==(-1)){
        //cout<<"LLEGUE";
        //Se hace rotacion doble hacia izquierda.
        Nodo *c = new Nodo();
        c=b->izq;
        if(c->izq==nullptr){
            //cout<<"C no tiene hijo"<<endl;
            //se hace rotacion simple y no hay nodos que reubicar.
            actual->der=c;
            c->der=b;
            b->der=nullptr;
            b->izq=nullptr;
            b->peso=0;
            c->peso=1;
            actual->peso=2;
            b->padre=c;
            c->padre=actual;
            rotacionizq(actual);
        }
        else{
            //cout<<"C si tiene hijo!!!"<<endl;
            actual->der=c;
            c->padre=actual;
            c->der=b;
            b->padre=c;
            b->izq=nullptr;
            c->peso=1;
            b->peso=1;
            actual->peso=2;
            rotacionizq(actual);
        }
        cout<<"rotacion doble a derecha"<<endl;
    }
}

void Arbol::insertar(Nodo *&actual,Nodo *&papa,int e, int refe){
    if(actual==nullptr){
        if(papa->izq!=nullptr||papa->der!=nullptr){
            //cout<<"ESE NIVEL YA EXISTIA, ESTAMOS AÑADIENDO UN HERMANO."<<endl;
            Nodo *aux = new Nodo();
            aux=papa->padre;
            while (aux){
                    //cout<<"Dato a evaluar: "<<aux->dato<<endl;
                if((aux->dato)>(e)){
                    aux->peso=aux->peso+1;
                }
                else{
                    aux->peso=aux->peso-1;
                }
                aux=aux->padre;
            }
        }
        Nodo *tmp = new Nodo();
        tmp->dato=e;
        tmp->referencia=refe;
        actual=tmp;
        actual->padre=papa;
        if(raiz==nullptr){
            raiz=actual;
        }
        return;
    }
    else{
        int vraiz=actual->dato;
        if(e<vraiz){
            actual->peso=(actual->peso-1);
            insertar(actual->izq,actual,e,refe);
        }
        else{
            actual->peso=(actual->peso+1);
            insertar(actual->der,actual,e,refe);
        }
    }
    if(actual->peso==2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a la derecha."<<endl;
        rotacionizq(actual);
        //ajuste de Nodos.
        while (aux){
            //cout<<"Dato a evaluar: "<<aux->dato<<endl;
            if((aux->dato)>(e)){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }
    if(actual->peso==-2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a izquierda."<<endl;
        rotacionder(actual);
        //si hay rotacion, ajustamos nodos
        while (aux){
            if((aux->dato)>(e)){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }
}

void Arbol::mostrar(Nodo *actual,int cont){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        mostrar(actual->der,cont+1);{
            for(int i=0;i<cont;i++){
                cout<<"   ";
            }
            cout<<actual->dato<<endl;
            mostrar(actual->izq,cont+1);
        }
    }
 }

void Arbol::inorden(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        inorden(actual->izq);
        cout<<"Indice "<<actual->dato<<")"<<"Referencia: "<<actual->referencia<<")";
        inorden(actual->der);
    }
 }

void Arbol::preorden(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        cout<<actual->dato<<")";
        preorden(actual->izq);
        preorden(actual->der);
    }
 }

void Arbol::postorden(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        postorden(actual->izq);
        postorden   (actual->der);
        cout<<actual->dato<<")";
    }
 }

int Arbol::buscar(Nodo *root, int e){
    if(vacio(raiz)){
        cout<<"Arbol vacio"<<endl;
        return -1;
    }
    if(vacio(raiz)==false and root==nullptr){
        cout<<"Correo no encontrado"<<endl;
        return -1;
    }
    else{
        Nodo *tmp = root;
        if(tmp->dato==e){
                return tmp->referencia;
        }
        else if(tmp->dato<e){
            buscar(tmp->der,e);
        }
        else if(tmp->dato>e){
            buscar(tmp->izq,e);
        }
    }
 }

 bool Arbol::vacio(Nodo *root){
    if(root == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Arbol::generaindices(){
    cout<<"Voy a generar El archivo de indices"<<endl;
    string file="pruebaSED.bin";
    string file2 = "indices.txt";
    fstream indices;
    Correos *uno = new Correos();
    int id;
    fstream f;
    bool band;
    int i = 0;
    int k=0;
    int tam=0;
    indices.open(file2, ios::in| ios::app);
    f.open( file, ios::in | ios::out);
    while((!f.eof()) and band==false){
        f.seekg(tam, ios::beg);
        int id = 0;
        f.read((char *)(&id),sizeof(id));
        if (id>0){
            //SI hubo ID mayor a 0, es correo valido y lo mandamos al arbol.
            Nodo *pa = new Nodo();
            //MANDO UN NODO NULL PARA QUE SEA EL PADRE DE LA RAIZ.
            int referencia = uno->obtenReferencia(file,tam);
            //continua aqui!!!!!!!!!
            insertar(raiz,pa,id,referencia);
            indices<<id<<"|"<<referencia<<"\n";
        }
        //leo idactual
        int mostraridact;
        f.read((char *)(&mostraridact),sizeof(mostraridact));
        tam=tam+400;
        //leo id siguiente. Si son iguales y mayores a 0 ya no leo mas, ya que es la basura.
        f.seekg(tam, ios::beg);
        int mostrarid;
        f.read((char *)(&mostrarid),sizeof(mostrarid));
            //comparo con el if y si son iguales, activo bandera para que no me haga una iteracion extra.
        if((mostraridact>0) and mostrarid==mostraridact){
            band=true;
          }
      i++;
    }
     f.close();
     indices.close();
}

void Arbol::cargaArbol(){
    ifstream archivo("indices.txt");
    fstream f;
    string linea;
    char delimitador = ',';
    int p=0;
    int estado=0;
    string aux;
    string x;
    int tam=0;
    bool limite = true;
    getline(archivo,x,'\n');
    while(getline(archivo,linea,'|')){
        getline(archivo,aux,'\n');
        cout<<endl;
        Nodo *papa = new Nodo();
        int id = stoi(linea);
        int referencia = stoi(aux);
        insertar(raiz,papa,id,referencia);
    }
}

void Arbol::actualizaIndices(Nodo *actual){
    fstream f;
    f.open("auxindices.txt", ios::out);
    f.close();
    f.open("auxindices.txt", ios::in| ios::app);
    f<<"ACTUALIZADO   "<<"\n";
    f.close();
    inordenEscribe(raiz);
    f.open("indices.txt", ios::in|ios::out);
    f.seekp(0, ios::beg);
    f<<"DESACTUALIZADO";
    f.close();
    f.open( "indicesoldver.txt", ios::in | ios::out |ios::binary );
            // Si el archivo no existe
            if( !f.is_open())
            {
                rename("indices.txt", "indicesoldver.txt");
                rename("auxindices.txt","indices.txt");
            }
            else{
                f.close();
                remove("indicesoldver.txt");
                rename("indices.txt", "indicesoldver.txt");
                rename("auxindices.txt","indices.txt");
            }
            f.close();

}

void Arbol::inordenEscribe(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{
        int prubea = actual->dato;
        inordenEscribe(actual->izq);
        fstream f;
        f.open("auxindices.txt", ios::in| ios::app);
        f<<actual->dato<<"|"<<actual->referencia<<"\n";
        f.close();
        inordenEscribe(actual->der);
    }
}


void Arbol::eliminar(Nodo *&actual,Nodo *&papa,int e){
    if(actual->dato==e){
        if(papa->izq!=nullptr||papa->der!=nullptr){
            //cout<<"ESE NIVEL YA EXISTIA, ESTAMOS AÑADIENDO UN HERMANO."<<endl;
            Nodo *aux = new Nodo();
            aux=papa->padre;
            while (aux){
                    //cout<<"Dato a evaluar: "<<aux->dato<<endl;
                if((aux->dato)>(e)){
                    aux->peso=aux->peso-1;
                }
                else{
                    aux->peso=aux->peso+1;
                }
                aux=aux->padre;
            }
        }
        int prueba = actual->dato;
        int obj = e;
        actual=nullptr;
        return;
    }
    else{
        int vraiz=actual->dato;
        if(e<vraiz){
            actual->peso=(actual->peso+1);
            eliminar(actual->izq,actual,e);
        }
        else{
            actual->peso=(actual->peso-1);
            eliminar(actual->der,actual,e);
        }
    }
    if(actual->peso==2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a la derecha."<<endl;
        rotacionizq(actual);
        //ajuste de Nodos.
        while (aux){
            //cout<<"Dato a evaluar: "<<aux->dato<<endl;
            if((aux->dato)>(e)){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }
    if(actual->peso==-2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a izquierda."<<endl;
        rotacionder(actual);
        //si hay rotacion, ajustamos nodos
        while (aux){
            if((aux->dato)>(e)){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }
}


///////////////////////METODOS DE REMITENTE.

void Arbol::insertarRem(char e[],Nodo *&actual,Nodo *&papa,int refe){
        if(actual==nullptr){
        if(papa->izq!=nullptr||papa->der!=nullptr){
            //cout<<"ESE NIVEL YA EXISTIA, ESTAMOS AÑADIENDO UN HERMANO."<<endl;
            Nodo *aux = new Nodo();
            aux=papa->padre;
            while (aux){
                    //cout<<"Dato a evaluar: "<<aux->dato<<endl;
                if(esMenor(e,aux->remitente)==1){
                    aux->peso=aux->peso+1;
                }
                else{
                    aux->peso=aux->peso-1;
                }
                aux=aux->padre;
            }
        }
        Nodo *tmp = new Nodo();
        int i=0;
        while(e[i]!='\0'){
            tmp->remitente[i]=e[i];
            i++;
        }
        tmp->remitente[i] = '\0';
        //tmp->referencia=refe;
        actual=tmp;
        actual->padre=papa;
        NodoSec *auxiliar = new NodoSec();
        auxiliar->referenciaPrim = refe;
        actual->ancla = auxiliar;

        if(raiz==nullptr){
            raiz=actual;
        }
        return;
    }
    else{
        int vraiz=actual->dato;
        if(sonIguales(e,actual->remitente)){
            Nodo *aux = new Nodo();
            aux=papa->padre;
            while (aux){
                    //cout<<"Dato a evaluar: "<<aux->dato<<endl;
                if(esMenor(e,aux->remitente)==1){
                    aux->peso=aux->peso+1;
                }
                else{
                    aux->peso=aux->peso-1;
                }
                    aux=aux->padre;
            }
            NodoSec *auxiliar = new NodoSec();
            auxiliar->referenciaPrim = refe;
            NodoSec *recorre = new NodoSec();
            recorre = actual->ancla;
            while(recorre->sig!=nullptr){
                recorre=recorre->sig;
            }
            recorre->sig = auxiliar;
            return;
        }
        if(esMenor(e,actual->remitente)==1){
            actual->peso=(actual->peso-1);
            insertarRem(e,actual->izq,actual,refe);
        }
        else{
            actual->peso=(actual->peso+1);
            insertarRem(e,actual->der,actual,refe);
        }
    }
    if(actual->peso==2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a la derecha."<<endl;
        rotacionizq(actual);
        //ajuste de Nodos.
        while (aux){
            //cout<<"Dato a evaluar: "<<aux->dato<<endl;
            if(esMenor(e,aux->remitente)==1){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }
    if(actual->peso==-2){
        Nodo *aux = new Nodo();
        aux=actual->padre;
        //cout<<"EL nodo :"<<actual->dato;
        //cout<<"Tiene un peso de "<<actual->peso<<") Se requiere rotación a izquierda."<<endl;
        rotacionder(actual);
        //si hay rotacion, ajustamos nodos
        while (aux){
            if(esMenor(e,aux->remitente)==1){
                aux->peso=aux->peso+1;
            }
            else{
                aux->peso=aux->peso-1;
            }
            aux=aux->padre;
        }
    }

}


bool Arbol::sonIguales(char a[],char b[]){
    int i=0;
    while(i<24){
        if(a[i]!=b[i]){
            return false;
        }
        if(a[i]=='\0' && b[i]=='\0'){
            return true;
        }
        i++;
    }
}

int Arbol::esMenor(char a[],char b[]){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    int longa=0;
    int longb=0;
    longa=i;
    i=0;
    while(b[i]!='\0'){
        i++;
    }
    longb=i;
    i=0;
    if(longb<longa){
        while(comparaChar(a[i],b[i])==2 || i<longb){
            if(comparaChar(a[i],b[i])==0){
                    return 1;

            }else if(comparaChar(a[i],b[i])==1){
                char auxa = a[i];
                char auxb = b[i];
                return 2;
            }
            i++;
        }
        return 2;
    }else{
        while(comparaChar(a[i],b[i])==2 || i<longa){
            if(comparaChar(a[i],b[i])==0){
                    return 1;

            }else if(comparaChar(a[i],b[i])==1){
                return 2;
            }
            i++;
        }
        return 1;
    }

}


int Arbol::comparaChar(char a, char b){
    int valora;
    int valorb;
    if(a==b){
        return 2;
    }
    if(a=='A' || a=='a'){
        valora = 1;
    }
    if(b=='A' || b=='a'){
        valorb = 1;
    }
    if(a=='B' || a=='b'){
        valora = 2;
    }
    if(b=='B' || b=='b'){
        valorb = 2;
    }
    if(a=='C' || a=='c'){
        valora = 3;
    }
    if(b=='C' || b=='c'){
        valorb = 3;
    }
    if(a=='D' || a=='d'){
        valora = 4;
    }
    if(b=='D' || b=='d'){
        valorb = 4;
    }
    if(a=='E' || a=='e'){
        valora = 5;
    }
    if(b=='E' || b=='e'){
        valorb = 5;
    }
    if(a=='F' || a=='f'){
        valora = 6;
    }
    if(b=='F' || b=='f'){
        valorb = 6;
    }
    if(a=='G' || a=='g'){
        valora = 7;
    }
    if(b=='G' || b=='g'){
        valorb = 7;
    }
    if(a=='H' || a=='h'){
        valora = 8;
    }
    if(b=='H' || b=='h'){
        valorb = 8;
    }
    if(a=='I' || a=='i'){
        valora = 9;
    }
    if(b=='I' || b=='i'){
        valorb = 9;
    }
    if(a=='J' || a=='j'){
        valora = 10;
    }
    if(b=='J' || b=='j'){
        valorb = 10;
    }
    if(a=='K' || a=='k'){
        valora = 11;
    }
    if(b=='K' || b=='k'){
        valorb = 11;
    }
    if(a=='L' || a=='l'){
        valora = 12;
    }
    if(b=='L' || b=='l'){
        valorb = 12;
    }
    if(a=='M' || a=='m'){
        valora = 13;
    }
    if(b=='M' || b=='m'){
        valorb = 13;
    }
    if(a=='N' || a=='n'){
        valora = 14;
    }
    if(b=='N' || b=='n'){
        valorb = 14;
    }
    if(a=='Ñ' || a=='ñ'){
        valora = 15;
    }
    if(b=='Ñ' || b=='ñ'){
        valorb = 15;
    }
    if(a=='O' || a=='o'){
        valora = 16;
    }
    if(b=='O' || b=='o'){
        valorb = 16;
    }
    if(a=='P' || a=='p'){
        valora = 17;
    }
    if(b=='P' || b=='p'){
        valorb = 17;
    }
    if(a=='Q' || a=='q'){
        valora = 18;
    }
    if(b=='Q' || b=='q'){
        valorb = 18;
    }
    if(a=='R' || a=='r'){
        valora = 19;
    }
    if(b=='R' || b=='r'){
        valorb = 19;
    }
    if(a=='S' || a=='s'){
        valora = 20;
    }
    if(b=='S' || b=='s'){
        valorb = 20;
    }
    if(a=='T' || a=='t'){
        valora = 21;
    }
    if(b=='T' || b=='t'){
        valorb = 21;
    }
    if(a=='U' || a=='u'){
        valora = 22;
    }
    if(b=='U' || b=='u'){
        valorb = 22;
    }
    if(a=='V' || a=='v'){
        valora = 24;
    }
    if(b=='V' || b=='v'){
        valorb = 24;
    }
    if(a=='W' || a=='w'){
        valora = 25;
    }
    if(b=='W' || b=='w'){
        valorb = 25;
    }
    if(a=='X' || a=='x'){
        valora = 26;
    }
    if(b=='X' || b=='x'){
        valorb = 26;
    }
    if(a=='Y' || a=='y'){
        valora = 27;
    }
    if(b=='Y' || b=='y'){
        valorb = 27;
    }
    if(a=='Z' || a=='z'){
        valora = 28;
    }
    if(b=='Z' || b=='z'){
        valorb = 28;
    }
    //comparo cual demis dos caracteres fue mayor, en caso de que no hayn sido iguales
    if(valora<valorb){
        return 0;
    }
    if(valorb<valora){
        return 1;
    }

}


void Arbol::inordenRem(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{

        fstream indices;
        string file2 = "indicesSecundarios.txt";
        indices.open(file2, ios::in| ios::app);
        inordenRem(actual->izq);
        NodoSec *auxlist = new NodoSec();
        auxlist = actual->ancla;
        indices<<actual->remitente<<"|";
        while(auxlist){
            indices<<auxlist->referenciaPrim<<")";
            auxlist=auxlist->sig;
        }
        indices<<endl;
        indices.close();
        inordenRem(actual->der);
    }
 }

 void Arbol::inordenRemAux(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{

        fstream indices;
        string file2 = "auxindicesSecundarios.txt";
        indices.open(file2, ios::in| ios::app);
        inordenRemAux(actual->izq);
        NodoSec *auxlist = new NodoSec();
        auxlist = actual->ancla;
        indices<<actual->remitente<<"|";
        while(auxlist){
            indices<<auxlist->referenciaPrim<<")";
            auxlist=auxlist->sig;
        }
        indices<<endl;
        indices.close();
        inordenRemAux(actual->der);
    }
 }

 void Arbol::inordenMostrar(Nodo *actual){
    if (actual == nullptr){//arbol que mandamos esta vacía
        return;
    }
    else{

        fstream indices;
        string file2 = "indicesSecundarios.txt";
        inordenMostrar(actual->izq);
        indices.open(file2, ios::in| ios::app);
        NodoSec *auxlist = new NodoSec();
        auxlist = actual->ancla;
        cout<<"Remitente: "<<actual->remitente<<"|";
        while(auxlist){
            cout<<"Indice:"<<auxlist->referenciaPrim<<")";
            auxlist=auxlist->sig;
        }
        indices.close();
        inordenMostrar(actual->der);
    }
 }

void Arbol::eliminaRem(Nodo *root,char e[],int referencia){
    if(vacio(raiz)){
        cout<<"Arbol vacio"<<endl;
        return ;
    }
    if(vacio(raiz)==false and root==nullptr){
        cout<<"Correo no encontrado"<<endl;
        return ;
    }
    else{
        Nodo *tmp = root;
        if(sonIguales(tmp->remitente,e)){
            NodoSec *lista = tmp->ancla;
            Correos *uno = new Correos();
            while(lista){
                string file = "pruebaSED.bin";
                //uno->leer(lista->referenciaPrim,file);
                if(lista->referenciaPrim==referencia){
                    lista->referenciaPrim = -1;
                    return;
                }
                lista=lista->sig;
            }
        }
        else if(esMenor(tmp->remitente,e)==1){
            eliminaRem(tmp->der,e,referencia);
        }
        else if(esMenor(e,tmp->remitente)==1){
            eliminaRem(tmp->izq,e,referencia);
        }
    }
}

 void Arbol::cargaArbolRem(){
    ifstream archivo("indicesSecundarios.txt");
    fstream f;
    string linea;
    int p=0;
    int estado=0;
    string aux;
    string x;
    int tam=0;
    bool limite = true;
    getline(archivo,x,'\n');
    while(getline(archivo,linea,'|')){
        while(archivo.peek()!='\n'){
            getline(archivo,aux,')');
            Nodo *papa = new Nodo();
            int referencia = stoi(aux);
            char *c_string_copy = new char[24];
            memmove(c_string_copy, linea.c_str(), linea.length());
            c_string_copy[linea.length()]='\0';
            //MANDO UN NODO NULL PARA QUE SEA EL PADRE DE LA RAIZ.

            //uno->ObtenRemitente(aux,tam);
            //continua aqui!!!!!!!!!
            insertarRem(c_string_copy,raiz,papa,referencia);
        }
        getline(archivo,x,'\n');
    }
}

void Arbol::generaindicesRem(){
    cout<<"Voy a generar El archivo de indicesSecundarios"<<endl;
    string file="pruebaSED.bin";
    string file2 = "indicesSecundarios.txt";
    fstream indices;
    Correos *uno = new Correos();
    int id;
    fstream f;
    bool band;
    int i = 0;
    int k=0;
    int tam=0;
    f.open( file, ios::in | ios::out);
    while((!f.eof()) and band==false){
        f.seekg(tam, ios::beg);
        int id = 0;
        f.read((char *)(&id),sizeof(id));
        if (id>0){
            //SI hubo ID mayor a 0, es correo valido y lo mandamos al arbol.
            Nodo *pa = new Nodo();
            char aux[24];
            //MANDO UN NODO NULL PARA QUE SEA EL PADRE DE LA RAIZ.
            int referencia = uno->obtenReferencia(file,tam);
            uno->ObtenRemitente(aux,tam);
            //continua aqui!!!!!!!!!
            insertarRem(aux,raiz,pa,referencia);
        }
        //leo idactual
        int mostraridact;
        f.read((char *)(&mostraridact),sizeof(mostraridact));
        tam=tam+400;
        //leo id siguiente. Si son iguales y mayores a 0 ya no leo mas, ya que es la basura.
        f.seekg(tam, ios::beg);
        int mostrarid;
        f.read((char *)(&mostrarid),sizeof(mostrarid));
            //comparo con el if y si son iguales, activo bandera para que no me haga una iteracion extra.
        if((mostraridact>0) and mostrarid==mostraridact){
            band=true;
          }
      i++;
    }
     f.close();
     inordenRem(raiz);
}

void Arbol::busquedaRem(Nodo *root,char e[]){
    if(vacio(raiz)){
        cout<<"Arbol vacio"<<endl;
        return ;
    }
    if(vacio(raiz)==false and root==nullptr){
        cout<<"Correo no encontrado"<<endl;
        return ;
    }
    else{
        Nodo *tmp = root;
        if(sonIguales(tmp->remitente,e)){
            NodoSec *lista = tmp->ancla;
            Correos *uno = new Correos();
            while(lista){
                string file = "pruebaSED.bin";
                if(lista->referenciaPrim!=-1)
                    uno->leer(lista->referenciaPrim,file);
                    lista=lista->sig;
                }
            }
        else if(esMenor(tmp->remitente,e)==1){
            busquedaRem(tmp->der,e);
        }
        else if(esMenor(e,tmp->remitente)==1){
            busquedaRem(tmp->izq,e);
        }
    }
}


void Arbol::actualizaIndicesSec(Nodo *actual){
    fstream f;
    f.open("auxindicesSecundarios.txt", ios::out);
    f.close();
    f.open("auxindicesSecundarios.txt", ios::in| ios::app);
    f<<"ACTUALIZADO   "<<"\n";
    f.close();
    inordenRemAux(raiz);
    f.open("indicesSecundarios.txt", ios::in|ios::out);
    f.seekp(0, ios::beg);
    f<<"DESACTUALIZADO";
    f.close();
    f.open( "indicesSecundariosoldver.txt", ios::in | ios::out |ios::binary );
            // Si el archivo no existe
            if( !f.is_open())
            {
                rename("indicesSecundarios.txt", "indicesSecundariosoldver.txt");
                rename("auxindicesSecundarios.txt","indicesSecundarios.txt");
            }
            else{
                f.close();
                remove("indicesSecundariosoldver.txt");
                rename("indicesSecundarios.txt", "indicesSecundariosoldver.txt");
                rename("auxindicesSecundarios.txt","indicesSecundarios.txt");
            }
            f.close();

}

Arbol::Arbol()
{
    raiz=nullptr;
}
