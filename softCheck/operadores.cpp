#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "fecha.h"
#include "operadores.h"
    operadores ObjOper;
    int oper;



    ///gets

    int operadores::getUsuario(){
        return _usuario;
    }

    bool operadores::getEstado(){
        return _estado;
    }

    int operadores::getTurno(){
        return _turno;
    }
    ///sets

    void operadores::setNombre(const char *n){
        strcpy (_nombre,n);
    }
    void operadores::setApellido(const char *ape){
        strcpy (_apellido,ape);
    }

    void operadores::setUsuario(int usu){
        _usuario = usu;
    }

    void operadores::setTurno(int tur){
        _turno = tur;
    }

    void operadores::setEstado(bool est){
        _estado = est;
    }

    //Comportamientos
    void operadores::cargarOperador(){
        char nom[20],ape[20];
        int tur, usu;
        bool est;


        cout << "Cargar nombre: ";
        cin >> nom;
        cout << "Cargar apellido: ";
        cin >> ape;
        cout << "Cargar usuario (numerico): ";
        cin >> usu;
        cout << "Cargar turno: ";
        cin >>tur;
        est = true;

        setNombre(nom);
        setApellido(ape);
        setUsuario(usu);
        setTurno(tur);
        setEstado(est);
    }


    void operadores::mostrarOperador(){
        if(_estado== true){
        cout << getNombre() << "      |   " << getApellido() << "     |    " << getUsuario() << " |    " << getTurno() << "        | "<< getEstado() << "            | ";
        cout << "-----------------------------------------------------------------------------------";
        }

    }


    void verOperadores(){
        cout << " NOMBRE    " << " |    " << " APELLIDO " << " | " << " USUARIO " << " | " << " TURNO     " << " | " << " ESTADO     " <<endl;
        cout << "-----------------------------------------------------------------------------------"<< endl;
    }

    void listarOperadores(){

        while(ObjOper.leerdeDisco(oper)==1){
        ObjOper.mostrarOperador();
        oper++;
        cout << endl;
        }

    }


    int operadores::grabarenDisco(){
    FILE *pOperadores;
    pOperadores = fopen("operadores.dat", "ab");
    if(pOperadores == NULL){
        cout << "ERROR DE ARCHIVO"<< endl;
        system("pause");
        return -1;
        }

    int escribio = fwrite(this, sizeof(operadores), 1, pOperadores);
    fclose(pOperadores);
    return escribio;
    }

    int operadores::leerdeDisco(int pos){
    FILE *pOperador;
    int leyo;
    pOperador = fopen("operadores.dat", "rb");
        if(pOperador == NULL){
            cout << "ERROR DE ARCHIVO"<< endl;
            system("pause");
            return -1;
        }
    fseek(pOperador, pos*sizeof(operadores),0);
    leyo = fread(this, sizeof(operadores),1,pOperador);
    fclose(pOperador);
    return leyo;

    }

    bool operadores::modificarEnDisco(int pos){
        FILE *p;
        p=fopen("operadores.dat","rb+");
        if(p==NULL) return false;
        fseek(p, pos * sizeof(operadores), 0);
        bool escribio=fwrite(this, sizeof (operadores), 1, p);
        fclose(p);
        return escribio;


    }



    int buscarOper(int nUsu){
        operadores obj;
        int pos=0;
        while(obj.leerdeDisco(pos)){
            if(obj.getUsuario()==nUsu){
                return pos;
            }
            pos++;
        }

        return -1;

    }

    bool altaOper(){
        operadores obj;
        int nUsu, pos;
        cout << "Validacion de usuario: ";
        cin >> nUsu;
        pos = buscarOper(nUsu);
        if(pos>=0 ){
            cout << "EL USUARIO YA ENCUENTRA REGISTRADO";
            return false;
            system("pause");
        }
        obj.cargarOperador();
        return obj.grabarenDisco();


    }
    bool bajaOper(){
        operadores obj;
        int nUsu, pos;
        cout << "Validacion de usuario: ";
        cin >> nUsu;
        pos = buscarOper(nUsu);
        if(pos==-1){
        cout << "El numero de usuario no existe en el archivo"<< endl;
        system("pause");
        return false;
        }
        obj.leerdeDisco(pos);
        if(obj.getEstado()==false){
        cout << "Operador ya fue dada de baja"<< endl;
        system("pause");
        return false;
        }

        obj.leerdeDisco(pos);
        obj.setEstado(false);
        obj.modificarEnDisco(pos);

    }


    bool grabarCsvOper(){
    operadores obj;
    int pos=0;



    ofstream _oper("bkp-operadores.csv",ios::app);

    if(!_oper){
        cout << "Error al grabar registro en csv";
    }
    else{
        _oper<<"NOMBRE"<<";"<<"APELLIDO"<<";"<<"USUARIO"<<";"<<"ESTADO"<<";"<<"TURNO"<<endl;
        while(obj.leerdeDisco(pos)==1){
                _oper<<obj.getNombre()<<";"<<obj.getApellido()<<";"<<obj.getUsuario()<<";"<<obj.getEstado()<<";"<<obj.getTurno()<<endl;
                pos++;
            }
            _oper.close();
        }




    }


