// lab2mult2ndc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LI.h"
#include <iostream>


int main()
{
	LI a =1437;
	LI b = 587;
	LI c= b.Karatsuba_mul(a);
	c.out();

	system("pause");
    return 0;
}

