// lab2mult2ndc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LI.h"
#include <iostream>
using namespace std;

int main()
{
	/* a =149999937;
	LI b = 998599897;
	LI c= b.Karatsuba_mul(a);
	c.out();
	LI d = b.ordinary_mul(a);
	d.out();
	LI v = c - d;
	v.out();
	*/
	LI a = "543243237";
	LI b = "998599897";
	LI::check(a, b);
	system("pause");
    return 0;
}

