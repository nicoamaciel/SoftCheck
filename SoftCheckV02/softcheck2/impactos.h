#ifndef IMPACTOS_H_INCLUDED
#define IMPACTOS_H_INCLUDED


#include "fecha.h"
class impactos{
private:
    int _IpHost;
    int _NroImpacto;
    string _Torre;
    string  _TipoImpacto;
    string _ServicioAlertado;
public:
    ///Gets

    int getIpHost();
    int getNroImpacto();
    string getTorre();
    string  getTipoImpacto();
    string getServicioAlertado();
    ///Sets

    void setIpHost(int );
    void setNroImpacto(int);
    void setTorre(string);
    void setTipoImpacto(string );
    void setServicioAlertado(string);

    ///Comporatmientos

    void cargarImpactos();
    void mostrarImpactos();
    int grabarenDisco();
    int leerdeDisco(int);
    void grabarCsv();

};

void verImpactos();
//void grabarCsv();


#endif // IMPACTOS_H_INCLUDED
