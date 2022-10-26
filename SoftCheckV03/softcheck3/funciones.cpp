#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

#include "funciones.h"
#include "equipos.h"
#include "operadores.h"
#include "impactos.h"
#include "alertas.h"
#include "torres.h"


int funcion::cantidadEquipos(){
int cant=0;
FILE *pE = fopen("equipos.dat","rb");
if(pE==nullptr){return 0;}

fseek(pE,0,SEEK_END);
cant = ftell(pE)/sizeof(equipos);
fclose(pE);
return cant;

}


void funcion::leerEquipos(equipos equ[], int cant){
FILE *pE = fopen("equipos.dat","rb");
if(pE==nullptr){cout << "Error de lectura" << endl;}

fread(equ, sizeof(equipos), cant, pE);
fclose(pE);

}


void funcion::listadoEquipos(){

int cantidad = cantidadEquipos();

equipos *equ = new equipos[cantidad];

leerEquipos(equ,cantidad);

verEquipos();
for(int i=0; i<cantidad; i++){
    equ[i].mostrarEquipos();
}

delete []equ;

}

void funcion::ingresarEquipos(){

int cant, archivoEquipo=0;

cout << "Ingresar cantidad de equipos a cargar: ";
cin >> cant;

equipos *objEqui= new equipos[cant];


    for(int i=0; i<cant; i++){
    objEqui[i].cargarEquipos();
        archivoEquipo = objEqui[i].grabarenDisco();
        if(archivoEquipo == 1){
        cout << "Archivo cargado" << endl;


        }
    }

delete []objEqui;

}

void funcion::bajadeEquipos(){

bool comparar = bajaEquipo();
if(comparar){
    cout << "Equipo dado de baja" << endl;
    }



}

void funcion::ingresoOperadores(){

int cant, archivoOper=0;

cout << "Ingresar cantidad de operadores a cargar: ";
cin >> cant;

operadores *objOper= new operadores[cant];


    for(int i=0; i<cant; i++){
    objOper[i].cargarOperador();
        archivoOper = objOper[i].grabarenDisco();
        if(archivoOper == 1){
        cout << "Archivo cargado" << endl;


        }
    }

delete []objOper;

}


int funcion::cantidadOperadores(){
int cant=0;
FILE *pO = fopen("operadores.dat","rb");
if(pO==nullptr){return 0;}

fseek(pO,0,SEEK_END);
cant = ftell(pO)/sizeof(operadores);
fclose(pO);
return cant;

}


void funcion::leerOper(operadores oper[], int cant){
FILE *pO = fopen("operadores.dat","rb");
if(pO==nullptr){cout << "Error de lectura" << endl;}

fread(oper, sizeof(operadores), cant, pO);
fclose(pO);

}

void funcion::listadoOper(){

int cantidad = cantidadOperadores();

operadores *oper = new operadores[cantidad];

leerOper(oper,cantidad);

verOperadores();
for(int i=0; i<cantidad; i++){
    oper[i].mostrarOperador();
}

delete []oper;

}

void funcion::bajadeOperadores(){

bool comparar = bajaOper();
    if(comparar){
        cout << "Operador dado de baja" << endl;
    }


}


void funcion::ingresoImpactos(){
int cant, archivoImpactos=0;

cout << "Ingresar cantidad de impactos a cargar: ";
cin >> cant;

impactos *objImpac= new impactos[cant];


    for(int i=0; i<cant; i++){
    objImpac[i].cargarImpactos();
        archivoImpactos = objImpac[i].grabarenDisco();
        if(archivoImpactos == 1){
        cout << "Archivo cargado" << endl;


        }
    }

delete []objImpac;

}

//void funcion::bajadeImpactos(){
//bool comparar = bajaImpac();
//    if(comparar){
//        cout << "Impacto dado de baja" << endl;
//    }
//
//}

int funcion::cantidadImpactos(){
int cant=0;
FILE *pI = fopen("impactos.dat","rb");
if(pI==nullptr){return 0;}

fseek(pI,0,SEEK_END);
cant = ftell(pI)/sizeof(impactos);
fclose(pI);
return cant;


}

void funcion::leerImpac(impactos impac[], int cant){
FILE *pI = fopen("impactos.dat","rb");
if(pI==nullptr){cout << "Error de lectura" << endl;}

fread(impac, sizeof(impactos), cant, pI);
fclose(pI);
}

void funcion::listadoImpac(){

int cantidad = cantidadImpactos();

impactos *impac = new impactos[cantidad];

leerImpac(impac,cantidad);

verImpactos();
for(int i=0; i<cantidad; i++){
    impac[i].mostrarImpactos();
}

delete []impac;


}


void funcion::ingresoAlertas(){
int cant, archivoAlertas=0;

cout << "Ingresar cantidad de alertas a cargar: ";
cin >> cant;

alertas *objAlert= new alertas[cant];


    for(int i=0; i<cant; i++){
    objAlert[i].cargarAlertas();
        archivoAlertas = objAlert[i].grabarenDisco();
        if(archivoAlertas == 1){
        cout << "Archivo cargado" << endl;
        }
    }

delete []objAlert;

}

void funcion::bajadeAlertas(){


}

int funcion::cantidadAlertas(){

int cant=0;
FILE *pA = fopen("alertas.dat","rb");
if(pA==nullptr){return 0;}

fseek(pA,0,SEEK_END);
cant = ftell(pA)/sizeof(alertas);
fclose(pA);
return cant;


}

void funcion::leerAlertas(alertas alert[], int cant){
FILE *pA = fopen("alertas.dat","rb");
if(pA==nullptr){cout << "Error de lectura" << endl;}

fread(alert, sizeof(alertas), cant, pA);
fclose(pA);


}

void funcion::listadoAlert(){

int cantidad = cantidadAlertas();

alertas *alert = new alertas[cantidad];

leerAlertas(alert,cantidad);

verAlertas();
for(int i=0; i<cantidad; i++){
    alert[i].mostrarAlertas();
}

delete []alert;

}


void funcion::ingresoTorres(){
int cant, archivoTorres=0;

cout << "Ingresar cantidad de torres a cargar: ";
cin >> cant;

torres *objTorres= new torres[cant];


    for(int i=0; i<cant; i++){
    objTorres[i].cargarTorres();
        archivoTorres = objTorres[i].grabarenDisco();
        if(archivoTorres == 1){
        cout << "Archivo cargado" << endl;


        }
    }

delete []objTorres;




}

//void funcion::bajadeTorres(){}

int funcion::cantidadTorres(){
int cant=0;
FILE *pT = fopen("torres.dat","rb");
if(pT==nullptr){return 0;}

fseek(pT,0,SEEK_END);
cant = ftell(pT)/sizeof(torres);
fclose(pT);
return cant;

}

void funcion::leerTorres(torres torr[], int cant){

FILE *pT = fopen("torres.dat","rb");
if(pT==nullptr){cout << "Error de lectura" << endl;}

fread(torr, sizeof(torres), cant, pT);
fclose(pT);

}

void funcion::listadoTorres(){
int cantidad = cantidadTorres();

torres *torr = new torres[cantidad];

leerTorres(torr,cantidad);

verTorres();
for(int i=0; i<cantidad; i++){
    torr[i].mostrarTorres();
}

delete []torr;


}


void funcion::alertasWarning(){

int cantAlertas = cantidadAlertas();

alertas *alert = new alertas[cantAlertas];

leerAlertas(alert,cantAlertas);
cout << "TORRE" << " | " << "IMPACTO" << " | " << " TIPO IMPACTO " << "       | " << " SERVICIO " << "       | " << " DIAS PARA RESOLVER " << endl;
cout << "---------------------------------------------------------------------------------------------" << endl;
for(int i=0; i<cantAlertas; i++){
    buscarWarning(alert[i].getServicio());
}

delete []alert;


}

void funcion::buscarWarning(char const *servicio){

int cantidadImpac = cantidadImpactos();

impactos *impact = new impactos [cantidadImpac];

leerImpac(impact,cantidadImpac);

const char war[] = "Warning";

for(int i=0; i<cantidadImpac; i++){

    int comparardor = strcmp(impact[i].getTipoImpacto(),war);
    int serv = strcmp(impact[i].getServicioAlertado(),servicio);

    if(comparardor==0 && serv==0){
    cout << impact[i].getTorre() << "| " << impact[i].getNroImpacto() << "      | " << impact[i].getTipoImpacto()<<  "           | " << impact[i].getServicioAlertado()<< " |        " << impact[i].getDiasResolucion()<<endl;
    }

}

delete []impact;

}

void funcion::alertasCritical(){

int cantAlertas = cantidadAlertas();

alertas *alert = new alertas[cantAlertas];

leerAlertas(alert,cantAlertas);
cout << "TORRE" << " | " << "IMPACTO" << " | " << " TIPO IMPACTO " << "       | " << " SERVICIO " << "       | " << " DIAS PARA RESOLVER " << endl;
cout << "---------------------------------------------------------------------------------------------" << endl;
for(int i=0; i<cantAlertas; i++){
    buscarCritical(alert[i].getServicio());
}

delete []alert;



}


void funcion::buscarCritical(const char *servicio){

int cantidadImpac = cantidadImpactos();

impactos *impact = new impactos [cantidadImpac];

leerImpac(impact,cantidadImpac);

const char war[] = "Critical";

for(int i=0; i<cantidadImpac; i++){

    int comparardor = strcmp(impact[i].getTipoImpacto(),war);
    int serv = strcmp(impact[i].getServicioAlertado(),servicio);

    if(comparardor==0 && serv==0){
    cout << impact[i].getTorre() << "| " << impact[i].getNroImpacto() << "      | " << impact[i].getTipoImpacto()<<  "           | " << impact[i].getServicioAlertado()<< " |        " << impact[i].getDiasResolucion()<<endl;
    }

}

delete []impact;




}


void funcion::alertasPorTurno(){

int turno;
cout << "TURNO MANIANA ---->> 1" << endl;
cout << "TURNO TARDE ----->> 2" << endl;
cout << "TURNO NOCHE ----->> 3" << endl;
cout << "Ingrese turno : ";
cin >> turno;
cout << endl;
buscarTurno(turno);



}

void funcion::buscarTurno(int turno){

int cantOper = cantidadOperadores();
operadores *oper = new operadores[cantOper];
leerOper(oper,cantOper);

int cantAlertas = cantidadAlertas();
alertas *alert = new alertas[cantAlertas];
leerAlertas(alert,cantAlertas);




int usuario=0;

cout << endl;
for(int i=0; i<cantOper; i++){
    if(oper[i].getTurno()==turno){
        cout << "OPERADOR: " << endl;
        cout << oper[i].getNombre() << " " << oper[i].getApellido() << endl;

        for(int j=0; j<cantAlertas; j++){
            if(oper[i].getUsuario()==alert[j].getUsuario()){
                cout << alert[j].getTorre() << " " <<alert[j].getServicio() <<endl;
            }
        }

        cout << "--------------------------------------------------" << endl;

    }



}

delete []oper;



//
//}
//
//delete []alert;




}







