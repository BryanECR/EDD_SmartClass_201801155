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
        return "Mes: "+to_string(this->mes)+" Dia: "+to_string(this->dia)+" Hora: "+to_string(this->hora)+" Carnet: "+to_string(this->carnet)+" Nombre: "+this->nombre+" Descripcion "+this->descripcion+" Materia: "+this->materia+" Fecha: "+this->fecha+" Estado: "+this->estado;
    }
};



int main(){
    
    Tarea matriz3d[3][2][2] = { Tarea() };

    
    matriz3d[0][0][0].getTarea(8,9,12,201801155,"Bryan","proyecto","EDD","123/15/12","Casi");
    matriz3d[1][1][0].getTarea(9,10,11,202000156,"Eduardo","proyecto","OCL1","2021/09/05","Casi");
    matriz3d[2][0][1].getTarea(13,14,15,202108479,"Caal","tarea","Apli1","2021/10/8","Casi");
     

    for(int i=0; i<3 ; i++){
        cout<<" *** nivel "<<i<<endl;
        for(int j=0; j<2 ; j++){
            cout<<"fila: "<<j<<endl;
            for(int k=0; k<2 ; k++){
                cout<<"columna: "+to_string(k)+" ";
                cout<<matriz3d[i][j][k].setTarea()<<endl;
            }
        }
    }

}