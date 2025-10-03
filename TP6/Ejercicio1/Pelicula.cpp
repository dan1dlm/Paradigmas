#include "Pelicula.h"

int Pelicula ::autonumerico = 0;

Pelicula ::Pelicula()
{
    this->codigo = 0;
    this->titulo = "SinTitulo";
    this->director = "SinNombre";
    this->estreno = false;
    this->precioBase = 0.00;
    this->tipo = N;
}

Pelicula ::Pelicula(string titulo, string director, bool estreno, float precioBase, enum tipoPelicula tipo)
{
    this->codigo = ++(this->autonumerico);
    this->titulo = titulo;
    this->director = director;
    this->estreno = estreno;
    this->precioBase = precioBase;
    this->tipo = tipo;
}

Pelicula ::Pelicula(const Pelicula &P)
{

    if (this != &P)
    {
        this->codigo = P.codigo;
        this->titulo = P.titulo;
        this->director = P.director;
        this->estreno = P.estreno;
        this->precioBase = P.precioBase;
        this->tipo = P.tipo;
    }
}

int Pelicula ::getAutonumerico()
{
    return this->autonumerico;
}

void Pelicula ::setDirector(string nombre)
{
    this->director = nombre;
}

void Pelicula ::listarInformacion()
{
    cout << "Pelicula" << "  (Direccion del Objeto: " << this << " )" << endl;
    cout << "  Codigo: " << this->codigo << endl;
    cout << "  Titulo: " << this->titulo << endl;
    cout << "  Director: " << this->director << endl;
    cout << "  Produccion: " << ((this->tipo == N) ? "Nacional" : "Internacional") << endl;
    cout << "  Estreno: " << ((this->estreno) ? "SI" : "NO") << endl;
    cout << "  Precio Base: " << this->precioBase << endl
         << endl;
}

float Pelicula ::calcularCosto()
{
    float costo = this->precioBase;
    if (this->tipo == I)
    {
        costo *= 1.30;
    }
    else
    {
        if (this->estreno == false)
        {
            costo *= 0.8;
        }
    }

    return costo;
}

Pelicula ::~Pelicula()
{
    cout << "Se destruye la pelicula codigo:" << this->codigo;
    cout << "  (Direccion del Objeto destruido: " << this << " )" << endl
         << endl;

    this->codigo = 0;
    this->titulo = "SinTitulo";
    this->director = "SinNombre";
    this->estreno = false;
    this->precioBase = 0.00;
    this->tipo = N;
    
}

int main(){
    cout<<"Codigo de prueba";

    //Hace lo que quieras mi rey ...
}
