// lab2mult2ndc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LI.h"
#include <iostream>
using namespace std;

int main()
{

	LI a = "58657574";
	LI b = "39876576";
	LI c = b.Karatsuba_mul(a);
	c.out();
	LI d = b.ordinary_mul(a);
	d.out();
	LI v = c - d;
	v.out();

	




	system("pause");
    return 0;
}

