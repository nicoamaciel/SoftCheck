#ifndef ALERTAS_H_INCLUDED
#define ALERTAS_H_INCLUDED

#include "fecha.h"

class alertas{
private:
    char _Usuario[20];
    int _IpHost;
    int _Impacto;
    fecha _FechaDeAlerta;
    bool _Estado;
public:
    ///Gets
    const char *getUsuario(){return _Usuario;}
    int getIpHost();
    int getImpacto();
    fecha getFechaDeAlerta();
    bool getEstado();
    ///Sets

    void setUsuario(const char* );
    void setIpHost(int);
    void setImpacto(int);
    void setFechaDeAlerta(fecha);
    void setEstado(bool);

    ///Comportamientos

    void cargarAlertas();
    void mostrarAlertas();
    int grabarenDisco();
    int leerdeDisco(int);



};

void verAlertas();



#endif // ALERTAS_H_INCLUDED
