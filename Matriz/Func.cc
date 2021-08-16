#include <iostream>
#include <fstream>

using namespace std;

class Func{
    public:
        Func(){ }

    void graficar(string cadena){
        ofstream archivo;
        archivo.open("Estudiantes.txt",ios::out);

        if(archivo.fail()){
            cout<<"No se pudo abrir el archivo";
            exit(1);
        }

        archivo<<cadena;
        archivo.close();
    }
};

