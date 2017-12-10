// lab2mult2ndc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LI.h"
#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int main()
{
	LI a = "52345";
	LI b = "54";
	cout << "52345/54=";
	(a / b).out();
	LI d = "149";
	if (d.Rabin_Miller()) cout << "d is probably prime." << endl;
	else cout<<"d is composite." << endl;
	LI k = "221";
	if (k.Rabin_Miller()) cout << "k is probably prime." << endl;
	else cout << "k is composite." << endl;
	LI e = "54637827";
	LI f = "75687649"; //max length for mine Karatsuba :(
    LI g=e*f;
	LI h = e.Karatsuba_mul(f);
	g.out();
	h.out();
	(g - h).out();
	system("pause");
    return 0;
}

