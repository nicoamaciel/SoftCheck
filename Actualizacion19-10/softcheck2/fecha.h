#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class fecha{
private:
    int _dia;
    int _mes;
    int _anio;
public:

//Gets
    int getDia();
    int getMes();
    int getAnio();

//Sets
    void setDia(int);
    void setMes(int);
    void setAnio(int);
//Comportamientos
    void cargarFecha();
    void mostrarFecha();

};

#endif // FECHA_H_INCLUDED
