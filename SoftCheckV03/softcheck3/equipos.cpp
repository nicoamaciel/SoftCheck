#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "equipos.h"
#include "menu.h"
#include "rlutil.h"
#include "iomanip"

    equipos objEquipos;
    int eq;


    int equipos::getIphost(){
        return _IpHost;

    }
    bool equipos::getEstado(){
        return _Estado;
    }

    //sets
    void equipos::setNombreHost(const char *n){
        strcpy (_NombreHost,n);
    }
    void equipos::setMarca(const char *mar){
        strcpy (_Marca,mar);

    }
    void equipos::setIphost(int ip){
        _IpHost = ip;

    }
    void equipos::setEstado(bool est){
        _Estado = est;

    }


    //comportamiento

    void equipos::cargarEquipos(){
    char nom[20], mark[20];
    int numIp, pos;
    bool est;

    do{
    cout << " Cargar numero de ip: ";
    cin >> numIp;
    pos = buscarEquipo(numIp);
    if(pos>=0){
        menu aux;
        bool estado = buscarEstado(numIp);
        if(estado==false){
            cout << "IP YA REGISTRADA" << endl;
            aux.subMenuCambiarEstado(50,1,pos);
        }
        else{
            cout << "IP YA REGISTRADA"<<endl;
        }
    }
    else{
        setIphost(numIp);
        }
    }while(pos>=0);

    cout << " Cargar nombre de host: ";
    cin >>nom;
    setNombreHost(nom);
    cout << " Cargar marca del host: ";
    cin >>mark;
    setMarca(mark);

    est = true;
    setEstado(est);




    }


    void equipos::mostrarEquipos(){

        if(_Estado== true){

        cout<<left;
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(12) << getNombreHost();
        rlutil::setColor(rlutil::WHITE);
        cout<< setw(3) << " | ";
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(15) << getMarca();
        rlutil::setColor(rlutil::WHITE);
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(3) << " | ";
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(8) << getIphost();
        rlutil::setColor(rlutil::WHITE);
        cout<< setw(3) << " | ";
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(12) << getEstado();
        rlutil::setColor(rlutil::WHITE);
        cout<< setw(2) << " |" << endl;
        cout<< setw(58) << "----------------------------------------------------------" << endl;
        }

    }

    void verEquipos(){

        cout<<left;
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(12) << "NOMBRE HOST";
        rlutil::setColor(rlutil::WHITE);
        cout<< setw(3) << " | ";
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(15) << "MARCA DEL HOST";
        rlutil::setColor(rlutil::WHITE);
        cout<< setw(3) << " | ";
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(8) << "IP HOST";
        rlutil::setColor(rlutil::WHITE);
        cout<< setw(3) << " | ";
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout<< setw(12) << "ESTADO HOST";
        rlutil::setColor(rlutil::WHITE);
        cout<< setw(2) << " |" << endl;
        cout<< setw(58) << "==========================================================" << endl;
    }



    int equipos::grabarenDisco(){
        FILE *pEquipos;
        pEquipos = fopen("equipos.dat","ab");
        if(pEquipos==NULL){
            cout << "Error en archivo";
            return -1;
        }

        int escribio = fwrite(this, sizeof(equipos), 1, pEquipos);
        fclose(pEquipos);
        return escribio;

    }
    int equipos::leerdeDisco(int pos){
        FILE *pEquipos;
        int leyo;
        pEquipos = fopen("equipos.dat","rb");
        if(pEquipos==NULL){
            cout << "Error en archivo";
            return -1;
        }
        fseek(pEquipos, pos*sizeof(equipos),0);
        leyo = fread(this, sizeof(equipos),1,pEquipos);
        fclose(pEquipos);
        return leyo;


    }

    bool equipos::modificarEnDisco(int pos){
        FILE *p;
        p=fopen("equipos.dat","rb+");
        if(p==NULL) return false;
        fseek(p, pos * sizeof(equipos), 0);
        bool escribio=fwrite(this, sizeof (equipos), 1, p);
        fclose(p);
        return escribio;

    }

    int buscarEquipo(int nIP){
        equipos obj;
        int pos=0;
        while(obj.leerdeDisco(pos)){
            if(obj.getIphost()==nIP){
                return pos;
            }
            pos++;
        }
        return -1;

    }

    bool buscarEstado(int nIP){
        equipos obj;
        int pos=0;
        while(obj.leerdeDisco(pos)){
            if(obj.getIphost()==nIP){
                return obj.getEstado();
            }
            pos++;
        }
    }

    void modificarEstado(int nIP){
        equipos obj;
        int pos = buscarEquipo(nIP);
        obj.leerdeDisco(pos);
        obj.setEstado(true);
        obj.modificarEnDisco(pos);

    }


    bool bajaEquipo(){
        equipos obj;
        int nIP, pos;
        cout << "Validacion de ip: ";
        cin >> nIP;
        pos = buscarEquipo(nIP);
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
        cout<< "EQUIPO DADO DE BAJA"<<endl;

    }


    bool grabarCsv(){
    equipos obj;
    int pos=0;



    ofstream _equipos("Informe-equipos.csv",ios::app);

    if(!_equipos){
        cout << "Error al grabar registro en csv";
    }
    else{
        _equipos<<"NOMBRE"<<";"<<"MARCA"<<";"<<"IP"<<";"<<"ESTADO"<<endl;
        while(obj.leerdeDisco(pos)==1){
                _equipos<<obj.getNombreHost()<<";"<<obj.getMarca()<<";"<<obj.getIphost()<<";"<<obj.getEstado()<<endl;

                pos++;
            }
            _equipos.close();
        }
    }

