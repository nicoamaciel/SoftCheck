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

    int alertas::getImpacto(){
        return _Impacto;
    }

    fecha alertas::getFechaDeAlerta(){
        return _FechaDeAlerta;

    }
    bool alertas::getEstado(){
        return _Estado;
    }


    ///Sets

    void alertas::setUsuario(const char* usu){
        strcpy (_Usuario,usu);
    }
    void alertas::setIpHost(int ip){
        _IpHost=ip;
    }
    void alertas::setImpacto(int imp){
        _Impacto=imp;
    }

    void alertas::setFechaDeAlerta(fecha fe){
        _FechaDeAlerta=fe;
    }
    void alertas::setEstado(bool est){
        _Estado=est;
    }


    ///Comportamientos

    void alertas::cargarAlertas(){
        int ip, imp;
        char usu[20];
        fecha fe;

        cout << "Cargar usuario: ";
        cin >> usu;
        cout << "Cargar ip host: ";
        cin >> ip;
        cout << "Cargar fecha de impacto: ";
        fe.cargarFecha();
        cout << "Cargar numero de impacto: ";
        cin >> imp;


        setIpHost(ip);
        setUsuario(usu);
        setFechaDeAlerta(fe);
        setImpacto(imp);
    }

        void alertas::mostrarAlertas(){
        cout << getIpHost() << "  |    " << getUsuario()<< "          |     "<< getImpacto()<< "          |     ";
        getFechaDeAlerta().mostrarFecha();
        cout << "------------------------------------------------------------------"<<endl;
        }

        void verAlertas(){
        cout << " IP HOST " << " | "  << " USUARIO " << " | "  <<" IMPACTO "<< " | "  <<" FECHA " << endl;
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

