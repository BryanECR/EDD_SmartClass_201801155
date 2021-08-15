#include <iostream>
#include <string>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "ListaCircular/ListaCircular.cpp"
using namespace std;

ListaCirculasDoblementeEnlazada listacircular;
int contadorgraficaestudiantes = 0;

class Menu{

    void reportes(){
        int opcion;
        bool seguir = true;
        while(seguir){
            cout<<" ************ REPORTES ************ \n";
            cout<<"       1- Lista de Estudiantes \n";
            cout<<"       2- Linealizacion de Tareas \n";
            cout<<"       3- salir\n";
            cout<<"Ingrese la Opcion que desea realizar: ";
            cin>>opcion;
            switch(opcion){
                case 1:
                    listacircular.graficar(contadorgraficaestudiantes);
                    contadorgraficaestudiantes+=1;
                 break;
                case 2:
                    cout<<"Linealizacion de Tareas"<<endl;
                 break;
                case 3:
                    cout<<"Salir"<<endl;
                    seguir = false;
                 break;
                default:
                   cout<<"Opcion no valida"<<endl;
            }
        }
    }

    void ingresoDeTareas(){
        bool seguir = true;
        
        while(seguir){
            int Opcion;
            cout<<endl<<" ******* INGRESO MANUAL DE TAREAS ******* \n";
            cout<<endl<<"         1- Ingresar una tarea\n";
            cout<<"         2- Modificar una tarea\n";
            cout<<"         3- Eliminar una tarea\n";
            cout<<"         4- Salir\n";
            cout<<"Ingrese la opcion que desea por teclado: ";
            cin>>Opcion;
            switch(Opcion){
                case 1:
                    cout<<" ******* Ingresar tarea ******* \n";
                 break;
                case 2:
                    cout<<"Modificar tarea\n";
                 break;
                case 3:
                    cout<<"Eliminar tarea\n";
                 break;
                case 4:
                    cout<<"¡Hasta la proxima!\n";
                    seguir = false;
                 break;
                default:
                cout<<"La opcion que eligio no esta en el menu\n";

            }
        }
    }

    void ingresoDeUsuarios(){
        bool seguir = true;
        int carnet, creditos, edad, Opcion;
        long long int dpi;
        string nombre, carrera, password,correo;

        while(seguir){
            cout<<endl<<" ******* INGRESO MANUAL DE USUARIOS ******* "<<endl;
            cout<<endl<<"         1- Ingresar un usuario"<< endl;
            cout<<"         2- Modificar un usuario"<< endl;
            cout<<"         3- Eliminar un usuario"<< endl;
            cout<<"         4- Salir"<< endl;
            cout<<"Ingrese la opcion que desea mediante teclado: ";
            cin>>Opcion;
            switch(Opcion){
                case 1:
                    cout<<" ****** Ingresar Usuario ****** "<<endl;
                    cin.ignore();
                    cout<<"Nombre: ";
                    getline(cin,nombre);
                    cout<<"Carnet: ";
                    cin>>carnet;
                    cout<<"DPI: ";
                    cin>>dpi;                    
                    cout<<"Password: ";
                    cin>>password;
                    cout<<"Creditos: ";
                    cin>>creditos;
                    cout<<"Edad: ";
                    cin>>edad;
                    cout<<"Correo: ";
                    cin>>correo;
                    cin.ignore();
                    cout<<"Carrera: ";
                    getline(cin,carrera);
                    if(listacircular.validarCarnetDpi(dpi) == 1 && listacircular.validarCarnetDpi(carnet) == 1 && listacircular.validarCorreo(correo) == 1){
                        listacircular.agregar(carnet,dpi,nombre,carrera,password,creditos,edad,correo);
                    }else{
                        cout<<"\n **** El usuario no fue agregado debido a errores en la informacion **** \n";
                    }
                    
                    system("pause");
                    system("cls");

                 break;
                case 2:
                    cout<<" ****** Modificar Usuario ****** "<<endl;
                    cout<<" Ingrese el DPI del usuario: ";
                    cin>>dpi;
                    if(listacircular.buscarEstudiantes(dpi)){
                        listacircular.modificarEstudiante(dpi);
                    }else{
                        cout<<"* El usuario no existe o la lista esta vacia *"<<endl;
                    }
                    system("pause");
                    system("cls");

                 break;
                case 3:
                    cout<<" ****** Eliminar Usuario ****** "<<endl;
                    cout<<" Ingrese el DPI del usuario: ";
                    cin>>dpi;
                    if(listacircular.buscarEstudiantes(dpi)){
                        listacircular.eliminarEstudiante(dpi);
                    }else{
                        cout<<"* El usuario no existe o la lista esta vacia *"<<endl;
                    }
                    system("pause");
                    system("cls");
                    
                 break;
                case 4:
                    cout<<"¡Hasta la proxima!"<<endl;
                    seguir = false;

                 break;
                default:
                cout<<"La opcion que eligio no esta en el menu"<<endl;

            }
        }
    }

    void ingresoManual(){
        bool seguir = true;
        while(seguir){
            int Opcion;
            cout<<endl<<" ******* INGRESO MANUAL ******* "<<endl;
            cout<<endl<<"         1- Usuarios"<< endl;
            cout<<"         2- Tareas"<< endl;
            cout<<"         3- salir"<< endl;
            cout<<"Ingrese por teclado la opcion que desea realizar: ";
            cin>>Opcion;
            switch(Opcion){
                case 1:
                    cout<<"Usuarios"<<endl;
                    system("cls");
                    ingresoDeUsuarios();
                    
                break;
                case 2:
                    cout<<"Tareas"<<endl;
                    ingresoDeTareas();
                break;
                case 3:
                    cout<<"¡Hasta la proxima!"<<endl;
                    seguir = false;
                break;
                default:
                cout<<"La opcion que eligio no esta en el menu"<<endl;

            }
        }
        
    }

    public:
    void menu(){
        
        bool seguir = true;
        while(seguir){
            int Opcion;
            cout<<endl<<"              ******* MENU ******* "<<endl;
            cout<<"              1- Carga de Usuarios "<<endl;
            cout<<"              2- Carga de Tareas "<<endl;
            cout<<"              3- Ingreso manual "<<endl;
            cout<<"              4- Reportes "<<endl;
            cout<<"              5- Salir "<<endl;
            cout<<"Ingrese por teclado la opcion que desea realizar: ";
            cin>>Opcion;

            switch(Opcion){
                case 1:
                    cout<<"Caso 1"<<endl;
                 break;
                case 2:
                    cout<<"caso 2"<<endl;
                 break;
                case 3:
                    system("cls");
                    ingresoManual();
                    
                 break;
                case 4:
                    system("cls");
                    reportes();

                 break;
                case 5:
                    cout<<"¡Hasta la proxima!"<<endl;
                    seguir = false;
                 break;
                default:
                    cout<<"El valor ingresado no esta en el menu"<<endl;
                    
            }
        }
    }

};

int main(){
    Menu m;
    m.menu();

    return 0;
}

/*
                     ´´´´´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶¶¶´´´´´´´´´´´´´´´
                     ´´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´¶¶¶¶´´´´
                     ´´´´´´´´´´´´´´´´´´´´´¶¶¶¶¶¶´´´´´´´’’¶¶¶¶¶¶¶¶¶´´´
                     ´´´´´´´´´´´´´´´´´´´¶¶¶¶¶´´´´´´´´´´´´´´´¶¶¶¶´´´´´
                     ´´´´´´´´´´´´´´´´´´¶¶¶¶´´´´´´´´´´´´´´´´´´´´´´´´´´
                     ´´´´´´´´´´´´´´´´´¶¶¶´´´´´´´´´´¶¶¶¶¶¶´´´´´´´´´´´´
                     ´´´´´´´´´´´´´´´´¶¶¶´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´
                     ´´´´´´´´´´´´´´¶¶¶¶´´´´´´´¶¶¶´´ ´´´´´´´´´¶¶¶´´´´´
                     ´´´´´´´´´´´´´¶¶¶¶¶´´´´´´´¶¶¶´´´´´¶¶¶ ´´´¶¶¶´´´´´
                     ´´´´´´´´´´´´¶¶¶¶¶¶´´´´´´´¶¶¶¶´´´ ¶¶¶ ´´´´¶¶¶´´´´
                     ´´´´´´´´´´¶¶¶¶¶¶¶¶´´´´´´´´¶¶¶¶¶¶¶¶¶ ´´´´¶¶¶´´´´´
                     ´´´´´´´´´¶¶¶¶´´¶¶¶¶´´´´´´´´´¶¶¶¶¶¶´´´´´¶¶¶´´´´´´
                     ´´´´´´´´¶¶¶¶´´´´¶¶¶¶´´´´´´´´´´´´´´´´´´¶¶¶¶´´´´´´
                     ´´´´´¶¶¶¶´´´´´´´¶¶¶¶´´´´´´´´´´´´´´´´¶¶¶¶´´´´´´´´
                     ´´´´´¶¶¶¶´´´´´´´´´¶¶¶¶¶¶´´´´´´´´´´¶¶¶¶¶´´´´´´´´´
                     ´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´´´´´
*/