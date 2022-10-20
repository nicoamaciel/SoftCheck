#ifndef OPERADORES_H_INCLUDED
#define OPERADORES_H_INCLUDED

#include "fecha.h"

class operadores{

private:
    char _nombre[20];
    char _apellido[20];
    int _usuario;
    int _turno;
    bool _estado;
public:
    ///gets
    const char *getNombre(){return _nombre;}
    const char *getApellido(){return _apellido;}
    int getUsuario();
    int getTurno();
    bool getEstado();
    ///sets
    void setNombre(const char*);
    void setApellido(const char*);
    void setUsuario(int);
    void setTurno(int);
    void setEstado(bool);

    ///Comportamientos
    void cargarOperador();
    void mostrarOperador();
    int grabarenDisco();
    int leerdeDisco(int);
    bool modificarEnDisco(int);



};

void verOperadores();
int buscarOper(int);
bool altaOper();
bool bajaOper();
bool grabarCsvOper();


#endif // OPERADORES_H_INCLUDED
