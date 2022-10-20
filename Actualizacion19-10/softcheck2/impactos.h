#ifndef IMPACTOS_H_INCLUDED
#define IMPACTOS_H_INCLUDED


#include "fecha.h"
class impactos{
private:
    int _IpHost;
    int _NroImpacto;
    char _Torre[20];
    char  _TipoImpacto[20];
    char _ServicioAlertado[20];
    bool _Estado;
public:
    ///Gets

    int getIpHost();
    int getNroImpacto();
    const char *getTorre(){return _Torre;}
    const char *getTipoImpacto(){return _TipoImpacto;}
    const char *getServicioAlertado(){return _ServicioAlertado;}
    bool getEstado();
    ///Sets

    void setIpHost(int );
    void setNroImpacto(int);
    void setTorre(const char *);
    void setTipoImpacto(const char * );
    void setServicioAlertado(const char *);
    void setEstado(bool);

    ///Comporatmientos

    void cargarImpactos();
    void mostrarImpactos();
    int grabarenDisco();
    int leerdeDisco(int);
    bool modificarEnDisco(int);

};

int buscarImpac(int);
void verImpactos();
bool bajaImpac();
//void grabarCsv();


#endif // IMPACTOS_H_INCLUDED
