#include "Nodo.cpp"
#include <iostream>

using namespace std;

class ListaDoblementeEnlazada{
    private:
        Nodo* inicio;
        Nodo* fin;
    public:
        ListaDoblementeEnlazada(){
            inicio = NULL;
            fin = NULL;
        }
    
    void agregar(int carnet,string nombre,string descripcion,string materia,string fecha,string hora,string estado){
        Nodo* nuevo = new Nodo();
        nuevo->carnet=carnet;
        nuevo->nombre=nombre;
        nuevo->descripcion=descripcion;
        nuevo->materia=materia;
        nuevo->fecha=fecha;
        nuevo->hora=hora;
        nuevo->estado=estado;

        if(inicio == NULL){
            inicio = nuevo;
            fin = nuevo;
            nuevo->izq = NULL;
            nuevo->der = NULL;

        }else{
            nuevo->izq = fin;
            fin->der = nuevo;
            fin = fin->der;
            fin->der = NULL;

        }
    }

    void mostrar(){
        Nodo* actual = inicio;
        while(actual!= NULL){
            cout<< actual->carnet <<'\t';
            cout<< actual->nombre <<'\t';
            cout<< actual->descripcion <<'\t';
            cout<< actual->materia <<'\t';
            cout<< actual->fecha <<'\t';
            cout<< actual->hora <<'\t';
            cout<< actual->estado <<endl;
            actual = actual->der;
        }
    }
    
    int sizeDeLaLista(){
        int contador = 1;
        if(inicio == NULL){
            cout<<"La lista esta vacia"<<endl;
        }else{
            Nodo* actual = inicio;
            while(actual->der != NULL){
                contador+=1;
                actual = actual->der;
            }
        }
        return contador;
    }


    void borrarElemento(int valor){
        if(inicio == NULL){
            cout<<"La lista esta vacia"<<endl;

        }else if(valor == 1){
            Nodo* borrarInicio = inicio;
            inicio = inicio->der;
            inicio->izq == NULL;
            delete borrarInicio;

        }else if(valor > sizeDeLaLista()){
            cout<<"El numero ingresado es mayor a la cantidad de elementos en la lista"<<endl;

        }else if(valor == sizeDeLaLista()){
            Nodo* borrarFin = fin;
            fin = fin->izq;
            fin->der = NULL;
            delete borrarFin;

        }else{
            Nodo* actual = inicio;
            Nodo* anterior;
            Nodo* siguiente;
            Nodo* borrar;
            int contador=1;

            while(actual->der != NULL){
                if(contador == valor){
                    anterior=actual->izq;
                    siguiente=actual->der;
                    borrar = actual;
                    anterior->der = siguiente;
                    siguiente->izq = anterior;
                    delete borrar;
                    break;
                }
                contador+=1;
                actual=actual->der;
            }
        }
    }

    int valoresparaModificar(){
        int opcion;
        cout<<" ******* Opciones para modificar *******"<<endl;
        cout<<"|              1- Carnet               |"<<endl;
        cout<<"|              2- Nombre               |"<<endl;
        cout<<"|              3- Descripcion          |"<<endl;
        cout<<"|              4- Materia              |"<<endl;
        cout<<"|              5- Fecha                |"<<endl;
        cout<<"|              6- Hora                 |"<<endl;
        cout<<"|              7- Estado               |"<<endl;
        cout<<"Ingrese por teclado la opcion que desea modificar: ";
        cin>>opcion;
        if(opcion > 7){
            cout<<"Opcion no valida"<<endl;
            valoresparaModificar();
        }else{
            return opcion;
        }
    }
    

    void ModificarNodo(int valor){
        int opcion;
        int carnetNuevo;
        string nombreNuevo;
        string descripcionNuevo;
        string materiaNuevo;
        string fechaNuevo;
        string horaNuevo;
        string estadoNuevo;

        if(inicio == NULL){
            cout<<"La lista se encuentra vacia";
        }else{
            Nodo* actual = inicio;
            int contador = 1;
            while(actual->der != NULL){
                if(valor == contador){
                    opcion = valoresparaModificar();
                    switch (opcion){
                    case 1:
                        cout<<"Ingrese el nuevo valor del carnet: ";
                        cin>>carnetNuevo;
                        actual->carnet = carnetNuevo;
                     break;

                    case 2:
                        cout<<"Ingrese el nuevo valor del nombre: ";
                        cin>>nombreNuevo;
                        actual->nombre = nombreNuevo;
                     break;

                    case 3:
                        cout<<"Ingrese el nuevo valor del descripcion: ";
                        cin>>descripcionNuevo;
                        actual->descripcion = descripcionNuevo;
                     break;

                    case 4:
                        cout<<"Ingrese el nuevo valor del materia: ";
                        cin>>materiaNuevo;
                        actual->materia = materiaNuevo;
                     break;

                    case 5:
                        cout<<"Ingrese el nuevo valor del fecha: ";
                        cin>>fechaNuevo;
                        actual->fecha = fechaNuevo;
                     break;

                    case 6:
                        cout<<"Ingrese el nuevo valor del hora: ";
                        cin>>horaNuevo;
                        actual->hora = horaNuevo;
                     break;

                    case 7:
                        cout<<"Ingrese el nuevo valor del estado: ";
                        cin>>estadoNuevo;
                        actual->estado = estadoNuevo;
                     break;

                    }
                }
                contador+=1;
                actual=actual->der;
            }
        }
    }

};