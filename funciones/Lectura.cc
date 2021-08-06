#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

// Prototipo de funciones
string lectura(string r);

int main(){
    string ruta,texto;
    cout<<"ingrese la ruta del archivo:  ";
    cin>>ruta;
    texto = lectura(ruta);
    cout<<texto;

    system("pause");
    return 0;
}

// Lectura de los archivos Externos
string lectura(string r){
    ifstream archivo;
    string linea,texto;
    // abrir el archivo en modo lectura
    archivo.open(r,ios::in);

    // Si el archivo falla
    if(archivo.fail()){
        cout<<"no se pudo abrir el archivo";
        exit(1);
    }

    // mientras no sea el final del archivo
    while(!archivo.eof()){
        getline(archivo,linea);
        texto += linea+"\n";
    }

    archivo.close();
    return texto;

}

// Separacion de categorias y verificacion de errores
void validacionDeDatos(int a[]){
    
}