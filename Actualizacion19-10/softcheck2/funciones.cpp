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
funcion funcion;

int cantidad = funcion.cantidadEquipos();

equipos *equ = new equipos[cantidad];

funcion.leerEquipos(equ,cantidad);

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
funcion funcion;

int cantidad = funcion.cantidadOperadores();

operadores *oper = new operadores[cantidad];

funcion.leerOper(oper,cantidad);

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

void funcion::bajadeImpactos(){
bool comparar = bajaImpac();
    if(comparar){
        cout << "Impacto dado de baja" << endl;
    }



}

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
funcion funcion;

int cantidad = funcion.cantidadImpactos();

impactos *impac = new impactos[cantidad];

funcion.leerImpac(impac,cantidad);

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
funcion funcion;

int cantidad = funcion.cantidadAlertas();

alertas *alert = new alertas[cantidad];

funcion.leerAlertas(alert,cantidad);

verAlertas();
for(int i=0; i<cantidad; i++){
    alert[i].mostrarAlertas();
}

delete []alert;

}

