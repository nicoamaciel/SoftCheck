#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "fecha.h"
#include "impactos.h"

    ///Gets

    int impactos::getIpHost(){
        return _IpHost;
    }
    int impactos::getNroImpacto(){
        return _NroImpacto;
    }
    string impactos::getTorre(){
        return _Torre;
    }
    string  impactos::getTipoImpacto(){
        return _TipoImpacto;
    }
    string impactos::getServicioAlertado(){
        return _ServicioAlertado;
    }
    ///Sets

    void impactos::setIpHost(int ip){
        _IpHost=ip;
    }
    void impactos::setNroImpacto(int impacto){
        _NroImpacto=impacto;
    }
    void impactos::setTorre(string torre){
        _Torre=torre;
    }
    void impactos::setTipoImpacto(string tipo){
        _TipoImpacto=tipo;
    }
    void impactos::setServicioAlertado(string servicio){
        _ServicioAlertado=servicio;

    }

    ///Comporatmientos

    void impactos::cargarImpactos(){
        int ip, impacto;
        string servicio, tipo, torre;

        cout << "Cargar ip del host: ";
        cin >> ip;
        cout << "Cargar numero impacto: ";
        cin >> impacto;
        cout << "Cargar nombre de torre: ";
        cin >> torre;
        cout << "Cargar tipo de impacto: ";
        cin >> tipo;
        cout << "Cargar servicio alertado: ";
        cin >> servicio;

        setIpHost(ip);
        setNroImpacto(impacto);
        setTorre(torre);
        setTipoImpacto(tipo);
        setServicioAlertado(servicio);

    }
    void impactos::mostarImpactos(){
    cout<< "Ip del host: "<< getIpHost() << endl;
    cout<< "Numero de impacto: "<< getNroImpacto() << endl;
    cout<< "Torre correspondiente: "<< getTorre() << endl;
    cout<< "Tipo de impacto: "<< getTipoImpacto()<< endl;
    cout<< "Servicio alertado: "<< getServicioAlertado() <<endl;
    cout<< " - - - - - -- - - - - - - "<< endl;

    }
    int impactos::grabarenDisco(){
        FILE *pImpactos;
        pImpactos = fopen("impactos.dat", "ab");
        if(pImpactos == NULL){
            cout << "ERROR DE ARCHIVO"<< endl;
            system("pause");
            return -1;
            }

        int escribio = fwrite(this, sizeof(impactos), 1, pImpactos);
        fclose(pImpactos);
        return escribio;

    }

    int impactos::leerdeDisco(int){
    }
    void impactos::grabarCsv(){
    }
