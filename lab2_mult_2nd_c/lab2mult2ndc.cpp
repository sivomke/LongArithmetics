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
	/*random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<int> distribution(2, (17));
	for (int i = 0; i < 17; ++i) {
		cout<<distribution(generator)<<" ";
	}
	*/
	LI a="113";
	LI b = "8";

	cout << boolalpha << a.Rabin_Miller() << endl;;

	system("pause");
    return 0;
}

