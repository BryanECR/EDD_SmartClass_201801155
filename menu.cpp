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
#include "Matriz/NodoM.cpp"
using namespace std;

ListaCirculasDoblementeEnlazada listacircular;
NodoM Matrix[5][9][30] = { NodoM() };
ListaDoblementeEnlazada listatareas;
int contadorgraficaestudiantes = 0;
int contadorgraficastareas = 0;
ListaSimple errores;
Func funciones;


class Menu{

    void limpiarConsola(){
        system("pause");
        system("cls");
    }

    void graficarTareas(){
        string texto;
        int numero;

        for(int k=0; k<5 ; k++){
            texto+="digraph G{\n\ta0 [shape=square label=<\n\t\t<TABLE border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n";
            for(int j=0; j<9 ; j++){
                texto+="\t\t\t<TR>\n";
                for(int i=0; i<30 ; i++){
                    if(Matrix[k][j][i].carnet != 0){
                        texto+="\t\t\t<TD border=\"1\">"+Matrix[k][j][i].estado+"</TD>\n";
                    }else{
                        texto+="\t\t\t<TD border=\"1\">-1</TD>\n";
                    }
                }
                texto+="\t\t\t</TR>\n";
            }
            texto+="\t\t</TABLE>>];\n}\n";
            funciones.graphtask(numero,texto);
            texto="";
            numero++;
        }
    }

    void recorrerMat(){
        string nombre,descripcion,materia,fecha,estado;
        int carnet,mes,hora;

        for(int i=0; i<9; i++){
            for(int j=0; j<30; j++){
                for(int k = 0; k<5; k++){
                    carnet = Matrix[k][i][j].carnet;
                    nombre = Matrix[k][i][j].nombre;
                    descripcion = Matrix[k][i][j].descripcion;
                    materia = Matrix[k][i][j].materia;
                    fecha = Matrix[k][i][j].fecha;
                    estado = Matrix[k][i][j].estado;
                    mes = funciones.fechasInv(k,"Mes");
                    hora = funciones.fechasInv(i,"Hora");
                    listatareas.agregar(mes,(j+1),hora,carnet,nombre,descripcion,materia,fecha,estado);
                }
            }
        }
    }

    void LecturaEstudiantes(){
        string nombre,carrera,password,correo,ruta,data,item;
        int carnet,creditos,edad,counter,linea,i;
        long long int dpi;
        
        ifstream file;
        cin.ignore();
        cout<<"Ingrese la ruta del archivo que desea leer: ";
        getline(cin,ruta);
        file.open(ruta, ios::in);

        if(!file.fail()){
            while(!file.eof()){
                getline(file, data);
                istringstream div(data);
                while(getline(div, item, ',')){
                    if(linea!=0){
                        switch(counter){
                            case 0:
                                istringstream(item) >> i;
                                carnet = i;
                            break;
                            case 1:
                                dpi = stoll(item,nullptr,10);
                            break;
                            case 2:
                                nombre = item;
                            break;
                            case 3:
                                carrera = item;
                            break;
                            case 4:
                                password = item;
                            break;
                            case 5:
                                istringstream(item) >> i;
                                creditos = i;
                            break;
                            case 6:
                                istringstream(item) >> i;
                                edad = i;
                            break;
                            case 7:
                                correo = item;
                            break;
                        }
                    } 
                    counter++;
                }
                if(linea!=0){
                    if(listacircular.validarCarnetDpi(carnet)==0){
                        listacircular.agregar(carnet,dpi,nombre,carrera,password,creditos,edad,correo);
                        errores.agregar(carnet,"Estudiante","El carnet no presenta el formato debido");
                    }else if( listacircular.validarCarnetDpi(dpi) == 0){
                        listacircular.agregar(carnet,dpi,nombre,carrera,password,creditos,edad,correo);
                        errores.agregar(carnet,"Estudiante","El DPI no presenta el formato debido");
                    }else if(listacircular.validarCorreo(correo) == 0){
                        listacircular.agregar(carnet,dpi,nombre,carrera,password,creditos,edad,correo);
                        errores.agregar(carnet,"Estudiante","El correo no presenta el formato debido");
                    }else{
                        listacircular.agregar(carnet,dpi,nombre,carrera,password,creditos,edad,correo);
                    }
                }
                
                linea++;
                counter = 0;
                carnet=0;
                creditos=0;
                edad=0;
                dpi=0;
                nombre="";
                carrera="";
                password="";
                correo="";
            }
        }
        cout<<"Lectura realizada con exito"<<endl;
    }

    void LecturaTareas(){
        string nombre,descripcion,materia,fecha,estado,ruta,data,item;
        int mes,dia,hora,carnet,counter,i;
        int linea = 0;

        ifstream file;
        cin.ignore();
        cout<<"Ingresar la Ruta: ";
        getline(cin, ruta);
        file.open(ruta, ios::in);

        if(!file.fail()){
            while(!file.eof()){
                getline(file, data);
                istringstream div(data);
                while(getline(div, item, ',')){
                    if(linea!=0){
                        switch(counter){
                            case 0:
                                i = stoi(item,nullptr,10);
                                mes = funciones.fechas(i,"Mes");
                            break;
                            case 1:
                                i = stoi(item,nullptr,10);
                                dia = (i-1);
                            break;
                            case 2:
                                i = stoi(item,nullptr,10);
                                hora = funciones.fechas(i,"Hora");
                            break;
                            case 3:
                                carnet = stoi(item,nullptr,10);
                            break;
                            case 4:
                                nombre = item;
                            break;
                            case 5:
                                descripcion = item;
                            break;
                            case 6:
                                materia = item;
                            break;
                            case 7:
                                fecha = item;
                            break;
                            case 8:
                                estado = item;
                            break;
                        }
                    } 
                    
                    counter++;
                }
                if(linea!=0){    
                    if(listacircular.buscarPorCarnet(carnet)==false){
                        errores.agregar(carnet,"Tarea","El carnet del estudiante no de encuentra registrado");
                    }else{
                        Matrix[mes][hora][dia].carnet = carnet;
                        Matrix[mes][hora][dia].nombre = nombre;
                        Matrix[mes][hora][dia].descripcion = descripcion;
                        Matrix[mes][hora][dia].materia = materia;
                        Matrix[mes][hora][dia].fecha = fecha;
                        Matrix[mes][hora][dia].estado = estado;
                    }
                    
                }
                
                linea++;
                counter = 0;
                mes = 0;
                dia = 0;
                hora = 0;
                carnet = 0;
                nombre = "";
                descripcion = "";
                materia = "";
                fecha = "";
                estado = "";
            }
        }
        recorrerMat();
        cout<<"Lectura realizada con exito"<<endl;
    }

    void reportes(){
        int opcion,mes,dia,hora;
        string salida="";
        bool seguir = true;
        while(seguir){
            cout<<" ************ REPORTES ************ \n";
            cout<<"       1- Lista de Estudiantes \n";
            cout<<"       2- Linealizacion de Tareas \n";
            cout<<"       3- Graficar Calendario de Tareas\n";
            cout<<"       4- Busqueda en estructura linealizada \n";
            cout<<"       5- Busqueda de posicion en estructura linealizada \n";
            cout<<"       6- Cola de Errores \n";
            cout<<"       7- Generar archivo de salida\n";
            cout<<"       8- salir\n";
            cout<<"Ingrese la Opcion que desea realizar: ";
            cin>>opcion;
            switch(opcion){
                case 1:
                    listacircular.crearTabla(contadorgraficaestudiantes);
                    contadorgraficaestudiantes++;

                 break;
                case 2:
                    listatareas.tablaTareas(contadorgraficastareas);
                    contadorgraficastareas++;

                 break;
                 case 3:
                    graficarTareas();

                 break;
                case 4:
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
                case 5:
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
                case 6:
                    errores.graficar();
                    limpiarConsola();

                 break;
                case 7:
                    if(errores.vacia()){
                        salida +="¿Elements?";
                        salida += listacircular.Salida();
                        salida += listatareas.salida();
                        salida +="\n¿$Elements?";
                        funciones.graficar(salida);
                        limpiarConsola();

                    }else{
                        cout<<"El archivo de salida no se puede generar hasta que la cola de errores sea corregidas"<<endl;
                    }
                    

                 break;
                case 8:
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
        string nombre,carrera,password,correo;
        int carnet,creditos,edad,Opcion;
        bool seguir = true;
        long long int dpi;
        
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
                    limpiarConsola();
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
            cout<<"              5- Eliminar el primer error"<<endl;
            cout<<"              6- Reportes "<<endl;
            cout<<"              7- Salir "<<endl;
            cout<<"Ingrese por teclado la opcion que desea realizar: ";
            cin>>Opcion;

            switch(Opcion){
                case 1:
                    LecturaEstudiantes();
                    limpiarConsola();
                 break;
                case 2:
                    LecturaTareas();
                    limpiarConsola();
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
                    errores.eliminar();
                    limpiarConsola();
                 break;
                case 6:
                    limpiarConsola();
                    reportes();
                 break;
                case 7:
                    cout<<"¡Hasta la proxima!"<<endl;
                    seguir = false;
                 break;
                default:
                    cout<<"El valor ingresado no esta en el menu"<<endl;
                    
            }
        }
    }
};
