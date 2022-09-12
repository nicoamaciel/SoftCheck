#ifndef OPERADORES_H_INCLUDED
#define OPERADORES_H_INCLUDED

#include "fecha.h"

class operadores{

private:
    string _nombre;
    string _apellido;
    string _usuario;
    fecha _fechaIngegreso;
    int _dni;
    int _turno;
public:
    ///gets
    string getNombre();
    string getApellido();
    string getUsuario();
    fecha getFechaIngreso();
    int getDni();
    int getTurno();
    ///sets
    void setNombre(string);
    void setApellido(string );
    void setUsuario(string);
    void setFechaIngreso(fecha);
    void setDni(int);
    void setTurno(int);

    ///Comportamientos
    void cargarOperador();
    void mostarOperador();
    int grabarenDisco();
    int leerdeDisco(int);
    void grabarCsv();

};


#endif // OPERADORES_H_INCLUDED
