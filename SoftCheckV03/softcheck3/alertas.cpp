#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "fecha.h"
#include "alertas.h"




    ///Gets

    int alertas::getUsuario(){
        return _Usuario;
    }
    fecha alertas::getFechaDeAlerta(){
        return _FechaDeAlerta;
    }
    bool alertas::getEstado(){
        return _Estado;
    }


    ///Sets

    void alertas::setTorre(const char *torre){
        strcpy (_Torre,torre);
    }
    void alertas::setServicio(const char *ser ){
         strcpy (_Servicio,ser);
    }

    void alertas::setUsuario(int usu){
        _Usuario=usu;
    }

    void alertas::setFechaDeAlerta(fecha fe){
        _FechaDeAlerta=fe;
    }

    void alertas::setEstado(bool est){
        _Estado=est;
    }




    ///Comportamientos

        void alertas::cargarAlertas(){
        int usu;
        char torre[20], servicio[20];
        fecha fe;
        bool est;

        cout << "Cargar torre de resolucion: ";
        cin >> torre;
        cout << "Cargar servicio alertado: ";
        cin >> servicio;
        cout << "Cargar usuario: ";
        cin >> usu;
        cout << "Cargar fecha de impacto: ";
        fe.cargarFecha();
        est = true;

        setTorre(torre);
        setServicio(servicio);
        setUsuario(usu);
        setFechaDeAlerta(fe);
        setEstado(est);

        }

        void alertas::mostrarAlertas(){
        cout  << getTorre() << "          |     "<< getServicio() << "          |     "<< getUsuario() << "          |     ";
        getFechaDeAlerta().mostrarFecha();
        cout << "-------------------------------------------------------------------------------------------------------"<<endl;
        }

        void verAlertas(){
        cout << " TORRE " << "           |     "  << " SERVICIO " << "               | "  <<" USUARIO "<< "             | "  <<" FECHA DE ALERTA" << endl;
        cout << "------------------------------------------------------------------------------------------------------"<< endl;
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

    bool csvAlertas(){
    alertas obj;
    int pos=0;

    ofstream _alertas("alertas.csv",ios::ate);

    if(!_alertas){
        cout << "Error al grabar registro en csv";
    }
    else{
        _alertas<<"TORRE"<<";"<<"SERVICIO"<<";"<<"USUARIO"<<";"<<"DIA"<<";"<<"MES"<<";"<<"ANIO"<<endl;
        while(obj.leerdeDisco(pos)==1){
                _alertas<<obj.getTorre()<<";"<<obj.getServicio()<<";"<<obj.getUsuario()<<";"<<obj.getFechaDeAlerta().getDia()<<";"<<obj.getFechaDeAlerta().getMes()<<";"<<obj.getFechaDeAlerta().getAnio()<<endl;
                pos++;
            }
            _alertas.close();
        }

    }


