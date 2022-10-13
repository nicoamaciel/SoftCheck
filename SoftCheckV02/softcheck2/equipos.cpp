#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "equipos.h"
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
    int numIp;
    bool est;

    cout << " Cargar nombre de host: ";
    cin >>nom;
    setNombreHost(nom);
    cout << " Cargar numero de ip: ";
    cin >> numIp;
    setIphost(numIp);
    cout << " Cargar marca del host: ";
    cin >>mark;
    setMarca(mark);

    est = true;
    setEstado(est);




    }


    void equipos::mostrarEquipos(){

        if(_Estado== true){
        cout << getNombreHost() << "         |    " << getMarca() << "      |    " << getIphost() << "        |    " << getEstado();
        cout << endl << "------------------------------------------------------------" << endl;
        }

    }

    void verEquipos(){
        cout << " NOMBRE HOST " << " | " << " MARCA DEL HOST " << " | " << " IP HOST " << " | " << " ESTADO HOST "<<endl;
        cout << "------------------------------------------------------------------"<< endl;



    }

    void listarEquipos(){
        while(objEquipos.leerdeDisco(eq)==1){
        objEquipos.mostrarEquipos();
        eq++;
        }


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

    bool altaEquipo(){
        equipos obj;
        int nIP, pos;
        cout << "Validacion de ip: ";
        cin >> nIP;
        pos = buscarEquipo(nIP);
        if(pos>=0 ){
            cout << "LA IP YA SE ENCUENTRA REGISTRADA";
            return false;
            system("pause");
        }
        obj.cargarEquipos();
        return obj.grabarenDisco();

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
        return false;
        }

        obj.leerdeDisco(pos);
        obj.setEstado(false);
        obj.modificarEnDisco(pos);

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
