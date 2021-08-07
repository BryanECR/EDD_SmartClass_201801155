#include <iostream>
#include "Nodo.cpp"

using namespace std;

class ListaCirculasDoblementeEnlazada{
    private:
        Nodo* inicio;
        Nodo* fin;
    public:
        ListaCirculasDoblementeEnlazada(){
            inicio = NULL;
            fin = NULL;
        }

    void agregar(int carnet,int dpi,string nombre,string carrera,string password,int creditos,int edad){
        Nodo* nuevo = new Nodo();
        nuevo->carnet = carnet;
        nuevo->dpi = dpi;
        nuevo->nombre = nombre;
        nuevo->carrera = carrera;
        nuevo->password = password;
        nuevo->creditos = creditos;
        nuevo->edad = edad;

        if(inicio == NULL){
            inicio = nuevo;
            inicio->der=inicio;
            inicio->izq=inicio;
            fin=inicio;

        }else{
            fin->der=nuevo;
            nuevo->der=inicio;
            nuevo->izq=fin;
            fin=nuevo;
            inicio->izq=fin;

        }
    }

    void mostrar(){
        Nodo* actual = new Nodo();
        actual = inicio;
        if(inicio==NULL){
            cout<<"la lista esta vacia"<<endl;
        }else{
            do{
                cout<<actual->carnet<<"\t";
                cout<<actual->dpi<<"\t";
                cout<<actual->nombre<<"\t";
                cout<<actual->carrera<<"\t";
                cout<<actual->password<<"\t";
                cout<<actual->creditos<<"\t";
                cout<<actual->edad<<endl;

                actual=actual->der;
            }while(actual != inicio);
        }
    }

    void tareaRealizada(string tarea){
        if(tarea == "eliminar"){
            cout<<"Estudiante eliminado con exito"<<endl;
        }else{
            cout<<"Datos modificados con exito"<<endl;
        }
    }

    int datosParaModificar(){
        int opcion;
        cout<<" ********** DATOS DEL ESTUDIANTE PARA MODIFICAR **********  \n";
        cout<<"                     1- Carnet\n";
        cout<<"                     2- DPI\n";
        cout<<"                     3- Nombre\n";
        cout<<"                     4- Carrera\n";
        cout<<"                     5- Password\n";
        cout<<"                     6- Creditos\n";
        cout<<"                     7- Edad\n";
        cout<<"Ingrese la Opcion que desea modificar: ";
        cin>>opcion;
        return opcion;
    }

    void modificarEstudiante(int dpi){
        int opcion;
        int carnetNuevo;
        int dpiNuevo;
        string nombreNuevo;
        string carreraNuevo;
        string passwordNuevo;
        int creditosNuevo;
        int edadNuevo;

        if(inicio == NULL){
            cout<<"La lista se encuantra vacia"<<endl;

        }else{
            Nodo* actual = inicio;
            opcion = datosParaModificar();

            do{
                if(dpi == actual->dpi){
                    switch(opcion){
                    case 1:
                        cout<<"Ingrese el nuevo carnet: ";
                        cin>>carnetNuevo;
                        actual->carnet = carnetNuevo;
                        tareaRealizada("a");

                     break;
                    case 2:
                        cout<<"Ingrese el nuevo dpi: ";
                        cin>>dpiNuevo;
                        actual->dpi = dpiNuevo;
                        tareaRealizada("a");

                     break;
                    case 3:
                        cout<<"Ingrese el nuevo nombre: ";
                        cin>>nombreNuevo;
                        actual->nombre = nombreNuevo;
                        tareaRealizada("a");

                     break;
                    case 4:
                        cout<<"Ingrese el nuevo carrera: ";
                        cin>>carreraNuevo;
                        actual->carrera = carreraNuevo;
                        tareaRealizada("a");

                     break;
                    case 5:
                        cout<<"Ingrese el nuevo password: ";
                        cin>>passwordNuevo;
                        actual->password = passwordNuevo;
                        tareaRealizada("a");

                     break;
                    case 6:
                        cout<<"Ingrese el nuevo creditos: ";
                        cin>>creditosNuevo;
                        actual->creditos = creditosNuevo;
                        tareaRealizada("a");

                     break;
                    case 7:
                        cout<<"Ingrese el nuevo edad: ";
                        cin>>edadNuevo;
                        actual->edad = edadNuevo;
                        tareaRealizada("a");

                     break;
                    }
                    break;
                }
                actual = actual->der;
            }while(actual != inicio);
        }
    }

    void eliminarEstudiante(int dpi){
        if(inicio == NULL){
            cout<<"La lista esta vacia"<<endl;

        }else if(inicio->dpi == dpi){
            Nodo* borrarInicio = inicio;
            inicio = inicio->der;
            inicio->izq == fin;
            tareaRealizada("eliminar");
            delete borrarInicio;

        }else if(fin->dpi == dpi){
            Nodo* borrarFin = fin;
            fin = fin->izq;
            fin->der = inicio;
            tareaRealizada("eliminar");
            delete borrarFin;

        }else{
            Nodo* actual = inicio;
            Nodo* anterior;
            Nodo* siguiente;
            Nodo* borrar;

            do{
                if(actual->dpi == dpi){
                    anterior=actual->izq;
                    siguiente=actual->der;
                    borrar = actual;
                    anterior->der = siguiente;
                    siguiente->izq = anterior;
                    tareaRealizada("eliminar");
                    delete borrar;
                    break;
                }
                actual = actual->der;
            }while(actual != inicio);
        }
    }



};
