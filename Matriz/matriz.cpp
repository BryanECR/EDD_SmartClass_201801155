#include <iostream>
#include <string>

using namespace std;

class Tarea{
    private:
        int mes;
        int dia;
        int hora;
        int carnet;
        string nombre;
        string descripcion;
        string materia;
        string fecha;
        string estado;
    public:
        Tarea(){
            this->mes = 0;
            this->dia = 0;
            this->hora = 0;
            this->carnet = 0;
            this->nombre = "";
            this->descripcion = "";
            this->materia = "";
            this->fecha = "";
            this->estado = "";
        }
    
    void getTarea(int mes,int dia,int h,int c,string n,string d, string m, string f,string e){
        this->mes = mes;
        this->dia = dia;
        this->hora = h;
        this->carnet = c;
        this->nombre = n;
        this->descripcion = d;
        this->materia = m;
        this->fecha = f;
        this->estado = e;
    }

    string setTarea(){
        return "Mes: "+to_string(this->mes)+"\nDia: "+to_string(this->dia)+"\nHora: "+to_string(this->hora)+"\nCarnet: "+to_string(this->carnet)+"\nNombre: "+this->nombre+"\nDescripcion "+this->descripcion+"\nMateria: "+this->materia+"\nFecha: "+this->fecha+"\nEstado: "+this->estado;
    }
};

int main(){
    Tarea matriz3d[2][2][2] = { Tarea() };
    int contador=0;
    int mes,dia,h,c;
    string n,d,m,f,e;

    for(int i=0; i<2 ; i++){
        for(int j=0; j<2 ; j++){
            for(int k=0; k<2 ; k++){
                cout<<"Mes: ";
                cin>>mes;
                cout<<"Dia: ";
                cin>>dia;
                cout<<"Hora: ";
                cin>>h;
                cout<<"Carnet: ";
                cin>>c;
                cout<<"Nombre: ";
                cin>>n;
                cout<<"Descripcion: ";
                cin>>d;
                cout<<"Materia: ";
                cin>>m;
                cout<<"Fecha: ";
                cin>>f;
                cout<<"Estado: ";
                cin>>e;
                matriz3d[i][j][k].getTarea(mes,dia,h,c,n,d,m,f,e);
            }
        }
    }

    for(int i=0; i<2 ; i++){
        cout<<"nivel "<<i<<endl;
        for(int j=0; j<2 ; j++){
            cout<<"fila: "<<j<<endl;
            for(int k=0; k<2 ; k++){
                cout<<"columna: "<<k<<endl;
                cout<<matriz3d[i][j][k].setTarea()<<endl;
            }
        }
    }

    return 0;
}