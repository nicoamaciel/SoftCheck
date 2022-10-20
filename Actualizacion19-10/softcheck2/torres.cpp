#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#include "torres.h"
#include "fecha.h"

    bool torres::getEstado(){return _Estado;}
///Sets
    void torres::setNombreTorre (const char *n){
        strcpy (_NombreTorre,n);
    }
    void torres::setHost(const char *hst){
        strcpy (_Host,hst);
    }
    void torres::setEstado(bool est){_Estado=est;}

///Comportamientos

    void torres::cargarTorres(){
        char nom[20],hst[20];
        bool est;

        cout << "Cargar nombre de torre: ";
        cin >> nom;
        cout << "Cargar nombre del host: ";
        cin >> hst;
        est = true;

        setNombreTorre(nom);
        setHost(hst);
        setEstado(est);

    }
    void torres::mostrarTorres(){
        if(_Estado == true){
        cout << getNombreTorre() << "      |   " << getNombreTorre() << "     |    " ;
        cout << "-----------------------------------------------------------------------------------";
        }


    }

    void verTorres(){
        cout << " NOMBRE TORRE   " << " |    " << " APELLIDO " << " | "  <<endl;
        cout << "---------------------------------------------------------"<< endl;
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
