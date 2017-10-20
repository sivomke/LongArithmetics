#include "stdafx.h"
#include "LI.h"
#include <algorithm>
#include <iostream>
using namespace std;

LI::LI(long int input) {
	set_value(input);
	//reverse(value.begin(), value.end());
}


void LI:: set_value(long int input) {
	value.push_back(input % this->Base);
	int temp = input / this->Base;
	if (temp == 0) return;
	set_value(temp);
}

void LI::out() {
	reverse(value.begin(), value.end());
	for (auto elem : value)
		cout << elem << " ";
	cout << endl;
}

const LI LI::operator+(const LI & b)
{
	
	int n = max(this->value.size(), b.value.size());
	LI sum;
	sum.value = vector<int>(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		sum.value[i] += (value[i] + b.value[i]) % Base;
		sum.value[i + 1] = (value[i] + b.value[i]) / Base;

	}
	return sum;
}

const LI LI::operator*(const LI & b)
{
	int n = max(this->value.size(), b.value.size());
	LI mul;
	mul.value = vector<int>(2*n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j){
		
		}
		mul.value[i] += (value[i] * b.value[i]) % Base;
		mul.value[i + 1] += (value[i] * b.value[i]) / Base;


	}
	return mul;
}

void LI::add_zeros(int add)
{
	while (add--)
		value.push_back(0);
}
