#include <iostream>
using namespace std;

typedef int item;
const item indef = -1;

class Vector{
    item *elementos;
    int MAX;

    //METODOS AUXILIARES
    bool reservarMemoria(int tama);
    bool redimensionar(int tama);

    public:
    Vector(int n = 10);
    Vector(Vector&);
    void insertar(const int p, int item);
    int capacidad();
    item elemento(const int p);
    void borrar();
    void borrar(const int p);
    ~Vector();
    void mostrar();
    bool operator==(Vector&);
    Vector operator+(Vector& V);
};

//Desarrollo de métodos

