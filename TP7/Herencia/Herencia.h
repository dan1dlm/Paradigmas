//============================================================================
// Name        : HerenciaVirtual.cpp
// Author      : CW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class X{
public:
	X(){ cout << "Constructor X" << endl;};
};
class Y{
public:
	Y(){ cout << "Constructor Y" << endl;};

};
class Z : public Y, virtual public X {
public:
	Z(){ cout << "Constructor Z" << endl;};

};

class Z1 : public Y, virtual public X {
public:
	Z1(){ cout << "Constructor Z1" << endl;};

};
class Z2 : public Z, virtual public Z1 {
public:
	Z2(){ cout << "Constructor Z2" << endl;};


};


int main() {

	cout << "Orden de llamada a los constructores de a" << endl;
	Z2 a;
// Los constructores heredados virtualmente
// s�lo se invocan una vez
	return 0;
}