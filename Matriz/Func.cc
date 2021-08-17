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

    int fechas(int numero, string tipo){
        if(tipo=="Mes"){
            switch(numero){
                case 7:
                    return 0;
                break;
                case 8:
                    return 1;
                break;
                case 9:
                    return 2;
                break;
                case 10:
                    return 3;
                break;
                case 11:
                    return 4;
                break;
            }
        }else{
            switch(numero){
                case 8:
                    return 0;
                break;
                case 9:
                    return 1;
                break;
                case 10:
                    return 2;
                break;
                case 11:
                    return 3;
                break;
                case 12:
                    return 4;
                break;
                case 13:
                    return 5;
                break;
                case 14:
                    return 6;
                break;
                case 15:
                    return 7;
                break;
                case 16:
                    return 8;
                break;
            }
        }
    }

    
};

