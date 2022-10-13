#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

#include "funciones.h"
#include "equipos.h"



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

for(int i=0; i<cantidad; i++){
    equ[i].mostrarEquipos();
}

delete []equ;

}
