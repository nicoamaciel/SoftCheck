#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "impresion.h"


    void verImpactos(){
        cout << " IP HOST " << " | " << " IMPACTO " << " | " << " TORRE " << " | " << " TIPO IMPACTO " << " | " << " SERVICO ALERTADO " << endl;
        cout << "------------------------------------------------------------------"<< endl;
    }


     void verEquipos(){
        cout << " NOMBRE HOST " << " | " << " MARCA DEL HOST " << " | " << " IP HOST " << " | " << " ESTADO HOST " <<  endl;
        cout << "------------------------------------------------------------------"<< endl;



     }
    void verOperadores(){
        cout << " NOMBRE " << " | " << " APELLIDO " << " | " << " USUARIO " << " | " << " TURNO " << " | " << " DNI" <<  " | " << " INGRESO" <<endl;
        cout << "------------------------------------------------------------------"<< endl;



    }

    void verAlertas(){
        cout << " IP HOST " << " | " << " IMPACTO " << " | " << " SERVICO ALERTADO " << " | " << " TIPO IMPACTO " << " | " << " FECHA " << endl;
        cout << "------------------------------------------------------------------"<< endl;



    }



