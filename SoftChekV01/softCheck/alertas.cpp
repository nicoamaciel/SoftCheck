#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "fecha.h"
#include "alertas.h"




    ///Gets
    int alertas::getIpHost(){
        return _IpHost;
    }
    fecha alertas::getFechaDeAlerta(){
        return _FechaDeAlerta;
    }
    int alertas::getNumeroImpacto(){
        return _NumeroImpacto;
    }
    string alertas::getTipoImpacto(){
        return _TipoImpacto;
    }
    string alertas::getServicioAlertado(){
        return _ServicioAlertado;
    }

    ///Sets

    void alertas::setIpHost(int ip){
        _IpHost = ip;
    }
    void alertas::setFechaDeAlerta(fecha fe){
        _FechaDeAlerta = fe;
    }
    void alertas::setNumeroImpacto(int num){
        _NumeroImpacto = num;
    }
    void alertas::setTipoImpacto(string tipo){
        _TipoImpacto = tipo;
    }
    void alertas::setServicioAlertado(string service){
        _ServicioAlertado = service;
    }

    ///Comportamientos

        void alertas::cargarAlertas(){
        int ip, num;
        string tipo, service;
        fecha fe;

        cout << "Cargar ip host: ";
        cin >> ip;
        cout << "Cargar numero de impacto: ";
        cin >> num;
        cout << "Cargar fecha de impacto: ";
        fe.cargarFecha();
        cout << "Cargar tipo de impacto: ";
        cin >> tipo;
        cout << "Cargar servicio alertado: ";
        cin >> service;

        setIpHost(ip);
        setNumeroImpacto(num);
        setFechaDeAlerta(fe);
        setTipoImpacto(tipo);
        setServicioAlertado(service);
        }

        void alertas::mostarAlertas(){

        cout << getIpHost() << "      |   " << getNumeroImpacto() << "     |    " << getTipoImpacto() << "  |    " << getServicioAlertado() << "       | ";
        _FechaDeAlerta.mostrarFecha();
        cout << endl << "------------------------------------------------------------------"<< endl;
        }

        int alertas::grabarenDisco(){
            FILE *pAlertas;
            pAlertas = fopen("alertas.dat", "ab");
            if(pAlertas == NULL){
            cout << "ERROR DE ARCHIVO"<< endl;
            system("pause");
            return -1;
            }

            int escribio = fwrite(this, sizeof(alertas), 1, pAlertas);
            fclose(pAlertas);
            return escribio;


        }
        int alertas::leerdeDisco(int){

        }
        void alertas::grabarCsv(){

        }

