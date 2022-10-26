#ifndef TORRES_H_INCLUDED
#define TORRES_H_INCLUDED

class torres{
private:
        char _NombreTorre[30];
        int _Equiposxtorre;
        bool _Estado;

public:
    ///Gets

        const char *getNombreTorre(){return _NombreTorre;}
        int getEquiposxtorre();
        bool getEstado();
    ///Sets

        void setNombreTorre(const char *nom);
        void setEquiposxtorre(int);
        void setEstado(bool est);


    ///Comportamientos

    void cargarTorres();
    void mostrarTorres();
    int grabarenDisco();
    int leerdeDisco(int);

};
void verTorres();


#endif // TORRES_H_INCLUDED
