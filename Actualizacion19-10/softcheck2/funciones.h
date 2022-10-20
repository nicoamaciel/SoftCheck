#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "equipos.h"
#include "operadores.h"
#include "impactos.h"
#include "alertas.h"

class funcion{
private:
public:
    void ingresarEquipos();
    void bajadeEquipos();
    int cantidadEquipos();
    void leerEquipos(equipos equ[], int cant);
    void listadoEquipos();

    void ingresoOperadores();
    void bajadeOperadores();
    int cantidadOperadores();
    void leerOper(operadores oper[], int cant);
    void listadoOper();

    void ingresoImpactos();
    void bajadeImpactos();
    int cantidadImpactos();
    void leerImpac(impactos impac[], int cant);
    void listadoImpac();

    void ingresoAlertas();
    void bajadeAlertas();
    int cantidadAlertas();
    void leerAlertas(alertas alert[], int cant);
    void listadoAlert();





};

#endif // FUNCIONES_H_INCLUDED
