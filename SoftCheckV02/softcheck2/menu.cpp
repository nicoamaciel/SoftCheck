#include <iostream>
using namespace std;

#include "menu.h"
#include "funciones.h"
#include "rlutil.h"
#include "equipos.h"
#include "operadores.h"
#include "alertas.h"
#include "impactos.h"
#include "torres.h"


menu llamar;
funcion funcion;

void menu::tituloSoft(const char* text, int posx, int posy){
    rlutil::locate(posx, posy);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<<text<<endl;
    rlutil::setColor(rlutil::WHITE);
}

void menu::seleccion(const char* text, int posx, int posy, bool selected){
    if(selected){
        rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
        rlutil::setColor(rlutil::BLACK);
        rlutil::locate(posx - 2, posy);
        cout<< (char)62 << " " << text << " "  <<endl;

    }
    else{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(posx - 3, posy);
        cout<< "   " << text << " " << endl;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);

}


int menu::menuPrincipal(){
    int y=0;
    rlutil::hidecursor();

    while(true){
    menu mp;

    mp.tituloSoft(" SOFTCHECK ", 23, 2);

    mp.seleccion("GESTION ALTA-BAJA", 20, 4, y==0);
    mp.seleccion("CONSULTAS", 20, 5, y==1);
    mp.seleccion("EXPORTAR", 20, 6, y==2);
    mp.seleccion("MANTENIMIENTO", 20, 7, y==3);
    mp.seleccion("SALIR", 20, 8, y==4);

    switch(rlutil::getkey()){

    case 14: //ARRIBA
        rlutil::locate(18,4+y);
        cout<<" "<<endl;
        y--;
        if(y<0){
            y = 0;
        }
        break;
    case 15: //ABAJO
        rlutil::locate(18,4+y);
        cout<<" "<<endl;
        y++;
        if(y>4){
            y=4;
        }
        break;
    case 1: //ENTER

        switch(y){
            menu op;
            case 0:
                op.altaBaja();
            break;
            case 1:
                op.consultas();
                break;
            case 2:
                op.exportar();
                break;
            case 3:
                op.mantenimieto();
                break;
            case 4:
                exit(0);
                break;


            default:
                break;
        }
    break;
    default:
        break;
    }
}
}

int menu::altaBaja(){

    int y=0;
    rlutil::hidecursor();
    rlutil::cls();

    while(true){
    menu mp;

    mp.tituloSoft(" SOFTCHECK ", 23, 1);
    mp.tituloSoft(" ALTAS & BAJAS ", 21, 2);

    mp.seleccion("EQUIPOS", 20, 4, y==0);
    mp.seleccion("OPERADORES", 20, 5, y==1);
    mp.seleccion("IMPACTOS", 20, 6, y==2);
    mp.seleccion("ALERTAS", 20, 7, y==3);
    mp.seleccion("TORRES", 20, 8, y==4);
    mp.seleccion("VOLVER", 20, 9, y==5);
    mp.seleccion("SALIR", 20, 10, y==6);

    switch(rlutil::getkey()){

    case 14: //ARRIBA
        rlutil::locate(18,6+y);
        cout<<" "<<endl;
        y--;
        if(y<0){
            y = 0;
        }
        break;
    case 15: //ABAJO
        rlutil::locate(18,6+y);
        cout<<" "<<endl;
        y++;
        if(y>6){
            y=6;
        }
        break;
    case 1: //ENTER
        rlutil::cls();


        switch(y){
            menu op;
            case 0:
                op.subMenuAB(y, "EQUIPOS");
            break;
            case 1:
                op.subMenuAB(y, "OPERADORES");
                break;
            case 2:
                op.subMenuAB(y, "IMPACTOS");
                break;
            case 3:
                op.subMenuAB(y, "ALERTAS");
                break;
            case 4:
                op.subMenuAB(y, "TORRES");
                break;
            case 5:
                menu mp;
                mp.menuPrincipal();
                break;
            case 6:
                exit(0);

            default:
                break;
        }
    break;
    default:
        break;
    }
}

}

int menu::subMenuAB(int x, const char*text){

    int y=0;
    rlutil::hidecursor();
    rlutil::cls();

    while(true){

    menu mp;

    mp.tituloSoft(" SOFTCHECK ", 23, 1);
    mp.tituloSoft(" ALTAS & BAJAS ", 21, 2);
    mp.tituloSoft(text,23,3);

    mp.seleccion("ALTA", 20, 4, y==0);
    mp.seleccion("BAJA", 20, 5, y==1);
    mp.seleccion("VOLVER", 20, 6, y==2);

    switch(rlutil::getkey()){

    case 14: //ARRIBA
        rlutil::locate(18,2+y);
        cout<<" "<<endl;
        y--;
        if(y<0){
            y = 0;
        }
        break;
    case 15: //ABAJO
        rlutil::locate(18,2+y);
        cout<<" "<<endl;
        y++;
        if(y>2){
            y=2
            ;
        }
        break;
    case 1: //ENTER
        rlutil::cls();

        switch(y){
            menu op;
            case 0:
                if(x==0){
                    altaEquipo();
                    op.subMenuVolver();
                }
                else if(x==1){
                    altaOper();
                    op.subMenuVolver();
                }
                else if(x==2){
                    //ALTA IMPACTO
                    op.subMenuVolver();
                }
                else if(x==3){
                    //ALTA ALERTA
                    op.subMenuVolver();
                }
                else if(x==4){
                    //ALTA TORRE
                    op.subMenuVolver();
                }
            break;
            case 1:
                if(x==0){
                    bajaEquipo();
                    op.subMenuVolver();
                }
                else if(x==1){
                    bajaOper();
                    op.subMenuVolver();
                }
                else if(x==2){
                    //BAJA IMPACTO
                    op.subMenuVolver();
                }
                else if(x==3){
                    //BAJA ALERTA
                    op.subMenuVolver();
                }
                else if(x==4){
                    //BAJA TORRE
                    op.subMenuVolver();
                }
                 break;
            case 2:
                menu mp;
                mp.altaBaja();
                break;

            default:
                break;
        }
    break;
    default:
        break;
    }
}
}


int menu::subMenuVolver(){
    int y=0;
    rlutil::hidecursor();

    while(true){
    menu mp;

    mp.tituloSoft("DESEA VOLVER AL MENU PRINCIPAL?", 1,6);
    mp.seleccion("SI", 1, 7, y==0);
    mp.seleccion("NO", 1, 8, y==1);

    switch(rlutil::getkey()){

    case 14: //ARRIBA
        rlutil::locate(0,7+y);
        cout<<" "<<endl;
        y--;
        if(y<0){
            y = 0;
        }
        break;
    case 15: //ABAJO
        rlutil::locate(0,8+y);
        cout<<" "<<endl;
        y++;
        if(y>1){
            y=1
            ;
        }
        break;
    case 1: //ENTER
        rlutil::cls();

        switch(y){
            menu op;
            case 0:
                op.menuPrincipal();
            break;

            case 1:
                exit(0);
                break;

            default:
                break;
        }
    break;
    default:
        break;
    }
}
}

int menu::consultas(){
    int y=0;
    rlutil::hidecursor();
    rlutil::cls();

    while(true){
    menu mp;

    mp.tituloSoft(" SOFTCHECK ", 23, 1);
    mp.tituloSoft(" CONSULTAS ", 23, 2);

    mp.seleccion("LISTADO DE EQUIPOS", 20, 4, y==0);
    mp.seleccion("LISTADO DE TORRES", 20, 5, y==1);
    mp.seleccion("OPERADORES POR TURNO", 20, 6, y==2);
    mp.seleccion("ALERTAS POR TURNO", 20, 7, y==3);
    mp.seleccion("ALERTAS WARNING", 20, 8, y==4);
    mp.seleccion("ALERTAS CRITICAL", 20, 9, y==5);
    mp.seleccion("ESCALA DE RESOLUCIONES", 20, 10, y==6);
    mp.seleccion("VOLVER", 20, 11, y==7);
    mp.seleccion("SALIR", 20, 12, y==8);

    switch(rlutil::getkey()){

    case 14: //ARRIBA
        rlutil::locate(18,8+y);
        cout<<" "<<endl;
        y--;
        if(y<0){
            y = 0;
        }
        break;
    case 15: //ABAJO
        rlutil::locate(18,8+y);
        cout<<" "<<endl;
        y++;
        if(y>8){
            y=8;
        }
        break;
    case 1: //ENTER
        rlutil::cls();
        switch(y){
            menu mp;
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                mp.menuPrincipal();
                break;
            case 8:
                exit(0);
            default:
                break;
        }
    break;
    default:
        break;
    }
}
}

int menu::exportar(){
    int y=0;
    rlutil::hidecursor();
    rlutil::cls();

    while(true){
    menu mp;

    mp.tituloSoft(" SOFTCHECK ", 23, 1);
    mp.tituloSoft(" EXPORTAR CSV ", 23, 2);

    mp.seleccion("EXPORTAR EQUIPOS", 20, 4, y==0);
    mp.seleccion("EXPORTAR OPERADORES", 20, 5, y==1);
    mp.seleccion("EXPORTAR ALERTAS", 20, 6, y==2);
    mp.seleccion("VOLVER", 20, 7, y==3);
    mp.seleccion("SALIR", 20, 8, y==4);

    switch(rlutil::getkey()){

    case 14: //ARRIBA
        rlutil::locate(18,4+y);
        cout<<" "<<endl;
        y--;
        if(y<0){
            y = 0;
        }
        break;
    case 15: //ABAJO
        rlutil::locate(18,4+y);
        cout<<" "<<endl;
        y++;
        if(y>4){
            y=4;
        }
        break;
    case 1: //ENTER
        rlutil::cls();
        switch(y){
            menu mp;
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                mp.menuPrincipal();
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    break;
    default:
        break;
    }
}
}


int menu::mantenimieto(){

    int y=0;
    rlutil::hidecursor();
    rlutil::cls();

    while(true){
    menu mp;

    mp.tituloSoft(" SOFTCHECK ", 23, 1);
    mp.tituloSoft(" MANTENIMIENTO ", 23, 2);

    mp.seleccion("BACKUP EQUIPOS", 20, 4, y==0);
    mp.seleccion("BACKUP TORRES", 20, 5, y==1);
    mp.seleccion("BACKUP IMPACTOS", 20, 6, y==2);
    mp.seleccion("MANUAL DE USUARIO", 20, 7, y==3);
    mp.seleccion("VOLVER", 20, 8, y==4);
    mp.seleccion("SALIR", 20, 9, y==5);

    switch(rlutil::getkey()){

    case 14: //ARRIBA
        rlutil::locate(18,5+y);
        cout<<" "<<endl;
        y--;
        if(y<0){
            y = 0;
        }
        break;
    case 15: //ABAJO
        rlutil::locate(18,5+y);
        cout<<" "<<endl;
        y++;
        if(y>5){
            y=5;
        }
        break;
    case 1: //ENTER
        rlutil::cls();
        switch(y){
            menu mp;
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                mp.menuPrincipal();
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }
    break;
    default:
        break;
    }
}
}





