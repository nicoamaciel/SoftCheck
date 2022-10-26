#include <iostream>
using namespace std;

#include "menu.h"
#include "funciones.h"

menu llamar;
funcion funcion;

int menu::menuPrincipal(){

    int opcion;

    while(true){

    system("cls");
    cout<<"------- SOFTCHECK -------"<<endl;
    cout<<"1.     GESTION ALTA-BAJA"<<endl;
    cout<<"2.     CONSULTAS"<<endl;
    cout<<"3.     EXPORTAR"<<endl;
    cout<<"4.     MANTENIMIENTO"<<endl;
    cout<<"0.     SALIR"<<endl;
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:
        llamar.altaBaja();

         break;
    case 2:
        llamar.consultas();
        break;
    case 3:
        llamar.exportar();
        break;
    case 4:
        llamar.mantenimieto();
        break;

    case 0:
        return 0;
    break;
    }
        system("pause");

    }

	cout<<endl;
	system("pause");

}

int menu::altaBaja(){

int opcion, opc2;

    while(true){

    system("cls");
    cout<<"------- ALTAS & BAJAS -------"<<endl;
    cout<<"1.     EQUIPOS"<<endl;
    cout<<"2.     OPERADORES"<<endl;
    cout<<"3.     IMPACTOS"<<endl;
    cout<<"4.     ALERTAS"<<endl;
    cout<<"5.     TORRES"<<endl;
    cout<<"0.     SALIR"<<endl;
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:
        cout<<"1.    ALTA"<<endl;
        cout<<"2.    BAJA"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opc2;
        system("cls");
        switch(opc2){
        case 1:
            funcion.ingresarEquipos();
            break;
        case 2:
            funcion.bajadeEquipos();
            break;
            }
         break;
    case 2:
        cout<<"1.    ALTA"<<endl;
        cout<<"2.    BAJA"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opc2;
        system("cls");
        switch(opc2){
        case 1:
            funcion.ingresoOperadores();
            break;
        case 2:
            funcion.bajadeOperadores();
            break;
            }
         break;

        break;
    case 3:
        cout<<"1.    ALTA"<<endl;
        cout<<"2.    BAJA"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opc2;
        system("cls");
        switch(opc2){
        case 1:
            funcion.ingresoImpactos();
            break;
        case 2:

            break;
            }
         break;
        break;
    case 4:
        cout<<"1.    ALTA"<<endl;
        cout<<"2.    BAJA"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opc2;
        system("cls");
        switch(opc2){
        case 1:
            funcion.ingresoAlertas();
            break;
        case 2:
            break;

            }
         break;
        break;
    case 5:
        cout<<"1.    ALTA"<<endl;
        cout<<"2.    BAJA"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opc2;
        system("cls");
        switch(opc2){
        case 1:
            funcion.ingresoTorres();
            break;
        case 2:
            break;

            }
         break;
        break;
    case 0: return 0;
        break;

    }
        system("pause");

    }

	cout<<endl;
	system("pause");


}

int menu::consultas(){

int opcion;

    while(true){

    system("cls");
    cout<<"------- CONSULTAS -------"<<endl;
    cout<<"1.     LISTADO DE EQUIPOS"<<endl;
    cout<<"2.     LISTADO DE TORRES"<<endl;
    cout<<"3.     OPERADORES POR TURNO "<<endl;
    cout<<"4.     ALERTAS POR TURNO"<<endl;
    cout<<"5.     ALERTAS WARNING"<<endl;
    cout<<"6.     ALERTAS CRITICAL"<<endl;
    cout<<"7.     ESCALA DE RESOLUCIONES"<<endl;
    cout<<"0.     SALIR"<<endl;
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:
        {
        funcion.listadoEquipos();
        }

        break;
    case 2:
        {
        funcion.listadoTorres();

        }

        break;
    case 3:
        {
        funcion.listadoOper();
        }

        break;
    case 4:
        {
        funcion.alertasPorTurno();
        }
        break;
    case 5:
        {
        funcion.alertasWarning();
        }
        break;
    case 6:
        {
        funcion.alertasCritical();
        }
        break;
    case 7:
        {
        funcion.listadoImpac();

        }
        break;

    case 0: return 0;
        break;

    }
        system("pause");

    }

	cout<<endl;
	system("pause");

}

int menu::exportar(){

int opcion;

    while(true){

    system("cls");
    cout<<"------- EXPORTAR CSV -------"<<endl;
    cout<<"1.     EXPORTAR EQUIPOS"<<endl;
    cout<<"2.     EXPORTAR OPERADORES"<<endl;
    cout<<"3.     EXPORTAR ALERTAS"<<endl;
    cout<<"0.     SALIR"<<endl;
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:
        if(csvEquipos()>0){
            cout << "Archivo exportando" << endl;
        }
        break;
    case 2:
            if(CsvOperadores()>0){
               cout << "Archivo exportando" << endl;
            }
        break;
    case 3:
            if(csvAlertas()>0){
               cout << "Archivo exportando" << endl;
            }
        break;
    case 4:
        break;
    case 0: return 0;
        break;

    }
        system("pause");

    }

	cout<<endl;
	system("pause");





}

int menu::mantenimieto(){

int opcion;

    while(true){

    system("cls");
    cout<<"------- MANTENIMIENTO -------"<<endl;
    cout<<"1.     BACKUP EQUIPOS"<<endl;
    cout<<"2.     BACKUP TORRES"<<endl;
    cout<<"3.     BACKUP IMPACTOS"<<endl;
    cout<<"4.     MANUAL DE USUARIO"<<endl;
    cout<<"0.     SALIR"<<endl;
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    system("cls");
    switch(opcion){
    case 1:
         break;
    case 2:

        break;
    case 3:
        break;
    case 4:
        break;
    case 0: return 0;
        break;

    }
        system("pause");

    }

	cout<<endl;
	system("pause");



}




