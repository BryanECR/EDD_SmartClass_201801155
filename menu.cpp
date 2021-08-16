#include <iostream>
#include <string>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include "ListaCircular/ListaCircular.cpp"
#include "ListaDoble/ListaDoble.cpp"
#include "ListaErrores/listasimple.cpp"
#include "Matriz/Func.cc"
using namespace std;

ListaCirculasDoblementeEnlazada listacircular;
ListaDoblementeEnlazada listatareas;
ListaSimple errores;
Func funciones;
int contadorgraficastareas = 0;
int contadorgraficaestudiantes = 0;

class Menu{

    void limpiarConsola(){
        system("pause");
        system("cls");
    }


    void reportes(){
        int opcion,mes,dia,hora;
        string salida="";
        bool seguir = true;
        while(seguir){
            cout<<" ************ REPORTES ************ \n";
            cout<<"       1- Lista de Estudiantes \n";
            cout<<"       2- Linealizacion de Tareas \n";
            cout<<"       3- Busqueda en estructura linealizada \n";
            cout<<"       4- Busqueda de posicion en estructura linealizada \n";
            cout<<"       5- Cola de Errores \n";
            cout<<"       6- Generar archivo de salida\n";
            cout<<"       7- salir\n";
            cout<<"Ingrese la Opcion que desea realizar: ";
            cin>>opcion;
            switch(opcion){
                case 1:
                    listacircular.graficar(contadorgraficaestudiantes);
                    contadorgraficaestudiantes+=1;

                 break;
                case 2:
                    listatareas.graficar(contadorgraficastareas);
                    contadorgraficastareas+=1;

                 break;
                case 3:
                    cout<<"Ingrese Los siguientes datos para realizar la busqueda\n";
                    cout<<"Mes: ";
                    cin>>mes;
                    cout<<"Dia: ";
                    cin>>dia;
                    cout<<"Hora: ";
                    cin>>hora;
                    cout<<listatareas.reporte(mes,dia,hora,3);
                    limpiarConsola();

                 break;
                case 4:
                    cout<<"Ingrese Los siguientes datos para realizar la busqueda\n";
                    cout<<"Mes: ";
                    cin>>mes;
                    cout<<"Dia: ";
                    cin>>dia;
                    cout<<"Hora: ";
                    cin>>hora;
                    cout<<listatareas.reporte(mes,dia,hora,4);
                    limpiarConsola();

                 break;
                case 5:
                    errores.graficar();
                    limpiarConsola();

                 break;
                case 6:
                    salida +="¿Elements?";
                    salida += listacircular.Salida();
                    salida += listatareas.salida();
                    salida +="¿$Elements?";
                    funciones.graficar(salida);
                    limpiarConsola();

                 break;
                case 7:
                    cout<<"Salir"<<endl;
                    seguir = false;

                 break;
                default:
                   cout<<"Opcion no valida"<<endl;
            }
        }
    }

    void ingresoDeTareas(){
        int mes, dia, hora, carnet,indice;
        string nombre, descripcion, materia, fecha, estado;
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
                    cout<<"Mes: ";
                    cin>>mes;
                    cout<<"Dia: ";
                    cin>>dia;
                    cout<<"Hora: ";
                    cin>>hora;
                    cout<<"Carnet: ";
                    cin>>carnet;
                    cin.ignore();
                    cout<<"Nombre: ";
                    getline(cin,nombre);
                    cin.ignore();
                    cout<<"Descripcion: ";
                    getline(cin,descripcion);
                    cin.ignore();
                    cout<<"Materia: ";
                    getline(cin,materia);
                    cout<<"Fecha: ";
                    cin>>fecha;
                    cout<<"Estado: ";
                    cin>>estado;
                    if(listacircular.buscarPorCarnet(carnet) && listatareas.validarFechas(mes,"mes") == 1 && listatareas.validarFechas(dia,"dia") == 1 && listatareas.validarFechas(hora,"h") == 1){
                        listatareas.agregar(mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado);
                        cout<<"\n *Tarea Agregada con exito* \n";
                    }else{
                        cout<<"\n*** La tarea no se pudo agregar debido a que algunos datos estan incorrectos ***\n";
                    }
                    limpiarConsola();

                 break;
                case 2:
                    cout<<"Ingrese el indice de la tarea que desea modificar: ";
                    cin>>indice;
                    listatareas.ModificarNodo(indice);
                    limpiarConsola();

                 break;
                case 3:
                    cout<<"Ingrese el indice de la tarea que desea eliminar: ";
                    cin>>indice;
                    listatareas.borrarElemento(indice);
                    limpiarConsola();

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
                    limpiarConsola();

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
                    limpiarConsola();

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
                    limpiarConsola();
                    
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
        string ruta;
        bool seguir = true;
        while(seguir){
            int Opcion;
            cout<<endl<<"              ******* MENU ******* "<<endl;
            cout<<"              1- Carga de Usuarios "<<endl;
            cout<<"              2- Carga de Tareas "<<endl;
            cout<<"              3- Ingreso manual "<<endl;
            cout<<"              4- Mostrar Errores"<<endl;
            cout<<"              5- Reportes "<<endl;
            cout<<"              6- Salir "<<endl;
            cout<<"Ingrese por teclado la opcion que desea realizar: ";
            cin>>Opcion;

            switch(Opcion){
                case 1:
                    cin.ignore();
                    cout<<"Ingrese la ruta del archivo que desea leer";
                    getline(cin,ruta);
                 break;
                case 2:
                    cin.ignore();
                    cout<<"Ingrese la ruta del archivo que desea leer";
                    getline(cin,ruta);
                 break;
                case 3:
                    limpiarConsola();
                    ingresoManual();
                    
                 break;
                case 4:
                    errores.mostrar();
                    limpiarConsola();
                 break;
                case 5:
                    limpiarConsola();
                    reportes();

                 break;
                case 6:
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