#include "stdafx.h"
#include "LI.h"
#include <algorithm>
#include <iostream>
using namespace std;

LI::LI(long int input) {
	set_value(input);
	//reverse(value.begin(), value.end());
}

LI::LI(int length, int def_val): value(length, 0)
{
}


//LI::LI(int length):value(length, 0)
//{
//}

LI::LI():value(0,0)
{
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
		cout << elem;
	cout << endl;
	reverse(value.begin(), value.end());
} 

LI  LI::operator+( LI & b)
{

	int n = max(this->value.size(), b.value.size());
	this->add_zeros(n - this->value.size());
	b.add_zeros(n - b.value.size());
	LI sum(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		sum.value[i] += (value[i] + b.value[i]) % Base;
		sum.value[i + 1] = (value[i] + b.value[i]) / Base;

	}
	this->erase_zeros();
	b.erase_zeros();
	sum.erase_zeros();
	return sum;
}


LI LI::operator=(LI & b)
{
	this->value = b.value;
	return LI();
}



LI  LI::operator*(LI & b)
{
	 int l_a = value.size();
	 int l_b = b.value.size();
	 LI mul(l_a + l_b, 0);
	 this->value.push_back(0);
	 int remember = 0;
	 for (int j = 0; j < l_b; ++j) {
		 for (int i=0; i<l_a+1; ++i){
			// cout << "j=" << j << " " << "i=" << i << endl;
			 //cout << "j+i=" << j + i << endl;
			 mul.value[i+j]+=( remember + value[i] * b.value[j]);
			
			 //cout << value[i] << "*" << b.value[j] << endl;
			 //cout << "rem_prev: " << remember << endl;
			 //cout << "write down:" << mul.value[i + j] << endl;
			 remember = mul.value[i+j]/ Base;
			 mul.value[i + j] %= Base;
			
			 //cout << "carry:" << remember << endl;
			/* mul.value[i + j] += remember + value[i] * b.value[j];
			 remember = mul.value[i + j] / Base; // base -  база представления числа
			 mul.value[i + j] %= Base;
			 mul.value[i + j] += remember; */
		 }
	}
	 mul.erase_zeros();
	return mul;
}
 
void LI::add_zeros(int add)
{
	while (add--)
		value.push_back(0);
}

void LI::erase_zeros()
{
	while (this->value.back() ==0)
		this->value.pop_back();
}
