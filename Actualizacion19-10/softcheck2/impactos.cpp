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

    bool impactos::getEstado(){
        return _Estado;
    }
    ///Sets

    void impactos::setIpHost(int ip){
        _IpHost=ip;
    }
    void impactos::setNroImpacto(int impacto){
        _NroImpacto=impacto;
    }
    void impactos::setTorre(const char *towwer){
        strcpy (_Torre,towwer);
    }
    void impactos::setTipoImpacto(const char *tipo){
        strcpy (_TipoImpacto,tipo);
    }
    void impactos::setServicioAlertado(const char *servicio){
        strcpy (_ServicioAlertado,servicio);
    }

    void impactos::setEstado(bool est){
        _Estado=est;
    }
    ///Comporatmientos

    void impactos::cargarImpactos(){
        int ip, impacto, pos;
        char servicio[20], tipo[20], torre[20];
        bool est;
        cout << "Cargar ip del host: ";
        cin >> ip;
        setIpHost(ip);
//        do{
//        cout << "Cargar ip del host: ";
//        cin >> ip;
//        pos = buscarImpac(ip);
//        if(pos>=0){
//            cout << "Ip ya registarada con anterioridad" << endl;
//            system("pause");
//            }
//            else{
//            setIpHost(ip);
//            }
//        }while(pos>=0);
        cout << "Cargar numero impacto: ";
        cin >> impacto;
        cout << "Cargar nombre de torre: ";
        cin >> torre;
        cout << "Cargar tipo de impacto: ";
        cin >> tipo;
        cout << "Cargar servicio alertado: ";
        cin >> servicio;
        est=true;

        setEstado(est);
        setNroImpacto(impacto);
        setTorre(torre);
        setTipoImpacto(tipo);
        setServicioAlertado(servicio);

    }
    void impactos::mostrarImpactos(){

        if(_Estado==true){
        cout << getIpHost() << "      |   " << getNroImpacto() << "     |    " << getTorre() << " |    " << getTipoImpacto() << "        | "<< getServicioAlertado() << "            | ";
        cout <<endl << "-----------------------------------------------------------------------------------" << endl;
        }
    }

     void verImpactos(){
        cout << " IP HOST " << " | " << " IMPACTO " << " | " << " TORRE " << " | " << " TIPO IMPACTO " << " | " << " SERVICO ALERTADO " << endl;
        cout << "-----------------------------------------------------------------------------------"<< endl;

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

    int impactos::leerdeDisco(int pos){
    FILE *pImpactos;
    int leyo;
    pImpactos = fopen("impactos.dat", "rb");
    if(pImpactos == NULL){
        cout << "ERROR DE ARCHIVO"<< endl;
        system("pause");
        return -1;
    }
    fseek(pImpactos, pos*sizeof(impactos),0);
    leyo = fread(this, sizeof(impactos),1,pImpactos);
    fclose(pImpactos);
    return leyo;

    }

    bool impactos::modificarEnDisco(int pos){
    FILE *pI;
    pI=fopen("impactos.dat","rb+");
    if(pI==NULL) return false;
    fseek(pI, pos * sizeof(impactos), 0);
    bool escribio=fwrite(this, sizeof (impactos), 1, pI);
    fclose(pI);
    return escribio;

    }



    int buscarImpac(int nIP){
        impactos obj;
        int pos=0;
        while(obj.leerdeDisco(pos)){
            if(obj.getIpHost()==nIP){
                return pos;
            }
            pos++;
        }
        return -1;

    }


    bool bajaImpac(){
        impactos obj;
        int nIP, pos;
        cout << "Validacion de ip: ";
        cin >> nIP;
        pos = buscarImpac(nIP);
        if(pos==-1){
        cout << "El numero ingresado no existe en el archivo"<< endl;
        system("pause");
        return false;
        }
        obj.leerdeDisco(pos);
        if(obj.getEstado()==false){
        cout << "Equipo ya fue dada de baja"<< endl;
        system("pause");
        return true;
        }

        obj.leerdeDisco(pos);
        obj.setEstado(false);
        obj.modificarEnDisco(pos);

    }


//    void grabarCsv(){
//    }
