#include <iostream>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
using namespace std;

class Menu{

    void reportes(){
        cout<<" ************ REPORTES ************ \n";
        cout<<"       1- Lista de Estudiantes \n";
        cout<<"       2- Linealizacion de Tareas \n";
        cout<<"       3- salir\n";
        cout<<"Ingrese la Opcion que desea realizar: ";

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
            cin>>Opcion;
            switch(Opcion){
                case 1:
                    cout<<" ******* Ingresar Usuario ******* \n";

                 break;
                case 2:
                    cout<<"Modificar Usuario\n";
                 break;
                case 3:
                    cout<<"Eliminar Usuario\n";
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
        while(seguir){
            string carnet;
            string dpi;
            string nombre;
            string carrera;
            string password;
            string creditos;
            string edad;

            int Opcion;
            cout<<endl<<" ******* INGRESO MANUAL DE USUARIOS ******* "<<endl;
            cout<<endl<<"         1- Ingresar un usuario"<< endl;
            cout<<"         2- Modificar un usuario"<< endl;
            cout<<"         3- Eliminar un usuario"<< endl;
            cout<<"         4- Salir"<< endl;
            cin>>Opcion;
            switch(Opcion){
                case 1:
                    cout<<" ****** Ingresar Usuario ****** "<<endl;
                    cout<<"carnet: "<< endl;
                    cin>>carnet;
                    cout<<"dpi: "<< endl;
                    cin>>dpi;
                    cout<<"nombre: "<< endl;
                    cin>>nombre;
                    cout<<"carrera: "<< endl;
                    cin>>carrera;
                    cout<<"carnet: "<< endl;
                    cin>>carnet;
                    cout<<"password: "<< endl;
                    cin>>password;
                    cout<<"creditos: "<< endl;
                    cin>>creditos;
                    cout<<"edad: "<< endl;
                    cin>>edad;

                 break;
                case 2:
                    cout<<" ****** Modificar Usuario ****** "<<endl;
                    cout<<" Ingrese el DPI del usuario: ";
                    cin>>dpi;

                 break;
                case 3:
                    cout<<" ****** Eliminar Usuario ****** "<<endl;
                    cout<<" Ingrese el DPI del usuario: ";
                    cin>>dpi;

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
                break;
                case 2:
                    cout<<"Tareas"<<endl;
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
                    cout<<"caso 3"<<endl;
                    ingresoManual();
                 break;
                case 4:
                    cout<<"***** Reportes ******"<<endl;
                 break;
                case 5:
                    cout<<"¡Hasta la proxima!"<<endl;
                    seguir = false;
                 break;
                default:
                    cout<<"El valor ingresado no esta en el menu"<<endl;
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
            }
        }
    }

};
