#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "fecha.h"
#include "impactos.h"

    ///Gets

    int impactos::getNroImpacto(){
        return _NroImpacto;
    }

    int impactos::getDiasResolucion(){
        return _diasResolucion;
    }

    bool impactos::getEstado(){
        return _Estado;
    }
    ///Sets

    void impactos::setTorre(const char *towwer){
        strcpy (_Torre,towwer);
    }
    void impactos::setTipoImpacto(const char *tipo){
        strcpy (_TipoImpacto,tipo);
    }
    void impactos::setServicioAlertado(const char *servicio){
        strcpy (_ServicioAlertado,servicio);
    }

    void impactos::setNroImpacto(int impacto){
        _NroImpacto=impacto;
    }

    void impactos::setDiasResolucion(int diasR){
        _diasResolucion=diasR;
    }

    void impactos::setEstado(bool est){
        _Estado=est;
    }
    ///Comporatmientos

    void impactos::cargarImpactos(){
        int impacto, diasr, pos;
        char servicio[20], tipo[20], torre[20];
        bool est;

        cout << "Cargar nombre de torre: ";
        cin >> torre;
        cout << "Cargar numero impacto: ";
        cin >> impacto;
        cout << "Cargar tipo de impacto: ";
        cin >> tipo;
        cout << "Cargar dias de resolucion: ";
        cin >> diasr;
        cout << "Cargar servicio alertado: ";
        cin >> servicio;
        est=true;

        setEstado(est);
        setNroImpacto(impacto);
        setDiasResolucion(diasr);
        setTorre(torre);
        setTipoImpacto(tipo);
        setServicioAlertado(servicio);

    }
    void impactos::mostrarImpactos(){

        if(_Estado==true){
        cout << getTorre() << "     |    " << getNroImpacto() << " |    " << getTipoImpacto() << "        | "<< getDiasResolucion() << "        | "<< getServicioAlertado() << " ";
        cout <<endl << "-----------------------------------------------------------------------------------" << endl;
        }
    }

     void verImpactos(){
        cout << " TORRE " << " | " << " IMPACTO " << " | " << " TIPO IMPACTO" << " | " << " DIAS RESOLUCION " << " | " << " SERVICO ALERTADO " << endl;
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



//    int buscarImpac(int nIP){
//        impactos obj;
//        int pos=0;
//        while(obj.leerdeDisco(pos)){
//            if(obj.getIpHost()==nIP){
//                return pos;
//            }
//            pos++;
//        }
//        return -1;
//
//    }


//    bool bajaImpac(){
//        impactos obj;
//        int nIP, pos;
//        cout << "Validacion de ip: ";
//        cin >> nIP;
//        pos = buscarImpac(nIP);
//        if(pos==-1){
//        cout << "El numero ingresado no existe en el archivo"<< endl;
//        system("pause");
//        return false;
//        }
//        obj.leerdeDisco(pos);
//        if(obj.getEstado()==false){
//        cout << "Equipo ya fue dada de baja"<< endl;
//        system("pause");
//        return true;
//        }
//
//        obj.leerdeDisco(pos);
//        obj.setEstado(false);
//        obj.modificarEnDisco(pos);
//
//    }


//    void grabarCsv(){
//    }
