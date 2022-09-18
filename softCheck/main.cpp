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
    equipos objEqui[5];
    operadores ObjOper[5];
//    alertas objAlert;
//    impactos objImpac;

    int archivoEquipo, archivoOperadores, archivoImpactos, archivoAlertas;
    int opcion, opcion2, listado, abequipos, aboper, bkp;
    int oper, eq, imp, alert;



    while(true){

    system("cls");
    cout<<"------- SOFTCHECK -------"<<endl;
    cout<<"1.     GESTION ALTA-BAJA"<<endl;
    cout<<"2.     BACKUPS "<<endl;
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
        cout<<"5.     TORRES"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>opcion2;
        system("cls");
        switch(opcion2){
        case 1:
//                for(int i=0; i<5; i++){
//                objEqui[i].cargarEquipos();
//                archivoEquipo = objEqui[i].grabarenDisco();
//                if(archivoEquipo == 1){
//                cout << "Archivo cargado" << endl;
//
//
//                    }
//                  }
            cout<<"1.    ALTA"<<endl;
            cout<<"2.    BAJA"<<endl;
            cout<<"-----------------------------"<<endl<<endl;
            cout<<"OPCION: ";
             cin>>abequipos;
            system("cls");
            switch(abequipos){
                case 1:

                    if(altaEquipo() == true){
                            cout << endl;
                            cout << "Registro agregado correctamente" << endl;

                        }else{
                            cout << endl;
                            cout << "No se pudo agregar el registro" << endl;
                        }
                break;
                case 2:
                    if(bajaEquipo() == true){
                            cout << endl;
                            cout << "Registro fue dado de baja" << endl;

                        }else{
                            cout << endl;
                            cout << "No se pudo dar de baja el registro" << endl;
                        }

                break;

            }

        break;
        case 2:
//            for(int i=0; i<5; i++){
//                ObjOper[i].cargarOperador();
//                archivoOperadores = ObjOper[i].grabarenDisco();
//                if(archivoOperadores == 1){
//                cout << "Archivo cargado"<< endl;
//                }
//
//            }
            cout<<"1.    ALTA"<<endl;
            cout<<"2.    BAJA"<<endl;
            cout<<"-----------------------------"<<endl<<endl;
            cout<<"OPCION: ";
             cin>>aboper;
            system("cls");
            switch(aboper){
                case 1:

                    if(altaOper() == true){
                            cout << endl;
                            cout << "Registro agregado correctamente" << endl;

                        }else{
                            cout << endl;
                            cout << "No se pudo agregar el registro" << endl;
                        }
                break;
                case 2:
                    if(bajaOper() == true){
                            cout << endl;
                            cout << "Registro fue dado de baja" << endl;

                        }else{
                            cout << endl;
                            cout << "No se pudo dar de baja el registro" << endl;
                        }

                break;

            }






        break;
        case 3:
//            objImpac.cargarImpactos();
//            archivoImpactos = objImpac.grabarenDisco();
//            if(archivoImpactos == 1){
//                cout << "Archivo cargado"<< endl;
//            }

        break;
        case 4:
//            objAlert.cargarAlertas();
//            archivoAlertas = objAlert.grabarenDisco();
//            if(archivoAlertas == 1){
//                cout << "Archivo cargado"<< endl;
//            }

        break;
        case 5:
        break;



        }
        system("pause");
        system("cls");
    break;

    case 2:
        cout<<"1.     EQUIPOS"<<endl;
        cout<<"2.     OPERADORES"<<endl;
        cout<<"3.     ALERTAS"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cout<<"OPCION: ";
        cin>>bkp;
        system("cls");
        switch(bkp){
        case 1:
            if(grabarCsv() == true){
                cout << "Backup generado con exito" << endl;

            }


        break;
        case 2:
            if(grabarCsvOper() == true){
                cout << "Backup generado con exito" << endl;

            }

        break;
        case 3:

        break;




        }





    break;

    case 3:
        cout<<"1.     LEER EQUIPOS"<<endl;
        cout<<"2.     LEER OPERADORES"<<endl;
        cout<<"3.     LEER IMPACTOS"<<endl;
        cout<<"4.     LEER ALERTAS"<<endl;
        cout<<"0.     SALIR"<<endl;
        cout<<"-----------------------------"<<endl<<endl;
        cin>>listado;
        system("cls");
        switch(listado){
        case 1:
            verEquipos();
            listarEquipos();


        break;
        case 2:
            verOperadores();
            listarOperadores();

        break;
        case 3:
//            verImpactos();
//            while(objImpac.leerdeDisco(imp)==1){
//            objImpac.mostrarImpactos();
//            imp++;
//            cout << endl;
//            }




        break;
        case 4:





        break;

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





    return 0;
}
