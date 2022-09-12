#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "equipos.h"
#include "operadores.h"
#include "impactos.h"
#include "alertas.h"
#include "impresion.h"


int main()
{

    int opcion, equipo, impacto;
    int archivoEquipo, archivoOperadores, archivoImpactos, archivoAlertas;
    equipos obj;
    operadores obj2;
    impactos obj3;
    alertas obj4;


    while(true){

    system("cls");
    cout<<"------- SOFTCHECK -------"<<endl;
    cout<<"1.     GESTION AMB"<<endl;
    cout<<"2.     CONSULTAS "<<endl;
    cout<<"3.     INFORMES"<<endl;
    cout<<"4.     MANUAL SOFTCHECK"<<endl;
    cout<<"0.     SALIR"<<endl;
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:
        cout<<"1.     EQUIPOS"<<endl;
        cout<<"2.     OPERADORES"<<endl;
        cout<<"3.     IMPACTOS"<<endl;
        cout<<"4.     ALERTAS"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>equipo;
        system("cls");
        switch(equipo){
        case 1:
            obj.cargarEquipos();
            archivoEquipo = obj.grabarenDisco();
            if(archivoEquipo == 1){
                cout << "Archivo cargado" << endl;
            }

        break;
        case 2:
            obj2.cargarOperador();
            archivoOperadores = obj2.grabarenDisco();
            if(archivoOperadores == 1){
                cout << "Archivo cargado"<< endl;
            }

        break;
        case 3:
            obj3.cargarImpactos();
            archivoImpactos = obj3.grabarenDisco();
            if(archivoImpactos == 1){
                cout << "Archivo cargado"<< endl;
            }

        break;
        case 4:
            obj4.cargarAlertas();
            archivoImpactos = obj4.grabarenDisco();
            if(archivoAlertas == 1){
                cout << "Archivo cargado"<< endl;
            }

        break;



        }
    break;
    ///GestionAmb - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 2:

    break;
    ///Consultas - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 3:
        int listado, oper;
        cout<<"1.     LEER EQUIPOS"<<endl;
        cout<<"2.     LEER OPERADORES"<<endl;
        cout<<"3.     LEER IMPACTOS"<<endl;
        cout<<"4.     LEER ALERTAS"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cin>>listado;
        system("cls");
        switch(listado){
        case 1:
            int equipo;
            verEquipos();
             while(obj.leerdeDisco(equipo)==1){
                obj.mostrarEquipos();
                equipo++;
                cout << endl;
            }

        break;
        case 2:
            verOperadores();





        break;
        case 3:
            verImpactos();

        break;
        case 4:
            verAlertas();

        break;

        }




    break;
    ///Informes - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 4:


    break;
    ///ManualSoftcheck - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    case 0: return 0;
    break;
        }
        system("pause");

    }

	cout<<endl;
	system("pause");





    return 0;
}
