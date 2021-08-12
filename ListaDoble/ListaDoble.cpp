#include "Nodo.cpp"
#include <iostream>
#include <fstream>

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
    
    void agregar(int mes,int dia, int hora, int carnet,string nombre,string descripcion,string materia,string fecha,string estado){
        Nodo* nuevo = new Nodo();
        nuevo->mes = mes;
        nuevo->dia = dia;
        nuevo->hora=hora;
        nuevo->carnet=carnet;
        nuevo->nombre=nombre;
        nuevo->descripcion=descripcion;
        nuevo->materia=materia;
        nuevo->fecha=fecha;
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
            cout<< actual->mes<<'\t';
            cout<< actual->dia<<'\t';
            cout<< actual->hora <<'\t';
            cout<< actual->carnet <<'\t';
            cout<< actual->nombre <<'\t';
            cout<< actual->descripcion <<'\t';
            cout<< actual->materia <<'\t';
            cout<< actual->fecha <<'\t';
            cout<< actual->estado <<endl;
            actual = actual->der;
        }
    }
    
    int sizeDeLaLista(){
        int contador = 0;
        if(inicio == NULL){
            cout<<"La lista esta vacia"<<endl;
        }else{
            Nodo* actual = inicio;
            while(actual != NULL){
                contador+=1;
                actual = actual->der;
            }
        }
        return contador;
    }

    int valoresparaModificar(){
        int opcion;
        cout<<" ******* Opciones para modificar *******"<<endl;
        cout<<"|              1- mes                  |"<<endl;
        cout<<"|              2- dia                  |"<<endl;
        cout<<"|              3- Hora                 |"<<endl;
        cout<<"|              4- Carnet               |"<<endl;
        cout<<"|              5- Nombre               |"<<endl;
        cout<<"|              6- Descripcion          |"<<endl;
        cout<<"|              7- Materia              |"<<endl;
        cout<<"|              8- Fecha                |"<<endl;
        cout<<"|              9- Estado               |"<<endl;
        cout<<"Ingrese por teclado la opcion que desea modificar: ";
        cin>>opcion;
        if(opcion > 7){
            cout<<"Opcion no valida"<<endl;
            valoresparaModificar();
        }else{
            return opcion;
        }
    }

    void tareaRealizada(string tarea){
        if(tarea == "eliminar"){
            cout<<"Eliminado con Exito"<<endl;
        }else{
            cout<<"Modificado con exito"<<endl;
        }

    }

    void borrarElemento(int valor){
        if(inicio == NULL){
            cout<<"La lista esta vacia"<<endl;

        }else if(valor == 1){
            Nodo* borrarInicio = inicio;
            inicio = inicio->der;
            inicio->izq == NULL;
            tareaRealizada("eliminar");
            delete borrarInicio;

        }else if(valor > sizeDeLaLista()){
            cout<<"El numero ingresado es mayor a la cantidad de elementos en la lista"<<endl;

        }else if(valor == sizeDeLaLista()){
            Nodo* borrarFin = fin;
            fin = fin->izq;
            fin->der = NULL;
            tareaRealizada("eliminar");
            delete borrarFin;
        
        }else{
            Nodo* actual = inicio;
            Nodo* anterior;
            Nodo* siguiente;
            Nodo* borrar;
            int contador=1;

            while(actual != NULL){
                if(contador == valor){
                    anterior=actual->izq;
                    siguiente=actual->der;
                    borrar = actual;
                    anterior->der = siguiente;
                    siguiente->izq = anterior;
                    tareaRealizada("eliminar");
                    delete borrar;
                    break;
                }
                contador+=1;
                actual=actual->der;
            }
        }
    }

    void ModificarNodo(int valor){
        int opcion;
        int mesNuevo;
        int diaNuevo;
        int horaNuevo;
        int carnetNuevo;
        string nombreNuevo;
        string descripcionNuevo;
        string materiaNuevo;
        string fechaNuevo;
        string estadoNuevo;

        if(inicio == NULL){
            cout<<"La lista se encuentra vacia";

        }else if(valor == sizeDeLaLista()){
            Nodo* actual = fin;
            opcion = valoresparaModificar();
            switch (opcion){
                case 1:
                    cout<<"Ingrese el nuevo valor del mes: ";
                    cin>>mesNuevo;
                    actual->mes = mesNuevo;
                    tareaRealizada("a");
                    
                break;
                case 2:
                    cout<<"Ingrese el nuevo valor del dia: ";
                    cin>>diaNuevo;
                    actual->dia = diaNuevo;
                    tareaRealizada("a");
                    
                break;
                case 3:
                    cout<<"Ingrese el nuevo valor del hora: ";
                    cin>>horaNuevo;
                    actual->hora = horaNuevo;
                    tareaRealizada("a");

                break;
                case 4:
                    cout<<"Ingrese el nuevo valor del carnet: ";
                    cin>>carnetNuevo;
                    actual->carnet = carnetNuevo;
                    tareaRealizada("a");
                    
                break;
                case 5:
                    cout<<"Ingrese el nuevo valor del nombre: ";
                    cin>>nombreNuevo;
                    actual->nombre = nombreNuevo;
                    tareaRealizada("a");

                break;
                case 6:
                    cout<<"Ingrese el nuevo valor del descripcion: ";
                    cin>>descripcionNuevo;
                    actual->descripcion = descripcionNuevo;
                    tareaRealizada("a");

                break;
                case 7:
                    cout<<"Ingrese el nuevo valor del materia: ";
                    cin>>materiaNuevo;
                    actual->materia = materiaNuevo;
                    tareaRealizada("a");

                break;
                case 8:
                    cout<<"Ingrese el nuevo valor del fecha: ";
                    cin>>fechaNuevo;
                    actual->fecha = fechaNuevo;
                    tareaRealizada("a");

                break;
                case 9:
                    cout<<"Ingrese el nuevo valor del estado: ";
                    cin>>estadoNuevo;
                    actual->estado = estadoNuevo;
                    tareaRealizada("a");

                break;
            }

        }else{
            Nodo* actual = inicio;
            int contador = 1;
            while(actual != NULL){
                if(valor == contador){
                    opcion = valoresparaModificar();
                    switch (opcion){
                        case 1:
                            cout<<"Ingrese el nuevo valor del mes: ";
                            cin>>mesNuevo;
                            actual->mes = mesNuevo;
                            tareaRealizada("a");                            
                        break;
                        case 2:
                            cout<<"Ingrese el nuevo valor del dia: ";
                            cin>>diaNuevo;
                            actual->dia = diaNuevo;
                            tareaRealizada("a");                            
                        break;
                        case 3:
                            cout<<"Ingrese el nuevo valor del hora: ";
                            cin>>horaNuevo;
                            actual->hora = horaNuevo;
                            tareaRealizada("a");
                        break;
                        case 4:
                            cout<<"Ingrese el nuevo valor del carnet: ";
                            cin>>carnetNuevo;
                            actual->carnet = carnetNuevo;
                            tareaRealizada("a");
                        break;
                        case 5:
                            cout<<"Ingrese el nuevo valor del nombre: ";
                            cin>>nombreNuevo;
                            actual->nombre = nombreNuevo;
                            tareaRealizada("a");
                        break;
                        case 6:
                            cout<<"Ingrese el nuevo valor del descripcion: ";
                            cin>>descripcionNuevo;
                            actual->descripcion = descripcionNuevo;
                            tareaRealizada("a");
                        break;
                        case 7:
                            cout<<"Ingrese el nuevo valor del materia: ";
                            cin>>materiaNuevo;
                            actual->materia = materiaNuevo;
                            tareaRealizada("a");
                        break;
                        case 8:
                            cout<<"Ingrese el nuevo valor del fecha: ";
                            cin>>fechaNuevo;
                            actual->fecha = fechaNuevo;
                            tareaRealizada("a");
                        break;
                        case 9:
                            cout<<"Ingrese el nuevo valor del estado: ";
                            cin>>estadoNuevo;
                            actual->estado = estadoNuevo;
                            tareaRealizada("a");
                        break;

                    }
                }
                contador+=1;
                actual=actual->der;
            }
        }
    }

    void reporte(int m, int d, int h, int numero){
        Nodo* actual = inicio;
        if(numero == 3){
            do{
                if(actual->mes == m && actual->dia == d && actual->hora == h){
                    cout<<"\n*************** TAREA ***************\n";
                    cout<<"Mes:"+to_string(actual->mes)+"\nDia:"+to_string(actual->dia)+"\nHora:"+to_string(actual->hora)+"\nCarnet: "+to_string(actual->carnet)+"\nNombre: "+actual->nombre+"\nDescripcion: "+actual->descripcion+"\nMateria: "+actual->materia+"\nFecha: "+actual->fecha+"\nEstado: "+actual->estado;
                    break;
                }
                actual = actual->der;
            }while(actual != NULL);

        }else{
            int contador = 1;
            do{
                if(actual->mes == m && actual->dia == d && actual->hora == h){
                    cout<<"\n*************** TAREA "<<contador<<" ***************\n";
                    cout<<"Mes:"+to_string(actual->mes)+"\nDia:"+to_string(actual->dia)+"\nHora:"+to_string(actual->hora)+"\nCarnet: "+to_string(actual->carnet)+"\nNombre: "+actual->nombre+"\nDescripcion: "+actual->descripcion+"\nMateria: "+actual->materia+"\nFecha: "+actual->fecha+"\nEstado: "+actual->estado;
                    break;
                }
                actual = actual->der;
                contador+=1;
            }while(actual != NULL);

        }
    }

    void graficar(int numero){
        string nombredelagrafica = "Grafica"+to_string(numero);
        Nodo* actual = inicio;
        int contador = 0;
        string texto = "";

        while(actual!= NULL){
            texto += "nodo"+to_string(contador)+"[shape=square label=\"Mes: "+to_string(actual->mes)+"\nDia: "+to_string(actual->dia)+"\nHora: "+to_string(actual->hora)+"\nCarnet: "+to_string(actual->carnet)+"\nNombre: "+actual->nombre+"\nDescripcion: "+actual->descripcion+"\nMateria: "+actual->materia+"\nFecha: "+actual->fecha+"\nEstado: "+actual->estado+"\"]\n";
        
            contador+=1;
            actual = actual->der;
        }

        for(int i=0; i<(contador-1); i++){
            texto += "\nnodo"+to_string(i)+"->nodo"+to_string(i+1)+" [dir=both];";
        }

        ofstream archivo;
        archivo.open(nombredelagrafica+".dot",ios::out);

        if(archivo.fail()){
            cout<<"No se pude abrir el archivo";
            exit(1);
        }

        archivo<<"digraph G{\n"+texto+"\n}";
        archivo.close();
        std::string str = "dot -Tpng Grafica"+to_string(numero)+".dot -o Grafica"+to_string(numero)+".png";
        const char *cstm = str.c_str();
        system(cstm);

    }

    int validarFechas(int numero, string dato){
        int caso;
        if(dato == "mes"){
            caso = 1;
        }else if(dato == "dia"){
            caso = 2;
        }else{
            caso = 3;
        }
        switch(caso){
            case 1:
                if(numero >= 7 && numero <= 11){
                    return 1;
                }else{
                    return 0;
                }
            break;
            case 2:
                if(numero >= 1 && numero <= 30){
                    return 1;
                }else{
                    return 0;
                }
            break;
            case 3:
                if(numero >= 8 && numero <= 16){
                    return 1;
                }else{
                    return 0;
                }
            break;
        }
    }
};