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

        cout << "Cargar ip host: ";
        cin >> ip;
        cout << "Cargar numero de impacto: ";
        cin >> num;
        cout << "Cargar fecha de impacto: ";
        _FechaDeAlerta.cargarFecha();
        cout << "Cargar tipo de impacto: ";
        cin >> tipo;
        cout << "Cargar servicio alertado: ";
        cin >> service;

        setIpHost(ip);
        setNumeroImpacto(num);
        setTipoImpacto(tipo);
        setServicioAlertado(service);
    }

    void alertas::mostrarAlertas(){

        cout << getIpHost() << "      |   " << getNumeroImpacto() << "     |    " << getTipoImpacto() << "  |    " << getServicioAlertado() << "          |     ";
        _FechaDeAlerta.mostrarFecha();
        cout << "------------------------------------------------------------------";
        }

        void verAlertas(){
        cout << " IP HOST " << " | " << " IMPACTO " << " | " << " SERVICO ALERTADO " << " | " << " TIPO IMPACTO " << " | " << " FECHA " << endl;
        cout << "------------------------------------------------------------------"<< endl;
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
    int alertas::leerdeDisco(int pos){
            FILE *pAlertas;
            int leyo;
            pAlertas = fopen("alertas.dat", "rb");
            if(pAlertas == NULL){
                cout << "ERROR DE ARCHIVO"<< endl;
                system("pause");
                return -1;
            }
            fseek(pAlertas, pos*sizeof(alertas),0);
            leyo = fread(this, sizeof(alertas),1,pAlertas);
            fclose(pAlertas);
            return leyo;

    }
//    void grabarCsv(){
//
//    }

