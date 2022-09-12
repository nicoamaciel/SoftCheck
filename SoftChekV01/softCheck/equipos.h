#ifndef SOFTCHECK_H_INCLUDED
#define SOFTCHECK_H_INCLUDED



class equipos{

private:
    string _NombreHost; //Host
    string _Marca; //Service class
    int _IpHost;
    bool _Estado; //Estado de equipo

public:
    //gets
    string getNombreHost();
    string getMarca();
    int getIphost();
    bool getEstado();

    //sets
    void setNombreHost(string);
    void setMarca(string);
    void setIphost(int);
    void setEstado(bool);


    //comportamiento

    void cargarEquipos();
    void mostrarEquipos();
    int grabarenDisco();
    int leerdeDisco(int);
    void grabarCsv();


};






#endif // SOFTCHECK_H_INCLUDED
