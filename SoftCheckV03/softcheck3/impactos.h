#ifndef IMPACTOS_H_INCLUDED
#define IMPACTOS_H_INCLUDED


#include "fecha.h"
class impactos{
private:
    char _Torre[20];
    char  _TipoImpacto[20];
    char _ServicioAlertado[20];
    int _diasResolucion;
    int _NroImpacto;
    bool _Estado;
public:
    ///Gets
    const char *getTorre(){return _Torre;}
    const char *getTipoImpacto(){return _TipoImpacto;}
    const char *getServicioAlertado(){return _ServicioAlertado;}
    int getNroImpacto();
    int getDiasResolucion();
    bool getEstado();
    ///Sets
    void setTorre(const char *);
    void setTipoImpacto(const char * );
    void setServicioAlertado(const char *);
    void setDiasResolucion(int);
    void setNroImpacto(int);
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
