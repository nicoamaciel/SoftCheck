#ifndef ALERTAS_H_INCLUDED
#define ALERTAS_H_INCLUDED

#include "fecha.h"

class alertas{
private:
    char _Torre[20];
    char _Servicio[20];
    int _Usuario;
    fecha _FechaDeAlerta;
    bool _Estado;
public:
    ///Gets
    const char *getTorre(){return _Torre;}
    const char *getServicio(){return _Servicio;}
    int getUsuario();
    fecha getFechaDeAlerta();
    bool getEstado();
    ///Sets

    void setTorre(const char* );
    void setServicio(const char* );
    void setUsuario(int);
    void setFechaDeAlerta(fecha);
    void setEstado(bool);

    ///Comportamientos

    void cargarAlertas();
    void mostrarAlertas();
    int grabarenDisco();
    int leerdeDisco(int);



};

void verAlertas();
bool csvAlertas();



#endif // ALERTAS_H_INCLUDED
