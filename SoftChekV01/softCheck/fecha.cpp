#include <iostream>

using namespace std;
#include "fecha.h"

//Gets
    int fecha::getDia(){
        return _dia;
    }
    int fecha::getMes(){
        return _mes;
    }
    int fecha::getAnio(){
        return _anio;
    }

//Sets
    void fecha::setDia(int dia){
        _dia=dia;
    }
    void fecha::setMes(int mes){
        _mes=mes;
    }
    void fecha::setAnio(int anio){
        _anio=anio;
    }

//Comportamientos
    void fecha::cargarFecha(){
    int d,m,a;
    cout << "Dia: ";
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Anio: ";
    cin >> a;
    setDia(d);
    setMes(m);
    setAnio(a);
    }

    void fecha::mostrarFecha(){
    cout << getDia() << "/ " << getMes() << "/ " << getAnio() << endl;
    }


