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

    void graphtask(int numero,string cadena){
        string nombredelagrafica = "Calendario"+to_string(numero);
        ofstream archivo;
        archivo.open(nombredelagrafica+".dot",ios::out);

        if(archivo.fail()){
            cout<<"No se pude abrir el archivo";
            exit(1);
        }

        archivo<<cadena;
        archivo.close();
        std::string str = "dot -Tpng "+nombredelagrafica+".dot -o "+nombredelagrafica+".png";
        const char *cstm = str.c_str();
        system(cstm);
        cout<<"\n¡Grafica realizada con exito!\n";

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

    int fechasInv(int numero, string tipo){
        if(tipo=="Mes"){
            switch(numero){
                case 0:
                    return 7;
                break;
                case 1:
                    return 8;
                break;
                case 2:
                    return 9;
                break;
                case 3:
                    return 10;
                break;
                case 4:
                    return 11;
                break;
            }
        }else{
            switch(numero){
                case 0:
                    return 8;
                break;
                case 1:
                    return 9;
                break;
                case 2:
                    return 10;
                break;
                case 3:
                    return 11;
                break;
                case 4:
                    return 12;
                break;
                case 5:
                    return 13;
                break;
                case 6:
                    return 14;
                break;
                case 7:
                    return 15;
                break;
                case 8:
                    return 16;
                break;
            }
        }
    }

};

