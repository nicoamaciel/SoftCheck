#ifndef ALERTAS_H_INCLUDED
#define ALERTAS_H_INCLUDED
#include "fecha.h"

class alertas{
private:
    int _IpHost;
    fecha _FechaDeAlerta;
    int _NumeroImpacto;
    string _TipoImpacto;
    string _ServicioAlertado;
public:
    ///Gets
    int getIpHost();
    int getNumeroImpacto();
    string getTipoImpacto();
    string getServicioAlertado();

    ///Sets

    void setIpHost(int);
    void setNumeroImpacto(int);
    void setTipoImpacto(string);
    void setServicioAlertado(string);

    ///Comportamientos

    void cargarAlertas();
    void mostrarAlertas();
    int grabarenDisco();
    int leerdeDisco(int);
    void grabarCsv();


};


//void verAlertas();


#endif // ALERTAS_H_INCLUDED
