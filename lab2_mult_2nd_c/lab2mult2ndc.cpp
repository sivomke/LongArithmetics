// lab2mult2ndc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LI.h"
#include <iostream>


int main()
{
	LI a =12;
	LI b = 5;
	LI c(3, 0);
	int n = 6;
	LI ten_in_n = pow(10, n); //10^n
	LI ten_in_n_over_2 = pow(10, n / 2);
	ten_in_n.out();
	ten_in_n_over_2.out();
	//c= a.Karatsuba_mul(b);
	//c.out();
	system("pause");
    return 0;
}

