// lab2mult2ndc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LI.h"
#include <iostream>
using namespace std;

int main()
{

	LI a = "14999997764765543243237";
	LI b = "99859989876874543566787";
	//LI c = b.Karatsuba_mul(a);
	//c.out();
	//LI d = b.ordinary_mul(a);
	//d.out();
	LI v = a - b;
	v.out();


	system("pause");
    return 0;
}

