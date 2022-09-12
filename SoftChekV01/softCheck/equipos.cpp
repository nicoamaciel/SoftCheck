#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "equipos.h"

    //gets
    string equipos::getNombreHost(){
        return _NombreHost;
    }
    string equipos::getMarca(){
        return _Marca;
    }
    int equipos::getIphost(){
        return _IpHost;
    }
    bool equipos::getEstado(){
        return _Estado;
    }


    //sets
    void equipos::setNombreHost(string nombHost){
        _NombreHost=nombHost;
    }
    void equipos::setMarca(string marca){
        _Marca=marca;
    }
    void equipos::setIphost(int iphost){
        _IpHost=iphost;
    }
    void equipos::setEstado(bool estado){
        _Estado=estado;
    }


    //comportamientos

    void equipos::cargarEquipos(){
    int iphost;
    bool estado;
    string marca, nombrehost;

    cout << "Ingresar nombre del host: ";
    cin >> nombrehost;
    cout << "Ingresar marca del equipo: ";
    cin >> marca;
    cout << "Ingresar ip del host: ";
    cin >> iphost;
    cout << "Ingresar estado del equipo: ";
    cin >> estado;

    setNombreHost(nombrehost);
    setMarca(marca);
    setIphost(iphost);
    setEstado(estado);

    }


    void equipos::mostrarEquipos(){
        cout << getNombreHost() << "       |   " << getMarca() << "           |    " << getIphost() << "  | " << getEstado() ;
        cout << endl << "------------------------------------------------------------------";
    }



    int equipos::grabarenDisco(){
    FILE *pEquipos;
    pEquipos = fopen("equipos.dat", "ab");
    if(pEquipos == NULL){
        cout << "ERROR DE ARCHIVO"<< endl;
        system("pause");
        return -1;
    }

    int escribio = fwrite(this, sizeof(equipos), 1, pEquipos);
    fclose(pEquipos);
    return escribio;
    }

    int equipos::leerdeDisco(int pos){
    FILE *pEquipos;
    int leyo;
    pEquipos = fopen("equipos.dat", "rb");
    if(pEquipos == NULL){
        cout << "ERROR DE ARCHIVO"<< endl;
        system("pause");
        return -1;
    }
    fseek(pEquipos, pos*sizeof(equipos),0);
    leyo = fread(this, sizeof(equipos),1,pEquipos);
    fclose(pEquipos);
    return leyo;

    }

    void equipos::grabarCsv(){
    ofstream _equipos("equipos.csv",ios::app);

    if(!_equipos){
        cout << "Error al grabar registro en csv";
    }
    else{
        _equipos<<getNombreHost()<<";"<<getMarca()<<";"<<getIphost()<<";"<<getEstado()<<endl;
        _equipos.close();

        cout << "Csv generado con exito" << endl;
        }
    }
