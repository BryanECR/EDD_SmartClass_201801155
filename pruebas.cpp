#include <iostream>
#include <string>
#include <regex>

using namespace std;

void is_email_valid(const std::string& email)
{
   // define a regular expression
   const std::regex pattern
      ("[\\w]+@[\\w]+\\.[cmesorg]{2,3}");

   // try to match the string with the regular expression
   if(std::regex_match(email, pattern)){
     cout<<"Formato de correo correcto\n";
   }else{
     cout<<"formato de correo incorrecto\n";
   }
}


int main(){
    /*
    string info2 = "Carnet,DPI,Nombre,Carrera,Password,Creditos,Edad,Correo\n201700886,3502451230508,Emilia Miramontes,Ingeniería en Ciencias y Sistemas,roxodiciqi,205,21,nicols36@hotmail.com\n201501786,7249529279753,Juan Curiel,Ingeniería Industrial,zanolexima,245,24,jernimo.caballero@yahoo.com\n201822186,9298434863898,Eloisa Rincón,Ingeniería Civil,toqelijanu,95,19,carolinaelizondo85@yahoo.com\n201901425,4131766125532,Bernardo Hinojosa,Ingeniería Mecánica,wosopumano,100,20,alfonso03@hotmail.com\n201503186,8549191766348,Manuel Manzanares,Ingeniería Eléctrica,rejumudore,226,24,benitoarmas92@gmail.com\n201123146,9616636196552,Julia Corona,Ingeniería Electrónica,xojobavuji,237,26,ngela.solorio86@yahoo.com\n201704186,4778315315575,Berta Carrasco,Ingeniería Ambiental,gayahizatu,210,22,carmen.montenegro@yahoo.com\n202000786,7382344774121,Lola Delapaz,Ingeniería Química,hujocikimi,45,19,adriana56@gmail.com\n201611446,2511893949443,Sonia Arteaga,Ingeniería Mecánica Industrial,rezutafila,195,23,esperanza.meza41@hotmail.com\n201819852,3423442386382,Benjamín Asencio,Ingeniería Mecánica Eléctrica,runoqozepo,117,20,horacio.tejada15@yahoo.com";

    string info = "nombre,color,comida,estrellas\nmc,rojo&amarillo,hamburgesas,4\ndominos,azul,pizza,3\nmaton,naranja,pollo,3\nchino,blanco,comidachina,2\ngreen,verde,saludable,2\nwok,blanco,china,2\nking,cafe,hamburgesas,3";
    */
   
    std::string email1 = "text.example@random.com";
    std::string email2 = "textexample@random.coma";
    std::string email3 = "user@extension.org";



    is_email_valid(email1);
    is_email_valid(email2);
    is_email_valid(email3);


  return 0;
}




