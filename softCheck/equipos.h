#ifndef SOFTCHECK_H_INCLUDED
#define SOFTCHECK_H_INCLUDED



class equipos{

private:
    int _IpHost;
    char _NombreHost[20]; //Host
    char _Marca[20]; //Service class
    bool _Estado; //Estado de equipo

public:
    //gets
    int getIphost();
    const char *getNombreHost(){return _NombreHost;}
    const char *getMarca(){return _Marca;}
    bool getEstado();

    //sets
    void setNombreHost(const char*);
    void setMarca(const char*);
    void setIphost(int);
    void setEstado(bool);


    //comportamiento

    void cargarEquipos();
    void mostrarEquipos();
    int grabarenDisco();
    int leerdeDisco(int);
    bool modificarEnDisco(int);



};

 void verEquipos();
 void listarEquipos();
 int buscarEquipo(int);
 bool altaEquipo();
 bool bajaEquipo();
 bool grabarCsv();


#endif // SOFTCHECK_H_INCLUDED
