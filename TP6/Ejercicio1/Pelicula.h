#include <iostream>
using namespace std;

enum tipoPelicula {N, I};

class Pelicula{
    static int autonumerico;
    int codigo;
    string titulo;
    string director;
    bool estreno;
    float precioBase;
    enum tipoPelicula tipo;    

    public:
    Pelicula();
    Pelicula(string, string, bool, float, enum tipoPelicula);
    Pelicula(const Pelicula&);
    int getAutonumerico();
    void setDirector(string);
    void listarInformacion();
    float calcularCosto();

    //Destructor
    ~Pelicula();
};


