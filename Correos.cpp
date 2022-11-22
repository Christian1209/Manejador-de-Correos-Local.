#include "Correos.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <string.h>
#include <cstdlib>
using namespace std;
void Correos::eid(int a,int t,string file){
     int tam=0;
     tam=(t+tam);
     fstream f;
     f.open( file, ios::in | ios::out |ios::binary );
     f.seekp(tam, ios::beg);
     f.write((char *)(&a),sizeof(a));
     f.close();
}

void Correos::ehora(char a[],int t,string file){
     int tam=0;
     t=t+4;
     tam=(t+tam);
     fstream f;
     f.open( file, ios::in | ios::out |ios::binary );
     f.seekp(tam, ios::beg);
     int i=0;
     while(i<19){
                f.write((char *)(&a[i]),sizeof(a[i]));
                i++;
            }
     f.close();
}

void Correos::eremitente(int t,string file){
    cout<<"Introduce remitente. (max 25 caracteres)(introduce * para terminar)"<<endl;
    char rem [24];
    int i=0;
    /*while(i<=24){
        rem[i]=' ';
        i++;
    }
    */
    i=0;
    while(i<=24 and rem[i-1]!='*'){
                cin>>rem[i];
                i++;
            }
    rem[i-1]='\0';
    int tam = 0;
    t=t+23;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
            }
    f.close();
}

void Correos::eremitente(char rem[],int t,string file){
    int i=0;
    int tam = 0;
    t=t+23;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
            }
    f.close();
}

void Correos::edestinatario(int t,string file){
    char rem [24];
    int i;
    cout<<"Introduce Destinatario. (max 25 caracteres)(introduce * para terminar)"<<endl;
    /*
    while(i<24){
        rem[i]=' ';
        i++;
    }
    */
    i=0;
    while(i<=24 and rem[i-1]!='*'){
        cin>>rem[i];
                i++;
            }
    rem[i-1]='\0';
    int tam = 0;
    t=t+47;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::edestinatario(char rem[],int t,string file){
    int i=0;
    int tam = 0;
    t=t+47;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::ecc(int t,string file){
    int i;
    char rem[24];
    cin.clear();
    cout<<"Introduce Destinatario copia carbon CC:. (max 25 caracteres)(introduce * para terminar)"<<endl;
    //metodo copia carbonCC:
    i=0;
    while(i<=24 and rem[i-1]!='*'){
        cin>>rem[i];
        i++;
    }
    rem[i-1]='\0';
    int tam = 0;
    t=t+71;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::ecc(char rem[],int t,string file){
    int i=0;
    int tam = 0;
    t=t+71;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::eccciega(int t,string file){
    int i;
    cout<<"Introduce Destinatario copia carbon ciega CCC:. (max 25 caracteres)(introduce * para terminar)"<<endl;
    char rem[24];
        i=0;
        while(i<=24 and rem[i-1]!='*'){
            cin>>rem[i];
            i++;
        }
    rem[i-1]='\0';
    int tam = 0;
    t=t+95;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::eccciega(char rem[],int t,string file){
    int i=0;
    int tam = 0;
    t=t+95;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::easunto(int t,string file){
    int i;
    cout<<"Introduce Asunto: (max 25 caracteres)(introduce * para terminar)"<<endl;
    char rem[24];
    i=0;
    cin.get();
    while(i<=24 and rem[i-1]!='*'){
        cin.get(rem[i]);
        i++;
    }
    rem[i-1]='\0';
    int tam = 0;
    t=t+119;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::easunto(char rem[],int t,string file){
    int i=0;
    int tam = 0;
    t=t+119;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    f.close();
}

void Correos::econtenido(int t,string file){
    int i;
    cout<<"introduce Contenido (max 250 caracteres)(introduce * para terminar)"<<endl;
    cin.get();
    char cont[249];
    i=0;
    while(i<=249 and cont[i-1]!='*'){
        cin.get(cont[i]);
        i++;
    }
    cont[i-1]='\0';
    int tam = 0;
    t=t+143;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    i=0;
    while(i<=249){
                f.write((char *)(&cont[i]),sizeof(cont[i]));
                i++;
    }
    f.close();
}

void Correos::econtenido(char cont[],int t,string file){
    int i;
    int tam = 0;
    t=t+143;
    tam=(t+tam);
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekp(tam, ios::beg);
    i=0;
    while(i<=249){
                f.write((char *)(&cont[i]),sizeof(cont[i]));
                i++;
    }
    f.close();
}

void Correos::leer(int t,string file){
     fstream f;
     int tam=0;
     tam=(t+tam);
     string prueba = file;
     f.open( prueba, ios::in | ios::out |ios::binary );
     //mostrar id;
     f.seekg(tam, ios::beg);
     int mostrarid;
     f.read((char *)(&mostrarid),sizeof(mostrarid));
     cout << "id: " << mostrarid << endl;
     tam=tam+4;
     //mostrar hora
     f.seekg(tam, ios::beg);
     char mostrarhora[19];
     cout<<"Hora: ";
     f.read((char *)(&mostrarhora),sizeof(mostrarhora));
     int i = 0;
     while(i<19 and mostrarhora[i]!='\0'){
                cout<<mostrarhora[i];
                i++;
     }
     cout<<endl;
     tam=tam+19;
     //mostrar remitente
     char mostrarchar[24];
     f.seekg(tam, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     cout << "Remitente: ";
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cout<<mostrarchar[i];
                i++;
     }
     cout<<endl;
     tam = tam+24;
     //mostrar destinatario
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     cout << "Destinatario: ";
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cout<<mostrarchar[i];
                i++;
     }
     cout<<endl;
     tam=tam+24;
     //mostrar copia carbon
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     cout << "Copia carbon: ";
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cout<<mostrarchar[i];
                i++;
     }
     cout<<endl;
     tam=tam+24;
     //mostrar copia carbon oculta.
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     cout << "Copia carbon Oculta: ";
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cout<<mostrarchar[i];
                i++;
     }
     cout<<endl;
     tam=tam+24;
     //mostrar asunto
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     tam=tam+24;
     cout << "Asunto: ";
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cout<<mostrarchar[i];
                i++;
     }
     cout<<endl;
     //mostrar contenido
     char contenido[249];
     f.seekg((tam),ios::beg);
     f.read((char *)(&contenido),sizeof(contenido));
     cout<<"Contenido: ";
     i = 0;
     while(i<249 and contenido[i]!='\0'){
                cout<<contenido[i];
                i++;
     }
     cout<<endl;
     f.close();
}

void Correos::busquedaremitente(string file){
    int i=0;
    i=0;
    char rem[24];
    while(i<=26){
        rem[i]=' ';
        i++;
    }
    i=0;
    cout<<"¿Que remitente quieres buscar?"<<endl;
    cin.clear();
    while(i<=24 and rem[i-1]!='*'){
        cin>>rem[i];
        i++;
    }
    rem[i-1]=' ';
    bool band=false;
    bool encontrado=false;
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    f.seekg(0, ios::beg);
    //mostrar remitente
    int tam = 23;
    char mostrarchar[24];
    while((!f.eof()) and band==false){
    f.seekg(tam, ios::beg);
    band=true;
    f.read((char *)(&mostrarchar),sizeof(mostrarchar));
    for(int k=0; k<24; k++){
        if (rem[k]!=mostrarchar[k]){
            band=false;
            break;
        }
    }
    if (band==true){
    encontrado = true;
    tam=tam-23;
    leer(tam,file);
    modificar(tam,file);
    tam=tam+23;
    //f.open( file, ios::in | ios::out |ios::binary );
    int seg;
    do{
        cout<<"Seguir buscando correos del remitente? 1).-Si 2).-NO"<<endl;
        cin>>seg;
    }while(seg<1 and seg>2);
    if (seg==2){
        band=true;
    }
    else if (seg==1){
        band=false;
    }
    }
    f.seekg(tam-23, ios::beg);
    //leo idactual
    int mostraridact;
    f.read((char *)(&mostraridact),sizeof(mostraridact));
    tam=tam+400;
    //leo id siguiente. Si son iguales y mayores a 0 ya no leo mas, ya que es la basura.
    f.seekg(tam-23, ios::beg);
    int mostrarid;
    f.read((char *)(&mostrarid),sizeof(mostrarid));
        //comparo con el if y si son iguales, activo bandera para que no me haga una iteracion extra.
    if((mostraridact>0) and mostrarid==mostraridact){
        band=true;
      }
    }
    f.close();
    if (encontrado==false){
        cout<<"Remitente no encontrado"<<endl;
    }
}

void Correos::leerxremitente(string file){
     cout<<"¿Que remitente quieres buscar?"<<endl;
    int i=0;
    i=0;
    char rem[24];
    while(i<=24){
        rem[i]=' ';
        i++;
    }
    i=0;
    while(i<=24 and rem[i-1]!='*'){
        cin>>rem[i];
        i++;
    }
    rem[i-1]=' ';
    bool band=false;
    bool encontrado=false;
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    //mostrar remitente
    int tam = 23;
    char mostrarchar[24];
    while((!f.eof()) and band==false){
    f.seekg(tam, ios::beg);
    band=true;
    f.read((char *)(&mostrarchar),sizeof(mostrarchar));
    int j=0;
    for(int k=0; k<24; k++){
        if (rem[k]!=mostrarchar[k]){
            band=false;
            break;
        }
    }
    if (band==true){
    cout<<"Remitente encontrado"<<endl;
    encontrado = true;
    tam=tam-23;
    f.seekg(tam, ios::beg);
    int id = 0;
    f.read((char *)(&id),sizeof(id));
    if (id>0){
          leer(tam,file);
    }
    tam=tam+23;
    //f.open( file, ios::in | ios::out |ios::binary );
    int seg;
    do{
        cout<<"Seguir buscando correos del remitente? 1).-Si 2).-NO"<<endl;
        cin>>seg;
    }while(seg<1 and seg>2);
    if (seg==2){
        band=true;
    }
    else if (seg==1){
        band=false;
    }
    }
    f.seekg(tam-23, ios::beg);
    //leo idactual
    int mostraridact;
    f.read((char *)(&mostraridact),sizeof(mostraridact));
    tam=tam+400;
    //leo id siguiente. Si son iguales y mayores a 0 ya no leo mas, ya que es la basura.
    f.seekg(tam-23, ios::beg);
    int mostrarid;
    f.read((char *)(&mostrarid),sizeof(mostrarid));
        //comparo con el if y si son iguales, activo bandera para que no me haga una iteracion extra.
    if((mostraridact>0) and mostrarid==mostraridact){
        band=true;
      }
    }
    f.close();
    if (encontrado==false){
        cout<<"Remitente no encontrado"<<endl;
    }
}

void Correos::modificar(int tam,string file){
    int mod=0;
    cout<<"¿Que apartado quieres modificar? 1).-Remitente 2).-Destinatario 3).-Copia carbon."<<endl;
    cout<<"4).-Copia carbon ciega. 5).- Asunto. 6).-Contenido."<<endl;
    cin>>mod;
    switch(mod){
    case 1:
        cout<<"Modificar Remitente"<<endl;
        eremitente(tam,file);
        break;
    case 2:
        cout<<"Modificar Destinatario"<<endl;
        edestinatario(tam,file);
        break;
    case 3:
        cout<<"Modificar Copia carbon"<<endl;
        ecc(tam,file);
        break;
    case 4:
        cout<<"Modificar Copia Carbon Ciega"<<endl;
        eccciega(tam,file);
        break;
    case 5:
        cout<<"Modificar Asunto"<<endl;
        easunto(tam,file);
        break;
    case 6:
        cout<<"Modificar Contenido"<<endl;
        econtenido(tam,file);
        break;
    }
}

void Correos::eliminar(int t,string file,Arbol *&tree, Arbol*&treeRem){
    //eliminar id
     int a=0;
     fstream f;
     f.open( file, ios::in | ios::out |ios::binary );
     f.seekg(t, ios::beg);
     char auxborrar[24];
     ObtenRemitente(auxborrar,t);
     treeRem->eliminaRem(treeRem->raiz,auxborrar,t);
     int mostrarid;
     f.read((char *)(&mostrarid),sizeof(mostrarid));
     Nodo *pa = new Nodo();
     tree->eliminar(tree->raiz,pa,mostrarid);
     f.close();
     f.open( file, ios::in | ios::out |ios::binary );
     f.seekp(t, ios::beg);
     f.write((char *)(&a),sizeof(a));
     //eliminar hora
     t=t+4;
     f.seekp(t, ios::beg);
     int i=0;
     char horav [19]; //horavacia para eliminar
     while (i<19){
        horav[i]=' ';
        i++;
     }
     i=0;
     while(i<19){
                f.write((char *)(&horav[i]),sizeof(horav[i]));
                i++;
            }
     t=t+19;
    //metodo remitente.
    char rem [24];
    i=0;
    while(i<=24){
        rem[i]=' ';
        i++;
    }
    i=0;
    f.seekp(t, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
            }
    //metodo Destinatario
    t=t+24;
    f.seekp(t, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    //metodo copia carbon
    t=t+24;
    f.seekp(t, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    //metodo copia ciega.
    t=t+24;
    f.seekp(t, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    //metodo asunto
    t=t+24;
    f.seekp(t, ios::beg);
    i=0;
    while(i<24){
                f.write((char *)(&rem[i]),sizeof(rem[i]));
                i++;
    }
    //metodo contenido
    char cont[249];
    i=0;
    while(i<=249){
        cont[i]=' ';
        i++;
    }
    t=t+24;
    f.seekp(t, ios::beg);
    i=0;
    while(i<=249){
                f.write((char *)(&cont[i]),sizeof(cont[i]));
                i++;
    }

}

void Correos::eliminarxremitente(string file,Arbol *&tree,Arbol *&treeRem){
    cout<<"¿Que remitente quieres buscar?"<<endl;
    int i=0;
    i=0;
    char rem[24];
    while(i<=24){
        rem[i]=' ';
        i++;
    }
    i=0;
    while(i<=24 and rem[i-1]!='.'){
        cin>>rem[i];
        i++;
    }
    bool band=false;
    bool encontrado=false;
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
    //mostrar remitente
    int tam = 23;
    char mostrarchar[24];
    while((!f.eof()) and band==false){
    f.seekg(tam, ios::beg);
    band=true;
    f.read((char *)(&mostrarchar),sizeof(mostrarchar));
    int j=0;
    for(int k=0; k<24; k++){
        if (rem[k]!=mostrarchar[k]){
            band=false;
            break;
        }
    }
    if (band==true){
    cout<<"Remitente encontrado"<<endl;
    encontrado = true;
    tam=tam-23;
    leer(tam,file);
    eliminar(tam,file,tree,treeRem);
    char auxborrar[24];
    ObtenRemitente(auxborrar,tam);
    treeRem->eliminaRem(treeRem->raiz,auxborrar,tam);
    tam=tam+23;
    //f.open( file, ios::in | ios::out |ios::binary );
    int seg;
    do{
        cout<<"Seguir buscando correos del remitente? 1).-Si 2).-NO"<<endl;
        cin>>seg;
    }while(seg<1 and seg>2);
    if (seg==2){
        band=true;
    }
    else if (seg==1){
        band=false;
    }
    }
    f.seekg(tam-23, ios::beg);
    //leo idactual
    int mostraridact;
    f.read((char *)(&mostraridact),sizeof(mostraridact));
    tam=tam+400;
    //leo id siguiente. Si son iguales y mayores a 0 ya no leo mas, ya que es la basura.
    f.seekg(tam-23, ios::beg);
    int mostrarid;
    f.read((char *)(&mostrarid),sizeof(mostrarid));
        //comparo con el if y si son iguales, activo bandera para que no me haga una iteracion extra.
    if((mostraridact>0) and mostrarid==mostraridact){
        band=true;
      }
    }
    f.close();
    if (encontrado==false){
        cout<<"Remitente no encontrado"<<endl;
    }
}

void Correos::exportarcsv(string file){
    fstream f;
    bool sobrescribe=true;
    int op=0;
    f.open( "copia.csv", ios::in | ios::out |ios::binary );
     if( !f.is_open())
        {
        f.open("copia.csv", ios::out);
        cout<<"creando archivo csv..."<<endl;
        f.close();
        f.open("copia.csv", ios::in | ios::app);
        char coma = ',';
        char comilla = '"';
        f<<"ID:"<<coma<<"Hora:"<<coma<<"Remitente:"<<coma<<"Destinatario:"<<coma<<"CC:"<<coma<<"CC(CIEGA):"<<coma<<"Asunto: "<<coma<<"Contenido: "<<endl;
        f.close();
        if( ! f.good() )
        {
        cout << "Error al crear el archivo... abortando" << endl;
        }
     }
     else{
        do{
        cin.clear();
        cout<<"Copia ya existente. \nSobreescribirla .-1)\nAgregar correos actuales .-2)"<<endl;
        cin>>op;
        }while(op>2 || op<1);
     }
     f.close();
     if(op==1){
        remove("copia.csv");
        f.open("copia.csv", ios::out);
        cout<<"creando archivo prop..."<<endl;
        f.close();
        f.open("copia.csv", ios::in | ios::app);
        char coma = ',';
        char comilla = '"';
        f<<"ID:"<<coma<<"Hora:"<<coma<<"Remitente:"<<coma<<"Destinatario:"<<coma<<"CC:"<<coma<<"CC(CIEGA):"<<coma<<"Asunto: "<<coma<<"Contenido: "<<endl;
        f.close();
     }
    //mostrar remitente
    int tam = 0;
    bool band = false;
    f.open( file, ios::in | ios::out |ios::binary );
    while((!f.eof()) and band==false){
    f.seekg(tam, ios::beg);
    int id = 0;
    f.read((char *)(&id),sizeof(id));
    if (id>0){
          copiacsv(tam,file);
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
    }
}

void Correos::copiacsv(int t,string file){
     fstream f;
     fstream csv;
     char coma = ',';
     char comilla = '"';
     int tam=0;
     tam=(t+tam);
     f.open( file, ios::in | ios::out);
     csv.open("copia.csv", ios::in | ios::app);
     //mostrar id;
     f.seekg(tam, ios::beg);
     int mostrarid;
     f.read((char *)(&mostrarid),sizeof(mostrarid));
     //aqui vamos creando la copia, le añadimos el entero y le añadimos una coma.
     csv<<mostrarid;
     csv<<coma;
     tam=tam+4;
     //mostrar hora
     f.seekg(tam, ios::beg);
     char mostrarhora[19];
     f.read((char *)(&mostrarhora),sizeof(mostrarhora));
     int i = 0;
     while(i<19 and mostrarhora[i]!='\0'){
                csv<<mostrarhora[i];
                i++;
     }
     //LE AÑADIMOS A LA COPIA LA HORA.
     csv<<coma;
     tam=tam+19;
     //mostrar remitente
     char mostrarchar[24];
     f.seekg(tam, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                csv<<mostrarchar[i];
                i++;
     }
     csv<<coma;
     tam = tam+24;
     //mostrar destinatario
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                csv<<mostrarchar[i];
                i++;
     }
     csv<<coma;
     tam=tam+24;
     //mostrar copia carbon
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                csv<<mostrarchar[i];
                i++;
     }
     csv<<coma;
     tam=tam+24;
     //mostrar copia carbon oculta.
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                csv<<mostrarchar[i];
                i++;
     }
     csv<<coma;
     tam=tam+24;
     //mostrar asunto
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     tam=tam+24;
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
            if(mostrarchar[i]=='"'){
                csv<<comilla;
            }
                csv<<mostrarchar[i];
                i++;
     }
     csv<<coma;
     //mostrar contenido
     char contenido[249];
     f.seekg((tam),ios::beg);
     f.read((char *)(&contenido),sizeof(contenido));
     csv<<comilla;
     i = 0;
     while(i<249 and contenido[i]!='\0'){
            if(contenido[i]=='"'){
                csv<<comilla;
            }
                csv<<contenido[i];
                i++;
     }
     csv<<comilla;
     char fin = '\n';
     csv<<fin;
     f.close();
     csv.close();
}

void Correos::cargar(string file){
    ifstream archivo("copia.csv");
    string linea;
    char delimitador = ',';
    int p=0;
    int estado=0;
    string aux;
    string x;
    int tam=0;
    bool limite = true;
    getline(archivo,x,'\n');
    while(getline(archivo,linea,'"')){
        aux+=linea;
        if (estado==0){
            estado=1;
        }
        else if(estado==1){
            estado=2;
        }
        if(estado==2){
                if(archivo.peek()!='\n'){
                    aux+='"';
                }
            if(archivo.peek()=='\n'){
                getline(archivo,x,'\n');
                estado=0;
                char *c_string_copy = new char[aux.length() + 1];
                memmove(c_string_copy, aux.c_str(), aux.length());
                /* do operations on c_string_copy here */
                int op=0;
                int id=0;
                int a=0;
                char auxid[4];
                char aux2[24];
                char cont[249];
                bool ocho = false;
                for(int i=0;i<aux.length();i++){
                    if(op==7 && limite){
                            if(a==249){
                                ocho=true;
                            }
                        cont[a]=c_string_copy[i];
                        a++;
                        if(i+1==aux.length()){
                            ocho=true;
                        }
                    }
                    else if(op==0 && limite){
                        if(a>4){
                                limite=false;
                            }
                        auxid[a]=c_string_copy[i];
                        a++;
                    }
                    else{
                        if(limite){
                            if(c_string_copy[i]!=','){
                                aux2[a]=c_string_copy[i];
                            }
                            a++;
                        }

                    }
                    //Copio el arreglo a un auxiliar
                    //aux[i]=c_string_copy[i];
                    if((ocho==true) || (c_string_copy[i]==',') && limite){
                        op++;
                        switch(op){
                    case 1:{
                        //caso id
                        fstream f;
                        // Verificar si existe el archivo
                        f.open( file, ios::in | ios::out |ios::binary );
                        // Si el archivo no existe
                        if( !f.is_open())
                        {
                        f.open(file, ios::out);
                        if( ! f.good() )
                        {
                        cout << "Error al crear el archivo... abortando" << endl;
                        break;
                        }
                        }
                        f.close();
                        int l=0;
                        string id(auxid);
                        int enteroid=0;
                        enteroid = stoi(id);
                        tam=((enteroid-1)*400);
                        //Llamamos eid con entero y tam.
                        eid(enteroid,tam,file);
                        f.close();
                        memset(auxid, 0, 4);
                        a=0;
                    }
                        break;
                    case 2:{
                        //asunto
                        tam=(tam);
                        //llamamos ehora.
                        ehora(aux2,tam,file);
                        memset(aux2, 0, 19);
                        a=0;
                    }
                        break;
                    case 3:{
                        //llamamos remitente
                        tam=(tam);
                        eremitente(aux2,tam,file);
                        memset(aux2, 0, 24);
                        a=0;
                    }
                        break;
                    case 4:{
                        //llamamos edestinatario
                        tam=(tam);
                        edestinatario(aux2,tam,file);
                        memset(aux2, 0, 24);
                        a=0;
                    }
                        break;
                    case 5:{
                        //asunto
                        tam=(tam);
                        ecc(aux2,tam,file);
                        memset(aux2, 0, 24);
                        a=0;
                        break;
                    }
                    case 6:{
                        //asunto
                        tam=(tam);
                        eccciega(aux2,tam,file);
                        fstream f;
                        memset(aux2, 0, 24);
                        a=0;
                        break;
                    }
                    case 7:{
                        //asunto
                        tam=(tam);
                        easunto(aux2, tam,file);
                        memset(aux2, 0, 24);
                        a=0;

                    }
                        break;
                    case 8:{

                        tam=(tam);
                        econtenido(cont,tam,file);
                        memset(cont, 0, 249);
                        a=0;
                        ocho=false;
                    }
                        break;
                        }
                    }
                }
                aux.clear();
            }
            else{
                estado=0;
            }
        }
    }
    cout<<"Se ha cargado la copia CSV!"<<endl;
}

void Correos::eliminarcopiacsv(Arbol *&tree,Arbol *&treeRem){
    string file = "auxiliar.bin";
    cargar(file);
    int tam=0;
    cout<<"Introduce el ID del correo a eliminar"<<endl;
    cin>>tam;
    tam=((tam-1)*400);
    eliminar(tam,file,tree,treeRem);
    remove("copia.csv");
    exportarcsv(file);
    cout<<"correo Eliminado";
    remove("auxiliar.bin");
}

void Correos::modificarcopiacsv(){
    string file = "auxiliar.bin";
    cargar(file);
    int tam=0;
    cout<<"Introduce el ID del correo a Modificar"<<endl;
    cin>>tam;
    tam=((tam-1)*400);
    modificar(tam,file);
    remove("copia.csv");
    exportarcsv(file);
    cout<<"correo Modificado";
    remove("auxiliar.bin");
}

void Correos::exportarprop(string file){
    fstream f;
    bool sobrescribe=true;
    int op=0;
    f.open( "copiaprop.bin", ios::in | ios::out |ios::binary );
     if( !f.is_open())
        {
        f.open("copiaprop.bin", ios::out);
        cout<<"creando archivo propietario..."<<endl;
        f.close();
        f.open("copiaprop.bin", ios::in | ios::app);
        f.close();
        if( ! f.good() )
        {
        cout << "Error al crear el archivo... abortando" << endl;
        }
     }
     else{
        do{
        cin.clear();
        cout<<"Copia propietario ya existente. \nSobreescribirla .-1)\nAgregar correos actuales .-2)"<<endl;
        cin>>op;
        }while(op>2 || op<1);
     }
     f.close();
     if(op==1){
        remove("copiaprop.bin");
        f.open("copiaprop.bin", ios::out);
        cout<<"creando archivo propietario..."<<endl;
        f.close();
        f.open("copiaprop.bin", ios::in | ios::app);
        f.close();
     }
    //mostrar remitente
    int tam = 0;
    int tamesc=0;
    bool band = false;
    f.open( file, ios::in | ios::out |ios::binary );
    while((!f.eof()) and band==false){
    f.seekg(tam, ios::beg);
    int id = 0;
    f.read((char *)(&id),sizeof(id));
    if (id>0){
       tamesc=copiaprop(tam,tamesc,file);
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
    }
}

int Correos::copiaprop(int t,int tamesc, string file){
     fstream f;
     fstream prop;
     int tam=0;
     tam=tam+tamesc;
     int tamlect=0;
     tamlect=tamlect+t;
     int n=0;
     f.open( file, ios::in | ios::out);
     prop.open("copiaprop.bin", ios::in | ios::app | ios::binary );
     //mostrar id;
     f.seekg(tamlect, ios::beg);
     int mostrarid;
     f.read((char *)(&mostrarid),sizeof(mostrarid));
     n=4;
     prop.seekp(tam, ios::beg);
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     tamlect=tamlect+4;
     prop.seekp(tam, ios::beg);
     prop.write((char *)(&mostrarid),sizeof(mostrarid));
     tam=tam+4;
     ////////////////////////////////////////////////////////////////
     //mostrar hora
     f.seekg(tamlect, ios::beg);
     prop.seekp(tam, ios::beg);
     char mostrarhora[19];
     f.read((char *)(&mostrarhora),sizeof(mostrarhora));
     int i = 0;
     n=19;
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     prop.seekp(tam, ios::beg);
     while(i<19){
                prop.write((char *)(&mostrarhora[i]),sizeof(mostrarhora[i]));
                i++;
     }
     cout<<endl;
     tam=tam+19;
     prop.seekp(tam, ios::beg);
     tamlect=tamlect+19;
     /////////////////////////////////////////////////////////////////
     //LE AÑADIMOS A LA COPIA LA HORA
     //mostrar remitente
     char mostrarchar[24];
     f.seekg(tamlect, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     //n es el valor de mi campo de dimension, lo usare antes de escribir cualquier otro registro.
     //lo aumentaré conforme itero hasta encontrar un caracter nulo
     n=0;
     while(i<24 and mostrarchar[i]!='\0'){
        i++;
         n++;
     }
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     prop.seekp(tam, ios::beg);
     i=0;
     prop.seekp(tam, ios::beg);
     while(i<n){
                prop.write((char *)(&mostrarchar[i]),sizeof(mostrarchar[i]));
                i++;
     }
     tam=tam+n;
     prop.seekp(tam, ios::beg);
     n=0;
     tamlect=tamlect+24;
     ///////////////////////////////////////////////////////////////////////////////////////
     //mostrar destinatario
     f.seekg(tamlect, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     //n es el valor de mi campo de dimension, lo usare antes de escribir cualquier otro registro.
     //lo aumentaré conforme itero hasta encontrar un caracter nulo
     while(i<24 and mostrarchar[i]!='\0'){
         n++;
         i++;
     }
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     prop.seekp(tam, ios::beg);
     i=0;
     while(i<n){
                prop.write((char *)(&mostrarchar[i]),sizeof(mostrarchar[i]));
                i++;
     }
     tam=tam+n;
     prop.seekp(tam, ios::beg);
     n=0;
     tamlect=tamlect+24;
     /////////////////////////////////////////////
     //mostrar destinatario copia
     f.seekg(tamlect, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     //n es el valor de mi campo de dimension, lo usare antes de escribir cualquier otro registro.
     //lo aumentaré conforme itero hasta encontrar un caracter nulo
     while(i<24 and mostrarchar[i]!='\0'){
         i++;
         n++;
     }
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     prop.seekp(tam, ios::beg);
     i=0;
     while(i<n){
                prop.write((char *)(&mostrarchar[i]),sizeof(mostrarchar[i]));
                i++;
     }
     tam=tam+n;
     prop.seekp(tam, ios::beg);
     n=0;
     tamlect=tamlect+24;
     /////////////////////////////////////////////////////////
      //mostrar destinatario copia ciega
     f.seekg(tamlect, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     //n es el valor de mi campo de dimension, lo usare antes de escribir cualquier otro registro.
     //lo aumentaré conforme itero hasta encontrar un caracter nulo
     while(i<24 and mostrarchar[i]!='\0'){
         i++;
         n++;
     }
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     prop.seekp(tam, ios::beg);
     i=0;
     while(i<n){
                prop.write((char *)(&mostrarchar[i]),sizeof(mostrarchar[i]));
                i++;
     }
     tam=tam+n;
     prop.seekp(tam, ios::beg);
     n=0;
     tamlect=tamlect+24;
     /////////////////////////////////////////////////////////
     //Mostrar asunto.
     f.seekg(tamlect, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     //n es el valor de mi campo de dimension, lo usare antes de escribir cualquier otro registro.
     //lo aumentaré conforme itero hasta encontrar un caracter nulo
     while(i<24 and mostrarchar[i]!='\0'){
         i++;
         n++;
     }
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     prop.seekp(tam, ios::beg);
     i=0;
     while(i<n){
                prop.write((char *)(&mostrarchar[i]),sizeof(mostrarchar[i]));
                i++;
     }
     tam=tam+n;
     prop.seekp(tam, ios::beg);
     //6cin>>n;
     n=0;
     tamlect=tamlect+24;
     /////////////////////////////////////////////////////////
     //mostrar contenido
     f.seekg(tamlect, ios::beg);
     char contenido[249];
     f.read((char *)(&contenido),sizeof(contenido));
     i = 0;
     while(i<249 and contenido[i]!='\0'){
         i++;
         n++;
     }
     prop.write((char *)(&n),sizeof(n));
     tam=tam+4;
     prop.seekp(tam, ios::beg);
     i=0;
     while(i<n){
                prop.write((char *)(&contenido[i]),sizeof(contenido[i]));
                i++;
     }
     char salto = '\n';
     prop.write((char*)(&salto),sizeof(salto));
     tam=tam+n+1;
     f.close();
     prop.close();
     return tam;
}

void Correos::modificarprop(string file, int op){
    int id;
    if (op==1){
        cout<<"¿Que correo quieres eliminar? (introduce id)"<<endl;
        cin>>id;
    }
    else{
        cout<<"¿Que correo quieres modificar? (introduce id)"<<endl;
        cin>>id;
    }
    int i=0;
    int tam=0;
    int tamesc=0;
    bool band=false;
    bool encontrado=false;
    fstream f;
    f.open( file, ios::in | ios::out |ios::binary );
//    prop.open( "auxiliarprop.bin", ios::in | ios::app |ios::binary );
    /*if(prop.is_open()){
      remove()
    }*/
    //mostrar remitente
    while(!f.eof()){
    f.close();
    //creo un id auxiliar que mandare como parametro para poder compararlo con el id del usuario.
    int idaux;
    ////////////////HERE!!!!!!!!!!
    tam=leerprop(file,tam,&idaux,id,&tamesc,op);
    if(idaux==id){
        band=true;
    }
    //leo id siguiente. Si son iguales y mayores a 0 ya no leo mas, ya que es la basura.
    f.open( file, ios::in | ios::out |ios::binary );
    char dos[3];
    tam=tam+4;
    f.seekg(tam, ios::beg);
    int mostrarid;
    f.read((char *)(&mostrarid),sizeof(dos));
    tam=tam-4;
        //comparo con el if y si son iguales, activo bandera para que no me haga una iteracion extra.
    if((mostrarid>0) and mostrarid==idaux){
        band=true;
      }
      f.close();
    }
    f.close();
    if (encontrado==false){
        cout<<"ID no encontrado"<<endl;
    }
    else{
        cout<<"Se ha borrado correctamente..."<<endl;
    }
    remove("copiaprop.bin");
    rename("auxiliarprop.bin", "copiaprop.bin");

}

int Correos::leerprop(string file,int t,int *idaux,int idbuscar,int *tamesc, int op){
    int i=0;
    fstream f;
    fstream prop;
    int mostrarid=0;
    int tamalprincipio=0;
    char prueba;
    char dos[3];
    char aux[24];
    char auxcont[249];
    int tam=0;
    bool write = true;
    bool edit =false;
    int caso = 0;
    tam=tam+t;
    cout<<"tam al llegar: "<<tam;
    prop.open( "auxiliarprop.bin", ios::in | ios::app |ios::binary );
     if( !prop.is_open())
        {
        prop.open("auxiliarprop.bin", ios::out);
        prop.close();
        prop.open("auxiliarprop.bin", ios::in | ios::app);
        prop.close();
        if( ! prop.good() )
        {
        cout << "Error al crear el archivo... abortando" << endl;
        }
    }
    prop.close();
     ////VALIDAMOS EL ID, POR SI FUERA EL QUE SE BUSCA, NO ESCRIBIR LO DEMAS DEL CODIGO.
     f.open( file, ios::in | ios::out |ios::binary );
     prop.open( "auxiliarprop.bin", ios::in | ios::app |ios::binary );
     tam=tam+4;
     f.seekg(tam, ios::beg);
     f.read((char *)(&mostrarid),sizeof(dos));
     tam=tam-4;
     if(idbuscar == mostrarid and op==1){
        cout<<"Tu id a buscar: "<<idbuscar<<"es igual al ID de este correo: "<<mostrarid<<"No se escribira!"<<endl;
         write=false;
     }
     if(idbuscar == mostrarid and op==2){
        edit=true;
        do{
            cout<<"Que parte quieres modificar?"<<endl;
            cout<<"1).-Remitente, 2).- Destinatario, 3).- Destinatario Copia carbon, 4).-Destinatario Copia ciega, 5).- Asunto, 6).-Contenido"<<endl;
            cin>>caso;

        }while((caso<1) || (caso>6));
     }
     //////////////////////////////////////mostrar id;
    f.seekg(tam, ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    if(write){
         prop.seekp(*tamesc, ios::beg);
         prop.write((char *)(&mostrarid),sizeof(mostrarid));
         *tamesc=*tamesc+4;
     //si escribimos un campo, debemos aumentar tamesc, ya que es el tamaño de escrituras
    }
    cout << "Dimension de id: " << mostrarid << endl;
    tam=tam+4;
    mostrarid=0;
    f.seekg(tam, ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    cout << "id: " << mostrarid << endl;
    *idaux=mostrarid;
    if(write){
         prop.seekp(*tamesc, ios::beg);
         prop.write((char *)(&mostrarid),sizeof(mostrarid));
         *tamesc=*tamesc+4;
         //si escribimos un campo, debemos aumentar *tamesc, ya que es el tamaño de escrituras
    }
    tam=tam+4;
    //////////////////////////////////////////////mostrar hora
    f.seekg(tam, ios::beg);
    mostrarid=0;
    f.read((char *)(&mostrarid),sizeof(dos));
    cout << "Dimension de hora: " << mostrarid << endl;
    if(write){
         prop.seekp(*tamesc, ios::beg);
         prop.write((char *)(&mostrarid),sizeof(mostrarid));
         *tamesc=*tamesc+4;
         //si escribimos un campo, debemos aumentar *tamesc, ya que es el tamaño de escrituras
    }
    tam=tam+4;
    f.seekg(tam, ios::beg);
    char mostrarhora[19];
    cout<<"Hora: "<<endl;
    f.read((char *)(&mostrarhora),sizeof(mostrarhora));
    i = 0;
    while(i<19 and mostrarhora[i]!='\0'){
        cout<<mostrarhora[i];
        i++;
     }
    i=0;
    if(write){
    prop.seekp(*tamesc, ios::beg);
        while(i<19){
                prop.write((char *)(&mostrarhora[i]),sizeof(mostrarhora[i]));
                cout<<mostrarhora[i];
                i++;
        }
        *tamesc=*tamesc+19;
    }
    cout<<endl;
    tam=tam+19;
    if(caso==1){
        write=false;
        //si edit era true, a partir de aqui es donde puedo editar, por ello ya no debo de copiar a mi "copia".
    }
    //mostrar remitente
    f.seekg(tam, ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    if(write){
         prop.seekp(*tamesc, ios::beg);
         prop.write((char *)(&mostrarid),sizeof(mostrarid));
         *tamesc=*tamesc+4;
         //si escribimos un campo, debemos aumentar *tamesc, ya que es el tamaño de escrituras
    }
    cout << "Dimension de remitente: " << mostrarid << endl;
    tam=tam+4;
    char mostrarrem[mostrarid];
    f.seekg(tam, ios::beg);
    f.read((char *)(&mostrarrem),sizeof(mostrarrem));
    cout << "Remitente: ";
    i = 0;
    while(i!=mostrarid and mostrarrem[i]!='\0'){
            cout<<mostrarrem[i];
            i++;
    }
    cout<<endl;
    i=0;
    if (write){
        prop.seekp(*tamesc, ios::beg);
        while(i!=mostrarid and mostrarrem[i]!='\0'){
                prop.write((char *)(&mostrarrem[i]),sizeof(mostrarrem[i]));
                i++;
        }
        *tamesc=*tamesc+mostrarid;
    }
    i=0;
    if(caso==1){
        cout<<"Introduce nuevo remitente. (max 25 caracteres)(introduce * para terminar)"<<endl;
        while(i<=24 and aux[i-1]!='*'){
                cin>>aux[i];
                i++;
            }
        aux[i-1]='\0';
        i--;
        int mostrarid2=i;
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid2),sizeof(mostrarid2));
        *tamesc=*tamesc+4;
        //escribo dimension, y luego el remitente.
        i=0;
        while(i<mostrarid2){
            prop.write((char *)(&aux[i]),sizeof(aux[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid2;
        write=true;
    }
    tam = tam+mostrarid;
    /////////mostrar destinatario
    if(caso==2){
        write=false;
        //si edit era true, a partir de aqui es donde puedo editar, por ello ya no debo de copiar a mi "copia".
    }
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    if(write){
         prop.seekp(*tamesc, ios::beg);
         prop.write((char *)(&mostrarid),sizeof(mostrarid));
         *tamesc=*tamesc+4;
         //si escribimos un campo, debemos aumentar *tamesc, ya que es el tamaño de escrituras
    }
    cout << "Dimension de destinatario: " << mostrarid << endl;
    *tamesc=*tamesc+4;
    tam=tam+4;
    char mostrardest[mostrarid];
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrardest),sizeof(mostrardest));
    cout << "Destinatario: ";
    i = 0;
    while(i<24 and mostrardest[i]!='\0'){
            cout<<mostrardest[i];
            i++;
    }
    i=0;
    if(write){
        prop.seekp(*tamesc, ios::beg);
        while(i!=mostrarid and mostrardest[i]!='\0'){
                prop.write((char *)(&mostrardest[i]),sizeof(mostrardest[i]));
                i++;
        }
        *tamesc=*tamesc+mostrarid;
    }
    if(caso==2){
        cout<<"Introduce Destinatario. (max 25 caracteres)(introduce * para terminar)"<<endl;
        i=0;
        while(i<=24 and aux[i-1]!='*'){
                cin>>aux[i];
                i++;
            }
        aux[i-1]='\0';
        i--;
        int mostrarid2=i;
        prop.seekp(*tamesc, ios::beg);
         prop.write((char *)(&mostrarid2),sizeof(mostrarid2));
        *tamesc=*tamesc+4;
        //escribo dimension, y luego el remitente.
        i=0;
        while(i<mostrarid2){
            prop.write((char *)(&aux[i]),sizeof(aux[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid2;
        write = true;
    }
    cout<<endl;
    tam=tam+mostrarid;
    //mostrar copia carbon
    if(caso==3){
        write=false;
        //si edit era true, a partir de aqui es donde puedo editar, por ello ya no debo de copiar a mi "copia".
    }
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    if(write){
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid),sizeof(mostrarid));
       *tamesc=*tamesc+4;
    }
    cout << "Dimension de copia carbon: " << mostrarid << endl;
    tam=tam+4;
    char mostrarcopia[mostrarid];
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarcopia),sizeof(mostrarcopia));
    cout << "Copia carbon: ";
    i = 0;
    while(i<24 and mostrarcopia[i]!='\0'){
            cout<<mostrarcopia[i];
            i++;
    }
    i=0;
    if(write){
        prop.seekp(*tamesc, ios::beg);
        while(i!=mostrarid and mostrarcopia[i]!='\0'){
        prop.write((char *)(&mostrarcopia[i]),sizeof(mostrarcopia[i]));
        i++;
        }
        *tamesc=*tamesc+mostrarid;
    }
    if(caso==3){
        cout<<"Introduce Destinatario Copia carbon. (max 25 caracteres)(introduce * para terminar)"<<endl;
        i=0;
        while(i<=24 and aux[i-1]!='*'){
                cin>>aux[i];
                i++;
            }
        aux[i-1]='\0';
        i--;
        int mostrarid2=i;
        prop.seekp(*tamesc, ios::beg);
         prop.write((char *)(&mostrarid2),sizeof(mostrarid2));
        *tamesc=*tamesc+4;
        //escribo dimension, y luego el remitente.
        i=0;
        while(i<mostrarid2){
            prop.write((char *)(&aux[i]),sizeof(aux[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid2;
        write=true;
    }
    cout<<endl;
    tam=tam+mostrarid;
     //mostrar copia carbon oculta.
     if(caso==4){
        write=false;
        //si edit era true, a partir de aqui es donde puedo editar, por ello ya no debo de copiar a mi "copia".
    }
     f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    if(write){
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid),sizeof(mostrarid));
       *tamesc=*tamesc+4;
    }
    cout << "Dimension de copia carbon ocultas " << mostrarid << endl;
    tam=tam+4;
    char mostrarciega[mostrarid];
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarciega),sizeof(mostrarciega));
    cout << "Copia carbon Oculta: ";
    i = 0;
    while(i<24 and mostrarciega[i]!='\0'){
            cout<<mostrarciega[i];
            i++;
    }
    prop.seekp(*tamesc, ios::beg);
    i=0;
    if(write){
        while(i!=mostrarid and mostrarciega[i]!='\0'){
            prop.write((char *)(&mostrarciega[i]),sizeof(mostrarciega[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid;
    }
    if(caso==4){
        cout<<"Introduce Destinatario Copia carbon Oculta. (max 25 caracteres)(introduce * para terminar)"<<endl;
        i=0;
        while(i<=24 and aux[i-1]!='*'){
                cin>>aux[i];
                i++;
            }
        aux[i-1]='\0';
        i--;
        int mostrarid2=i;
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid2),sizeof(mostrarid2));
        *tamesc=*tamesc+4;
        //escribo dimension, y luego el remitente.
        i=0;
        while(i<mostrarid2){
            prop.write((char *)(&aux[i]),sizeof(aux[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid2;
        write=true;
    }
    cout<<endl;
    tam=tam+mostrarid;
    //mostrar asunto
     if(caso==5){
        write=false;
        //si edit era true, a partir de aqui es donde puedo editar, por ello ya no debo de copiar a mi "copia".
    }
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    if(write){
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid),sizeof(mostrarid));
       *tamesc=*tamesc+4;
    }
    cout << "Dimension de asunto: " << mostrarid << endl;
    tam=tam+4;
    char mostrarasunto[mostrarid];
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarasunto),sizeof(mostrarasunto));
    cout << "Asunto: ";
    i = 0;
    while(i<24 and mostrarasunto[i]!='\0'){
            cout<<mostrarasunto[i];
            i++;
     }
     prop.seekp(*tamesc, ios::beg);
    i=0;
    if(write){
        while(i!=mostrarid and mostrarasunto[i]!='\0'){
            prop.write((char *)(&mostrarasunto[i]),sizeof(mostrarasunto[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid;
    }
    if(caso==5){
        cout<<"Introduce Asunto. (max 25 caracteres)(introduce * para terminar)"<<endl;
        i=0;
        while(i<=24 and aux[i-1]!='*'){
                cin>>aux[i];
                i++;
            }
        aux[i-1]='\0';
        i--;
        int mostrarid2=i;
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid2),sizeof(mostrarid2));
        *tamesc=*tamesc+4;
        //escribo dimension, y luego el remitente.
        i=0;
        while(i<mostrarid2){
            prop.write((char *)(&aux[i]),sizeof(aux[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid2;
        write=true;
    }
    tam=tam+mostrarid;
    cout<<endl;
    //mostrar contenido
     if(caso==6){
        write=false;
        //si edit era true, a partir de aqui es donde puedo editar, por ello ya no debo de copiar a mi "copia".
    }
    f.seekg((tam), ios::beg);
    f.read((char *)(&mostrarid),sizeof(dos));
    if(write){
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid),sizeof(mostrarid));
       *tamesc=*tamesc+4;
    }
    cout << "Dimension de contenido: " << mostrarid << endl;
    tam=tam+4;
    char contenido[mostrarid];
    f.seekg((tam),ios::beg);
    f.read((char *)(&contenido),sizeof(contenido));
    cout<<"Contenido: ";
    i = 0;
    while(i<mostrarid and contenido[i]!='\0'){
            cout<<contenido[i];
            i++;
    }
    prop.seekp(*tamesc, ios::beg);
    i=0;
    if(write){
    while(i!=mostrarid and contenido[i]!='\0'){
            prop.write((char *)(&contenido[i]),sizeof(contenido[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid;
    }
    if(caso==6){
        cout<<"Introduce Contenido. (max 250 caracteres)(introduce * para terminar)"<<endl;
        i=0;
        while(i<=249 and auxcont[i-1]!='*'){
                cin>>auxcont[i];
                i++;
            }
        auxcont[i-1]='\0';
        i--;
        int mostrarid2=i;
        prop.seekp(*tamesc, ios::beg);
        prop.write((char *)(&mostrarid2),sizeof(mostrarid2));
        *tamesc=*tamesc+4;
        //escribo dimension, y luego el remitente.
        i=0;
        while(i<mostrarid2){
            prop.write((char *)(&auxcont[i]),sizeof(auxcont[i]));
            i++;
        }
        *tamesc=*tamesc+mostrarid2;
        write=true;
    }
    tam=tam+mostrarid;
    cout<<endl;
    tam=tam+1;
    if(write || edit){
        char salto = '\n';
        prop.write((char*)(&salto),sizeof(salto));
        *tamesc=*tamesc+1;
    }
    prop.close();
    f.close();
return tam;
}


//////////metodo copia RAM seguir aqui,
Correo Correos::copiaRam(int t,string file){
     fstream f;
     Correo c1;
     int tam=0;
     tam=(t+tam);
     f.open( file, ios::in | ios::out);
     //mostrar id;
     f.seekg(tam, ios::beg);
     int mostrarid;
     f.read((char *)(&mostrarid),sizeof(mostrarid));
     //aqui vamos creando la copia, le añadimos el entero y le añadimos una coma.
     c1.setId(mostrarid);
     tam=tam+4;
     //mostrar hora
     f.seekg(tam, ios::beg);
     char mostrarhora[19];
     f.read((char *)(&mostrarhora),sizeof(mostrarhora));
     int i = 0;
     string hora;
     while(i<19 and mostrarhora[i]!='\0'){
                hora+=mostrarhora[i];
                i++;
     }
     //LE AÑADIMOS A LA COPIA LA HORA.
     c1.setHora(hora);
     tam=tam+19;
     //mostrar remitente
     char mostrarchar[24];
     f.seekg(tam, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     //remitente si debe ser arreglo para la comparacion de las cadenas.
     while(i<24 and mostrarchar[i]!='\0'){
                c1.rem[i]=mostrarchar[i];
                i++;
     }
     c1.rem[i]='\0';
     ////
     ////aqui lo que voy a hacer es crear un string e irle concatenando todas los campos para hacer mas facil su manejo.
     ////
     string cont1 = "Destinatario:";
     tam = tam+24;
     //mostrar destinatario
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cont1+=mostrarchar[i];
                i++;
     }
     tam=tam+24;
     //mostrar copia carbon
     cont1 += "\nCopia carbon:";
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cont1+=mostrarchar[i];
                i++;
     }
     tam=tam+24;
     c1.setContenido(cont1);
     //mostrar copia carbon oculta.
     //creo esta string porque la copiaoculta no la voy a mostrar
     string copiaoculta = "\nCopia oculta:";
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                copiaoculta+=mostrarchar[i];
                i++;
     }
     c1.setCopiaOculta(copiaoculta);
     string cont2 = "\nAsunto:";
     tam=tam+24;
     //mostrar asunto
     f.seekg((tam), ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     tam=tam+24;
     i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                cont2+=mostrarchar[i];
                i++;
     }
     cont2 += "\nContenido:";
     //mostrar contenido
     char contenido[249];
     f.seekg((tam),ios::beg);
     f.read((char *)(&contenido),sizeof(contenido));
     i = 0;
     while(i<249 and contenido[i]!='\0'){
                cont2+=contenido[i];
                i++;
     }
     f.close();
     c1.setContenido2(cont2);
     return c1;
}

int Correos::comparaChar(char a, char b){
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

void Correos::shell(Correo a[], int n){
   int i,j,k,incremento;
   Correo aux;
    incremento=n/2;
    while(incremento>0){
        for(i=incremento+1;i<=n;i++){
            j=i-incremento;
            while(j>0){
                if(esMenor(a[j].rem,a[j+incremento].rem)==2){
                    aux = a[j];
                    Correo debug;
                    debug = a[j+incremento];
                    a[j] = a[j+incremento];
                    a[j+incremento] = aux;
                }
                else{
                        j=0;
                    }
                j=j-incremento;
            }
        }
        incremento=incremento/2;
    }
}

int Correos::esMenor(char a[],char b[]){
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

void Correos::busquedaBinaria(Correo a[], char obj[],int n){
    int inf, sup, mitad;
    bool band = false;
    //BB
    inf = 0;
    sup = n;
    while((inf)!=sup){
        mitad = (inf+sup)/2;
        if(sonIguales(a[mitad].rem,obj)){
            cout<<"ID: "<<a[mitad].getId()<<"\nHora:"<<a[mitad].getHora()<<"\nRemitente:"<<a[mitad].rem<<"\n"<<a[mitad].getContenido()<<a[mitad].getCopiaOculta()<<a[mitad].getContenido2()<<endl;
            int bus;
            cout<<"Seguir buscando correos de este remitente? 1).- SI   2).-NO"<<endl;
            cin>>bus;
            if(bus==1){
                if(sonIguales(a[mitad+1].rem,obj)){
                    int i=1;
                    while(sonIguales(a[mitad+i].rem,obj)){
                        cout<<"ID: "<<a[mitad+i].getId()<<"\nHora:"<<a[mitad+i].getHora()<<"\nRemitente:"<<a[mitad+i].rem<<"\n"<<a[mitad+i].getContenido()<<a[mitad+i].getCopiaOculta()<<a[mitad+i].getContenido2()<<endl;
                        int seguir;
                        cout<<"Seguir buscando correos de este remitente? 1).- SI   2).-NO"<<endl;
                        cin>>seguir;
                        if(seguir==2){
                            break;
                        }
                        i++;
                    }


                }else if(sonIguales(a[mitad-1].rem,obj)){
                    int i=1;
                    while(sonIguales(a[mitad-i].rem,obj)){
                        cout<<"ID: "<<a[mitad-i].getId()<<"\nHora:"<<a[mitad-i].getHora()<<"\nRemitente:"<<a[mitad-i].rem<<"\n"<<a[mitad-i].getContenido()<<a[mitad-i].getCopiaOculta()<<a[mitad-i].getContenido2()<<endl;
                        int seguir;
                        cout<<"Seguir buscando correos de este remitente? 1).- SI   2).-NO"<<endl;
                        cin>>seguir;
                        if(seguir==2){
                            break;
                        }
                        i++;
                    }

                }else{
                    cout<<"No hay mas correos!"<<endl;
                    break;
                }
            }
            band = true;
            break;
        }
        //cout<<"DEBUGEAR SON IGUALES"<<endl;
        if(esMenor(a[mitad].rem,obj)==2){
            sup = mitad;
            mitad = (inf+sup)/2;
        }
        if(esMenor(a[mitad].rem,obj)==1){
            inf = mitad;
            mitad = (inf+sup)/2;
        }
    }
    if(band!=true){
        cout<<"Correo no encontrado!"<<endl;
    }
}

bool Correos::sonIguales(char a[],char b[]){
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


void Correos::ObtenRemitente(char aux[], int t){
     fstream f;
     int tam=0;
     tam=(t+tam);
     string prueba = "pruebaSED.bin";
     f.open( prueba, ios::in | ios::out |ios::binary );
     //mostrar id;;
     tam=tam+4;
     //mostrar hora;
     tam=tam+19;
     //mostrar remitente
     char mostrarchar[24];
     f.seekg(tam, ios::beg);
     f.read((char *)(&mostrarchar),sizeof(mostrarchar));
     int i = 0;
     while(i<24 and mostrarchar[i]!='\0'){
                aux[i]=mostrarchar[i];
                i++;
     }
     aux[i]='\0';
     f.close();
}

int Correos::obtenReferencia(string file, int tam){
     fstream f;
     f.open( file, ios::in | ios::out |ios::binary);
     f.seekp(tam, ios::beg);
     int referencia = f.tellg();
     f.close();
     return referencia;
}

int Correos::yaExisteIndices(){
    fstream f;
    // Verificar si existe el archivo
    f.open( "indices.txt", ios::in | ios::out);
    // Si el archivo no existe
    if( !f.is_open())
    {
        f.open("indices.txt", ios::in | ios:: app);
        cout<<"creando archivo de indices por primera vez..."<<endl;
        f<<"ACTUALIZADO   "<<"\n";
        f.close();
        return 0;
    }
    f.close();
    return 1;
}

int Correos::retornaId(int t){
    //Obten ID.
     fstream f;
     string file = "pruebaSED.bin";
     f.open( file, ios::in | ios::out |ios::binary );
     f.seekg(t, ios::beg);
     int mostrarid;
     f.read((char *)(&mostrarid),sizeof(mostrarid));
     f.close();
     return mostrarid;
}

bool Correos::indiceActualizado(){
    ifstream archivo("indices.txt");
    string linea;
    getline(archivo,linea,'\n');
    if(linea=="ACTUALIZADO   "){
        return true;
    }
    else{
        return false;
    }
}

bool Correos::indiceSecActualizado(){
    ifstream archivo("indicesSecundarios.txt");
    string linea;
    getline(archivo,linea,'\n');
    if(linea=="ACTUALIZADO   "){
        return true;
    }
    else{
        return false;
    }
}


//metodos rem
int Correos::yaExisteIndicesSec(){
    fstream f;
    // Verificar si existe el archivo
    f.open( "indicesSecundarios.txt", ios::in | ios::out);
    // Si el archivo no existe
    if( !f.is_open())
    {
        f.open("indicesSecundarios.txt", ios::in | ios:: app);
        cout<<"creando archivo de indices secundarios por primera vez..."<<endl;
        f<<"ACTUALIZADO   "<<"\n";
        f.close();
        return 0;
    }
    f.close();
    return 1;
}

Correos::Correos()
{
}
Correos::~Correos()
{//dtor
}
