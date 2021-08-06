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
        Nodo* reco = inicio;
        while(reco!= NULL){
            cout<< reco->carnet <<'\t';
            cout<< reco->nombre <<'\t';
            cout<< reco->descripcion <<'\t';
            cout<< reco->materia <<'\t';
            cout<< reco->fecha <<'\t';
            cout<< reco->hora <<'\t';
            cout<< reco->estado <<endl;
            reco = reco->der;
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
        }
        else if(valor == sizeDeLaLista()){
            Nodo* borrarFin = fin;
            fin = fin->izq;
            fin->der = NULL;
            delete borrarFin;

        }else{
            Nodo* reco = inicio;
            Nodo* anterior;
            Nodo* siguiente;
            Nodo* borrar;
            int contador=1;

            while(reco->der != NULL){
                if(contador == valor){
                    anterior=reco->izq;
                    siguiente=reco->der;
                    borrar = reco;
                    anterior->der = siguiente;
                    siguiente->izq = anterior;
                    delete borrar;
                    break;
                }
                contador+=1;
                reco=reco->der;
            }
        }
    }

    /*
    void ModificarNodo(int valor){
        int nuevoValor;
        if(inicio == NULL){
            cout<<"La lista esta vacia"<<endl;

        }else if(fin->info == valor){
            cout<<"Ingresar el nuevo valor: ";
            cin>>nuevoValor;
            fin->info = nuevoValor;
            cout<<"valor modificado";

        }else{
            Nodo* reco = inicio;
            while(reco->der != NULL){
                if(reco->info == valor){
                    cout<<"Ingresar el nuevo valor: ";
                    cin>>nuevoValor;
                    reco->info = nuevoValor;
                    cout<<"valor modificado";
                    break;
                }
                reco=reco->der;
            }
        }
    }
    */
};