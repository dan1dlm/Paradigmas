#include "Vector.h"

bool Vector ::reservarMemoria(int tama)
{
    item *nuevo = new item(tama);
    if (nuevo != nullptr)
    {
        for (int i = 0; i < tama; i++)
        {
            nuevo[i] = indef;
        }

        delete[] elementos;
        elementos = nuevo;

        MAX = tama;

        return true;
    }

    return false;
}

bool Vector ::redimensionar(int tama)
{
    int tope = MAX;
    item *nuevo = new item(tope);

    if (nuevo == NULL)
        return false;
    for (int i = 0; i < tope; i++)
    {
        nuevo[i] = this->elementos[i];
    }

    delete[] this->elementos;
    if (reservarMemoria(tama))
    {
        for (int i = 0; i < tope; i++)
        {
            elementos[i] = nuevo[i];
        }

        this->MAX = tama;
        delete[] nuevo;

        return true;
    }

    return false;
}

Vector ::Vector(int n)
{
    bool resultado = reservarMemoria(n);
    if (n <= 0 || !resultado)
    {
        this->MAX = 0;
    }
}

Vector ::Vector(Vector &V)
{
    if (this != &V)
    {
        if (!this->reservarMemoria(V.MAX))
        {
            this->MAX = 0;
        }
        else
        {
            this->MAX = V.MAX;
            for (int i = 0; i < this->MAX; i++)
            {
                this->elementos[i] = V.elementos[i];
            }
        }
    }
}

void Vector :: insertar(int p, int x){
    if(p<=this->MAX && 0<p || this->redimensionar(p)){
        this->elementos[p-1] = x;
    }
}

int Vector ::capacidad()
{
    return this->MAX;
}

item Vector ::elemento(int p)
{
    if (p <= MAX)
        return elementos[p - 1];
    else
        return indef;
}

void Vector ::borrar()
{
    for (int i = 0; i < this->MAX; i++)
    {
        this->elementos[i] = indef;
    }
}

void Vector ::borrar(const int p)
{
    if (p <= this->MAX && 0 < p)
        this->elementos[p - 1] = indef;
}

Vector ::~Vector()
{
    cout << "\nDireccion del puntero: " << elementos;
    delete[] this->elementos;
    this->MAX = 0;
    cout << "\nVector destruido: " << this << endl;
}

void Vector ::mostrar()
{
    for (int i = 0; i < MAX; i++)
    {
        cout << "elementos " << i << ": " << elementos[i] << endl;
    }
}

bool Vector ::operator==(Vector &V)
{
    if (MAX == V.MAX)
    {
        int i = 0;
        while (i < MAX && elementos[i] == V.elementos[i])
            i++;
        return i == MAX;
    }

    return false;
}

Vector Vector ::operator+(Vector &V1)
{
    int tamanio = MAX;
    if (MAX > V1.capacidad())
    {
        tamanio = V1.capacidad();
    }

    Vector resultado(tamanio);

    for (int i = 0; i < tamanio; i++)
    {
        resultado.elementos[i] = elementos[i] + V1.elementos[i];
    }

    return resultado;
}
