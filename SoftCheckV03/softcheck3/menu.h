#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class menu{
private:

public:
    int menuPrincipal();
    int mantenimieto();
    int altaBaja();
    int consultas();
    int exportar();
    int subMenuAB(int x, const char*);
    int subMenuVolver(int posx, int posy);
    int subMenuCambiarEstado(int posx, int posy, int ip);

    //EDICION DE MENUS
    void tituloSoft(const char* text, int posx, int posy);
    void seleccion(const char* text, int posx, int posy, bool selected);

};


#endif // MENU_H_INCLUDED
