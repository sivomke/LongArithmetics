// lab2mult2ndc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LI.h"
#include <iostream>
using namespace std;

int main()
{

	LI a="52345";
	LI b = "7642";
	LI res=a / b;
	res.out();
	a.out();
	b.out();
	//LI(a*b).out();
	//b.out();


	
	




	system("pause");
    return 0;
}

