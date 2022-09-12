#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "fecha.h"
#include "operadores.h"

    ///gets
    string operadores::getNombre(){
        return _nombre;
    }
    string operadores::getApellido(){
        return _apellido;
    }

    string operadores::getUsuario(){
        return _usuario;
    }


    fecha operadores::getFechaIngreso(){
        return _fechaIngegreso;


    }

    int operadores::getDni(){
        return _dni;

    }
    int operadores::getTurno(){
        return _turno;
    }
    ///sets

    void operadores::setNombre(string nom){
        _nombre=nom;
    }
    void operadores::setApellido(string ape){
        _apellido=ape;
    }

    void operadores::setUsuario(string usu){
        _usuario = usu;
    }
    void operadores::setFechaIngreso(fecha fe){
        _fechaIngegreso = fe;

    }

    void operadores::setDni(int dni){
        _dni=dni;

    }

    void operadores::setTurno(int tur){
        _turno = tur;
    }

    //Comportamientos
    void operadores::cargarOperador(){
        string nom,ape,usu;
        int tur,dni;
        fecha fe;
        cout << "Cargar nombre: ";
        cin >> nom;
        cout << "Cargar apellido: ";
        cin >> ape;
        cout << "Cargar usuario: ";
        cin >> usu;
        cout << "Cargar fecha de ingreso: ";
        fe.cargarFecha();
        cout << "Cargar dni: ";
        cin >>dni;
        cout << "Cargar turno: ";
        cin >>tur;

        setFechaIngreso(fe);
        setNombre(nom);
        setApellido(ape);
        setUsuario(usu);
        setTurno(tur);
        setDni(dni);
    }


    void operadores::mostarOperador(){

        cout << getNombre() << "      |   " << getApellido() << "     |    " << getUsuario() << "  |    " << getTurno() << "       | "<< getDni() << "       | ";
        _fechaIngegreso.mostrarFecha();
        cout << endl << "------------------------------------------------------------------"<< endl;


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





