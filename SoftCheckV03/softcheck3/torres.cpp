#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "torres.h"
#include "fecha.h"


    int torres::getEquiposxtorre(){return _Equiposxtorre;}
    bool torres::getEstado(){return _Estado;}

///Sets

    void torres::setNombreTorre (const char *n){
        strcpy (_NombreTorre,n);
    }
    void torres::setEquiposxtorre(int equi){_Equiposxtorre=equi;}

    void torres::setEstado(bool est){_Estado=est;}

///Comportamientos

    void torres::cargarTorres(){
        char nom[20];
        bool est;
        int equi;

        cout << "Cargar nombre de torre: ";
        cin >> nom;
        cout << "Equipos monitoreados: ";
        cin >> equi;
        est = true;

        setNombreTorre(nom);
        setEquiposxtorre(equi);
        setEstado(est);

    }
    void torres::mostrarTorres(){
        if(_Estado == true){
        cout << getNombreTorre() << "              |   " << getEquiposxtorre() << "      |   " ;
        cout << endl << "--------------------------------------" << endl;
        }


    }

    void verTorres(){
        cout << " NOMBRE TORRE   " << " |  " << " EQUIPOS POR TORRE " <<  " | "  <<endl;
        cout << "------------------------------------"<< endl;
    }



    int torres::grabarenDisco(){

    FILE *pTorres;
    pTorres = fopen("torres.dat", "ab");
    if(pTorres == NULL){
        cout << "ERROR DE ARCHIVO"<< endl;
        system("pause");
        return -1;
        }

    int escribio = fwrite(this, sizeof(torres), 1, pTorres);
    fclose(pTorres);
    return escribio;
    }

    int torres::leerdeDisco(int pos){
    FILE *pTorres;
    int leyo;
    pTorres = fopen("operadores.dat", "rb");
        if(pTorres == NULL){
            cout << "ERROR DE ARCHIVO"<< endl;
            system("pause");
            return -1;
        }
    fseek(pTorres, pos*sizeof(torres),0);
    leyo = fread(this, sizeof(torres),1,pTorres);
    fclose(pTorres);
    return leyo;
    }
