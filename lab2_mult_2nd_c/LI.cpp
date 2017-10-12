#include "stdafx.h"
#include "LI.h"
#include <algorithm>
#include <iostream>
using namespace std;

LI::LI(long int input) {
	set_value(input);
	reverse(value.begin(), value.end());
}

void LI:: set_value(long int input) {
	value.push_back(input % 10);
	int temp = input / 10;
	if (temp == 0) return;
	set_value(temp);
}

void LI::out() {
	for (auto elem : value)
		cout << elem;
	cout << endl;
}
